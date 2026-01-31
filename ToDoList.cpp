//
// Created by Matteo Torelli on 31/01/26.
//

#include "ToDoList.h"

void ToDoList::aggiungiTask(const std::string &descrizione){
  attività.push_back(Task(nextId++, descrizione, false));
}

bool ToDoList::rimuoviTask(int id){
  for(std::size_t i = 0; i < attività.size(); i++){
    if(attività[i].getId() == id){
      attività.erase(attività.begin() + i);
      return true;
    }
  }
  return false;
}