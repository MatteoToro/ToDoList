//
// Created by Matteo Torelli on 31/01/26.
//

#include "ToDoList.h"

void ToDoList::aggiungiTask(const std::string &descrizione){
  attività.push_back(Task(nextId++, descrizione, false));
}

