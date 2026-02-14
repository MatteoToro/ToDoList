//
// Created by Matteo Torelli on 14/02/26.
//
#include "gtest/gtest.h"
#include "Task.h"
#include <cstdio>

TEST(TaskTest, ConstructorAndGetters) {
    Task t(5, "Prova", true);
    EXPECT_EQ(t.getId(), 5);
    EXPECT_EQ(t.getDescrizione(), "Prova");
    EXPECT_TRUE(t.isStato());
}

TEST(TaskTest, MarkAndUnmark) {
    Task t(1, "Da fare", false);
    EXPECT_FALSE(t.isStato());
    t.segnaFatto();
    EXPECT_TRUE(t.isStato());
    t.segnaNoFatto();
    EXPECT_FALSE(t.isStato());
}

TEST(TaskTest, ConvertAndRebuild) {
    Task t(10, "Descrizione con | pipe", true);
    std::string s = t.convertiInStringa();

    // ricostruisco l'oggetto dalla stringa
    Task r = Task::ricostruisciOggetto(s);
    EXPECT_EQ(r.getId(), 10);
    EXPECT_EQ(r.getDescrizione(), "Descrizione con | pipe");
    EXPECT_TRUE(r.isStato());
}

TEST(TaskTest, EmptyDescriptionAndDefaultState) {
    Task t(2, "", false);
    EXPECT_EQ(t.getDescrizione(), "");
    EXPECT_FALSE(t.isStato());
}