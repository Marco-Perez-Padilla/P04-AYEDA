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
 * @brief
 * @param
 * @param
 */
template <class Key, class Container = StaticSequence<Key>> class HashTable {
 private:
  unsigned table_size_;
  Container* table_;
  DispersionFunction<Key>& fd_;
  ExplorationFunction<Key>& fe_;
  unsigned block_size_;
 public:
};

#endif