//============================================================================
// Name        : ProgPrincipal.cpp
// Author      : Profesores de la asignatura EDI
// Version     : curso 24/25
// Copyright   :
// Description : programa principal alquiler Patinetes
//============================================================================


#include <iostream>
#include "sistema.h"
using namespace std;


int menu(string nombreSistema) {
	int opcion;
	do {
		cout << endl<<endl;
		cout << " -------- " << nombreSistema << " --------" << endl <<endl;
		cout << " 1. Mostrar todos los usuarios          " << endl;
		cout << " 2. Buscar y mostrar un usuario         " << endl;
		cout << " 3. Mostrar todos patinetes             " << endl;
		cout << " 4. Mostrar estaciones con sus patinetes" << endl;
		cout << " 5. Buscar y mostrar una estación       " << endl;
		cout << " 6. Reparar patinetes estación          " << endl;
		cout << " 7. Alquilar/devolver                   " << endl;
		cout << " 8. Estación con mayor nº de patines alquilados" << endl;
		cout << " 9. Buscar patinetes extraviados        " << endl;

		cout << " 0. Finalizar. " << endl;
		cout << " Opción: ";
		cout<<"_";
		cin>>opcion;
		cin.ignore();
		cout<<endl;

	} while ((opcion < 0) || (opcion > 10));
	return opcion;
}


int main() {
	// TODO Crear un objeto dinámico de la clase Sistema
	//los datos se cargan automáticamente.
	// TODO no olvidar hacer new
	bool salir = false;
	int opcion;
	string nombreSistema;

	while (!salir) {

		opcion = menu(nombreSistema);
		switch (opcion) {
		case 1:

			break;
		case 2:
			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;
		case 7:

			break;
		case 8:

			break;
		case 9:

			break;
		case 0:
			salir = true;
			break;
		default:
			break;
		}
	}

	// TODO no olvidar el delete al puntero
	return 0;
}


