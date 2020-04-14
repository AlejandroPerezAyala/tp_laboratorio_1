/*
 ============================================================================
 Name        : Calculadora2.c
 Author      : Alejandro Perez Ayala
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "Funciones2.h"
//#include <conio.h> windows



int main(void) {

	float numero1;
	float numero2;
	int seguir = 0;
	int seguir2 = 0;
	int flagnumero1 = 0;
	int flagnumero2 = 0;
	int flagcalculadora = 0;


	system("clear");
	do {
		//switch principal.
		switch(menu()) {
			case 1:
				flagnumero1 = 1;
				printf("ingresar el primer numero: ");
				scanf("%f", &numero1);
				break;
			case 2:
				flagnumero2 = 1;
				printf("ingresar segundo numero: ");
				scanf("%f", &numero2);
				break;
			case 3:
				if (flagnumero1 == 1 && flagnumero2 ==1) {
					flagcalculadora = 1;
					do {
						//subswitch para el menu de las operaciones.
						switch(calculadora(numero1, numero2)) {
							case 1:
								sumar(numero1, numero2);

								break;
							case 2:
								resta(numero1, numero2);

								break;
							case 3:
								multiplicacion(numero1, numero2);

								break;
							case 4:
								division(numero1, numero2);

								break;
							case 5:
								factorial(numero1);
								factorial(numero2);

								break;
							case 6:
								seguir2 = 1;

								break;
							default:
								//por si ingresa una opcion que no este incluida en el menu de operaciones.
								printf("ingrese una opcion valida!!\n\n");
								break;

						}
						__fpurge(stdin);//fflush(stdin) windows.
						getchar();//system("pause") windows.
					}while (seguir2 == 0);
				} else {
					//por si no ingresa un o los numeros a operar.
					printf("falta ingresar un numero...\n\n");
				}
				break;
			case 4:
				//valida si ya realizo las operaciones.
				if (flagcalculadora == 1){
					//reset de flags
					flagnumero1 = 0;
					flagnumero2 = 0;
					flagcalculadora = 0;
					//funcion que muestra los resultados de las operaciones.
					muestreo (numero1, numero2);
				} else {
					//por si elige la opcion sin haber hecho las operaciones.
					printf("necesita hacer las operaciones antes de ver los resultados\n\n");
				}
				break;
			case 5:
				seguir = 1;
				//muestra de agradecimiento.
				salir();
				break;
			default:
				//por si ingresa una opcion que no esta en el menu principal.
				printf("ingrese una opcion valida!!\n\n");
				break;
		}
		__fpurge(stdin);//fflush(stdin) windows.
		getchar();//system("pause") windows.
	} while (seguir == 0);


	return 0;
}
