#include <iostream>
#include "ToDoList.h"
#include "Memoria.h"

int main() {
    ToDoList todo;
    Memoria::carica(todo, "todo.txt");

    // Proviamo a caricare dal file
    if (!Memoria::carica(todo, "todo.txt")) {
        std::cout << "Nessun file trovato, creo una nuova todo list.\n";
    }

    std::cout << "Todo attuale:\n";

    if (todo.getAll().empty()) {
        std::cout << "(lista vuota)\n";
    } else {
        for (const auto &t : todo.getAll()) {
            std::cout << t.getId()
                      << (t.isStato() ? " [x] " : " [ ] ")
                      << t.getDescrizione()
                      << "\n";
        }
    }

    // Esempio di utilizzo
    todo.aggiungiTask("Comprare il latte");
    todo.aggiungiTask("Studiare C++");
    todo.aggiungiTask(1);

    std::cout << "\nDopo le modifiche:\n";
    for (const auto &t : todo.getAll()) {
        std::cout << t.getId()
                  << (t.isStato() ? " [x] " : " [ ] ")
                  << t.getDescrizione()
                  << "\n";
    }

    if (!Memoria::salva(todo, "todo.txt")) {
        std::cerr << "Errore nel salvataggio\n";
    } else {
        std::cout << "\nSalvato in todo.txt\n";
    }

    return 0;
}
