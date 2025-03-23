/**
** Universidad de La Laguna
** Escuela Superior de Ingenieria y Tecnologia
** Grado en Ingenieria Informatica
** Asignatura: Algoritmos y Estructuras de Datos Avanzadas
** Curso: 2º
** Practica 4: Búsqueda por dispersión
** Autor: Marco Pérez Padilla
** Correo: alu0101469348@ull.edu.es
** Fecha: 22/03/2025

** Archivo hashf.h: Declaracion e implementacion de la plantilla para
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      22/03/2025 - Creacion (primera version) del codigo
**/

#ifndef HASH_H
#define HASH_H

#include "dispersion.h"
#include "exploration.h"
#include "sequence.h"

/**
 * @brief HashTable class that
 * @param Key class to be interpreted as a Key for the hash table
 * @param Container static or dynamic in which the data will be allocated in
 */
template <class Key, class Container = StaticSequence<Key>> class HashTable {
 private:
  unsigned table_size_; // Size of the table
  Container** table_; // Array of arrays (pointer of pointers)
  DispersionFunction<Key>& fd_; // Dispersion function to be used
  ExplorationFunction<Key>& fe_; // Exploration function to be used
  unsigned block_size_; // Size of each block
 public:
  HashTable(unsigned, DispersionFunction<Key>&, ExplorationFunction<Key>&, unsigned);
  ~HashTable();
};


/**
 * @brief Constructor for the HashTable. Creates the table
 * @param unsigned maximum size of the table
 * @param DispersionFunction& to be used
 * @param ExplorationFunction& to be used
 * @param unsigned maximum size of each container
 */
template<class Key, class Container> HashTable<Key, Container>::HashTable(unsigned table_size, DispersionFunction<Key>& fd, ExplorationFunction<Key>& fe, unsigned block_size) : table_size_(table_size), fd_(fd), fe_(fe), block_size_(block_size) {
  // Assign the memory to the table
  table_ = new Container*[table_size_];
  // Create a container for each position
  for (unsigned i {0}; i < table_size_; ++i) {
    table_[i] = new Container<Key>(block_size_);
  }
  
}


/**
 * @brief Default destructor for HashTable class
 */
template<class Key, class Container> HashTable<Key, Container>::~HashTable() {
  for (unsigned i {0}; i < table_size_; ++i) {
    delete table_[i];
  }
  delete[] table_;
}


#endif