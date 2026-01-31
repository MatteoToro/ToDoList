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

bool ToDoList::segnaFatto(int id){
  for(auto &a : attività){
    if(a.getId() == id){
      a.segnaFatto();
      return true;
    }
  }
  return false;
}

Task* ToDoList::trovaTask(int id){
  for(auto &a : attività){
    if(a.getId() == id){
      return &a;//Si deve ritornare un puntatore
    }
    return nullptr;//Se non si trova si ritorna il puntatore vuoto
  }
}
const std::vector<Task>& ToDoList::getAll() const {
  return attività;
}

void ToDoList::clear() {
  attività.clear();
  nextId = 1;
}