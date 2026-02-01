//
// Created by Matteo Torelli on 29/01/26.
//

#include "Task.h"
#include <iostream>
#include <sstream>
#include <string>

//Definiamo il coastruttore
Task::Task(int id, const std::string &descrizione, bool stato) : id(id), descrizione(descrizione), stato(stato) {}

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

std::string Task::convertiInStringa() const {
  std::ostringstream oss;
  oss << id << "|" <<  (stato ? 1 : 0 )<< "|" << descrizione;
  return oss.str();//funzione della libreria sstream
}

Task Task::ricostruisciOggetto(const std::string &line){
  std::istringstream iss(line);//Crea uno stream di input da tastiera
  std::string part; //Varibaile temporanea per memorizzare ogni campo letto
  int id = 0;
  bool stato = false;
  std::string descrizione;

  if(std::getline(iss, part, '|')){//Legge dallo stream 'iss', si ferma al carattere '|', mette il risultato in part
    id = std::stoi(part);//converte la stringa in intero
  }
  if(std::getline(iss,part, '|')){
    stato = (part == "1");//se il campo è 1 stato = true, sennò false
  }
  if(std::getline(iss, descrizione)){//Legge il resto della stringa fino a fine riga

  }
  return Task(id, descrizione, stato);
}


