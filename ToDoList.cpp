//
// Created by Matteo Torelli on 31/01/26.
//

#include "ToDoList.h"

void ToDoList::aggiungiTask(const std::string &descrizione){
  attivita.push_back(Task(nextId++, descrizione, false));
}

bool ToDoList::rimuoviTask(int id){
  for(std::size_t i = 0; i < attivita.size(); i++){
    if(attivita[i].getId() == id){
      attivita.erase(attivita.begin() + i);
      return true;
    }
  }
  return false;
}

bool ToDoList::segnaFatto(int id){
  for(auto &a : attivita){
    if(a.getId() == id){
      a.segnaFatto();
      return true;
    }
  }
  return false;
}

Task* ToDoList::trovaTask(int id){
  for(auto &a : attivita){
    if(a.getId() == id){
      return &a;//Si deve ritornare un puntatore
    }
  }
  return nullptr;//Se non si trova si ritorna il puntatore vuoto
}
const std::vector<Task>& ToDoList::getAll() const {
  return attivita;
}

void ToDoList::clear() {
  attivita.clear();
  nextId = 1;
}