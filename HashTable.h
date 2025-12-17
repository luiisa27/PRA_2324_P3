#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include <string>

#include "Dict.h"
#include "TableEntry.h"
#include "../PRA_2324_P1/ListLinked.h"

template <typename V>
class HashTable: public Dict<V> {

    private:
        // Número de elementos almacenados actualmente en la tabla hash.
        int n;

        //tamaño de la tabla hash (número total de cubetas).
        int max;

        //Tabla de cubetas, representada por un array de punteros a listas enlazadas (tipo ListLinked<T>) que almacenan pares clave→valor (tipo TableEntry<V>).
        ListLinked<TableEntry<V>>* table;

        //Función hash que devuelve la posición (cubeta) en la tabla hash de key.  Se calculará como el resto de la divisón entre la suma de los valores ASCII numéricos de los caracteres de la clave y el tamaño de la tabla hash 
        int h(std::string key) const {
            int sumaAsciiClave = 0;
            for (size_t i = 0; i < key.size(); i++) {
                sumaAsciiClave += int(key.at(i));
            }
            return sumaAsciiClave % max;
        }

    public:
        //Método constructor. Reservará memoria dinámica para crear una tabla table de tamaño size, e inicializará los atributos n y max de la clase.
        HashTable(int size){
            max = size;
            n = 0;
            table = new ListLinked<TableEntry<V>>[max];
        }

        //Método destructor. Se encargará de liberar la memoria dinámica reservada al crear la tabla table.
        ~HashTable(){
            delete[] table;
        }

        //Devuelve el número total de cubetas de la tabla.
        int capacity(){
            return max;
        }

        //Sobrecarga global del operador << para imprimir el contenido de la tabla hash por pantalla. Recuerda incluir la cabecera <ostream> en el .h.
        friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th){
            for(int i = 0; i < th.max; i++){
                out << "Cubeta " << i << ": ";
                out << th.table[i] << "\n"; // se usa el operador << de ListLinked (comentario añadido)
            }
            return out;
        }

        //Sobrecarga del operador []. Devuelve el valor correspondiente a key. Si no existe, lanza la excepción std::runtime_error.
        V operator[](std::string key){
            return search(key);
        }

        // IMPLEMENTACIÓN DE LOS MÉTODOS PÚBLICOS HEREDADOS DE LA INTERFAZ Dict<V>
        virtual void insert(std::string key, V value) override{
            int pos = h(key);

            TableEntry<V> entry(key, value);

            // comprobar si la clave ya existe en la lista de esa cubeta
            if(table[pos].search(entry) != -1){
                throw std::runtime_error("La clave ya existe en el diccionario");
            }

            // si no existe, insertar nueva entrada
            table[pos].append(entry);
            n++;
        }

        virtual V search(std::string key) override{
            int pos = h(key);
            TableEntry<V> dummy(key, V());

            int idx = table[pos].search(dummy);
            if(idx == -1){
                throw std::runtime_error("Clave no encontrada en el diccionario");
            }

            return table[pos].get(idx).value;
        }

        virtual V remove(std::string key) override{
            int pos = h(key);
            TableEntry<V> dummy(key, V());

            int idx = table[pos].search(dummy);
            if(idx == -1){
                throw std::runtime_error("El par key->value no se encuentra en el diccionario");
            }

            V val = table[pos].get(idx).value;
            table[pos].remove(idx);
            n--;
            return val;
        }

        virtual int entries() override{
            return n; // número de elementos almacenados actualmente
        }
};

#endif

