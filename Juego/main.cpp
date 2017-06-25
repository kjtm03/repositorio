#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "Nave.h"
#include "Borde.h"
#include "Kamikaze.h"
#include "Bala.h"
#include "list"
#define ESPACIO 32
using namespace std;

int main()
{
    list <Bala *> balas;
    list <Bala *>::iterator iterador;

    Borde limite(0,0);
    limite.crearLimites();
    Nave uno(37,30,6);
    uno.caracter();
    uno.borrar();
    uno.borrarCursor();
    uno.numeroVidas();
    Kamikaze kamikaze(10,10),kamikaze1(10,10);

    bool game_over = false;
    while(!game_over){

        if (kbhit())
        {
            char tecla = getch();
            if(tecla = ESPACIO)
                balas.push_back(new Bala(uno.get_x()+2,uno.get_y()-1));
        }
        for(iterador = balas.begin();iterador != balas.end();iterador++)
        {
            (*iterador)->mover();
        }

        kamikaze.mover(); kamikaze.colision(uno);
        //kamikaze1.mover(); kamikaze1.colision(uno);
        uno.morir();
        uno.mover();
        Sleep(30);
    }
}
