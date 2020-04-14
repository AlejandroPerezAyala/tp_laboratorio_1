/*
 * Funciones2.c
 *
 *  Created on: 11 abr. 2020
 *      Author: Alejandro Perez Ayala
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "Funciones2.h"
//#include <conio.h> windows

//menu de operaciones.
int calculadora(float num1, float num2) {

	int opcion;

	//system("cls") windows.
	system("clear");

	printf("El primer numero ingresado es: %.2f\n\n", num1);
	printf("El segundo numero ingresado es: %.2f\n\n", num2);

	printf(" ____________________________________\n");
	printf("|                                    |\n");
	printf("|-------------OPERACIONES------------|\n");
	printf("|____________________________________|\n\n");


	printf("[1]-***********|Sumar|**************\n\n");
	printf("[2]-***********|Restar|*************\n\n");
	printf("[3]-*********|Multiplicar|**********\n\n");
	printf("[4]-***********|Dividir|************\n\n");
	printf("[5]-**********|Factorial|***********\n\n");
	printf("[6]-************|Salir|*************\n\n");
	printf("Escoge una opcion: ");
	scanf("%d", &opcion);

	__fpurge(stdin);

	return opcion;
}

// menu Principal
int menu() {

	int opcion;

	//system("cls") windows.
	system("clear");

	printf(" _______________________________________________\n");
	printf("|                                               |\n");
	printf("|-----------------BIENVENIDOS-------------------|\n");
	printf("|-----------------CALCULADORA-------------------|\n");
	printf("|---------------MENU DE OPCIONES----------------|\n");
	printf("|_______________________________________________|\n\n");

	printf("[1]-***********|Ingresar 1º numero|*************\n\n");//windows º = \247
	printf("[2]-***********|Ingresar 2º numero|*************\n\n");//windows º = \247
	printf("[3]-**************|Hacer calculos|**************\n\n");
	printf("[4]-*************|Mostrar resultado|************\n\n");
	printf("[5]-******************|Salir|*******************\n\n");
	printf("Escoge una opcion: ");
	scanf("%d", &opcion);



	return opcion;
}


float sumar (float num1, float num2) {

	float resultado;

	resultado = num1 + num2;

	return resultado;
}

float resta (float num1, float num2) {

	float resultado;

	resultado = num1 - num2;

	return resultado;
}

float multiplicacion (float num1, float num2) {

	float resultado;

	resultado = num1 * num2;

	return resultado;
}

float division (float num1, float num2) {

	float resultado;

	resultado = num1 / num2;

	return resultado;
}


float factorial(float numingresado) {

	float fact = 1;


	if (numingresado == 1) {
		fact = 1;
	} else {
		fact = numingresado * factorial(numingresado - 1);
	}

	return fact;
}


float muestreo(float num1, float num2){

	//system("cls") windows.
	system("clear");

	printf(" _______________________________________________\n");
	printf("|                                               |\n");
	printf("|------------------RESULTADOS-------------------|\n");
	printf("|_______________________________________________|\n\n");

	printf("El resultado de %.2f + %.2f es: %.2f\n\n",num1, num2, sumar(num1, num2));
	printf("El resultado de %.2f - %.2f es: %.2f\n\n",num1, num2, resta(num1, num2));
	printf("El resultado de %.2f x %.2f es: %.2f\n\n",num1, num2,  multiplicacion(num1, num2));
	if(num2 != 0){
		printf("El resultado de %.2f / %.2f es: %.2f\n\n",num1, num2, division(num1, num2));
	} else {
		printf("no se puede dividir por 0\n\n");
	}

	printf("El factorial de %.2f es: %.2f\n\n", num1, factorial(num1));
	printf("el factorial de %.2f es: %.2f\n\n", num2, factorial(num2));


	return 0;
}

int salir(){

	//system("cls") windows.
	system("clear");

	printf(" ________________________________________________\n");
	printf("|                                                |\n");
	printf("|-----Muchas gracias por probar mi programa------|\n");
	printf("|--------------------Saludos!--------------------|\n");
	printf("|--------------By:Alejandro Perez Ayala----------|\n");
	printf("|________________________________________________|\n\n");

	return 0;
}
