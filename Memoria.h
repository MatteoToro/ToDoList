//
// Created by Matteo Torelli on 01/02/26.
//

#ifndef MEMORIA_H
#define MEMORIA_H

#include "ToDoList.h"
#include <iostream>

class Memoria {
public:
    static bool salva(const ToDoList &lista, const std::string &nomeFile);

    //Salva la lista di attività su file (restituisce true se salvataggio riuscito)

    static bool carica(ToDoList &lista, const std::string &nomeFile);

    //carica la lista di attività da un file e ritorna true se tutto ok
};


#endif //MEMORIA_H
