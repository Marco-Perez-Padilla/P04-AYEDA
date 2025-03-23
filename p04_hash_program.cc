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

** Archivo p04_hash_program.cc: programa cliente.
**      Contiene la funcion main del proyecto que usa las templates para 
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      22/03/2025 - Creacion (primera version) del codigo
**/

#include <iostream>

#include "check_functions.h"
#include "nif.h"
#include "hash.h"
#include "dispersion.h"
#include "exploration.h"


int main(int argc, char* argv[]) {

  auto options = parse_args(argc,argv);

  if (!options.has_value()) {
    if (options.error() == parse_args_errors::unknown_option) {
      std::cerr << "fatal error: Unknown option" << std::endl;;
    }
    Usage();
    return EXIT_FAILURE;
  }

  if (options.value().show_help) {
    Help(); 
    return EXIT_SUCCESS;
  }

  const unsigned table_size = options.value().table_size;
  const unsigned block_size = options.value().block_size;
  const unsigned fd_option = options.value().dispersion_function;
  const unsigned fe_option = options.value().exploration_function;
  const unsigned close_option = options.value().open_close_hash;
  
  // Process Dispersion Function
  DispersionFunction<NIF>* fd = nullptr;
  if (fd_option == 0) {
    fd = new ModuleDispersion<NIF>(table_size);
  } else if (fd_option == 1) {
    fd = new SumDispersion<NIF>(table_size);
  } else if (fd_option == 2) {
    fd = new PseudoRandomDispersion<NIF>(table_size);
  }

  // If closed
  if (close_option == 0) {
    // Process Exploration Function
    ExplorationFunction<NIF>* fe = nullptr;
    if (fe_option == 0) {
      fe = new LinearExploration<NIF>();
    } else if (fe_option == 1) {
      fe = new QuadraticExploration<NIF>();
    } else if (fe_option == 2) {
      fe = new DoubleDispersionExploration<NIF>(*fd);
    } else if (fe_option == 3) {
      fe = new RedispersionExploration<NIF>(table_size);
    }
    HashTable<NIF, StaticSequence<NIF>> closed_table(table_size, *fd, *fe, block_size);

    closed_table.insert(NIF(12345678)); // Hash: 12345678 % 10 = 8
    closed_table.insert(NIF(87654321)); // Hash: 87654321 % 10 = 1
    closed_table.insert(NIF(13579246)); // Hash: 13579246 % 10 = 6
    

    // Buscar elementos
    std::cout << "Buscar 12345678: " << closed_table.search(NIF(12345678)) << "\n"; // true
    std::cout << "Buscar 11111111: " << closed_table.search(NIF(11111111)) << "\n"; // false

  } else { // If opened
    HashTable<NIF, DynamicSequence<NIF>> open_table(table_size, *fd);

    // Insertar elementos (colisiones en misma posición)
    open_table.insert(NIF(12345678)); // Hash: 8
    open_table.insert(NIF(12345688)); // Hash: 8 (colisión)
    open_table.insert(NIF(12345698)); // Hash: 8 (colisión)

    // Buscar elementos
    std::cout << "Buscar 12345688: " << open_table.search(NIF(12345688)) << "\n"; // true
    std::cout << "Buscar 99999999: " << open_table.search(NIF(99999999)) << "\n"; // false
  }

  return 0;
}