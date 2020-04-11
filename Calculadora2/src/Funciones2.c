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

int opcion;
int opcion2;
float resultado;



int calculadora(float num1, float num2) {

	system("clear");
	printf("El primer numero ingresado es: %.2f\n\n", num1);
	printf("El segundo numero ingresado es: %.2f\n\n", num2);

	printf(" _____________________________________________________________\n");
	printf("|                                                             |\n");
	printf("|----------------------CALCULADORA----------------------------|\n");
	printf("|_____________________________________________________________|\n\n");


	printf("[1]-**********************|Sumar|*******************************\n\n");
	printf("[2]-**********************|Restar|******************************\n\n");
	printf("[3]-********************|Multiplicar|****************************\n\n");
	printf("[4]-**********************|Dividir|******************************\n\n");
	printf("[5]-*********************|Factorial|******************************\n\n");
	printf("[6]-***********************|Salir|*******************************\n\n");
	printf("Escoge una opcion: ");
	scanf("%d", &opcion);


	return opcion;
}


int menu() {

	system("clear");
	printf(" _______________________________________________\n");
	printf("|                                               |\n");
	printf("|---------------MENU DE OPCIONES----------------|\n");
	printf("|_______________________________________________|\n\n");

	printf("1-*****************|Ingresar primer numero|******************\n\n");
	printf("2-*****************|Ingresar segundo numero|*****************\n\n");
	printf("3-*********************|Hacer calculos|***********************\n\n");
	printf("4-********************|Mostrar resultado|**********************\n\n");
	printf("5-**************************|Salir|******************************\n\n");
	printf("Escoge una opcion: ");
	scanf("%d", &opcion2);



	return opcion2;
}


float sumar (float num1, float num2) {

	resultado = num1 + num2;

	return resultado;
}

float resta (float num1, float num2) {

	resultado = num1 - num2;

	return resultado;
}

float multiplicacion (float num1, float num2) {

	resultado = num1 * num2;

	return resultado;
}

float division (float num1, float num2) {

	resultado = num1 / num2;

	return resultado;
}


float factorial(float numingresado) {

	float fact = 1;

	if (numingresado <= 0) {
		fact = 0;
	} else if (numingresado == 1) {
		fact = 1;
	} else {
		fact = numingresado * factorial(numingresado - 1);
	}

	return fact;
}


float muestreo(float num1, float num2){

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
