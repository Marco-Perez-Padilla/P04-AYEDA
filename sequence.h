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

** Archivo sequence.h: Declaracion e implementacion de la plantilla para 
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      22/03/2025 - Creacion (primera version) del codigo
**      23/03/2025 - Creación de sub-clases dinamica y estatica
**/

#ifndef SEQUENCE_H
#define SEQUENCE_H


#include <list>
#include <algorithm> // find()


/**
 * @brief Abstract class that represents the kind of dispersion technics (open or close) we'll use.
 *        It has a virtual operator that will be the specialized functions in each sub-class 
 * @param Key class to be interpreted as a Key for the hashes
 */
template <class Key> class Sequence {
 public:
  virtual bool search(const Key&) const = 0;
  virtual bool insert(const Key&) = 0;
};
 

/**
 * @brief Sub-class that specializes the dynamic sequence in a hash table
 * @param Key class to be interpreted as a Key for the hashes
 */
template<class Key> class DynamicSequence : public Sequence<Key> {
 private:
  std::list<Key> values_;
 public:
  // Search and insert methods
  bool search(const Key&) const override;
  bool insert(const Key&) override;
};


/**
 * @brief Search method to search an element in the linked list with the data
 * @param Key type, element to be searched
 * @return true if the element has been found, false otherwise
 */
template<class Key> bool DynamicSequence<Key>::search(const Key& key) const {
  return std::find(values_.begin(), values_.end(), key) != values_.end();
}


/**
 * @brief Insert method to insert an element in the  linked list with the data
 * @param Key type, element to be inserted
 * @return true if the element can be inserted (if it wasn't previously on the sequence), false otherwise
 */
template<class Key> bool DynamicSequence<Key>::insert(const Key& key) {
  if (!search(key)) {
    values_.push_back(key);
    return true;
  } else {
    return false;
  }
}


/**
 * @brief Sub-class that specializes the static sequence in a hash table
 * @param Key class to be interpreted as a Key for the hashes
 */
template <class Key> class StaticSequence : public Sequence<Key> {
 private:
  Key* values_;
  unsigned block_size_;
  unsigned size_;
 public:
  // Constructor
  StaticSequence(unsigned block_size) : block_size_(block_size), size_(0) {
    values_ = new Key[block_size_];
  }
  // Destructor
  ~StaticSequence() {
    delete[] values_;
  }
  // Check full method
  virtual bool isFull() const {
    return size_ >= block_size_;
  }
  // Search and insert methods
  bool search(const Key&) const override;
  bool insert(const Key&) override;
};


/**
 * @brief Search method to search an element in the array with the data
 * @param Key type, element to be searched
 * @return true if the element has been found, false otherwise
 */
template<class Key> bool StaticSequence<Key>::search(const Key& key) const {
  return std::find(values_, values_ + size_, key) != values_ + size_;
}


/**
 * @brief Insert method to insert an element in the array with the data
 * @param Key type, element to be inserted
 * @return true if the element can be inserted (if it wasn't previously on the sequence nor the table is full), false otherwise
 */
template <class Key> bool StaticSequence<Key>::insert(const Key& key) {
  if (!isFull() && !search(key)) {
    values_[size_] = key;
    size_ += 1;
    return true;
  } else {
    return false;
  }
}


#endif