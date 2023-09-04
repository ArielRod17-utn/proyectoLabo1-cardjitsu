#include <iostream>
#include <locale.h>
#include <ctime>
#include <windows.h>
#include "menu.h"
#include "rlutil.h"

using namespace std;
using namespace rlutil;

///funcion que muestra el men� principal
void MostrarMenuInicio(){


locate(20,1);
setColor(LIGHTBLUE);
cout<<"      ====================================================================================  "<<endl;
locate(20,2);
setColor(YELLOW);
cout<<"       #### ##### ####  ####     #####  #  #####   ####   #  #         ##          ##  "<<endl;
locate(20,3);
setColor(YELLOW);
cout<<"       #### ##### ####  ####     #####     #####   ####   #  #         ##          ##      "<<endl;
locate(20,4);
setColor(YELLOW);
cout<<"       #    #   # ##  # #   #      #    #    #     #      #  #      ########    ########        "<<endl;
locate(20,5);
setColor(YELLOW);
cout<<"       #    ##### ####  #   #      #    #    #      #     #  #      ########    ########        "<<endl;
locate(20,6);
setColor(YELLOW);
cout<<"       #### #   # #   # ####     ###    #    #     # #    ####         ##          ##  "<<endl;
locate(20,7);
setColor(YELLOW);
cout<<"       #### #   # #   # ####     ###    #    #     # #    ####         ##          ##  "<<endl;
locate(20,8);
setColor(LIGHTBLUE);
cout<<"      =====================================================================================  "<<endl;
setColor(WHITE);
 locate(45,13);
 cout << "----------------------------------------"<<endl;
 locate(45,14);
 cout << "----------------------------------------"<<endl;
 locate(45,15);
 cout << " 1- JUGAR " << endl;
 locate(45,16);
 cout << " 2- ESTAD�STICAS " << endl;
 locate(45,17);
 cout << " 3- CR�DITOS "<<endl;
 locate(45,18);
 cout << " 4- REGLAS DEL JUEGO " << endl;
 locate(45,19);
 cout << "----------------------------------------"<<endl;
 locate(45,20);
 cout << "----------------------------------------"<<endl;
 locate(45,21);
 cout << " 0- SALIR " << endl<<endl;
 locate(45,22);
 cout << " OPCION?"<< endl;
 locate(45,23);
}

///funcion que muestra men� previo a robar carta
void MostrarMenuRobarCartaDeMazo(int &ronda, string &usuario){
locate(45,11);
cout << "----------------------------------------------------"<<endl<<endl;
setBackgroundColor(GREEN);
locate(45,12);
cout << "||               CARD-JITSU++                     ||"<<endl;
setBackgroundColor(BLACK);
locate(45,13);
cout << "----------------------------------------------------"<<endl<<endl;
locate(45,14);
cout << " "<< usuario << "    VS    CPU                 RONDA "<< ronda <<endl;
locate(45,15);
cout<<endl;
locate(45,16);
cout << "[1] - VER CARTA DESAFIO"<<endl;
locate(45,17);
cout << "[2] - VER CARTAS DE ELEMENTOS"<<endl;
locate(45,18);
cout << "[3] - ROBAR CARTA DE ELEMENTOS DE LA PILA"<<endl;
locate(45,19);
cout << endl<<endl<<endl;
locate(45,20);
cout << " OPCION? (1 a 3):"<<endl;

}

/// funcion que muestra el menu para jugar una carta
void MostrarMenuJugarCarta(string MazoElementos[], string MazoUsuario[] , string MazoCpu[] , bool MazoBoleano[], string &usuario, int &ronda) {
locate(45,11);
cout << "--------------------------------------------------"<<endl;
setBackgroundColor(GREEN);
locate(45,12);
cout << "||                CARD-JITSU++                  ||"<<endl;
setBackgroundColor(BLACK);
locate(45,13);
cout << "--------------------------------------------------"<<endl<<endl;
locate(45,14);
cout << " "<< usuario << " VS  CPU                RONDA "<< ronda <<endl;
locate(45,15);
cout <<endl;
locate(45,16);
cout << "[1] - VER CARTA DESAFIO"<<endl;
locate(45,17);
cout << "[2] - VER CARTAS DE ELEMENTOS"<<endl;
locate(45,18);
cout << "[3] - JUGAR UNA CARTA"<<endl;
locate(45,19);
cout << endl<<endl<<endl;
locate(45,20);
cout << " OPCION? (1 a 3):"<<endl;


}






///funcion que guarda el nombre del jugador humano
string CargarJugador(){
string nombre;
cout << " INGRESE EL NOMBRE DE USUARIO: "<<endl;
cin >> nombre;
system("CLS");
cout << endl<<endl<<endl<<endl;
setColor(LIGHTGREEN);
cout << "                                     <===== M U C H A   S U E R T E =====>" << endl<<endl;cout << "                                    ���   V A M O S  A  J U G A R !!!" << endl << endl<<endl<<endl<<endl;
    setColor(WHITE);
    system("PAUSE");
    system("CLS");
return nombre;
}
///funcion que muestra las reglas del juego
void MostrarReglas(){
    cout<<"CARD-JITSU++ es un juego de cartas de dos jugadores"<<endl;
    cout<<"El objetivo del juego es obtener una combinaci�n de cartas de elementos y cumplir con una carta desaf�o espec�fica para cada jugador"<<endl;
    cout<<"El primer jugador en cumplir ambos hitos se convertir� en el ganador del juego"<<endl;
    cout<<endl;
    cout<<"�C�MO SE JUEGA UNA PARTIDA?"<<endl;
    cout<<"Las partidas se juegan con una serie de cartas especiales dividida en dos mazos" <<endl;
    cout<<"El primer mazo es el de Desaf�os, donde hay 10 tipos de cartas diferentes"<<endl;
    cout<<"Las cartas desaf�o contienen una descripci�n del objetivo que deber� cumplir su portador"<<endl;
    cout<<"Antes de comenzar cada partida, los jugadores roban una carta del Mazo Desaf�o"<<endl;
    cout<<"Cada jugador debe intentar cumplir con la condici�n de su carta desaf�o cuanto antes"<<endl;
    cout<<"El segundo mazo es el de Elementos, donde contamos con 60 cartas distinguidas por elemento, color y n�mero" <<endl;
    cout<<"Las cartas de elementos permiten que se desarrolle la partida" <<endl;
    cout<<"Sin embargo, son las que pueden marcar un desaf�o como cumplido o no"<<endl;
    cout<<"Y son las que permiten cumplir el segundo hito de la partida: obtener una combinaci�n ganadora" <<endl;
    cout<<endl;
    cout<<"MAZO DE CARTAS DESAF�O"<<endl;
    cout<<"Como se indic� anteriormente, este mazo cuenta con 10 cartas distintas" <<endl;
    cout<<"Dos cartas ser�n robadas antes del inicio de la partida, una para cada jugador" <<endl;
    cout<<"El mazo desaf�o contiene las siguientes cartas:" <<endl;
    cout<<"1) GANAR UNA CARTA DE NIEVE"<<endl;
    cout<<"2) GANAR UNA CARTA DE FUEGO"<<endl;
    cout<<"3) GANAR UNA CARTA DE AGUA" <<endl;
    cout<<"4) GANAR DOS CARTAS ROJAS" <<endl;
    cout<<"5) GANAR DOS CARTAS AMARILLAS" <<endl;
    cout<<"6) GANAR DOS CARTAS VERDES" <<endl;
    cout<<"7) GANAR DOS CARTAS AZULES" <<endl;
    cout<<"8) GANAR UNA CARTA CON EL MISMO ELEMENTO QUE EL ADVERSARIO" <<endl;
    cout<<"9) GANAR DOS CARTAS CON EL MISMO N�MERO" <<endl;
    cout<<"10) GANAR DOS RONDAS DE MANERA CONSECUTIVA" <<endl;
    cout<<endl;
    cout<<"Cada jugador conocer� �nicamente su carta desaf�o y cumplirla ser� excluyente para ganar la partida "<<endl;
    cout<<endl;
    cout<<"MAZO DE CARTAS DE ELEMENTOS "<<endl;
    cout<<"Estas cartas contienen un elemento (FUEGO, NIEVE o AGUA), un color (ROJO, AMARILLO, VERDE o AZUL) y un n�mero (de 1 a 5) "<<endl;
    cout<<"En total este mazo cuenta con 60 naipes y sus cartas permiten que se desarrolle el juego"<<endl;
    cout<<"Cada jugador comienza la partida con tres cartas de elementos repartidas al azar"<<endl;
    cout<<"En cada ronda cada jugador tendr� la obligaci�n de robar una carta del mazo de elementos "<<endl;
    cout<<"Tambi�n, ambos jugadores est�n obligados a jugar una carta por ronda para competir con la del adversario "<<endl;
    cout<<"Esto significa que un jugador puede recuperar su carta y ganar la del rival, o perder directamente su carta si el rival gan� la mano "<<endl;
    cout<<endl;
    cout<<"TRANSCURSO DEL JUEGO"<<endl;
    cout<<"El juego comienza con la Etapa de Desaf�os, donde cada jugador recibir� su carta desaf�o "<<endl;
    cout<<"A partir de all� comenzar� la Etapa de elementos, la cual no tiene una cantidad exacta de rondas"<<endl;
    cout<<"El juego finalizar� reci�n cuando un jugador cumpla con dos condiciones:"<<endl;
    cout<<"1) Lograr lo que indica su carta desaf�o"<<endl;
    cout<<"2) Obtener una combinaci�n ganadora "<<endl;
    cout<<endl;
    cout<<"CHOQUE DE CARTAS: DETERMINAR ELEMENTO"<<endl;
    cout<<"Luego de que ambos jugadores robaran una carta del mazo de elementos, comenzar� la etapa de Choque de Cartas "<<endl;
    cout<<"Para determinar qu� carta es la victoriosa se siguen ciertos criterios"<<endl;
    cout<<"Entre esos criterios est�n las ventajas de elementos: "<<endl;
    cout<<"1) FUEGO vence a NIEVE "<<endl;
    cout<<"2) NIEVE vence a AGUA "<<endl;
    cout<<"3) AGUA vence a FUEGO "<<endl;
    cout<<"Estan reglas se cumplen sin importar el n�mero del naipe "<<endl;
    cout<<"Esto significa que cualquier carta FUEGO derrota a cualquiera de NIEVE sin importar su n�mero"<<endl;
    cout<<endl;
    cout<<"CHOQUE DE CARTAS: DETERMINAR N�MERO "<<endl;
    cout<<"En caso de que ambas cartas jugadas compartan elemento, la victoriosa ser� la que cuenta con un n�mero mayor"<<endl;
    cout<<"Por ejemplo, si ambas cartas son de tipo FUEGO pero una es FUEGO #2 y la otra FUEGO #4, ganar� FUEGO #4 ya que 4 es mayor que 2"<<endl;
    cout<<endl;
    cout<<"CHOQUE DE CARTAS: DETERMINAR MANO "<<endl;
    cout<<"Existe una tercera posibilidad, donde las cartas tiradas comparten elemento y n�mero"<<endl;
    cout<<"Por ejemplo: FUEGO #4 ROJO contra FUEGO #4 AMARILLO"<<endl;
    cout<<"En este caso, como ambas cartas son pr�cticamente id�nticas, entrar� en juego la MANO "<<endl;
    cout<<"El jugador que sea mano en esa ronda ser� considerado victorioso de ese enfrentamiento "<<endl;
    cout<<"La ronda se determina de una forma muy sencilla"<<endl;
    cout<<"Si la ronda actual es de un n�mero PAR, el jugador HUMANO ser� mano"<<endl;
    cout<<"Si, por el contrario, la ronda es IMPAR, la mano ser� la CPU"<<endl;
    cout<<endl;
    cout<<"FIN DEL CHOQUE DE CARTAS "<<endl;
    cout<<"Luego de determinar el ganador de la ronda, ambas cartas jugadas pasan a ser parte de la mano del jugador que gan� esa ronda"<<endl;
    cout<<"Esto significa que un jugador puede tener muchas cartas en su mano si gana muchas rondas "<<endl;
    cout<<"No obstante, un jugador jam�s podr� contar con menos de tres cartas en su mano"<<endl;
    cout<<endl;
    cout<<"COMBINACI�N GANADORA"<<endl;
    cout<<"Ya detallamos las cartas desaf�o, su finalidad y cu�les son. Ahora hablaremos de las combinaciones ganadoras"<<endl;
    cout<<"Una combinaci�n ganadora es el segundo objetivo que debe cumplir un jugador para ganar la partida"<<endl;
    cout<<"Hay dos tipos de combinaciones ganadoras:"<<endl;
    cout<<"1) Tener tres cartas de distinto elemento y color"<<endl;
    cout<<"Por ejemplo: FUEGO #4 AZUL, NIEVE #4 VERDE y AGUA #1 ROJO ser�a una combinaci�n ganadora"<<endl;
    cout<<"2) Tener tres cartas del mismo elemento"<<endl;
    cout<<"Por ejemplo: AGUA #1 VERDE, AGUA #5 VERDE y AGUA #1 AMARILLO ser�a una combinaci�n ganadora"<<endl;
    cout<<"El primer jugador en cumplir su carta desaf�o y una combinaci�n ganadora ser� el ganador de la partida "<<endl;
    cout<<endl;
    cout<<"PUNTOS DE VICTORIA Y ESTAD�STICAS"<<endl;
    cout<<"Una vez finalizada la partida se determinan los puntos de victoria obtenidos por el ganador "<<endl;
    cout<<"Estos se calculan de la siguiente manera:"<<endl;
    cout<<"1) +3 PDV por haber ganado la partida"<<endl;
    cout<<"2) -1 PDV si el contrario obtuvo una combinaci�n ganadora"<<endl;
    cout<<"3) -1 PDV si el contrario cumpli� el objetivo de su carta desaf�o"<<endl;
    cout<<"4) +1 PDV por cada ronda ganada en el juego al adversario"<<endl;
    cout<<"5) +5 PDV por cada ronda ganada en el juego con un elemento igual al del adversario"<<endl;
    cout<<endl;
    cout<<"Eso es todo. Le deseamos mucha suerte y esperamos que disfrute del juego"<<endl;
    cout<<endl;
    cout<<"LOS ABUELOS DE LA JAVA� "<<endl;
    system("PAUSE");
    system("CLS");

}
///funcion que muestra los creditos
void MostrarCreditos(){
  cout<<"---------------------------------------------"<<endl;
  setBackgroundColor(LIGHTCYAN);
  setColor(BLACK);
        cout<<"JUEGO DESARROLLADO POR LOS ABUELOS DE LA JAVA"<<endl;
        setBackgroundColor(BLACK);
        cout<<"---------------------------------------------"<<endl;
        setBackgroundColor(BLUE);
        setColor(YELLOW);
        cout<<"[INTEGRANTES]"<<endl;
        setBackgroundColor(BLACK);
        cout<<" ================================================ "<<endl;
        cout<<"  Ariel Rodriguez                  LEGAJO: 27540"<<endl;
        cout<<"  Gaston Garcia                    LEGAJO: 27520"<<endl;
        cout<<"  Raul Rodriguez                   LEGAJO: 26097"<<endl;
        cout<<"  Gonzalo Ligero                   LEGAJO: 27581"<<endl;
        cout<<"================================================= "<<endl;
        setColor(WHITE);
        cout<<endl;
      system("PAUSE");
      system("CLS");

}
///funcion que finaliza el juego
int salir(){
    int devolver;
    setBackgroundColor(BLUE);
cout << " ESTA SEGURO QUE DESEA SALIR?"<< endl<<endl;
setBackgroundColor(BLACK);
cout << " 1- SALIR " << endl;
cout << " 2- VOLVER AL MENU DE INICIO " << endl;
        cin>>devolver;
        system("CLS");
        return devolver;

}
///-----------------------------------------------------------------------///
///FUNCION PARA MOSTRAR EL MAYOR PUNTAJE GUARDADO

void MostrarEstadisticas(int &TotalEstadistica,string &Ganador){
  if(TotalEstadistica==0){
        setColor(LIGHTCYAN);
    cout<<endl<< "*** NO HAY REGISTRO DE PUNTAJE EN ESTE MOMENTO***"<<endl;
    cout<< "================================================="<<endl;
    cout<<endl;
  setColor(WHITE);
    system("PAUSE");
    system("CLS");
  }else {
        cout<<endl<<endl<< "         ���  PUNTAJE MAXIMO REGISTRADO  !!!"<<endl<<endl;
        cout<< "           EL USUARIO: "<< Ganador << " REGISTRO EL MAYOR PUNTAJE "<<endl;
        cout<< "          PUNTOS DE VICTORIA: "<< TotalEstadistica << endl;
        cout<< "***================================================================***"<<endl;
        system("PAUSE");
        system("CLS");
  }

}


///================================================================================================///






