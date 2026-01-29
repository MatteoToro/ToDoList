//
// Created by Matteo Torelli on 29/01/26.
//

#ifndef TASK_H
#define TASK_H

#include <iostream>


class Task {
private:
  int id = 0;
  std::string descrizione;
  bool stato = false;

public:
  //Dichiaro i costruttori, di cui uno di default per avere un Task vuoto
  Task() = default;
  Task(int id, std::string descrizione, bool stato);



};



#endif //TASK_H
