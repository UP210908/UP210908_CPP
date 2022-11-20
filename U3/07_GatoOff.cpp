/*
Author: Miguel Angel Ortiz
Date: 06/11/2022
Description: Juego del gato
Unit: 3
*/

#include <iostream>

using namespace std;

char coordenadasGato[6][11];
char areaJuego[3][3]={{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int turnojugador=1;
int contador=0;

int seleccionarJugada(){

    int tiro;
    do
    {
        cout << "Dame tu jugada: ";
        cin >> tiro;
        contador++;
    } while (tiro>9 && tiro<0);
    return tiro;

}

bool revisarGanador(int jugada){
    int punto = 0;
    bool revisarGanador = false;
    for (int posicion = 0; posicion < 3; posicion++)
    {
        if ((areaJuego[0][posicion] == areaJuego[1][posicion]) && (areaJuego[0][posicion] == areaJuego[2][posicion]))
        {
            revisarGanador = true;
            break;
        }
        else if ((areaJuego[posicion][0] == areaJuego[posicion][1]) && (areaJuego[posicion][0] == areaJuego[posicion][2]))
        {
            revisarGanador = true;
            break;
        }
        else if ((areaJuego[posicion][posicion] == areaJuego[posicion+1][posicion+1]) && (areaJuego[posicion][posicion] == areaJuego[posicion+2][posicion+2]))
        {
            revisarGanador = true;
            break;
        }
        else if ((areaJuego[2][0] == areaJuego[1][1]) && (areaJuego[2][0] == areaJuego[0][2]))
        {
            revisarGanador = true;
            break;
        }
    }
    return revisarGanador;
}
   


bool comprobarCasillaOcupada(int jugada)
{
    int row;
    int col;
    if (jugada == 1)
    {
        row = 0;
        col = 0;
    }
    else if (jugada == 2)
    {
        row = 0;
        col = 1;
    }
    else if (jugada == 3)
    {
        row = 0;
        col = 2;
    }
    else if (jugada == 4)
    {
        row = 1;
        col = 0;
    }
    else if (jugada == 5)
    {
        row = 1;
        col = 1;
    }
    else if (jugada == 6)
    {
        row = 1;
        col = 2;
    }
    else if (jugada == 7)
    {
        row = 2;     
        col = 0;
    }
    else if (jugada == 8)
    {
        row = 2;
        col = 1;
    }
    else if (jugada == 9)
    {
        row = 2;
        col = 2;
    }
    if (areaJuego[row][col] == '0' || areaJuego[row][col] == 'x')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void colocarjugada(int jugada)
{
    char valorJugada;
    if (turnojugador % 2 == 0)
    {
        valorJugada = 'x';
    }
    else
    {
        valorJugada = '0';
    }

    if (jugada == 1)
    {
        areaJuego[0][0] = valorJugada;
    }
    else if (jugada == 2)
    {
        areaJuego[0][1] = valorJugada;
    }
    else if (jugada == 3)
    {
        areaJuego[0][2] = valorJugada;
    }
    else if (jugada == 4)
    {
        areaJuego[1][0] = valorJugada;
    }
    else if (jugada == 5)
    {
        areaJuego[1][1] = valorJugada;
    }
    else if (jugada == 6)
    {
        areaJuego[1][2] = valorJugada;
    }
    else if (jugada == 7)
    {
        areaJuego[2][0] = valorJugada;
    }
    else if (jugada == 8)
    {
        areaJuego[2][1] = valorJugada;
    }
    else if (jugada == 9)
    {
        areaJuego[2][2] = valorJugada;
    }
    turnojugador++;
}

void tableroGato(){
    int c1=0, f1=0;
    for(int row=0; row<6 ; row++){
        for(int col=0; col<11; col++){

            if(col==3 || col==7){
                coordenadasGato[row][col]='|';
            }
            else if (row==1 || row==3){
                coordenadasGato[row][col]='_';
            }
            
            else if (row!=5 &&(col ==9 || col== 5 || col==1))
            {
                coordenadasGato[row][col]= areaJuego[f1][c1];  
                c1++;
                if (c1 == 3)
                {
                    c1 = 0;
                    f1++;
                } 
            }
            
            else{
                coordenadasGato[row][col]=' ';
            }
        }
    }

    for(int f1=0; f1<6 ; f1++){
        for(int c1=0; c1<11; c1++){
            if (coordenadasGato[f1][c1]=='x')
            {
                cout<<coordenadasGato[f1][c1];
            }
            else if (coordenadasGato[f1][c1]=='0')
            {
                cout<<coordenadasGato[f1][c1];
            }
            else
            {
                cout<<coordenadasGato[f1][c1];
            }
        }
        cout<<"\n";
    }   
}

int main(){

    int jugada, juego=0;
    bool casillaOcupada=true, winner=false;

    
    do
    {
        do
    {
        tableroGato();
        jugada=seleccionarJugada();
        casillaOcupada= comprobarCasillaOcupada(jugada);
        if (casillaOcupada==false)  
        {
            
            winner=revisarGanador(winner);
            colocarjugada(jugada);
            system("clear");        
        }
        else if(casillaOcupada==true)
        {
            system("clear");
            cout<<"\033[0;31m"<<"Atencion:"<<"\033[0m"<<endl;
            cout<<"\tHazlo otra vez, la casilla esta ocupada :("<<endl;
        }
    } while (casillaOcupada==false && turnojugador<9);
    winner=revisarGanador(winner);
    if (turnojugador<10){
    if (turnojugador % 2 == 0)
    {
        cout << "Gano el jugador 2\n";
    }
    else
    {
        cout << "Gano el jugador 1\n";
    }
    } else{
        cout << "Empate\n";
    }

    } while (casillaOcupada==true);

    return 0;
}