//
// Created by Matteo Torelli on 01/02/26.
//

#include "Memoria.h"

#include "Memoria.h"
#include "Task.h"
#include <fstream>//libreria utile per lavorare con i file
#include <iostream>

bool Memoria::salva(const ToDoList &lista, const std::string &nomeFile){
  std::ofstream ofs(nomeFile.c_str());
  if(!ofs)
    return false;
  for(const auto &a : lista.getAll()){
    ofs << a.convertiInStringa() << std::endl;
  }
  return true;
}

