#include <iostream>
#include "ToDoList.h"
#include "Memoria.h"

int main() {
    ToDoList todo;
    Memoria::carica(todo, "todo.txt");

    std::cout << "Todo attuale:\n";
    for (const auto &t : todo.getAll()) {
        std::cout << t.getId() << (t.isStato() ? " [x] " : " [ ] ") << t.getDescrizione() << "\n";
    }

    // esempio di uso:
    todo.aggiungiTask("Comprare il latte");
    todo.aggiungiTask("Studiare C++");
    todo.segnaFatto(1); // marca il primo come fatto

    if (!Memoria::salva(todo, "todo.txt")) {
        std::cerr << "Errore nel salvataggio\n";
    } else {
        std::cout << "Salvato in todo.txt\n";
    }

    return 0;
}
