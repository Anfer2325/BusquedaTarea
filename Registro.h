#pragma once
#include <ctime>
#include "pch.h"
class contador_tiempo
{
private:
	double _duracion;
	clock_t reloj_inicio, reloj_final;
public:
	contador_tiempo() { _duracion = 0.0; }
	void iniciar() { _duracion = 0.0; reloj_inicio = clock(); }
	void terminar() { reloj_final = clock(); _duracion = (double)(reloj_final - reloj_inicio) / CLOCKS_PER_SEC; }
	double duracion() { return _duracion; }
	void resetear() { _duracion = 0.0; }
};

struct registro
{
	int id;
	char name[30];
	char lastname[30];
	char credit_card[25];
	char date[12];
	short int day;
	short int month;
	short int year;
	char payment_type[10];
	double total;
	char business_type[20];
	char business_name[50];
};

int cantidad_registros(const char *);

void imprimir_registros(int, int);

void busquedaBinaria(const char *,int );
void busquedaLineal(const char *, int);