#include <iostream>
#include <string>
#include <sstream>
#include "ToDoList.h"
#include "Memoria.h"

void legendaComandi() {
    std::cout << "Comandi disponibili: " << std::endl;
    std::cout << "a (descrizione)  -- aggiungi un nuovo task " << std::endl;
    std::cout << "l                -- lista di tutti i task" << std::endl;
    std::cout << "m (id)           -- segna come fatto il task con id" << std::endl;
    std::cout << "r (id)           -- rimuovi il task con id" << std::endl;
    std::cout << "s                -- salva su file" << std::endl;
    std::cout << "h                -- mostra questa legenda" << std::endl;
    std::cout << "e                -- esci (salvando)" << std::endl;
}

void stampaLista(const ToDoList &todo) {
    const auto &all = todo.getAll();
    if (all.empty()) {
        std::cout <<"lista vuota" << std::endl;
        return;
    }
    for (const auto &a: all) {
        std::cout << a.getId()
        << (a.isStato() ? "[x]" : "[ ]")
        << a.getDescrizione()
        << std::endl;
    }
}

int main() {
    ToDoList todo;

    if (Memoria::carica(todo, "todo.txt")) {
        std::cout << "Carciato todo.txt" << std::endl;
    }else {
        std::cout << "Nessun file todo.txt trovato,creo una nuova lista" << std::endl;
    }

    std::cout << "Ecco la lista di attività:" << std::endl;
    legendaComandi();

    std::string line;
    while (true) {
        std::cout << std::endl;
        if (!std::getline(std::cin, line)) {
            break;
        }

        if (line.empty()) {
            continue;
        }

        std::istringstream iss(line);
        std::string cmd;
        iss >> cmd;

        if (cmd == "a") {
            std::string descrizione;
            std::getline(iss, descrizione);

            // rimuove eventuale spazio iniziale
            if (!descrizione.empty() && descrizione[0] == ' ')
                descrizione = descrizione.substr(1);

            if (descrizione.empty()) {
                std::cout << "Descrizione vuota: aggiunto nulla" << std::endl;
            } else {
                todo.aggiungiTask(descrizione);
                std::cout << "Aggiunto: " << descrizione << std::endl;
            }

        } else if (cmd == "l") {
            stampaLista(todo);

        } else if (cmd == "m") {
            int id;
            if (!(iss >> id)) {
                std::cout << "Uso: m (id)" << std::endl;
            } else {
                if (todo.segnaFatto(id)) {
                    std::cout << "Attività " << id << " segnata come fatto" << std::endl;
                } else {
                    std::cout << "Attività con id " << id << " non trovata" << std::endl;
                }
            }

        } else if (cmd == "r") {
            int id;
            if (!(iss >> id)) {
                std::cout << "Uso: r (id)" << std::endl;
            } else {
                if (todo.rimuoviTask(id)) {
                    std::cout << "Attività " << id << " rimossa" << std::endl;
                } else {
                    std::cout << "Attività con id " << id << " non trovata" << std::endl;
                }
            }

        } else if (cmd == "s") {
            if (Memoria::salva(todo, "todo.txt")) {
                std::cout << "Salvato in todo.txt" << std::endl;
            } else {
                std::cerr << "Errore nel salvataggio di todo.txt" << std::endl;
            }

        } else if (cmd == "h") {
            legendaComandi();

        } else if (cmd == "e") {
            std::cout << "Vuoi salvare le modifiche prima di chiudere? (s/n): ";
            std::string risposta;
            if (!std::getline(std::cin, risposta))
                break;

            if (!risposta.empty() && (risposta[0] == 's' || risposta[0] == 'S')) {
                if (Memoria::salva(todo, "todo.txt")) {
                    std::cout << "Salvato in todo.txt" << std::endl;
                } else {
                    std::cerr << "Errore nel salvataggio di todo.txt" << std::endl;
                }
            }
            break;

        } else {
            std::cout << "Comando non esistente. Premi h per la legenda" << std::endl;
        }
    }
    }
