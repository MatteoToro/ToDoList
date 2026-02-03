//
// Created by Matteo Torelli on 02/02/26.
//

#include "gtest/gtest.h"
#include "ToDoList.h"
#include "Memoria.h"
#include <cstdio>


TEST(ToDoListTest, AggiungiTrova){
ToDoList lista;

lista.aggiungiTask("T1");
lista.aggiungiTask("T2");
EXPECT_EQ(lista.getAll().size(), 2u);

Task *t = lista.trovaTask(1);
ASSERT_NE(t,nullptr);
EXPECT_EQ(t->getDescrizione(), "T1");
}

TEST(ToDoListTest, SalvaCarica){
  ToDoList lista;
  lista.aggiungiTask("Salva");
  lista.segnaFatto(1);

  EXPECT_TRUE(Memoria::salva(lista, "Test.txt"));

  ToDoList caricato;
  EXPECT_TRUE(Memoria::carica(caricato, "Test.txt"));
  EXPECT_EQ(caricato.getAll().size(), 1u);

  std::remove("Test.txt");

}