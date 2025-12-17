#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>
using namespace std;
//TableEntry.h contendrá tanto la definición como la implementación de la clase TableEntry<V>
template <typename V>
class TableEntry {
    public:
        // atributos
        std::string key; // clave del par. 
        V value; // valor del par.

        // métodos
        //#1 Método constructor con el par clave->valor.
        TableEntry(std::string key, V value){
            this->key=key;
            this->value=value;
        }

        //#2 Crea una entrada solo con clave (sin valor). 
        TableEntry(std::string key){
            this->key=key;
        }

        //#3 Crea una entrada con la clave "" (cadena vacía) y sin valor.
        TableEntry(){
            this->key=" ";
            this->value=V();
        }

        //#4 Sobrecarga global del operador == para determinar que dos instancias de TableEntry son iguales solo si comparten l		a misma clave (con independencia del valor).
        friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2){
            return te1.key==te2.key;
        }

        //#5 Sobrecarga global del operador != para determinar que dos instancias de TableEntry son diferentes solo si sus clav		es son distintas (con independencia del valor).
        friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2){
            return te1.key!=te2.key;

        }

        //#6 Sobrecarga global del operador << para imprimir el contenido de la entrada (par clave->valor) por pantalla. Recuer		da incluir la cabecera <ostream> en el .h.
        friend std::ostream& operator<<(std::ostream &out, const TableEntry<V> &te){
            out << "clave: "<< te.key << "-> valor: " << te.value << endl;
            return out;
        }
        // modificacion para comparación por clave
        friend bool operator<(const TableEntry<V>& te1, const TableEntry<V>& te2) {
        return te1.key < te2.key;
        }

        friend bool operator>(const TableEntry<V>& te1, const TableEntry<V>& te2) {
        return te1.key > te2.key;
        }
};

#endif
