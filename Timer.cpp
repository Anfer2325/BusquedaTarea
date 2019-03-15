
#include "pch.h"
#include <iostream>
#include <ctime>
#include "Registro.h"
using namespace std;
int main()
{
//	cout << " Cantidad total de registro: " << cantidad_registros("datab.dat")<<endl;
	contador_tiempo timer;
	timer.iniciar();
	busquedaBinaria("datab.dat", 25011);
	timer.terminar();

	cout << "Tiempo de duracion: " << timer.duracion();
}


