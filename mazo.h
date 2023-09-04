#ifndef MAZO_H_INCLUDED
#define MAZO_H_INCLUDED


#include "rlutil.h"
#include <iostream>
#include <ctime>
using namespace std;
using namespace rlutil;

void repartirCartaDesafio(string  MazoDesafio[], string &CartaDesafioUsuario, string &CartaDesafioCpu);
void repartir3cartas( string MazoElementos[], string  MazoUsuario[], string MazoCpu[],bool Mazoboleano[]);
void RobarCartaDelMazo(string MazoElementos[], string MazoUsuario[] , string MazoCpu[] , bool MazoBoleano[] );
void VaciarMazosJugadores(string MazoUsuario[], string MazoCpu[], bool MazoBoleano[],int VecMismoNumeroUsuario[],int VecMismoNumeroCpu[]);



#endif // MAZO_H_INCLUDED
