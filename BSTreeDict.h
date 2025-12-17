#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict : public Dict<V> {
private:
    BSTree<TableEntry<V>>* tree; // ABB con elementos de tipo TableEntry<V> para gestionar los elementos de un diccionario.

public:
    // Constructor: crea ABB vacío
    BSTreeDict() {
        tree = new BSTree<TableEntry<V>>();
    }

    // Destructor: libera memoria
    ~BSTreeDict() {
        delete tree;
    }

    // Sobrecarga global del operador << para imprimir el contenido del Diccionario por pantalla. 
    friend std::ostream& operator<<(std::ostream& out, const BSTreeDict<V>& bs) {
        out << *(bs.tree); // usa el operador << de BSTree
        return out;
    }

    // Sobrecarga del operador[]. Actúa como interfaz al método de interfaz heredado search(std::string key)
    V operator[](std::string key) {
        TableEntry<V> te(key); // entrada solo con clave
        return tree->search(te).value; // busca y devuelve el valor
    }

    // Métodos heredados de Dict<V>
    void insert(std::string key, V value) override {
        TableEntry<V> te(key, value);
        tree->insert(te);
    }

    V search(std::string key) override {
        TableEntry<V> te(key);
        return tree->search(te).value;
    }

    V remove(std::string key) override {
        TableEntry<V> te(key);
        V val = tree->search(te).value; // obtener valor antes de borrar
        tree->remove(te);
        return val;
    }

    int entries() override {
        return tree->size();
    }
};

#endif
