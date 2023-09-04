#ifndef ACCION_H_INCLUDED
#define ACCION_H_INCLUDED
#include <iostream>
#include <locale.h>
#include <ctime>
#include <windows.h>
#include "menu.h"
#include "rlutil.h"

using namespace std;
using namespace rlutil;

void EvaluarCombinacionGanadora(string MazoUsuario[], string MazoCpu[],string  MazoElementos[],int VecRojo[],int  VecAmarillo[],int  VecVerde[],int VecAzul[],bool &CombGanadoraUsuario,bool &CombGanadoraCpu);

void EvaluarCartasDesafio(string MazoDesafio[], string MazoUsuario[] , string MazoCpu[] ,string  &CartaDesafioUsuario,string  &CartaDesafioCpu,string &CartaUsuario,string &CartaCpu,string MazoElementos[] ,bool MazoBoleano[], int MazoNumerico[],bool &HitoCartaDesafioUsuario,bool &HitoCartaDesafioCpu,bool &GanaUsuario,bool &GanaCpu, int VecRojo[], int VecAmarillo[],int VecVerde[], int VecAzul[],int &contRojoUsuario,int &contAmarilloUsuario, int &contVerdeUsuario, int &contAzulUsuario, bool &MismoElementoUsuario, bool &MismoElementoCpu, int VecMismoNumeroUsuario[], int VecMismoNumeroCpu[], int &ContDosCartasUsuario, int &ContDosCartasCpu, int &contRojoCpu, int &contAmarilloCpu, int &contVerdeCpu, int &contAzulCpu);

void EvaluarHitos(bool &HitoCartaDesafioUsuario, bool &HitoCartaDesafioCpu, bool &CombGanadoraUsuario, bool &CombGanadoraCpu, bool &HitosUsuario, bool &HitosCpu);

void QuienGano(bool &HitoCartaDesafioUsuario,bool &HitoCartaDesafioCpu,bool &CombGanadoraUsuario,bool &CombGanadoraCpu,bool &HitosUsuario,bool &HitosCpu,int PdvUsuario[],int PdvCpu[],string &usuario,string &Ganador,int &TotalUsuario,int &TotalCpu,int &TotalEstadistica);

#endif // ACCION_H_INCLUDED
