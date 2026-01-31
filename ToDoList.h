//
// Created by Matteo Torelli on 31/01/26.
//

#ifndef TODOLIST_H
#define TODOLIST_H

#include "Task.h"
#include <iostream>
#include <vector>

class ToDoList {
  private:
    std::vector<Task> attività;
    int nextId = 1;//id progressivo

};



#endif //TODOLIST_H
