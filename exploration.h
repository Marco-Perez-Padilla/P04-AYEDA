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

** Archivo exploration.h: Declaracion e implementacion de la plantilla para 
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      22/03/2025 - Creacion (primera version) del codigo
**/

#ifndef EXPLORATION_H
#define EXPLORATION_H


#include "dispersion.h"

/**
 * @brief Abstract class that represents the exploration functions we'll use for the hash table.
 *        It has a virtual operator that will be the specialized functions in each sub-class 
 * @param Key class to be interpreted as a Key for the hashes
 */
template <class Key> class ExplorationFunction {
 public:
  virtual unsigned operator() (const Key&, unsigned) const = 0;
};


/**
 * @brief Sub-class that specializes the linear exploration function
 * @param Key class to be interpreted as a Key for the hashes
 */
template <class Key> class LinearExploration : public ExplorationFunction<Key> {
 public:
  unsigned operator()(const Key& key, unsigned i) const override {
    return i;
  }
};


/**
 * @brief Sub-class that specializes the quadratic exploration function
 * @param Key class to be interpreted as a Key for the hashes
 */
template <class Key> class QuadraticExploration : public ExplorationFunction<Key> {
 public:
  unsigned operator()(const Key& key, unsigned i) const override {
    return i * i;
  }
};


/**
 * @brief Sub-class that specializes the double dispersion exploration function
 * @param Key class to be interpreted as a Key for the hashes
 */
template <class Key> class DoubleDispersionExploration : public ExplorationFunction<Key> {
 private:
  DispersionFunction<Key>& function_;
 public:
  DoubleDispersion(DispersionFunction<Key>& function) : function_(function) {}
  unsigned operator()(const Key& key, unsigned i) const override {
    return function_(key) * i;
  }
};



/**
 * @brief Sub-class that specializes the linear exploration function
 * @param Key class to be interpreted as a Key for the hashes
 */
template <class Key> class LinearExploration : public ExplorationFunction<Key> {
 public:
  unsigned operator()(const Key& key, unsigned i) const override {
    return i;
  }
};


#endif