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
  Task(int id, std::string &descrizione, bool stato = false);

  //Dichiaro le funzioni che utilizzerò
  int getId() const;
  std::string getDescrizione() const;
  bool isStato() const;

  //Dichiaro funzioni che permettono di trasformare o un oggetto Task in una stringa o una stringa in un oggetto Task
  std::string convertiInStringa() const; //Trasforma un oggetto Task in stringa
  static Task ricostruisciOggetto(const std::string &line);//Prende una stringa, letta dal file, e ricostruisce un oggetto




};



#endif //TASK_H
