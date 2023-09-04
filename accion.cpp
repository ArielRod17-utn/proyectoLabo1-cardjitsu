#include <iostream>
#include <locale.h>
#include <ctime>
#include <windows.h>
#include "menu.h"
#include "rlutil.h"
#include "accion.h"

using namespace std;
using namespace rlutil;

void EvaluarCombinacionGanadora(string MazoUsuario[], string MazoCpu[],string  MazoElementos[],int VecRojo[],int  VecAmarillo[],int  VecVerde[],int VecAzul[],bool &CombGanadoraUsuario,bool &CombGanadoraCpu){
///evaluamos 3 cartas del mismo elemento usuario
int x, y, contFuego=0, contNieve=0,contAgua=0;
int cFuego=0, cNieve=0,cAgua=0;
while(CombGanadoraUsuario!=true){
for(x=0;x<60;x++){
    for(y=0;y<60;y++){
        if(MazoUsuario[x]==MazoElementos[y]){
            if(y<20){
                contFuego++;
            }else if(y>19 && y<40){
            contNieve++;
            }else {  contAgua++;}
        }
     }
   }

 if(contFuego>2 || contNieve>2 || contAgua>2){
    CombGanadoraUsuario=true;
   // cout<<endl<<" CUMPLISTE CON LA COMBINACION GANADORA "<<endl;///borrar al finalizar juego
    system ("CLS");
 }
}
  ///evaluamos 3 cartas del mismo elemento Cpu
while(CombGanadoraCpu!=true){
for(x=0;x<60;x++){
    for(y=0;y<60;y++){
        if(MazoCpu[x]==MazoElementos[y]){
            if(y<20){
                cFuego++;
            }else if(y>19 && y<40){
            cNieve++;
            }else {  cAgua++;}
        }
     }
   }

 if(cFuego>2 || cNieve>2 || cAgua>2){
    CombGanadoraCpu=true;
  ///  cout<<endl<< " CPU CUMPLIÓ CON LA COMBINACION GANADORA "<<endl;///borrar al finalizar juego
    system ("PAUSE");
    system ("CLS");
 }
}

 ///Evaluar 3 cartas de distinto elemento y color
 int a,b;
 bool VecFuegoUsuario[4]={}, VecNieveUsuario[4]={},VecAguaUsuario[4]={};
 bool VecFuegoCpu[4]={}, VecNieveCpu[4]={}, VecAguaCpu[4]={};
 ///analizamos el mazo del usuario

 for(x=0;x<60;x++){
 for(y=0;y<60;y++){

 if(MazoUsuario[x]==MazoElementos[y]){
   if(y<20){
    for(a=0;a<15;a++){
        if(VecRojo[a]==y){
            VecFuegoUsuario[0]=true;
        }
        if(VecAmarillo[a]==y){
            VecFuegoUsuario[1]=true;
        }
        if(VecVerde[a]==y){
            VecFuegoUsuario[2]=true;
        }
        if(VecAzul[a]==y){
            VecFuegoUsuario[3]=true;
        }
      }
    }
    else if(y>19 && y<40){

         for(a=0;a<15;a++){
        if(VecRojo[a]==y){
            VecNieveUsuario[0]=true;
        }
        if(VecAmarillo[a]==y){
            VecNieveUsuario[1]=true;
        }
        if(VecVerde[a]==y){
            VecNieveUsuario[2]=true;
        }
        if(VecAzul[a]==y){
            VecNieveUsuario[3]=true;
        }
        }
    }
    else{
        for(a=0;a<15;a++){
        if(VecRojo[a]==y){
            VecAguaUsuario[0]=true;
        }
        if(VecAmarillo[a]==y){
            VecAguaUsuario[1]=true;
        }
        if(VecVerde[a]==y){
            VecAguaUsuario[2]=true;
        }
        if(VecAzul[a]==y){
            VecAguaUsuario[3]=true;
        }
       }
      }
     }
    }
   }
///analisis final mazo usuario
bool flag1=false,flag2=false,flag3=false;
int fuego, nieve, agua;
while(CombGanadoraUsuario!=true){
for(x=0;x<4;x++){
    if(VecFuegoUsuario[x]==true){
        flag1=true;
        fuego=x;
    }
    for(b=0;b<4;b++){
        if(VecNieveUsuario[b]==true){
            flag2=true;
            nieve=b;
        }
        for(y=0;y<4;y++){
            if(VecAguaUsuario[y]==true){
                flag3=true;
                agua=y;
            }
            if(flag1==true && flag2==true && flag3==true){
                    if(fuego!=nieve && fuego!=agua && nieve!=agua){
                CombGanadoraUsuario=true;
             //  cout<<endl<< " CUMPLISTE OBJETIVO 3 CARTAS DISTINTO ELEMENTO Y COLOR "<<endl;///borra al finalizar el juego
                x=b=y=4;
                system("pause");
                system("CLS");

            }
        }
    }
  }
}
}

///analizamos el mazo de la Cpu
for(x=0;x<60;x++){
 for(y=0;y<60;y++){

 if(MazoCpu[x]==MazoElementos[y]){
   if(y<20){
    for(a=0;a<15;a++){
        if(VecRojo[a]==y){
            VecFuegoCpu[0]=true;
        }
        if(VecAmarillo[a]==y){
            VecFuegoCpu[1]=true;
        }
        if(VecVerde[a]==y){
            VecFuegoCpu[2]=true;
        }
        if(VecAzul[a]==y){
            VecFuegoCpu[3]=true;
        }
      }
    }
    else if(y>19 && y<40){

         for(a=0;a<15;a++){
        if(VecRojo[a]==y){
            VecNieveCpu[0]=true;
        }
        if(VecAmarillo[a]==y){
            VecNieveCpu[1]=true;
        }
        if(VecVerde[a]==y){
            VecNieveCpu[2]=true;
        }
        if(VecAzul[a]==y){
            VecNieveCpu[3]=true;
        }
        }
    }
    else{
        for(a=0;a<15;a++){
        if(VecRojo[a]==y){
            VecAguaCpu[0]=true;
        }
        if(VecAmarillo[a]==y){
            VecAguaCpu[1]=true;
        }
        if(VecVerde[a]==y){
            VecAguaCpu[2]=true;
        }
        if(VecAzul[a]==y){
            VecAguaCpu[3]=true;
        }
       }
      }
     }
    }
   }
///analisis final mazo Cpu
bool flagCpu1=false, flagCpu2=false,flagCpu3=false;
int fuegoCpu, nieveCpu, aguaCpu;
while(CombGanadoraCpu!=true){
for(x=0;x<4;x++){
    if(VecFuegoCpu[x]==true){
        flagCpu1=true;
        fuegoCpu=x;
    }
    for(b=0;b<4;b++){
        if(VecNieveCpu[b]==true){
            flagCpu2=true;
            nieveCpu=b;
        }
        for(y=0;y<4;y++){
            if(VecAguaCpu[y]==true){
                flagCpu3=true;
                aguaCpu=y;
            }
            if(flagCpu1==true && flagCpu2==true && flagCpu3==true){
                    if(fuegoCpu!=nieveCpu && fuegoCpu!=aguaCpu && nieveCpu!=aguaCpu){
                CombGanadoraCpu=true;
            ///    cout<<endl<< " CPU CUMPLIÓ OBJETIVO 3 CARTAS DISTINTO ELEMENTO Y COLOR "<<endl;///borrar al finalizar el juego
                x=b=y=4;
                system("pause");
                system("CLS");
                }
            }
        }
    }
  }
 }
}
///---------------------------------------------------------------------------------///

void EvaluarCartasDesafio(string MazoDesafio[], string MazoUsuario[] , string MazoCpu[] ,string  &CartaDesafioUsuario,string  &CartaDesafioCpu,string &CartaUsuario,string &CartaCpu,string MazoElementos[] ,bool MazoBoleano[], int MazoNumerico[],bool &HitoCartaDesafioUsuario,bool &HitoCartaDesafioCpu,bool &GanaUsuario,bool &GanaCpu, int VecRojo[], int VecAmarillo[], int VecVerde[], int VecAzul[],  int &contRojoUsuario,int &contAmarilloUsuario, int &contVerdeUsuario, int &contAzulUsuario, bool &MismoElementoUsuario, bool &MismoElementoCpu,int VecMismoNumeroUsuario[], int VecMismoNumeroCpu[], int &ContDosCartasUsuario,int &ContDosCartasCpu, int &contRojoCpu, int &contAmarilloCpu, int &contVerdeCpu, int &contAzulCpu){
int x,y,z,a,b,c,d,e,f,g,h,i, referencia, numero, refCpu, numeroCpu;
if(GanaUsuario==true){
  if(CartaDesafioUsuario==MazoDesafio[0]){
        for(x=0;x<60;x++){
            if(MazoElementos[x]==CartaCpu){
                if(x>19 && x<40){
                    HitoCartaDesafioUsuario=true;
                    cout<<endl;
                    setColor(LIGHTCYAN);
                    cout<< " GANAR CARTA DE NIEVE: ¡¡ OBJETIVO CUMPLIDO!!"<<endl;
                    setColor(WHITE);
                     system("PAUSE");
                     system ("CLS");
                }
            }
        }
    }else if(CartaDesafioUsuario==MazoDesafio[1]){
      for(y=0;y<60;y++){
        if(MazoElementos[y]==CartaCpu){
            if(y<20){
                HitoCartaDesafioUsuario=true;
               cout<<endl;
                setColor(RED);
                    cout<< " GANAR CARTA DE FUEGO: ¡¡ OBJETIVO CUMPLIDO!!"<<endl;
                  setColor(WHITE);
                     system("PAUSE");
                     system ("CLS");
            }
        }
      }
    }else if(CartaDesafioUsuario==MazoDesafio[2]){
      for(z=0;z<60;z++){
        if(MazoElementos[z]==CartaCpu){
            if(z>39){
                HitoCartaDesafioUsuario=true;
                cout<<endl;
                setColor(LIGHTCYAN);
                    cout<< " GANAR CARTA DE AGUA: ¡¡ OBJETIVO CUMPLIDO!!"<<endl;
                    setColor(WHITE);
                     system("PAUSE");
                     system ("CLS");
            }
        }
      }
    }else if(CartaDesafioUsuario==MazoDesafio[3]){
        for(a=0;a<60;a++){
            if(MazoElementos[a]==CartaCpu){
                for(b=0;b<15;b++){
                    if(VecRojo[b]==a){
                        contRojoUsuario++;
                    }
                }
            }
        }
        if(contRojoUsuario>1){
            HitoCartaDesafioUsuario=true;
            cout<<endl;
            setColor(RED);
            cout<< " GANAR DOS CARTAS ROJAS: ¡¡ OBJETIVO CUMPLIDO!!"<<endl;
            setColor(WHITE);
                     system("PAUSE");
                     system ("CLS");
        }

    }else if(CartaDesafioUsuario==MazoDesafio[4]){
        for(c=0;c<60;c++){
            if(MazoElementos[c]==CartaCpu){
                for(d=0;d<15;d++){
                    if(VecAmarillo[d]==c){
                        contAmarilloUsuario++;
                    }
                }
            }
        }
        if(contAmarilloUsuario>1){
            HitoCartaDesafioUsuario=true;
            cout<<endl;
            setColor(YELLOW);
            cout<< " GANAR DOS CARTAS AMARILLAS: ¡¡ OBJETIVO CUMPLIDO!!"<<endl;
            setColor(WHITE);
                     system("PAUSE");
                     system ("CLS");
        }
    }else if(CartaDesafioUsuario==MazoDesafio[5]){
        for(f=0;f<60;f++){
            if(MazoElementos[f]==CartaCpu){
                for(e=0;e<15;e++){
                    if(VecVerde[e]==f){
                        contVerdeUsuario++;
                    }
                }
            }
        }
        if(contVerdeUsuario>1){
            HitoCartaDesafioUsuario=true;
            cout<<endl;
            setColor(LIGHTGREEN);
            cout<< " GANAR DOS CARTAS VERDES: ¡¡ OBJETIVO CUMPLIDO!!"<<endl;
            setColor(WHITE);
                     system("PAUSE");
                     system ("CLS");
        }
    }else if(CartaDesafioUsuario==MazoDesafio[6]){
        for(g=0;g<60;g++){
            if(MazoElementos[g]==CartaCpu){
                for(h=0;h<15;h++){
                    if(VecAzul[h]==g){
                        contAzulUsuario++;
                    }
                }
            }
        }
        if(contAzulUsuario>1){
            HitoCartaDesafioUsuario=true;
            cout<<endl;
            setColor(LIGHTCYAN);
            cout<< " GANAR DOS CARTAS AZULES: ¡¡ OBJETIVO CUMPLIDO!!"<<endl;
            setColor(WHITE);
                     system("PAUSE");
                     system ("CLS");
        }
    }else if(CartaDesafioUsuario==MazoDesafio[7]){
    if(MismoElementoUsuario==true){
        HitoCartaDesafioUsuario=true;
        cout<<endl;
        setColor(LIGHTBLUE);
        cout<< " GANAR UNA CARTA DEL MISMO ELEMENTO QUE EL ADVERSARIO: ¡¡OBJETIVO CUMPLIDO!!"<<endl;
        setColor(WHITE);
        system("PAUSE");
        system("CLS");
    }
    }else if(CartaDesafioUsuario==MazoDesafio[8]){
        for(h=0;h<60;h++){
            if(MazoElementos[h]==CartaCpu){
                referencia=h;
            }
        }
         numero=MazoNumerico[referencia];
         if(numero==1){
            VecMismoNumeroUsuario[0]+=1;
         }else if(numero==2){
         VecMismoNumeroUsuario[1]+=1;
         }else if(numero==3){
         VecMismoNumeroUsuario[2]+=1;
         }else if(numero==4){
         VecMismoNumeroUsuario[3]+=1;
         }else if(numero==5){
         VecMismoNumeroUsuario[4]+=1;
         }
        for(i=0;i<5;i++){
           if(VecMismoNumeroUsuario[i]>1){
            HitoCartaDesafioUsuario=true;
            cout<<endl;
            setColor(LIGHTMAGENTA);
            cout<< " GANAR DOS CARTAS CON EL MISMO NUMERO: ¡¡OBJETIVO CUMPLIDO!!"<<endl;
            setColor(WHITE);
            system("PAUSE");
            system("CLS");
           }
        }



    }else if(CartaDesafioUsuario==MazoDesafio[9]){
            ContDosCartasUsuario++;
    }if(ContDosCartasCpu!=0){
    ContDosCartasUsuario=0;
    }
        if(ContDosCartasUsuario>1){
            HitoCartaDesafioUsuario=true;
            cout<<endl;
            setColor(LIGHTGREEN);
             cout<< " GANAR DOS MANOS CONSECUTIVAS: ¡¡OBJETIVO CUMPLIDO!!"<<endl;
             setColor(WHITE);
             system("PAUSE");
             system("CLS");
        }
     }

///-------------------------------------------------------------------------------------------///
     if(GanaCpu==true){
  if(CartaDesafioCpu==MazoDesafio[0]){
        for(x=0;x<60;x++){
            if(MazoElementos[x]==CartaUsuario){
                if(x>19 && x<40){
                    HitoCartaDesafioCpu=true;
                   /// cout<<endl<< " GANAR CARTA DE NIEVE: ¡¡ OBJETIVO CPU CUMPLIDO!!"<<endl;
                     system("PAUSE");
                     system ("CLS");
                }
            }
        }
    }else if(CartaDesafioCpu==MazoDesafio[1]){
      for(y=0;y<60;y++){
        if(MazoElementos[y]==CartaUsuario){
            if(y<20){
                HitoCartaDesafioCpu=true;
                   /// cout<<endl<< " GANAR CARTA DE FUEGO: ¡¡ OBJETIVO CPU CUMPLIDO!!"<<endl;
                     system("PAUSE");
                     system ("CLS");
            }
        }
      }
    }else if(CartaDesafioCpu==MazoDesafio[2]){
      for(z=0;z<60;z++){
        if(MazoElementos[z]==CartaUsuario){
            if(z>39){
                HitoCartaDesafioCpu=true;
                ///    cout<<endl<< " GANAR CARTA DE AGUA: ¡¡ OBJETIVO CPU CUMPLIDO!!"<<endl;
                     system("PAUSE");
                     system ("CLS");
            }
        }
      }
    }else if(CartaDesafioCpu==MazoDesafio[3]){
        for(a=0;a<60;a++){
            if(MazoElementos[a]==CartaUsuario){
                for(b=0;b<15;b++){
                    if(VecRojo[b]==a){
                        contRojoCpu++;
                    }
                }
            }
        }
        if(contRojoCpu>1){
            HitoCartaDesafioCpu=true;
         ///   cout<<endl<< " GANAR DOS CARTAS ROJAS: ¡¡ OBJETIVO CPU CUMPLIDO!!"<<endl;
                     system("PAUSE");
                     system ("CLS");
        }

    }else if(CartaDesafioCpu==MazoDesafio[4]){
        for(c=0;c<60;c++){
            if(MazoElementos[c]==CartaUsuario){
                for(d=0;d<15;d++){
                    if(VecAmarillo[d]==c){
                        contAmarilloCpu++;
                    }
                }
            }
        }
        if(contAmarilloCpu>1){
            HitoCartaDesafioCpu=true;
          ///  cout<<endl<< " GANAR DOS CARTAS AMARILLAS: ¡¡ OBJETIVO CPU CUMPLIDO!!"<<endl;
                     system("PAUSE");
                     system ("CLS");
        }
    }else if(CartaDesafioCpu==MazoDesafio[5]){
        for(f=0;f<60;f++){
            if(MazoElementos[f]==CartaUsuario){
                for(e=0;e<15;e++){
                    if(VecVerde[e]==f){
                        contVerdeCpu++;
                    }
                }
            }
        }
        if(contVerdeCpu>1){
            HitoCartaDesafioCpu=true;
          ///  cout<<endl<< " GANAR DOS CARTAS VERDES: ¡¡ OBJETIVO CPU CUMPLIDO!!"<<endl;
                     system("PAUSE");
                     system ("CLS");
        }
    }else if(CartaDesafioCpu==MazoDesafio[6]){
        for(g=0;g<60;g++){
            if(MazoElementos[g]==CartaUsuario){
                for(h=0;h<15;h++){
                    if(VecAzul[h]==g){
                        contAzulCpu++;
                    }
                }
            }
        }
        if(contAzulCpu>1){
            HitoCartaDesafioCpu=true;
          ///  cout<<endl<< " GANAR DOS CARTAS AZULES: ¡¡ OBJETIVO CPU CUMPLIDO!!"<<endl;
                     system("PAUSE");
                     system ("CLS");
        }
    }else if(CartaDesafioCpu==MazoDesafio[7]){
    if(MismoElementoCpu==true){
        HitoCartaDesafioCpu=true;
      ///  cout<<endl<< " GANAR UNA CARTA DEL MISMO ELEMENTO QUE EL ADVERSARIO: ¡¡OBJETIVO CPU CUMPLIDO!!"<<endl;
        system("PAUSE");
        system("CLS");
    }
    }else if(CartaDesafioCpu==MazoDesafio[8]){
        for(h=0;h<60;h++){
            if(MazoElementos[h]==CartaUsuario){
                refCpu=h;
            }
        }
         numeroCpu=MazoNumerico[refCpu];
         if(numeroCpu==1){
            VecMismoNumeroCpu[0]+=1;
         }else if(numeroCpu==2){
         VecMismoNumeroCpu[1]+=1;
         }else if(numeroCpu==3){
         VecMismoNumeroCpu[2]+=1;
         }else if(numeroCpu==4){
         VecMismoNumeroCpu[3]+=1;
         }else if(numeroCpu==5){
         VecMismoNumeroCpu[4]+=1;
         }
        for(i=0;i<5;i++){
           if(VecMismoNumeroCpu[i]>1){
            HitoCartaDesafioCpu=true;
           /// cout<<endl<< " GANAR DOS CARTAS CON EL MISMO NUMERO: ¡¡OBJETIVO CPU CUMPLIDO!!"<<endl;
            system("PAUSE");
            system("CLS");
           }
        }



    }else if(CartaDesafioCpu==MazoDesafio[9]){
            ContDosCartasCpu++;
    }if(ContDosCartasUsuario!=0){
    ContDosCartasCpu=0;
    }
        if(ContDosCartasCpu>1){
            HitoCartaDesafioCpu=true;
           ///  cout<<endl<< " GANAR DOS MANOS CONSECUTIVAS: ¡¡OBJETIVO CPU CUMPLIDO!!"<<endl;
             system("PAUSE");
             system("CLS");
        }
     }

}

///------------------------------------------------------------------------------------------///

void EvaluarHitos(bool &HitoCartaDesafioUsuario, bool &HitoCartaDesafioCpu, bool &CombGanadoraUsuario, bool &CombGanadoraCpu, bool &HitosUsuario, bool &HitosCpu){
if(HitoCartaDesafioUsuario==true && CombGanadoraUsuario==true){
    HitosUsuario=true;
}
if(HitoCartaDesafioCpu==true && CombGanadoraCpu==true){
    HitosCpu=true;
}
}
///--------------------------------------------------------------------------------------------///

void QuienGano(bool &HitoCartaDesafioUsuario,bool &HitoCartaDesafioCpu,bool &CombGanadoraUsuario,bool &CombGanadoraCpu,bool &HitosUsuario,bool &HitosCpu,int PdvUsuario[],int PdvCpu[],string &usuario,string &Ganador,int &TotalUsuario,int &TotalCpu,int &TotalEstadistica){
 if(CombGanadoraUsuario==true){
    if(PdvCpu[1]==0){
        PdvCpu[1]-=1;
    }
 }
 if(CombGanadoraCpu==true){
    if(PdvUsuario[1]==0){
        PdvUsuario[1]-=1;
    }
 }
 if(HitoCartaDesafioUsuario==true){
    if(PdvCpu[2]==0){
        PdvCpu[2]-=1;
    }
 }
 if(HitoCartaDesafioCpu==true){
    if(PdvUsuario[2]==0){
        PdvUsuario[2]-=1;
    }
 }
 ///DEFINIMOS QUIEN GANÓ

 if(HitosUsuario==true){
    PdvUsuario[0]+=3;
 }else if(HitosCpu==true){
    PdvCpu[0]+=3;
 }else if(HitosUsuario==true && HitosCpu==true){
    PdvUsuario[0]+=3;///EN CASO QUE GANEN AL MISMO TIEMPO(dificil), LE OTORGO LA VICTORIA AL HUMANO, POR QUE TENGO GANAS.
 }

 if(HitosUsuario==true){


    cout<<endl;
    cout<< "                 FELICIDADES"<<" "<<usuario<<" "<< " USTED A SIDO EL VENCEDÓR!!! "<<endl<<endl;
    cout<< " PUNTOS REALIZADOS "<<endl;
    cout<< "-------------------------------------------------------------------------------------------------"<<endl;
    cout<< " GANADOR DE LA PARTIDA                                                              "<<PdvUsuario[0]<<"  PDV"<<endl;
    cout<< " COMBINACIÓN ELEMENTOS CUMPLIDO POR CONTRARIO                                       "<<PdvUsuario[1]<<"  PDV"<<endl;
    cout<< " CARTA DESAFÍO CUMPLIDO POR CONTRARIO                                               "<<PdvUsuario[2]<<"  PDV"<<endl;
    cout<< " RONDAS GANADAS AL ADVERSARIO                                                       "<<PdvUsuario[3]<<"  PDV"<<endl;
    cout<< " POR CADA RONDA GANADA EN EL JUEGO CON UN ELEMENTO IGUAL AL DEL ADVERSARIO          "<<PdvUsuario[4]<<"  PDV"<<endl;
    cout<< "-------------------------------------------------------------------------------------------------"<<endl;
    // SUMAMOS EL PUNTAJE TOTAL DEL USUARIO
    for(int x=0;x<5;x++){
        TotalUsuario+=PdvUsuario[x];
    }
    cout<< " TOTAL          =================================================>                    "<<TotalUsuario<<" PDV"<<endl<<endl;

    // MOSTRAMOS EL PUNTAJE DE LA CPU
    cout<< " PUNTOS REALIZADOS CPU"<<endl;
    cout<< "-------------------------------------------------------------------------------------------------"<<endl;
    cout<< " GANADOR DE LA PARTIDA                                                              "<<PdvCpu[0]<<"  PDV"<<endl;
    cout<< " COMBINACIÓN ELEMENTOS CUMPLIDO POR CONTRARIO                                       "<<PdvCpu[1]<<"  PDV"<<endl;
    cout<< " CARTA DESAFÍO CUMPLIDO POR CONTRARIO                                               "<<PdvCpu[2]<<"  PDV"<<endl;
    cout<< " RONDAS GANADAS AL ADVERSARIO                                                       "<<PdvCpu[3]<<"  PDV"<<endl;
    cout<< " POR CADA RONDA GANADA EN EL JUEGO CON UN ELEMENTO IGUAL AL DEL ADVERSARIO          "<<PdvCpu[4]<<"  PDV"<<endl;
    cout<< "-------------------------------------------------------------------------------------------------"<<endl;
     for(int x=0;x<5;x++){
        TotalCpu+=PdvCpu[x];
    }
    cout<< " TOTAL         ====================================================>                "<<TotalCpu<<" PDV"<<endl<<endl;

    if(TotalUsuario>TotalEstadistica){
        TotalEstadistica=TotalUsuario;
        Ganador=usuario;
    }
    system("PAUSE");
    system("CLS");

    ///RECETEAMOS LOS PUNTOS DE VICTORIA
    for(int x=0;x<5;x++){
        PdvUsuario[x]=0;
        PdvCpu[x]=0;
    }

 }
 else if (HitosCpu==true){

    cout<<endl;
    cout<< "                 LO SIENTO, LA CPU A SIDO EL VENCEDOR!!! "<<endl<<endl;
    cout<< " PUNTOS REALIZADOS "<<endl;
    cout<< "-------------------------------------------------------------------------------------------------"<<endl;
    cout<< " GANADOR DE LA PARTIDA                                                              "<<PdvCpu[0]<<"  PDV"<<endl;
    cout<< " COMBINACIÓN ELEMENTOS CUMPLIDO POR CONTRARIO                                       "<<PdvCpu[1]<<"  PDV"<<endl;
    cout<< " CARTA DESAFÍO CUMPLIDO POR CONTRARIO                                               "<<PdvCpu[2]<<"  PDV"<<endl;
    cout<< " RONDAS GANADAS AL ADVERSARIO                                                       "<<PdvCpu[3]<<"  PDV"<<endl;
    cout<< " POR CADA RONDA GANADA EN EL JUEGO CON UN ELEMENTO IGUAL AL DEL ADVERSARIO          "<<PdvCpu[4]<<"  PDV"<<endl;
    cout<< "-------------------------------------------------------------------------------------------------"<<endl;
    // SUMAMOS EL PUNTAJE TOTAL DE LA CPU
    for(int x=0;x<5;x++){
        TotalCpu+=PdvCpu[x];
    }
    cout<< " TOTAL          =================================================>                    "<<TotalCpu<<" PDV"<<endl<<endl;

    // MOSTRAMOS EL PUNTAJE DEL USUARIO
    cout<< " PUNTOS REALIZADOS por "<< usuario<<endl;
    cout<< "-------------------------------------------------------------------------------------------------"<<endl;
    cout<< " GANADOR DE LA PARTIDA                                                              "<<PdvUsuario[0]<<"  PDV"<<endl;
    cout<< " COMBINACIÓN ELEMENTOS CUMPLIDO POR CONTRARIO                                       "<<PdvUsuario[1]<<"  PDV"<<endl;
    cout<< " CARTA DESAFÍO CUMPLIDO POR CONTRARIO                                               "<<PdvUsuario[2]<<"  PDV"<<endl;
    cout<< " RONDAS GANADAS AL ADVERSARIO                                                       "<<PdvUsuario[3]<<"  PDV"<<endl;
    cout<< " POR CADA RONDA GANADA EN EL JUEGO CON UN ELEMENTO IGUAL AL DEL ADVERSARIO          "<<PdvUsuario[4]<<"  PDV"<<endl;
    cout<< "-------------------------------------------------------------------------------------------------"<<endl;
     for(int x=0;x<5;x++){
        TotalUsuario+=PdvUsuario[x];
    }
    cout<< " TOTAL         ====================================================>                "<<TotalUsuario<<" PDV"<<endl<<endl;
    system("PAUSE");
    system("CLS");

    ///RECETEAMOS LOS PUNTOS DE VICTORIA
    for(int x=0;x<5;x++){
        PdvUsuario[x]=0;
        PdvCpu[x]=0;
    }
   }
  }

    ///--------------------------------------------------------------------------------------------------------------///














