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

** Archivo check_functions.h: Declaracion de las funciones de chequeo de parámetros.
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      22/03/2025 - Creacion (primera version) del codigo
**/

#include <iostream>
#include <string>
#include <expected>


constexpr std::size_t max_path_size = 4096;

enum class parse_args_errors {
 table_size_error,
 dispersion_function_error,
 exploration_function_error,
 hash_error,
 block_size_error,
 unknown_option,
};

struct program_options {
 bool show_help = false;
 int table_size = 1000; // table size 1000 as default
 int dispersion_function = 0; // Module function as default
 int exploration_function = 0; // Linear function as default
 int open_close_hash = 0; // close hash (static sequence) as default
 int block_size = 1; // block size 1 as default
};
 
bool ValidateFile (const std::string& name);
void CheckFileError (const std::string& name);
void ValidateCommand(int argc, char* argv[]);
bool ValidateNumber (const std::string& line);
void Help ();
void Usage();
std::expected<program_options, parse_args_errors> parse_args(int argc, char* argv[]);
