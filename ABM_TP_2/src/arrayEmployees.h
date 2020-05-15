/*
 * arrayEmployees.h
 *
 *  Created on: 10 may. 2020
 *      Author: alejandro
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

}Employee;

#endif /* ARRAYEMPLOYEES_H_ */

int initEmployee(Employee list[], int len);

int menu();

int listEmployee();

int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector);

int findEmpty(Employee list[], int tam);

int findEmployeeById(int id, Employee list[], int len);

int printEmployees(Employee list[], int len);

int printEmployee(Employee list);

int loadEmployee(Employee list[], int len, int id);

int removeEmployee(Employee list[], int len, int id);

int modifyEmployeeById(Employee list[], int len, int id);

int subMenu();

int newName(Employee list[], int len, int id);

int newLastName(Employee list[], int len, int id);

int newSector(Employee list[], int len, int id);

int newSalary(Employee list[], int len, int id);

int strlwrLinux(char cadena[]);

int sortEmployee(Employee list[], int len);

int showListEmployee(Employee list[], int len);

int contadorEmployee(Employee list[], int len);

float sumaSalary(Employee list[], int len);

int mostrarSalarios(Employee list[], int len);
