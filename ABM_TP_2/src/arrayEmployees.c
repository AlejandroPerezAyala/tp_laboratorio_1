/*
 * arrayEmployees.c
 *
 *  Created on: 10 may. 2020
 *      Author: alejandro
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "arrayEmployees.h"

#define TAM 2
#define TRUE 1
#define FALSE 0

int initEmployee(Employee list[], int len){

	for(int i = 0; i < len ; i ++){
		list[i].isEmpty = TRUE;
	}

	return 0;
}


int menu(){
	int opcion;

	system("clear");

		printf(" _______________________________________________\n");
		printf("|                                               |\n");
		printf("|-----------------BIENVENIDOS-------------------|\n");
		printf("|--------------LISTA DE EMPLEADOS---------------|\n");
		printf("|---------------MENU DE OPCIONES----------------|\n");
		printf("|_______________________________________________|\n\n");

		printf("[1]-********|Alta Empleado|********\n\n");
		printf("[2]-******|Modificar Empleado|*****\n\n");
		printf("[3]-********|Baja Empleado|********\n\n");
		printf("[4]-***********|Informar|**********\n\n");
		printf("[5]-************|Salir|************\n\n");
		printf("Escoge una opcion: ");
		scanf("%d", &opcion);



		return opcion;

}



int listEmployee(){
	Employee list[TAM];
	int salir = TRUE;
	int id;
	int proximoId = 1;
	int flag = 0;


	initEmployee(list, TAM);

	do{
		switch(menu()){

			case 1:
				if(loadEmployee(list, TAM, proximoId)){
					proximoId++;
					flag = 1;
					contadorEmployee(list, TAM);
					sumaSalary(list, TAM);
				}
				break;
			case 2:
				if(flag){
					printf("*********** modificar empleado **************\n\n");
					printf("ingrese ID: ");
					scanf("%d", &id);
					modifyEmployeeById(list, TAM, id);
				} else {
					printf("Debe cargar un empleado primero para modificar!\n\n");
				}
				break;
			case 3:
				if(flag){
					printf("********** borrar empleado ************\n\n");
					printf("ingrese ID: ");
					scanf("%d", &id);
					removeEmployee(list, TAM, id);
				} else {
					printf("Debe cargar un empleado para empezar a borrar!!\n\n");
				}
				break;
			case 4:
				if(flag){
					printf("informar\n\n");
					showListEmployee(list, TAM);

				} else {
					printf("no hay empleados que mostrar!!\n\n");
				}

				break;
			case 5:
				salir = FALSE;
				break;
		}
		__fpurge(stdin);
		getchar();
	} while (salir == TRUE);

	return 0;
}

int findEmpty(Employee list[], int len){
	int index = -1;
	for (int i = 0; i < len; i++){
		if (list[i].isEmpty == TRUE){
			index = i;
			break;
		}
	}
	return index;
}

int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector){
	int todoOk = 0;
	int index = findEmpty(list, len);
	Employee auxEmployee;

	if (index != -1){
		auxEmployee.id = id;
		strcpy(auxEmployee.name, name);
		strcpy(auxEmployee.lastName, lastName);
		auxEmployee.salary = salary;
		auxEmployee.sector = sector;
		auxEmployee.isEmpty = FALSE;

		list[index] = auxEmployee;

		todoOk = 1;
	}

	return todoOk;
}

int findEmployeeById(int id, Employee list[], int len){
	int index = -1;
	for (int i = 0; i < len; i++){
		if (list[i].id == id && list[i].isEmpty == FALSE){
			index = i;
			break;
		}
	}
	return index;
}

int printEmployee(Employee list){
	printf("%d    %11s    %11s   %5.2f   %2d\n\n", list.id, list.name, list.lastName, list.salary, list.sector);

	return 0;
}

int printEmployees(Employee list[], int len){
	printf("ID      NOMBRE       APELLIDO    SALARIO   SECTOR\n\n");
	for(int i = 0; i < len; i++){
		if(list[i].isEmpty == FALSE){
			printEmployee(list[i]);
		}
	}

	return 0;
}


int removeEmployee(Employee list[], int len, int id){
	int index = findEmployeeById(id, list, len);
	char confirm = 's';

	if (index == -1){
		printf("no hay empleados registrados con ese ID!\n\n");
	} else {
		printEmployee(list[index]);

		printf("confirma la baja del empleado?: ");
		__fpurge(stdin);
		scanf("%c", &confirm);

		if(confirm == 's'){
			list[index].isEmpty = TRUE;
			printf("La baja se realizo con exito!\n\n");
		} else {
			printf("Operacion cancelada!\n\n");
		}
	}


	return 0;
}

int loadEmployee(Employee list[], int len, int id){
	int flagId = 0;
	int sector;
	char nombre[51];
	char apellido[51];
	float salario;
	int index;

	index = findEmpty(list, len);
	if(index != -1){

		printf("ingrese el nombre: ");
		__fpurge(stdin);
		fgets(nombre, 51, stdin);
		for(int i = 0;nombre[i] != '\0'; i++){
			if (nombre[i] == '\n'){
				nombre[i] = '\0';
			}
		}

		strlwrLinux(nombre);
		nombre[0] = toupper(nombre[0]);

		printf("ingrese el apellido: ");
		__fpurge(stdin);
		fgets(apellido, 51, stdin);
		for(int i = 0; apellido[i] != '\0'; i++){
			if(apellido[i] == '\n'){
				apellido[i] = '\0';
			}
		}

		strlwrLinux(apellido);
		apellido[0] = toupper(apellido[0]);

		printf("ingese el salario: ");
		scanf("%f", &salario);

		printf("ingrese el sector: ");
		scanf("%d", &sector);

		if (addEmployee(list, len, id, nombre, apellido, salario, sector)){
			flagId = 1;
		}


	} else {
		printf("system Complete!\n\n");
	}



	return flagId;
}

int modifyEmployeeById(Employee list[], int len, int id){

	int index = findEmployeeById(id, list, len);
	int salir = TRUE;


	if(index == -1){
		printf("no hay ningun empleado con ese ID!!!\n\n");
	} else {

		do{
			system("clear");
			printEmployee(list[index]);

			switch(subMenu()){
				case 1:
					newName(list, len, id);
					break;
				case 2:
					newLastName(list, len, id);
					break;
				case 3:
					newSalary(list, len, id);
					break;
				case 4:
					newSector(list, len, id);
					break;
				case 5:
					salir = FALSE;
					break;
		}

	__fpurge(stdin);
	getchar();
	} while (salir == TRUE);

	}

	return 0;
}


int subMenu(){
	int opcion;




	printf(" _______________________________________________\n");
	printf("|                                               |\n");
	printf("|--------------LISTA DE EMPLEADOS---------------|\n");
	printf("|------------MENU DE MODIFICACIONES-------------|\n");
	printf("|_______________________________________________|\n\n");

	printf("[1]-*******|Modificar Nombre|******\n\n");
	printf("[2]-******|Modificar Apellido|*****\n\n");
	printf("[3]-*******|Modificar Sueldo|******\n\n");
	printf("[4]-*******|Modificar Sector|******\n\n");
	printf("[5]-************|Salir|************\n\n");
	printf("Escoge una opcion: ");
	scanf("%d", &opcion);



	return opcion;

}

int newName(Employee list[], int len, int id){
	int index = findEmployeeById(id, list, len);
	char nuevoNombre[51];
	char confirm = 's';

	printf("Ingrese el nuevo nombre: ");
	__fpurge(stdin);
	fgets(nuevoNombre, 51, stdin);
	for(int i = 0; nuevoNombre[i] != '\0'; i ++){
		if(nuevoNombre[i] == '\n'){
			nuevoNombre[i] = '\0';
		}
	}

	strlwrLinux(nuevoNombre);
	nuevoNombre[0] = toupper(nuevoNombre[0]);

	printf("confirma el cambio de nombre? ");
	__fpurge(stdin);
	scanf("%c", &confirm);

	if(confirm == 's'){
		strcpy(list[index].name, nuevoNombre);
		printf("Se realizo el cambio con exito!!!\n\n");
	} else {
		printf("Operacion cancelada!!\n\n");
	}


	return 0;
}

int newLastName(Employee list[], int len, int id){

	int index = findEmployeeById(id, list, len);
	char nuevoApellido[51];
	char confirm = 's';

	printf("Ingrese el nuevo Apellido: ");
	__fpurge(stdin);
	fgets(nuevoApellido, 51, stdin);
	for(int i = 0; nuevoApellido[i] != '\0'; i ++){
		if(nuevoApellido[i] == '\n'){
			nuevoApellido[i] = '\0';
		}
	}

	strlwrLinux(nuevoApellido);
	nuevoApellido[0] = toupper(nuevoApellido[0]);

	printf("confirma el cambio de Apellido? ");
	__fpurge(stdin);
	scanf("%c", &confirm);

	if(confirm == 's'){
		strcpy(list[index].lastName, nuevoApellido);
		printf("Se realizo el cambio con exito!!!\n\n");
	} else {
		printf("Operacion cancelada!!\n\n");
	}


	return 0;
}

int newSalary(Employee list[], int len, int id){
	int index = findEmployeeById(id, list, len);
	float nuevoSalario;
	char confirm = 's';

	printf("Ingrese el nuevo Salario: ");
	scanf("%f", &nuevoSalario);

	printf("confirma el cambio de Salario? ");
	__fpurge(stdin);
	scanf("%c", &confirm);

	if(confirm == 's'){
		list[index].salary = nuevoSalario;
		printf("Se realizo el cambio con exito!!!\n\n");
	} else {
		printf("Operacion cancelada!!\n\n");
	}


		return 0;

}

int newSector(Employee list[], int len, int id){

	int index = findEmployeeById(id, list, len);
	int nuevoSector;
	char confirm = 's';

	printf("Ingrese el nuevo Sector: ");
	scanf("%d", &nuevoSector);

	printf("confirma el cambio de Sector? ");
	__fpurge(stdin);
	scanf("%c", &confirm);

	if(confirm == 's'){
		list[index].sector = nuevoSector;
		printf("Se realizo el cambio con exito!!!\n\n");
	} else {
		printf("Operacion cancelada!!\n\n");
	}


	return 0;

}

int strlwrLinux(char cadena[]){

	int i = 0;

	while (cadena[i] != '\0'){
		cadena [i] = tolower(cadena[i]);
		i++;
	}

	return 0;
}

int subMenu2(){
	int opcion;

		system("clear");


		printf("                _______________________________________________\n");
		printf("               |                                               |\n");
		printf("               |-------------------INFORMES--------------------|\n");
		printf("               |_______________________________________________|\n\n");

		printf("[1]-**********************|Lista por apellido y sector|****************************\n\n");
		printf("[2]-******|Total, promedio de sueldos y cuantos empleados superan el promedio|*****\n\n");
		printf("[3]-********************************|Salir|****************************************\n\n");
		printf("Escoge una opcion: ");
		scanf("%d", &opcion);



		return opcion;

}


int showListEmployee(Employee list[], int len){
	int salir = TRUE;

	do{
		switch (subMenu2()){
			case 1:
				sortEmployee(list, len);
				printEmployees(list, len);
				break;
			case 2:
				mostrarSalarios(list, len);
				break;
			case 3:
				salir = FALSE;
				break;
		}
		__fpurge(stdin);
		getchar();
	} while (salir == TRUE);
	return 0;
}

int sortEmployee(Employee list[], int len){
	Employee auxLastName;
	Employee auxSector;

	for(int i = 0; i < len - 1; i ++){
		for(int j = 0; j < len; j ++){
			if (strcmp(list[i].lastName, list[j].lastName) > 0 ){
				auxLastName = list[i];
				list[i] = list[j];
				list[j] = auxLastName;

				if(strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector < list[j].sector){
					auxSector = list[i];
					list[i] = list[j];
					list[j] = auxSector;
				}

			}
		}
	}

	return 0;
}

int contadorEmployee(Employee list[], int len){

	int cont = 0;

	for(int i = 0; i < len; i++){
		if(list[i].isEmpty == FALSE){
			cont++;
		}
	}
	return cont;
}

float sumaSalary(Employee list[], int len){

	float sumaSalario = 0;

	for(int i = 0; i < len; i++){
		if (list[i].isEmpty == FALSE){
			sumaSalario += list[i].salary;
		}
	}
	return sumaSalario;
}

float promedioSalario(Employee list[], int len){

	float promedio;

	promedio = sumaSalary(list, len) / contadorEmployee(list, len);

	return promedio;

}

int mostrarSalarios(Employee list[], int len){

	int flag = 0;

	printf("la suma de los salarios es: %5.2f\n\n", sumaSalary(list, len));
	printf("el promedio de los salarios es: %5.2f\n\n", promedioSalario(list, len));

	for(int i = 0; i < len; i++){
		if (list[i].salary > promedioSalario(list, len) && list[i].isEmpty == FALSE){
			printEmployee(list[i]);
			flag = 1;
		}
	}

	if(flag == 0){
		printf("no hay empleados que superen el promedio de sueldo\n\n");
	}

	return 0;
}


