//
// Created by Matteo Torelli on 31/01/26.
//

#ifndef TODOLIST_H
#define TODOLIST_H

#include "Task.h"
#include <iostream>
#include <vector>
#include <algorithm>

class ToDoList {
  private:
    std::vector<Task> attività;
    int nextId = 1;//id progressivo

  public:
    ToDoList() = default;

    void aggiungiTask(const std::string &descrizione);
    bool rimuoviTask(int id);
    bool segnaFatto(int id);
    Task* trovaTask(int id);//Cerca un task e restituisce un puntatore
    const std::vector<Task>& getAll() const;

    void clear();//Per svuotare la lista e resettare id


};



#endif //TODOLIST_H
