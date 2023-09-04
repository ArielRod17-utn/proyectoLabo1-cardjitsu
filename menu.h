#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#endif // MENU_H_INCLUDED

#include "rlutil.h"
#include <iostream>
using namespace std;
using namespace rlutil;

///declaracion de funciones
void MostrarMenuInicio();
string CargarJugador();
void MostrarReglas();
void MostrarCreditos();
void MostrarMenuRobarCartaDeMazo(int &ronda, string &usuario);
void MostrarMenuJugarCarta(string MazoElementos[], string MazoUsuario[] , string MazoCpu[] , bool MazoBoleano[], string &usuario, int &ronda);
void MostrarEstadisticas(int &TotalEstadistica,string &Ganador);
int salir();


