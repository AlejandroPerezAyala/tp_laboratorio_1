/*
 * Funciones2.h
 *
 *  Created on: 11 abr. 2020
 *      Author: Alejandro Perez Ayala
 */

#ifndef FUNCIONES2_H_
#define FUNCIONES2_H_

/**
 * @brief: incorpora un menu de calculos.
 * @param: num1 es el primer numero ingresado.
 * @param: num2 es el segundo numero ingresado.
 * @return: retorna la opcion escogida.
 */
int calculadora(float num1, float num2);


/**
 * @brief: incorpora un menu de opciones.
 * @return: retorna la opcion escogida
 */
int menu();

/**
 * @brief: suma dos numeros flotantes.
 * @param: num1 es primer numero ingresado.
 * @param: num2 es el segundo numero ingresado.
 * @return: retorna el resultado de la suma.
 */
float sumar(float num1, float num2);

/**
 * @brief: resta dos numeros flotantes.
 * @param: num1 es primer numero ingresado.
 * @param: num2 es el segundo numero ingresado.
 * @return: retorna el resultado de la resta.
 */
float resta(float num1, float num2);

/**
 * @brief: suma dos numeros flotantes.
 * @param: num1 es primer numero ingresado.
 * @param: num2 es el segundo numero ingresado.
 * @return: retorna el resultado de la suma.
 */
float multiplicacion(float num1, float num2);

/**
 * @brief: suma dos numeros flotantes.
 * @param: num1 es primer numero ingresado.
 * @param: num2 es el segundo numero ingresado.
 * @return: retorna el resultado de la suma.
 */
float division(float num1, float num2);

/**
* @brief: realiza el muestreo de los resultados obtenidos en cada funcion.
* @param: num1 es el primer numero ingresado.
* @param: num2 es el primer numero ingresado.
*/
float muestreo(float num1, float num2);

/**
 * @brief: realiza el factotial de un numero flotante.
 * @param: num1 es el numero ingresa.
 * @return: retorna el factorial del numero ingresado.
 */
float factorial(float numingresado);

/**
 * @brief: incorpora unas palabras al salir del programa.
 */
int salir();


#endif /* FUNCIONES2_H_ */
