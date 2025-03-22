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

** Archivo exceptions.h: Declaracion de la clase que maneja los errores 
**
** Referencias:
**      Enlaces de interes

** Historial de revisiones:
**      22/03/2025 - Creacion (primera version) del codigo
**/

#ifndef BIG_NUMBER_EXCEPTION_H
#define BIG_NUMBER_EXCEPTION_H

#include <exception>
#include <string>


/**
 * @brief Class BigNumberException that heritages from std:exception, it has a protected member which is the message to be thrown if an error occurs
 */
class Exceptions : public std::exception {
 protected:
  std::string error_message_;
 public:
  explicit Exceptions (const std::string& error_message) : error_message_(error_message) {}
  const char* what() const throw() {return error_message_.c_str();}
};


/**
 * @brief Class NifStringException. Throws an exception if there is an invalid digit
 */
class NifStringException : public Exceptions {
 public:
  NifStringException() : Exceptions("Error: NIF size is different than 8") {}
};


/**
 * @brief Class NifLongException. Throws an exception if there is an invalid digit
 */
class NifLongException : public Exceptions {
 public:
  NifLongException() : Exceptions("Error: NIF cannot be negative nor superior than 99999999") {}
};


#endif