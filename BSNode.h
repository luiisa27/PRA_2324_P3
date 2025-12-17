#ifndef BSNODE_H
#define BSNODE_H

#include <ostream>

template <typename T>
class BSNode {
public:
    //atributos públicos
    T elem;             // elemento almacenado en el nodo
    BSNode<T>* left;    // puntero al sucesor izquierdo
    BSNode<T>* right;   // puntero al sucesor derecho

    //constructor que inicializa el nodo con elem y punteros opcionales
    BSNode(T elem, BSNode<T>* left = nullptr, BSNode<T>* right = nullptr) {
        this->elem = elem;
        this->left = left;
        this->right = right;
    }

    //sobrecarga del operador << para imprimir el nodo
    friend std::ostream& operator<<(std::ostream& out, const BSNode<T>& bsn) {
        out << bsn.elem; // por simplicidad, solo imprimimos el elemento
        return out;
    }
};

#endif

