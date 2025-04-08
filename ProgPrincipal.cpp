//============================================================================
// Name        : ProgPrincipal.cpp
// Author      : Profesores de la asignatura EDI
// Version     : curso 24/25
// Copyright   :
// Description : programa principal alquiler Patinetes
//============================================================================


#include <iostream>
#include "sistema.h"
#include "pruebas/PruebaSistema.h"//Sólo para pruebas
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
    pruebasSistema();//Sólo para pruebas
    std::cout << "Nombre del sistema: ";
    string nombreSistema;
    cin >> nombreSistema;
    Sistema* S = new Sistema(nombreSistema);
	//los datos se cargan automáticamente.
	bool salir = false;
	int opcion;

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
            S->alquilarDevolverPatinetes();
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
    
    delete S;
	return 0;
}


