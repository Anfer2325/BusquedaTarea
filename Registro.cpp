#include "pch.h"
#include "Registro.h"
#include <fstream>
#include <iostream>
using namespace std;
int  cantidad_registros(const char * nombreArchivo)
{
	ifstream archivo(nombreArchivo,ios::in| ios::binary);

	if (!archivo)
	{
		cout << " Error de lectura en archivo: ";
		return -1;
	}
	//posicionar al final del archivo
	archivo.seekg(0, ios::end);

	unsigned int tamArchivo = archivo.tellg();
	archivo.close();
	return tamArchivo / sizeof registro;


}

void imprimir_registros(int codigoInferior, int codigoSuperior)
{

	if (codigoInferior > codigoSuperior)
		return;
	ifstream archivo("datab.dat", ios::in | ios::binary);

	if (!archivo)
	{
		cout << "Error al abrir archivo";
		return;
	}

	archivo.seekg(0, ios::beg);
	registro regis;
	archivo.read(reinterpret_cast<char *>(&regis), sizeof(registro));

	while (!archivo.eof())
	{
		if (regis.id >= codigoInferior && regis.id <= codigoSuperior)
			cout << "Registro: {" << " Code: " << regis.id << " Name: " << regis.name << " LastName: " << regis.lastname << " Date: " << regis.date<< " }\n";
		archivo.read(reinterpret_cast<char *>(&regis), sizeof(registro));
	}

	archivo.close();
}
void busquedaBinaria(const char * entrada,int id)
{
	int menor = 0;
	int mayor = cantidad_registros(entrada) - 1;

	while (menor <= mayor)
	{
		int intento = (mayor + menor) / 2;

		if (id < intento)
			mayor = intento - 1;

		else if (id > intento)
			menor = intento + 1;
		else
		{
			ifstream archivo("datab.dat", ios::in | ios::binary);
			archivo.seekg(intento * sizeof(registro), ios::beg);
			registro regis;
			archivo.read(reinterpret_cast<char *>(&regis), sizeof(registro));
			cout << "Registro: {" << " Code: " << regis.id << " Name: " << regis.name << " LastName: " << regis.lastname << " Date: " << regis.date << " }\n";
			archivo.close();
			return;
		}
		
			
	}

	return;

}

void busquedaLineal(const char * entrada, int id)
{
	int max = cantidad_registros(entrada);
	int it = 0;
	while (it < max)
	{
		ifstream archivo("datab.dat", ios::in | ios::binary);
		archivo.seekg(it * sizeof(registro), ios::beg);
		registro regis;
		archivo.read(reinterpret_cast<char *>(&regis), sizeof(registro));
		if (regis.id == id)
		{
			cout << "Registro: {" << " Code: " << regis.id << " Name: " << regis.name << " LastName: " << regis.lastname << " Date: " << regis.date << " }\n";

			archivo.close();
			return;
		}
		else 
		{
			it++;
		}
	}
}