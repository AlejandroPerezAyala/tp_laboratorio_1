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

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return 0
 */
int initEmployee(Employee list[], int len);
/**
 * \brief incorpora un menu de opciones
 * \return  opcion escogida
 */
int menu();

/*
 * \brief es el switch principal de la App
 * return 0
 */
int listEmployee();

/*
 * \brief agrega los datos del empleado
 * \param list[] apunta al array de empelados
 * \param len es la cantidad de arrays
 * \param id numero asignado
 * \param name es le nombre del empleado
 * \param LastName es el apellido del empleado
 * \param salary es el sueldo del empleado
 * \param sector es el sector del empleado
 * \return todoOk 1 si se cargo el empleado correctamente
 */
int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector);

/*
 * \brief busca si hay lugares libre en el array de empleados
 * \param list[] apunta al array de empleados
 * \param len cantidad de arrays
 * \return indice vacio
 */

int findEmpty(Employee list[], int tam);

/*
 * \brief busca un empleado por ID
 * \param id ID para buscar al empleado
 * \param list[] apunta al array de empleados
 * \param len cantidad de arrays
 * \return indice del array donde esta ubicado el empelado
 */
int findEmployeeById(int id, Employee list[], int len);

/*
 * \brief imprime la lista de empleados en forma de columna
 * \param list[] apunta al array de empleados
 * \param len cantidad de arrays
 * \return 0
 */

int printEmployees(Employee list[], int len);

/*
 * \brief imprime un empleado
 * \param list[] apunta al array de empleados
 * \param len cantidad de arrays
 * \return 0
 */

int printEmployee(Employee list);

/*
 * \brief pide todos los datos del empleado
 * \param list[] apunta al array de empleados
 * \param len cantidad de arrays
 * \param id ID generado automaticamente
 * \return flagId devuelve un 1 si se cargo el empleado para autoincrementar el ID
 */

int loadEmployee(Employee list[], int len, int id);

/*
 * \brief borra de forma logica un empleado de la lista
 * \param list[] apunta al array de empleados
 * \param len cantidad de arrays
 * \param id ID del empleado que quiere borrar
 * \return 0
 */

int removeEmployee(Employee list[], int len, int id);

/*
 * \brief permite modificar los datos del empleado
 * \param list[] apunta al array de empleados
 * \param len cantidad de arrays
 * \param id ID del empleado que quiere modificar
 * \return 0
 */

int modifyEmployeeById(Employee list[], int len, int id);

/*
 * \brief incorpora un menu de modificaciones
 * \return 0
 */

int subMenu();

/*
 * \brief pide un nuevo nombre para midifcarlo
 * \param list[] apunta al array de empleados
 * \param len cantidad de arrays
 * \id ID del empleado
 * \return 0
 */

int newName(Employee list[], int len, int id);

/*
 * \brief pide un nuevo Apellido para midifcarlo
 * \param list[] apunta al array de empleados
 * \param len cantidad de arrays
 * \id ID del empleado
 * \return 0
 */

int newLastName(Employee list[], int len, int id);

/*
 * \brief pide un nuevo sector para midifcarlo
 * \param list[] apunta al array de empleados
 * \param len cantidad de arrays
 * \id ID del empleado
 * \return 0
 */

int newSector(Employee list[], int len, int id);

/*
 * \brief pide un nuevo salario para midifcarlo
 * \param list[] apunta al array de empleados
 * \param len cantidad de arrays
 * \id ID del empleado
 * \return 0
 */

int newSalary(Employee list[], int len, int id);

/*
 * \brief pasa un string a minuscula
 * \param cadena[] pide el string a modificar
 * \return 0
 */

int strlwrLinux(char cadena[]);

/*
 * \brief ordena la lista de empleados
 * \param list[] apunta al array de empleados
 * \param len cantidad de arrays
 * \return 0
 */

int sortEmployee(Employee list[], int len);

/*
 * \brief es el switch que permite hacer los muestreos de los informes
 * \param list[] apunta al array de empleados
 * \param len cantidad de arrays
 * \return 0
 */

int showListEmployee(Employee list[], int len);

/*
 * \brief cuenta la cantidad de empleados que se cargan
 * \param list[] apunta al array de empleados
 * \param len cantidad de arrays
 * \return cont la cantidad de empleados
 */

int contadorEmployee(Employee list[], int len);

/*
 * \brief suma los salarios de cada empleado ingresado
 * \param list[] apunta al array de empleados
 * \param len cantidad de arrays
 * \return sumaSalario la suma de los salarios
 */

float sumaSalary(Employee list[], int len);

/*
 * \brief muestra la suma, el promedio y la cantidad de empleados que superan el promedio
 * \param list[] apunta al array de empleados
 * \param len cantidad de arrays
 * \return 0
 */

int mostrarSalarios(Employee list[], int len);

/*
 * \brief incorpora un menu de muestreo de datos
 * \return 0
 */

int subMenu2();
