//
// Created by Matteo Torelli on 01/02/26.
//

#include "Memoria.h"


#include "Task.h"
#include <fstream>//libreria utile per lavorare con i file
#include <iostream>

bool Memoria::salva(const ToDoList &lista, const std::string &nomeFile) {
    std::ofstream ofs(nomeFile.c_str());
    if (!ofs)
        return false;
    for (const auto &a: lista.getAll()) {
        ofs << a.convertiInStringa() << std::endl;
    }
    return true;
}


bool Memoria::carica(ToDoList &lista, const std::string &nomeFile) {
    std::ifstream ifs(nomeFile.c_str());
    if (!ifs)
        return false;
    lista.clear(); //svuotiamo la lista esistente per evitare di mescolare dati vecchi e nuovi
    std::string riga; //Variabile per contare una riga di file alla volta
    while (std::getline(ifs, riga)) {
        if (riga.empty())
            continue; //Serve a saltare le righe vuote

        Task t = Task::ricostruisciOggetto(riga); //Converte la riga di testo in un oggetto Task

        lista.aggiungiTask(t.getDescrizione()); //Aggiunge un nuovo task alla lista; assegna un nuovo ID
        if (t.isStato()) {
            lista.segnaFatto(lista.getAll().back().getId());
        }
    }
    return true;
}
