#include "rlutil.h"
#include <iostream>
#include <locale.h>
#include "mazo.h"
#include <ctime>

using namespace std;
using namespace rlutil;
///funcion que reparte la carta desafio a los jugadores
void repartirCartaDesafio(string  MazoDesafio[], string &CartaDesafioUsuario, string &CartaDesafioCpu){
int azar;
bool banderaCpu=false;
bool banderaUsuario=false;


 while(banderaCpu==false){
azar=rand()%10;
if(banderaUsuario==false){
CartaDesafioUsuario=MazoDesafio[azar];
banderaUsuario=true;
  }else if(CartaDesafioUsuario!=MazoDesafio[azar]){
      CartaDesafioCpu=MazoDesafio[azar];
      banderaCpu=true;
   }
  }
 }
///funcion que reparte las 1ras 3 cartas a los jugadores x unica vez
 void repartir3cartas( string MazoElementos[], string  MazoUsuario[], string MazoCpu[], bool Mazoboleano[]){
 int azar, Cpu=0, x=0;

 while(Cpu!=3){
   azar= rand()%60;
   if(Mazoboleano[azar]==false){
        if(x<3){
   MazoUsuario[x]=MazoElementos[azar];
   Mazoboleano[azar]=true;

   x++;
        }else if(Cpu<3){
        MazoCpu[Cpu]=MazoElementos[azar];
        Mazoboleano[azar]=true;
        Cpu++;
         }
       }
      }
     }
///funcion que utilizamos para robar una carta del mazo de elementos
void RobarCartaDelMazo(string MazoElementos[], string MazoUsuario[] , string MazoCpu[] , bool MazoBoleano[]){
int azar;
for(int x=0;x<60;x++){
   azar= rand()%60;
   if(MazoBoleano[azar]==false){
        for(int y=0;y<60;y++){
   if(MazoUsuario[y]== "vacio"){
    MazoUsuario[y]=MazoElementos[azar];
    MazoBoleano[azar]=true;
    cout<<endl<<" CARTA ROBADA: "<<MazoUsuario[y]<<endl;

    x=y=60;
   }
   }
   }
}for(int x=0;x<60;x++){
   azar= rand()%60;
   if(MazoBoleano[azar]==false){
        for(int y=0;y<60;y++){
   if(MazoCpu[y]== "vacio"){
    MazoCpu[y]=MazoElementos[azar];
    MazoBoleano[azar]=true;
    x=y=60;
   }
        }
}
}
    system("PAUSE");
    system("CLS");
}

void VaciarMazosJugadores(string MazoUsuario[], string MazoCpu[], bool MazoBoleano[],int VecMismoNumeroUsuario[],int VecMismoNumeroCpu[]){

for(int x=0;x<60;x++){
    MazoUsuario[x]="vacio";
    MazoCpu[x]="vacio";
    MazoBoleano[x]=0;
}
for(int x=0;x<5;x++){
    VecMismoNumeroUsuario[x]=0;
    VecMismoNumeroCpu[x]=0;
}
}
