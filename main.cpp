/* Tarea1. Programación Intermedia Programa de Juego 21.
Realizado por Erick Marin Cartin
Versión final: 24 de Febrero del 2019
*/
#include <iostream>
#include <time.h>
using namespace std;

/*Definición de variables globales, a futuro como mejora se pueden usar variables locales,
y enviar los parámetros en las funciones*/
int cartas_Array[10]; // Se asume una cantidad máxima de 10 cartas, usualmente la re
int cantidad;
int suma;
int respuesta;
bool jugadorListo = false;

enum Status {CONTINUA, GANA, PIERDE};

Status estadoJuego;

/* Función de generación de números aleatorios*/
int carta(int min, int max)
{
    // genera un número aleatorio entre el valor máximo y el mínimo
    int numero = rand () % (max-min+1) + min;
//    cout << numero << endl;
   return numero;
}

// Función para agregar una nueva carta al mazo
void agregarCarta()
{
    if (cantidad <= 10)
    {
        cartas_Array[cantidad] = carta(1,11);
        cantidad++;
    }
    else
    {
        cout << "Lo sentimos ha alcanzado la cantidad maxima de cartas (10)." << endl;
        estadoJuego = PIERDE;
        jugadorListo = true;
    }
}

// Función para imprimir la mano actual en el arreglo
void ImprimirMano()
{
    cout << "Su Mano actual es ...\n";
    for (int i = 0; i < cantidad; i++)
    {
        cout << "    -" << cartas_Array[i] << "-    \n\n";
    }
 }

// Función para calcular e imprimir la suma de las cartas del Mazo.
void CalculaSuma()
{
    suma = 0;
    for (int j = 0; j < cantidad; j++)
    {
        suma += cartas_Array[j];
    }
    cout << "La suma de su mano actual es: " << suma << endl;
    if (suma == 21)
    {
        estadoJuego = GANA;
    }
    if (suma > 21)
    {
        estadoJuego = PIERDE;
    }
    if (suma < 21)
    {
        estadoJuego = CONTINUA;
    }

}

int main()
{
// Programa Principal
    cout << "======================Bienvenid@ al juego de 21 ==============" << endl;
//Inicia con 2 cartas

    srand (time(NULL)); // función para resetear la semilla en la funcion rand

    agregarCarta();
    agregarCarta();
    ImprimirMano();
    CalculaSuma();

    if (estadoJuego == GANA)
    {
        cout << "Jugador gana.\n";
        jugadorListo = true;
    }

// Ciclo de juego después de las primeras 2 cartas en caso que el jugador no haya ganado
    while (jugadorListo == false)
    {
            cout << "Desea Continuar? (1 - Si, 2 - No)\n";
            cin >> respuesta;

            if (respuesta == 1)
            {
                agregarCarta();
                ImprimirMano();
                CalculaSuma();

                if (estadoJuego == PIERDE)
                {
                    cout << "El jugador ha excedido 21. Jugador Pierde.\n";
                    jugadorListo = true;

                }
                if (estadoJuego == GANA)
                {
                    cout << "Jugador ha alcanzado 21.  Jugador Gana. \n";
                    jugadorListo = true;
                }
            }
            if (respuesta == 2)
            {
                cout << "Buen Intento. Gracias por participar.\n";
                jugadorListo = true;
            }

    }
    return 0;
}
