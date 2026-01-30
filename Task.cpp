//
// Created by Matteo Torelli on 29/01/26.
//

#include "Task.h"
#include <iostream>

//Definiamo il coastruttore
Task::Task(int id, std::string &descrizione, bool stato) : id(id), descrizione(descrizione), stato(stato) {}

//Definizione delle funzioni utili
int Task::getId() const {
  return id;
}

std::string Task::getDescrizione() const {
  return descrizione;
}

bool Task::isStato() const {
  return stato;
}

void Task::segnaFatto() {
  stato = true;
}

void Task::segnaNoFatto() {
  stato = false;
}