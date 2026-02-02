//
// Created by Matteo Torelli on 02/02/26.
//

#include "gtest/gtest.h"
#include "../src/TodoList.h"
#include "../src/Memoria.h"
#include <cstdio>


TEST(ToDoListTest, AddAndFind){
ToDolist lista;

lista.aggiungiTask("T1");
lista.aggiungiTask("T2");
EXPECT_EQ(lista.getAll().size(), 2u);

Task *t = lista.trovaTask(1);
ASSERT_NE(T,nullptr);
EXPECT_EQ(t->getDescrizione(), "T1");
}