#include <iostream>
#include <locale.h>
#include <ctime>
#include <windows.h>
#include "menu.h"
#include "rlutil.h"
#include "mazo.h"
#include "accion.h"


using namespace rlutil;
using namespace std;

int main()
{
   setlocale(LC_ALL, "Spanish");
   srand(time(NULL));

   ///Declaracion de variables
   int numero, eleccion, ronda=0, x, tirar,ContMazoCpu=0, azar, PdvUsuario[5]={}, PdvCpu[5]={}, TotalUsuario=0, TotalCpu=0, TotalEstadistica=0;
   string usuario, CartaDesafioUsuario, CartaDesafioCpu, CartaUsuario, CartaCpu, Ganador;
   string MazoDesafio[10]={"Ganar una carta de Nieve", "Ganar una carta de Fuego", "Ganar una carta de Agua", "Ganar dos cartas rojas", "Ganar dos cartas amarillas", "Ganar dos cartas verdes", "Ganar dos cartas azules", "Ganar una carta con el mismo elemento que el adversario","Ganar dos cartas con el mismo número", "Ganar dos rondas de manera consecutiva"};
   string MazoElementos[60]={"FUEGO ROJO #1", "FUEGO ROJO #2", "FUEGO ROJO #3", "FUEGO ROJO #4", "FUEGO ROJO #5", "FUEGO AMARILLO #1", "FUEGO AMARILLO #2", "FUEGO AMARILLO #3", "FUEGO AMARILLO #4", "FUEGO AMARILLO #5", "FUEGO VERDE #1", "FUEGO VERDE #2", "FUEGO VERDE #3", "FUEGO VERDE #4", "FUEGO VERDE #5", "FUEGO AZUL #1","FUEGO AZUL #2", "FUEGO AZUL #3", "FUEGO AZUL #4", "FUEGO AZUL #5","NIEVE ROJA #1", "NIEVE ROJA #2", "NIEVE ROJA #3", "NIEVE ROJA #4", "NIEVE ROJA #5", "NIEVE AMARILLA #1", "NIEVE AMARILLA #2", "NIEVE AMARILLA #3", "NIEVE AMARILLA #4", "NIEVE AMARILLA #5", "NIEVE VERDE #1","NIEVE VERDE #2", "NIEVE VERDE #3", "NIEVE VERDE #4", "NIEVE VERDE #5", "NIEVE AZUL #1", "NIEVE AZUL #2", "NIEVE AZUL #3", "NIEVE AZUL #4", "NIEVE AZUL #5", "AGUA ROJA #1", "AGUA ROJA #2", "AGUA ROJA #3", "AGUA ROJA #4", "AGUA ROJA #5", "AGUA AMARILLA #1", "AGUA AMARILLA #2", "AGUA AMARILLA #3", "AGUA AMARILLA #4", "AGUA AMARILLA #5", "AGUA VERDE #1", "AGUA VERDE #2", "AGUA VERDE #3", "AGUA VERDE #4", "AGUA VERDE #5", "AGUA AZUL #1", "AGUA AZUL #2", "AGUA AZUL #3", "AGUA AZUL #4", "AGUA AZUL #5"};
   string MazoUsuario[60]={ "vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio"};
   string MazoCpu[60]={"vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio","vacio" };
   int MazoNumerico[60]={1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5};
   int VecRojo[15]={0,1,2,3,4,20,21,22,23,24,40,41,42,43,44},VecAmarillo[15]={5,6,7,8,9,25,26,27,28,29,45,46,47,48,49}, VecVerde[15]={10,11,12,13,14,30,31,32,33,34,50,51,52,53,54}, VecAzul[15]={15,16,17,18,19,35,36,37,38,39,55,56,57,58,59};
   int contRojoUsuario=0, contAmarilloUsuario=0, contVerdeUsuario=0, contAzulUsuario=0, contRojoCpu=0, contAmarilloCpu=0, contVerdeCpu=0, contAzulCpu=0;
   int VecMismoNumeroUsuario[5]={}, VecMismoNumeroCpu[5]={}, ContDosCartasUsuario=0, ContDosCartasCpu=0;
   bool MazoBoleano[60]={}, GanaUsuario=false, GanaCpu=false,HitosUsuario=false, HitosCpu=false;
   bool HitoCartaDesafioUsuario=false, HitoCartaDesafioCpu=false, CombGanadoraUsuario=false, CombGanadoraCpu=false;
   bool MismoElementoUsuario=false, MismoElementoCpu=false;
   string cartaUsada;
 do{
          MostrarMenuInicio();
          locate(45,25);
          cin >> numero;
          system("CLS");

 switch(numero){
 case 1: ///RESETEO DE VARIABLES
         VaciarMazosJugadores(MazoUsuario, MazoCpu, MazoBoleano, VecMismoNumeroUsuario, VecMismoNumeroCpu);
         ronda=0, ContMazoCpu=0,contRojoUsuario=0, contAmarilloUsuario=0, contVerdeUsuario=0, contAzulUsuario=0;
         contRojoCpu=0, contAmarilloCpu=0, contVerdeCpu=0, contAzulCpu=0, TotalUsuario=0, TotalCpu=0;
         GanaUsuario=false, GanaCpu=false, HitosUsuario=false, HitosCpu=false,HitoCartaDesafioUsuario=false, HitoCartaDesafioCpu=false;
         CombGanadoraUsuario=false, CombGanadoraCpu=false, MismoElementoUsuario=false, MismoElementoCpu=false;
///-----------------------------------------------------------------------------------///
        usuario=CargarJugador();
        repartirCartaDesafio(MazoDesafio, CartaDesafioUsuario, CartaDesafioCpu);
        repartir3cartas(MazoElementos, MazoUsuario, MazoCpu, MazoBoleano);
       while(HitosUsuario==false && HitosCpu==false){
            ronda ++;
            numero=0;
            while(numero!=3){
             MostrarMenuRobarCartaDeMazo(ronda, usuario);
             locate(45,25);
             cin>>numero;
             system("CLS");
             switch(numero){
                case 1: cout << endl<<"**"<< CartaDesafioUsuario <<"**"<< endl<<endl;
              //  cout<<endl<< "** -CPU- "<<CartaDesafioCpu<<"**"<<endl;///borrar al finalizar el juego
                system("PAUSE");
                system("CLS");
                break;
                case 2: cout<< "**CARTAS DE ELEMENTOS DE "<<usuario<<"**"<<endl<<endl;
                for(int x=0;x<60;x++){
                    if(MazoUsuario[x]!="vacio"){
                        cout<<MazoUsuario[x]<<endl;
                    }
                }
                ///borrar al finalizar el juego
                   /*
                cout<<endl<<endl<< "**CARTAS DE ELEMENTOS DE CPU**"<<endl;
                for(int x=0;x<60;x++){
                    if(MazoCpu[x]!="vacio"){
                        cout<<MazoCpu[x]<<endl;
                    }
                }
                */
                cout<<endl<<endl;

                system("PAUSE");
                system("CLS");
                break;

                case 3:RobarCartaDelMazo(MazoElementos, MazoUsuario, MazoCpu, MazoBoleano);
                       EvaluarCombinacionGanadora(MazoUsuario,MazoCpu,MazoElementos,VecRojo, VecAmarillo, VecVerde, VecAzul, CombGanadoraUsuario, CombGanadoraCpu);

                break;


             }

            }
            numero=0;
            ContMazoCpu=0;
            while(numero!=3){
                    GanaCpu=false, GanaUsuario=false, MismoElementoUsuario=false, MismoElementoCpu=false;
                    MostrarMenuJugarCarta(MazoElementos, MazoUsuario, MazoCpu, MazoBoleano, usuario, ronda);
                        locate(45,25);
                        cin >>numero;
                        system("CLS");
                        switch(numero){
                         case 1: cout << endl<< "***"<<CartaDesafioUsuario <<"***"<< endl<<endl;
                        //cout<<endl<< "** -CPU- "<<CartaDesafioCpu<<"**"<<endl;///borrar al finalizar el juego
                        system("PAUSE");
                        system("CLS");

                break;
                       case 2: cout<< "**CARTAS DE ELEMENTOS DE "<<usuario<<"**"<<endl<<endl;
                for(int x=0;x<60;x++){
                    if(MazoUsuario[x]!="vacio"){
                        cout<<MazoUsuario[x]<<endl;
                    }
                }
                ///borrar al finalizar el juego
            /*
                cout<<endl<<endl<< "**CARTAS DE ELEMENTOS DE CPU**"<<endl;
                for(int x=0;x<60;x++){
                    if(MazoCpu[x]!="vacio"){
                        cout<<MazoCpu[x]<<endl;
                    }
                }
                */
                        system("PAUSE");
                        system("CLS");
                break;
                       case 3:cout<<endl<<endl<< " ***  QUE CARTA DESEA JUGAR?  *** "<<endl<<endl;
                       ///muestra que carta tenemos y la opcion de elegir una
                                x=0;
                                while(MazoUsuario[x]!= "vacio"){
                                    cout<< "["<<x+1<< "]-"<<MazoUsuario[x];
                                    x++;
                                    cout<<endl;
                                }
                                cin>>tirar;
                                CartaUsuario=MazoUsuario[tirar-1];
                                ///vemos cuantas cartas tiene la cpu para configurar rand, para tire una carta
                                system("CLS");

                                    x=0;
                                while(MazoCpu[x]!= "vacio"){
                                    ContMazoCpu++;
                                    x++;
                                }
                                azar=rand()%ContMazoCpu+1;


                                CartaCpu=MazoCpu[azar-1];
                                cout<<endl<<endl;
                                cout<< " CARTA JUGADA POR "<<usuario<<"====> "<<CartaUsuario<<endl<<endl;
                                cout<< " CARTA JUGADA POR CPU    ====>"<<CartaCpu<<endl;
                                cartaUsada=CartaUsuario;
                                ///detectamos indice para saber a que elemeto corresponde la carta
                                int PosHumano,PosCpu, NumeroCartaUsuario, NumeroCartaCpu;
                                string aux;
                                for(x=0;x<60;x++){
                                   if(CartaUsuario==MazoElementos[x]){
                                    PosHumano=x;

                                   }
                                   if(CartaCpu==MazoElementos[x]){
                                    PosCpu=x;
                                   }
                                }
                                   ///el mazo numerico guarda las posiciones del 1 al 5, para definir ganador por numero
                                    NumeroCartaUsuario=MazoNumerico[PosHumano];
                                    NumeroCartaCpu=MazoNumerico[PosCpu];
                                    ///separamos en funcion de acá

                                ///evaluamos choque de elementos y definimos ganador
                                if(PosHumano<20&&(PosCpu>19&&PosCpu<40)){
                                        GanaUsuario=true;
                                        PdvUsuario[3]+=1;
                                    cout<<endl<< "¡¡ GANA "<<usuario<< " POR QUE FUEGO VENCE A NIEVE !!"<<endl;
                                    for(x=0;x<60;x++){
                                        if(MazoUsuario[x]=="vacio"){
                                            MazoUsuario[x]=CartaCpu;
                                            x=60;
                                        }
                                    }
                                        MazoCpu[azar-1]= "vacio";
                                        ///ordenamos mazo de cpu con la carta que perdió
                                        for(x=0;x<59;x++){
                                            if(MazoCpu[x]== "vacio"){
                                                aux=MazoCpu[x];
                                                MazoCpu[x]=MazoCpu[x+1];
                                                MazoCpu[x+1]=aux;
                                            }
                                        }

                                }else if(PosHumano>39&&PosCpu<20){
                                    GanaUsuario=true;
                                    PdvUsuario[3]+=1;
                                cout<<endl<< "¡¡ GANA "<<usuario<< " POR QUE AGUA VENCE A FUEGO !!"<<endl;
                                 for(x=0;x<60;x++){
                                        if(MazoUsuario[x]=="vacio"){
                                            MazoUsuario[x]=CartaCpu;
                                            x=60;
                                        }
                                    }
                                        MazoCpu[azar-1]= "vacio";
                                          ///ordenamos mazo de cpu con la carta que perdió
                                        for(x=0;x<59;x++){
                                            if(MazoCpu[x]== "vacio"){
                                                aux=MazoCpu[x];
                                                MazoCpu[x]=MazoCpu[x+1];
                                                MazoCpu[x+1]=aux;
                                            }
                                        }

                                }else if((PosHumano>19&&PosHumano<40)&&PosCpu>39){
                                    GanaUsuario=true;
                                    PdvUsuario[3]+=1;
                                cout<<endl<< "¡¡ GANA "<<usuario<< " POR QUE NIEVE VENCE A AGUA !!"<<endl;
                                 for(x=0;x<60;x++){
                                        if(MazoUsuario[x]=="vacio"){
                                            MazoUsuario[x]=CartaCpu;
                                            x=60;
                                        }
                                    }
                                        MazoCpu[azar-1]= "vacio";
                                          ///ordenamos mazo de cpu con la carta que perdió
                                        for(x=0;x<59;x++){
                                            if(MazoCpu[x]== "vacio"){
                                                aux=MazoCpu[x];
                                                MazoCpu[x]=MazoCpu[x+1];
                                                MazoCpu[x+1]=aux;
                                            }
                                        }
                                }else if(PosCpu<20&&(PosHumano>19&&PosHumano<40)){
                                    GanaCpu=true;
                                    PdvCpu[3]+=1;
                                    cout<<endl<<endl<< "¡¡ GANA CPU POR QUE FUEGO VENCE A NIEVE !!"<<endl;
                                     for(x=0;x<60;x++){
                                        if(MazoCpu[x]=="vacio"){
                                            MazoCpu[x]=CartaUsuario;
                                            x=60;
                                        }
                                     }
                                        MazoUsuario[tirar-1]= "vacio";
                                          ///ordenamos mazo de usuario con la carta que perdió
                                        for(x=0;x<59;x++){
                                            if(MazoUsuario[x]== "vacio"){
                                                aux=MazoUsuario[x];
                                                MazoUsuario[x]=MazoUsuario[x+1];
                                                MazoUsuario[x+1]=aux;
                                            }
                                        }

                                }else if(PosCpu>39&&PosHumano<20){
                                    GanaCpu=true;
                                    PdvCpu[3]+=1;
                                cout<<endl<<endl<< "¡¡ GANA CPU  POR QUE AGUA VENCE A FUEGO !!"<<endl;
                                 for(x=0;x<60;x++){
                                        if(MazoCpu[x]=="vacio"){
                                            MazoCpu[x]=CartaUsuario;
                                            x=60;
                                        }
                                    }
                                        MazoUsuario[tirar-1]= "vacio";
                                           ///ordenamos mazo de usuario con la carta que perdió
                                        for(x=0;x<59;x++){
                                            if(MazoUsuario[x]== "vacio"){
                                                aux=MazoUsuario[x];
                                                MazoUsuario[x]=MazoUsuario[x+1];
                                                MazoUsuario[x+1]=aux;
                                            }
                                        }

                                }else if((PosCpu>19&&PosCpu<40)&&PosHumano>39){
                                    GanaCpu=true;
                                    PdvCpu[3]+=1;
                                cout<<endl<<endl<< "¡¡ GANA CPU POR QUE NIEVE VENCE A AGUA !!"<<endl;
                                 for(x=0;x<60;x++){
                                        if(MazoCpu[x]=="vacio"){
                                            MazoCpu[x]=CartaUsuario;
                                            x=60;
                                        }
                                    }
                                        MazoUsuario[tirar-1]= "vacio";
                                           ///ordenamos mazo de usuario con la carta que perdió
                                        for(x=0;x<59;x++){
                                            if(MazoUsuario[x]== "vacio"){
                                                aux=MazoUsuario[x];
                                                MazoUsuario[x]=MazoUsuario[x+1];
                                                MazoUsuario[x+1]=aux;
                                            }
                                        }
                               }else if(NumeroCartaUsuario>NumeroCartaCpu){
                                   GanaUsuario=true;
                                   PdvUsuario[4]+=5;
                                   MismoElementoUsuario=true;
                                    cout<<endl<< " ¡¡ GANA "<<usuario<< ", AUNQUE LOS  ELEMENTOS SEAN IGUALES, TIENE MAYOR VALOR !! "<<endl;
                                     for(x=0;x<60;x++){
                                        if(MazoUsuario[x]=="vacio"){
                                            MazoUsuario[x]=CartaCpu;
                                            x=60;
                                        }
                                     }
                                        MazoCpu[azar-1]= "vacio";
                                          ///ordenamos mazo de cpu con la carta que perdió
                                        for(x=0;x<59;x++){
                                            if(MazoCpu[x]== "vacio"){
                                                aux=MazoCpu[x];
                                                MazoCpu[x]=MazoCpu[x+1];
                                                MazoCpu[x+1]=aux;
                                            }
                                        }

                                }else if(NumeroCartaCpu>NumeroCartaUsuario){
                                    GanaCpu=true;
                                    PdvCpu[4]+=5;
                                    MismoElementoCpu=true;
                                cout<<endl<<endl<< " ¡¡ GANA CPU, AUNQUE LOS ELEMENTOS SEAN IGUALES, TIENE MAYOR VALOR !! "<<endl;
                                 for(x=0;x<60;x++){
                                        if(MazoCpu[x]=="vacio"){
                                            MazoCpu[x]=CartaUsuario;
                                            x=60;
                                        }
                                    }
                                        MazoUsuario[tirar-1]= "vacio";
                                           ///ordenamos mazo de usuario con la carta que perdió
                                        for(x=0;x<59;x++){
                                            if(MazoUsuario[x]== "vacio"){
                                                aux=MazoUsuario[x];
                                                MazoUsuario[x]=MazoUsuario[x+1];
                                                MazoUsuario[x+1]=aux;
                                            }
                                        }

                                }else if(NumeroCartaUsuario==NumeroCartaCpu){
                                        if(ronda%2==0){
                                                GanaUsuario=true;
                                                PdvUsuario[4]+=5;
                                            cout<<endl<<" ¡¡¡ ES  EMPATE!!!"<<endl<< " ¡¡¡ PERO GANA "<<usuario<< " POR QUE EL NUMERO DE RONDA ES PAR !!!"<<endl;
                                             for(x=0;x<60;x++){
                                        if(MazoUsuario[x]=="vacio"){
                                            MazoUsuario[x]=CartaCpu;
                                            x=60;
                                        }
                                    }
                                        MazoCpu[azar-1]= "vacio";
                                          ///ordenamos mazo de cpu con la carta que perdió
                                        for(x=0;x<59;x++){
                                            if(MazoCpu[x]== "vacio"){
                                                aux=MazoCpu[x];
                                                MazoCpu[x]=MazoCpu[x+1];
                                                MazoCpu[x+1]=aux;
                                            }
                                        }
                                    }else{ cout<<endl<< "  ¡¡ ES  EMPATE, PERO GANA CPU POR QUE EL NUMERO DE RONDA ES IMPAR !!" <<endl;
                                    GanaCpu=true;
                                    PdvCpu[4]+=5;
                                 for(x=0;x<60;x++){
                                        if(MazoCpu[x]=="vacio"){
                                            MazoCpu[x]=CartaUsuario;
                                            x=60;
                                        }
                                    }
                                        MazoUsuario[tirar-1]= "vacio";
                                           ///ordenamos mazo de usuario con la carta que perdió
                                        for(x=0;x<59;x++){
                                            if(MazoUsuario[x]== "vacio"){
                                                aux=MazoUsuario[x];
                                                MazoUsuario[x]=MazoUsuario[x+1];
                                                MazoUsuario[x+1]=aux;
                                            }
                                         }
                                    }

                                }

                                    EvaluarCombinacionGanadora(MazoUsuario,MazoCpu,MazoElementos,VecRojo, VecAmarillo, VecVerde, VecAzul, CombGanadoraUsuario, CombGanadoraCpu);
                                    EvaluarCartasDesafio(MazoDesafio, MazoUsuario, MazoCpu, CartaDesafioUsuario, CartaDesafioCpu, CartaUsuario, CartaCpu, MazoElementos, MazoBoleano, MazoNumerico, HitoCartaDesafioUsuario, HitoCartaDesafioCpu, GanaUsuario, GanaCpu, VecRojo, VecAmarillo, VecVerde, VecAzul, contRojoUsuario, contAmarilloUsuario, contVerdeUsuario, contAzulUsuario, MismoElementoUsuario, MismoElementoCpu, VecMismoNumeroUsuario, VecMismoNumeroCpu, ContDosCartasUsuario, ContDosCartasCpu, contRojoCpu, contAmarilloCpu, contVerdeCpu, contAzulCpu);
                                    EvaluarHitos(HitoCartaDesafioUsuario, HitoCartaDesafioCpu, CombGanadoraUsuario, CombGanadoraCpu, HitosUsuario, HitosCpu);
                                    QuienGano(HitoCartaDesafioUsuario, HitoCartaDesafioCpu, CombGanadoraUsuario, CombGanadoraCpu, HitosUsuario, HitosCpu, PdvUsuario, PdvCpu, usuario, Ganador, TotalUsuario, TotalCpu, TotalEstadistica);
                                system("PAUSE");
                                system("CLS");


                        break;


                    }
                }
                /// esta llave de abajo es la que termina el juego con un ganador
            }



    break;

 case 2:MostrarEstadisticas(TotalEstadistica, Ganador);

     break;

 case 3: MostrarCreditos();

    break;

 case 4:MostrarReglas();

    break;

 case 0:eleccion=salir();
       if(eleccion==1){
            setColor(LIGHTGREEN);
            cout <<endl<<endl<< " GRACIAS POR JUGAR "<<usuario<<"!!!"<< endl;
            cout<< "<====== HASTA LA PRÓXIMA ======>"<<endl;
            setColor(WHITE);
        system("PAUSE");
        system("CLS");
        return 0;
       }else{numero=1;}

        system("CLS");
    break;
 }








 }while(numero!=0);



    return 0;
}
