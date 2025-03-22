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

#include "check_functions.h"


/**
 * @brief Validates the extension of the input file
 * @param string  
 * @return bool-type. True if the file is accepted. False otherwise
 */
bool ValidateFile (const std::string& name) {
  if (name.find('.') == std::string::npos) {
    return false;  
  }
  std::regex pattern (R"((.*)\.(txt)$)");
  return std::regex_match(name, pattern);
}

/**
 * @brief Uses ValidateFile function. Acts in consequence of the returned type
 * @param string  
 */
void CheckFileError (const std::string& name) {
  if (ValidateFile(name)) return;
  std::cerr << "Error in input file: Wrong extension. Please, try \"./p03_big_calculator --help\" for further information" << std::endl;
  exit(EXIT_FAILURE);
}



/**
 * @brief Validates the line of commands and uses Help, Usage and CheckFileError functions
 * @param int argc  
 * @param char* argv[]
 */
void ValidateCommand(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "--help") {
    Help();
    exit(EXIT_SUCCESS);
  } else if (argc != 3) {
    Usage();
    exit(EXIT_FAILURE);
  } else {
    CheckFileError(std::string(argv[1]));
    CheckFileError(std::string(argv[2]));
  }
  
}


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
