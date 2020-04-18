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
#include <time.h>
#include <unistd.h>

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

	printf("[1]-*********|Ingresar 1º numero|***********\n\n");//windows º = \247
	printf("[2]-*********|Ingresar 2º numero|***********\n\n");//windows º = \247
	printf("[3]-************|Hacer calculos|************\n\n");
	printf("[4]-***********|Mostrar resultado|**********\n\n");
	printf("[5]-****************|Salir|*****************\n\n");
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


	if (numingresado == 1 || numingresado == 0) {
		fact = 1;
	} else {
		fact = numingresado * factorial(numingresado - 1);
	}

	return fact;
}

int muestreo(float num1, float num2){

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
		printf("No se puede dividir por 0\n\n");
	}

	if (num1 >= 0){
		printf("El factorial de %.2f es: %.2f\n\n", num1, factorial(num1));
	} else {
		printf("No se puede realizar el factorial de un numero negativo\n\n");
	}

	if(num2 >= 0){
		printf("El factorial de %.2f es: %.2f\n\n", num2, factorial(num2));
	} else {
		printf("No se puede realizar el factorial de un numero negativo\n\n");
	}


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

int animacioncase3(float num1, float num2) {

	printf(" _______________________________\n");
	printf("|-------[A]=%.2f [B]=%.2f-------|\n", num1, num2);
	sleep(2);
	printf("|-------Realizando Suma---------|\n");
	sleep(2);
	printf("|-------Realizando Resta--------|\n");
	sleep(2);
	printf("|---Realizando Multiplicacion---|\n");
	sleep(2);
	printf("|------Realizando Division------|\n");
	sleep(2);
	printf("|----Realizando Factoriales-----|\n");
	sleep(2);
	printf("|------Resultados Listos!!------|\n");
	printf("|_______________________________|\n\n");


	return 0;
}
