//TokyoDriftLibrary.cpp

#include "TokyoDriftLibrary.h"
#include <iostream>
#include <string>
#include <windows.h>


#define BLACK   "\x1B[30m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1B[37m"
#define ORANGE  "\x1B[38;2;255;128;0m"
#define ROSE    "\x1B[38;2;255;151;203m"
#define LBLUE   "\x1B[38;2;53;149;240m"
#define LGREEN  "\x1B[38;2;17;245;120m"
#define GRAY    "\x1B[38;2;176;174;174m"
#define RESET   "\x1b[0m"


using namespace std;

// Función para mostrar el título
void TDLibrary::TDL::title() {
    cout <<
        "@@@@@@@  @@@@@@  @  @  @   @  @@@@@@       @@@@     @@@@@   @@@  @@@@@  @@@@@@@\n" <<
        "   @     @    @  @ @    @ @   @    @       @    @   @    @   @   @         @  \n" <<
        "   @     @    @  @@      @    @    @       @    @   @@@@     @   @@@       @  \n" <<
        "   @     @    @  @ @     @    @    @       @    @   @  @     @   @         @  \n" <<
        "   @     @@@@@@  @  @    @    @@@@@@       @@@@     @   @   @@@  @         @  \n\n\n";
}

// Función para mostrar la historia/lore
void TDLibrary::TDL::lore() {
    cout <<
        "1. Carrera entre DK con el 350Zy Sean con el S15:\n\n"
        "En esta carrera inicial, el jugador asume el papel de Sean Boswell, un joven corredor estadounidense que llega a Tokio y desafia \n"
        "al lider de la escena de las carreras callejeras, DK(Drift King), interpretado por el personaje Takashi en la pelicula.\n"
        "La carrera se desarrolla por las calles nocturnas de Tokio, con neones resplandecientes y giros peligrosos.\n\n"
        "2. Persecucion donde muere Han :\n\n"
        "La persecucion en la que muere Han es la segunda carrera crucial del juego.\n"
        "Aqui, el jugador se encuentra en una intensa persecucion policial a traves de las calles de Tokio.\n"
        "Debe maniobrar habilmente entre el trafico, evitar los obstaculos y utilizar habilidades de drifting para escapar de la policia.\n"
        "Sin embargo, la trama toma un giro inesperado cuando un coche misterioso embiste el de Han, desencadenando una cadena de eventos que\n"
        " lleva a una confrontacion final.\n\n"
        "3. Carrera final contra el Mustang :\n\n"
        "Despues de varias pruebas y desafios, el jugador se encuentra nuevamente frente a frente con DK en la carrera final.\n"
        "Esta vez, Sean esta al volante de un clasico Ford Mustang.\n"
        "La carrera tiene lugar en una pista de montana serpenteante, con curvas cerradas y precipicios al borde del camino.\n"
        "El jugador debe dominar el arte del drifting para mantenerse al frente y reclamar la victoria.\n\n"
        "Estas tres carreras constituirian los momentos clave del juego, cada una con su propio desafio y emocion.\n"
        "Ademas, se podrian incluir otras caracteristicas del mundo de la pelicula, como la personalizacion de vehiculos, la interaccion con \n"
        "personajes iconicos y la exploracion de los escenarios emblematicos de Tokio.";
        ;
}


