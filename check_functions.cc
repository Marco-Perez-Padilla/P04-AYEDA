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

** Archivo check_functions.cc: Implementación de las funciones de chequeo de parámetros.
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      22/03/2025 - Creacion (primera version) del codigo
**/

#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <expected>
#include <string_view>
#include <vector>
#include <limits>

#include "check_functions.h"


/**
 * @brief Checks if a given string is made out of (only) numbers or not
 * @param string
 * @return bool
 */
bool ValidateNumber (const std::string& line) {
  if (!line.empty()) {
    for (char chr : line) {
      if (!std::isdigit(chr)) {
        return false;
      }
    }
    return true;
  } else {
    return false;
  }
}


/**
 * @brief Prints Help to the user
 */
void Help () {
    std::cout << "./p03_big_calculator -- Calculator that works in bases 2, 8, 10 and 16 with unsigned, integers and rationals\n"
              << "Usage:                ./p03_big_calculator filein.txt fileout.txt\n"
              << "\n"
              << "filein.txt:      Input file, with extension .txt and format:\n"
              << "                       First line specifying the base, such as: 'Base = X' in where X is the wanted base (2, 8, 10 or 16)\n"
              << "                       For each of the following lines, They must start with a label, followed by '=' OR '?':\n"
              << "                            - ?: Indicates that the following will be an expression to be evaluated\n"
              << "                            - =: Indicates that the following is the value of an operand. There are three posibilities for such:\n"
              << "                                - Unsigned: Unsigned number, according to the specified base. After the number, it must end with 'u'. Example: 10u\n"
              << "                                - Integer: Integer number, according to the specified base. After the number, it must end with 'u'. Example: -10i\n"
              << "                                - Rational: Rational number, according to the specified base. Format 'numerator/denominator'. After the number, it must end with 'r'. Ex: 10/-3r\n"
              << "fileout.txt:     Output file with the results of the analysis\n"
              << "\n";
}


/**
 * @brief Prints how to use the program
 */
void Usage() {
  std::cout << "How to use: ./p03_big_calculator\n"
            << "Try './p03_big_calculator --help' for further information\n";
}


/**
 * @brief Function that processes the arguments given through command line
 * @param argc
 * @param argv
 * @return Program options struct with all the options if no error has occured. Enum parse args error otherwise with the specified error
 */
std::expected<program_options, parse_args_errors> parse_args(int argc, char* argv[]) {
  bool table_size = false;
  bool dispersion_function = false;
  bool open_hash = false;
  bool block_size = false;
  bool exploration_function = false;

  std::vector<std::string_view> args(argv + 1, argv + argc);
  program_options options;

  for (auto it = args.begin(), end = args.end(); it != end; ++it) {
    if (*it == "-h" || *it == "--help") {
      options.show_help = true;
    } else if (*it == "-ts") {
      table_size = true;
      continue;
    } else if (*it == "-fd") {
      dispersion_function = true;
      continue;
    } else if (*it == "-hash") {
      open_hash = true;
      continue;
    } else if (*it == "-bs") {
      block_size = true;
      continue;
    } else if (*it == "-fe") {
      exploration_function = true;
      continue;
    } else if (table_size == true) {
      table_size = false;
      if (ValidateNumber(std::string(*it))) {
        options.table_size = std::stoi(std::string(*it));
      } else {
        return std::unexpected(parse_args_errors::table_size_error);
      }
    } else if (dispersion_function == true) {
      dispersion_function = false;
      if (ValidateNumber(std::string(*it))) {
        int disp_func = std::stoi(std::string(*it));
        if (disp_func < 0 || disp_func > 2) {
          return std::unexpected(parse_args_errors::dispersion_function_error);
        } else {
          options.dispersion_function = disp_func;
        }
      } else {
        return std::unexpected(parse_args_errors::dispersion_function_error);
      }
    } else if (exploration_function == true) {
      exploration_function = false;
      if (ValidateNumber(std::string(*it))) {
        int expl_func = std::stoi(std::string(*it));
        if (expl_func < 0 || expl_func > 3) {
          return std::unexpected(parse_args_errors::exploration_function_error);
        } else {
          options.exploration_function = expl_func;
        }
      } else {
        return std::unexpected(parse_args_errors::exploration_function_error);
      }
    } else if (open_hash == true) {
      open_hash = false;
      if (std::string(*it) == "open") {
        options.open_close_hash = 1;
      } else if (std::string(*it) == "close"){
        options.open_close_hash = 0;
      } else {
        return std::unexpected(parse_args_errors::hash_error);
      }
    } else if (block_size == true) {
      if (ValidateNumber(std::string(*it))) {
        options.block_size = std::stoi(std::string(*it));
      } else {
        return std::unexpected(parse_args_errors::block_size_error);
      }
    } else {
      return std::unexpected(parse_args_errors::unknown_option); 
    }
  }

  return options; 
}


/**
 * @brief function that waits for the user to press any key
 */
void pressanykey() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
  std::cin.get(); 
}


/**
 * @brief function to clear the standard ouput
 */
void clrscr() {
  system("clear");
}


/**
* @brief Start menu to choose an option of the following
* @param char option to be used
*/
void menu (char &opcion) {
 std::cout << "c. [c]argar grafo desde fichero" << std::endl;     
 std::cout << "a. Mostrar la lista de [a]dyacencia del grafo" << std::endl;
 std::cout << "m. Realizar un recorrido de a[m]plitud del grafo desde un nodo por sucesores" << std::endl;
 std::cout << "r. Realizar un [r]ecorrido de profundidad del grafo desde un nodo por sucesores" << std::endl;          
 std::cout << "q. Finalizar el programa" << std::endl;
 std::cout << "Introduce la letra de la accion a ejecutar  > ";
 std::cin >> opcion;
};