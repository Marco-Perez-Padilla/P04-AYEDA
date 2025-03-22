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


bool ValidateFile (const std::string& name);
void CheckFileError (const std::string& name);
void ValidateCommand(int argc, char* argv[]);
bool ValidateNumber (const std::string& line);
void Help ();
void Usage();