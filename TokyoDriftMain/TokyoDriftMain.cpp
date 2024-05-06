//TokyoDriftMain.cpp

#include "TokyoDriftLibrary.h"
#include "TokyoDriftClass.h"
#include <iostream>
#include <windows.h>
#include <random>


//colors
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

//Variables
int option;
int race;
int turno = 0;
string nirtoSN;



int main()
{

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 6);
    uniform_int_distribution<int> dat(1, 2);
    int randNum = dis(gen);
    int randNum12 = dat(gen);

    TDClassCharacters character1;
    TDClassCharacters character2;
    TDClassCharacters character3;
    character1.setBuilder(0, 0, 1, "Sean");
    character2.setBuilder(0, 0, 1, "D.K");
    character3.setBuilder(0, 0, 1, "Han");

    TDClassCarStats car1;
    TDClassCarStats car2;
    TDClassCarStats car3;
    TDClassCarStats car4;
    TDClassCarStats car5;
    car1.setBuilder("Nissan", "Silvia S15", 350, 249, "SR20DET");
    car2.setBuilder("Nissan", "350Z", 350, 249, "VQ35DE");
    car3.setBuilder("Ford", "Mustang", 350, 249, "SR20DET");
    car4.setBuilder("Mazda", "RX-7 FD", 350, 257, "Motor rotativo Wankel de dos rotores");
    car5.setBuilder("Mitsubishi", "Lancer Evolution", 350, 250, "4G63T");







    TDLibrary::TDL::title();
    Sleep(2000);


    cout << "Menu: ";
    cout << "\n1. Carrera \n2. Estadisticas de los coches \n3. Lore\n\nOpcion: ";
    cin >> option;
    system("CLS");
    TDLibrary::TDL::title();
    switch (option)
    {
    case 1:
        cout << "Estas carreras funcionan de la siguiente manera, tendreis 5 turnos para tirar los dados del 1 al 6 y el \nnumero que saqueis sera la velocidad que incrementara tu coche y el mas rapido en 5 turnos ganara.\n\nTienes la opcion de usar un nitro que tienes 50% de posibilidades de multiplicar tu velocidad por dos y \n50% de dividirla entre 2\n\n\n";
        cout << "\n\n";
        cout << "Elige una carrera:\n";
        cout << "1. Carrera entre DK con el 350Z y Sean con el S15\n";
        cout << "2. Persecucion de D.K con el 350Z contra Han con el RX-7 y Sean con el Mitsubishi Evo \n";
        cout << "3. Carrera final de D.K con el 350Z contra Sean con el Mustang\n";
        cin >> race;
        system("CLS");
        TDLibrary::TDL::title();
        switch (race)
        {
        case 1:
            cout << "Esta carrera es entre tu(Sean) con el S15 de Han y D.K con su 350z\nEsta carrera es la primera que hace Sean en japon y en la que destroza el S15 de Han\n\n";
            Sleep(3000);
            do
            {
                if (turno >= 1)
                {
                    system("CLS");
                    TDLibrary::TDL::title();
                    cout << "Sean:\n";
                    cout << "Velocidad: " << LGREEN << character1.getSpeed() << "km/h\n" << RESET;
                    cout << "Distancia recorrida: " << LGREEN << character1.getDistance() << "m\n\n" << RESET;
                    cout << "D.K:\n";
                    cout << "Velocidad: " << LGREEN << character2.getSpeed() << "km/h\n" << RESET;
                    cout << "Distancia recorrida: " << LGREEN << character2.getDistance() << "m\n\n\n\n" << RESET;
                    Sleep(1000);
                }

                turno = turno + 1;
                cout << "Es turno de Sean \n";
                randNum = dis(gen);
                character1.updateSpeed(randNum);
                cout << "Tu velocidad es ahora de " << LGREEN << character1.getSpeed() << "km/h\n\n" << RESET;
                Sleep(1000);
                if (character1.getNitro() != 0)
                {
                    cout << "Quieres usar el nitro(s/n)?\nNitros disponibles = " << LGREEN << character1.getNitro() << "\n" << RESET;
                    cin >> nirtoSN;
                    if (nirtoSN == "s")
                    {
                        character1.setNitro(0);
                        randNum = dat(gen);
                        if (randNum == 2)
                        {
                            character1.updateSpeed(character1.getSpeed());
                            cout << "El nitro ha funcionado correctamente\n\n";
                        }
                        else if (randNum == 1)
                        {
                            int halfvel = character1.getSpeed() / 2;
                            character1.decreaseSpeed(halfvel);
                            cout << "El nitro ha fallado\n";
                            cout << "Tu velocidad es ahora de " << LGREEN << character1.getSpeed() << "km/h\n\n" << RESET;
                        }


                        cout << character1.getSpeed() << "Km/h\n\n";
                        cout << "Ya no te quedan mas nitros\n\n\n";
                    }
                    else if (nirtoSN == "n")
                    {
                        cout << "Recuerda usarlo antes de que acaben tus turnos\n\n";
                    }
                    else
                    {
                        cout << "Esa no es una opcion";
                        return 0;
                    }
                    Sleep(1000);


                }


                Sleep(1000);

                cout << "Es turno de D.K \n";
                randNum = dis(gen);
                character2.updateSpeed(randNum);
                cout << "La velocidad de D.K es de " << LGREEN << character2.getSpeed() << "Km/h\n\n\n" << RESET;
                Sleep(1000);
                if (turno == 5 && character2.getSpeed() < character1.getSpeed())
                {
                    cout << "D.K ha usado el nitro para intentar atraparte\nn";
                    randNum = dis(gen);
                    character2.updateSpeed(randNum);
                    cout << "La velocidad de D.K es de " << LGREEN << character2.getSpeed() << "Km/h\n\n\n" << RESET;
                }
                character1.updateDistance(character1.getSpeed() * 100);
                character2.updateDistance(character2.getSpeed() * 100);
            } while (turno < 5);

            if (character1.getDistance() > character2.getDistance())
            {
                system("CLS");
                TDLibrary::TDL::title();
                cout << "Sean:\n";
                cout << "Velocidad: " << LGREEN << character1.getSpeed() << "km/h\n" << RESET;
                cout << "Distancia recorrida: " << LGREEN << character1.getDistance() << "m\n\n" << RESET;
                cout << "D.K:\n";
                cout << "Velocidad: " << LGREEN << character2.getSpeed() << "km/h\n" << RESET;
                cout << "Distancia recorrida: " << LGREEN << character2.getDistance() << "m\n\n\n\n" << RESET;
                Sleep(1000);
                cout << LGREEN << "Ha ganado Sean" << RESET;
                Sleep(4000);

            }
            else if (character1.getDistance() < character2.getDistance())
            {
                system("CLS");
                TDLibrary::TDL::title();
                cout << "Sean:\n";
                cout << "Velocidad: " << LGREEN << character1.getSpeed() << "km/h\n" << RESET;
                cout << "Distancia recorrida: " << LGREEN << character1.getDistance() << "m\n\n" << RESET;
                cout << "D.K:\n";
                cout << "Velocidad: " << LGREEN << character2.getSpeed() << "km/h\n" << RESET;
                cout << "Distancia recorrida: " << LGREEN << character2.getDistance() << "m\n\n\n\n" << RESET;
                Sleep(1000);
                cout << RED << "Ha ganado D.K" << RESET;
                Sleep(4000);

            }
            else if (character1.getDistance() == character2.getDistance())
            {
                system("CLS");
                TDLibrary::TDL::title();
                cout << "Sean:\n";
                cout << "Velocidad: " << LGREEN << character1.getSpeed() << "km/h\n" << RESET;
                cout << "Distancia recorrida: " << LGREEN << character1.getDistance() << "m\n\n" << RESET;
                cout << "D.K:\n";
                cout << "Velocidad: " << LGREEN << character2.getSpeed() << "km/h\n" << RESET;
                cout << "Distancia recorrida: " << LGREEN << character2.getDistance() << "m\n\n\n\n" << RESET;
                Sleep(1000);
                cout << LGREEN << "Ha sido empate" << RESET;
                Sleep(4000);

            }


            break;
        case 2:
            cout << "Esta carrera es entre tu(Sean) con el Lancer EVO de Han, Han con su rx-7 y D.K con su 350z\nEn esta carrera es en la que Han muere\n\n";
            Sleep(3000);
            do
            {
                if (turno >= 1)
                {
                    system("CLS");
                    TDLibrary::TDL::title();
                    cout << "Sean:\n";
                    cout << "Velocidad: " << LGREEN << character1.getSpeed() << "km/h\n" << RESET;
                    cout << "Distancia recorrida: " << LGREEN << character1.getDistance() << "m\n\n" << RESET;
                    cout << "Han:\n";
                    cout << "Velocidad: " << LGREEN << character3.getSpeed() << "km/h\n" << RESET;
                    cout << "Distancia recorrida: " << LGREEN << character3.getDistance() << "m\n\n\n\n" << RESET;
                    cout << "D.K:\n";
                    cout << "Velocidad: " << LGREEN << character2.getSpeed() << "km/h\n" << RESET;
                    cout << "Distancia recorrida: " << LGREEN << character2.getDistance() << "m\n\n\n\n" << RESET;
                    Sleep(1000);
                }

                turno = turno + 1;
                cout << "Es turno de Sean \n";
                randNum = dis(gen);
                character1.updateSpeed(randNum);
                cout << "Tu velocidad es ahora de " << LGREEN << character1.getSpeed() << "km/h\n\n" << RESET;
                Sleep(1000);
                if (character1.getNitro() != 0)
                {
                    cout << "Quieres usar el nitro(s/n)?\nNitros disponibles = " << LGREEN << character1.getNitro() << "\n" << RESET;
                    cin >> nirtoSN;
                    if (nirtoSN == "s")
                    {
                        character1.setNitro(0);
                        randNum = dat(gen);
                        if (randNum == 2)
                        {
                            character1.updateSpeed(character1.getSpeed());
                            cout << "El nitro ha funcionado correctamente\n\n";
                        }
                        else if (randNum == 1)
                        {
                            int halfvel = character1.getSpeed() / 2;
                            character1.decreaseSpeed(halfvel);
                            cout << "El nitro ha fallado\n";
                            cout << "Tu velocidad es ahora de " << LGREEN << character1.getSpeed() << "km/h\n\n" << RESET;
                        }


                        cout << character1.getSpeed() << "Km/h\n\n";
                        cout << "Ya no te quedan mas nitros\n\n\n";
                    }
                    else if (nirtoSN == "n")
                    {
                        cout << "Recuerda usarlo antes de que acaben tus turnos\n\n";
                    }
                    else
                    {
                        cout << "Esa no es una opcion";
                        return 0;
                    }
                    Sleep(1000);
                }


                Sleep(1000);

                cout << "Es turno de Han \n";
                randNum = dis(gen);
                character3.updateSpeed(randNum);
                cout << "La velocidad de Han es de " << LGREEN << character3.getSpeed() << "Km/h\n\n\n" << RESET;
                Sleep(1000);
                if (turno == 5 && character3.getSpeed() < character1.getSpeed())
                {
                    cout << "Han ha usado el nitro para intentar atraparte\nn";
                    randNum = dis(gen);
                    character3.updateSpeed(randNum);
                    cout << "La velocidad de Han es de " << LGREEN << character3.getSpeed() << "Km/h\n\n\n" << RESET;
                }


                cout << "Es turno de D.K \n";
                randNum = dis(gen);
                character2.updateSpeed(randNum);
                cout << "La velocidad de D.K es de " << LGREEN << character2.getSpeed() << "Km/h\n\n\n" << RESET;
                Sleep(1000);
                if (turno == 5 && character2.getSpeed() < character1.getSpeed())
                {
                    cout << "D.K ha usado el nitro para intentar atraparte\nn";
                    randNum = dis(gen);
                    character2.updateSpeed(randNum);
                    cout << "La velocidad de D.K es de " << LGREEN << character2.getSpeed() << "Km/h\n\n\n" << RESET;
                }
                character1.updateDistance(character1.getSpeed() * 100);
                character2.updateDistance(character2.getSpeed() * 100);
                character2.updateDistance(character3.getSpeed() * 100);
            } while (turno < 5);

            if (character1.getDistance() > character2.getDistance() || character3.getDistance())
            {
                system("CLS");
                TDLibrary::TDL::title();
                cout << "Sean:\n";
                cout << "Velocidad: " << LGREEN << character1.getSpeed() << "km/h\n" << RESET;
                cout << "Distancia recorrida: " << LGREEN << character1.getDistance() << "m\n\n" << RESET;
                cout << "Han:\n";
                cout << "Velocidad: " << LGREEN << character3.getSpeed() << "km/h\n" << RESET;
                cout << "Distancia recorrida: " << LGREEN << character3.getDistance() << "m\n\n\n\n" << RESET;
                cout << "D.K:\n";
                cout << "Velocidad: " << LGREEN << character2.getSpeed() << "km/h\n" << RESET;
                cout << "Distancia recorrida: " << LGREEN << character2.getDistance() << "m\n\n\n\n" << RESET;
                Sleep(1000);
                cout << LGREEN << "Ha ganado Sean" << RESET;
                Sleep(4000);

            }
            else if (character2.getDistance() > character1.getDistance() || character3.getDistance())
            {
                system("CLS");
                TDLibrary::TDL::title();
                cout << "Sean:\n";
                cout << "Velocidad: " << LGREEN << character1.getSpeed() << "km/h\n" << RESET;
                cout << "Distancia recorrida: " << LGREEN << character1.getDistance() << "m\n\n" << RESET;
                cout << "Han:\n";
                cout << "Velocidad: " << LGREEN << character3.getSpeed() << "km/h\n" << RESET;
                cout << "Distancia recorrida: " << LGREEN << character3.getDistance() << "m\n\n\n\n" << RESET;
                cout << "D.K:\n";
                cout << "Velocidad: " << LGREEN << character2.getSpeed() << "km/h\n" << RESET;
                cout << "Distancia recorrida: " << LGREEN << character2.getDistance() << "m\n\n\n\n" << RESET;
                Sleep(1000);
                cout << RED << "Ha ganado D.K" << RESET;
                Sleep(4000);

            }
            else if (character3.getDistance() > character1.getDistance() || character2.getDistance())
            {
                system("CLS");
                TDLibrary::TDL::title();
                cout << "Sean:\n";
                cout << "Velocidad: " << LGREEN << character1.getSpeed() << "km/h\n" << RESET;
                cout << "Distancia recorrida: " << LGREEN << character1.getDistance() << "m\n\n" << RESET;
                cout << "Han:\n";
                cout << "Velocidad: " << LGREEN << character3.getSpeed() << "km/h\n" << RESET;
                cout << "Distancia recorrida: " << LGREEN << character3.getDistance() << "m\n\n\n\n" << RESET;
                cout << "D.K:\n";
                cout << "Velocidad: " << LGREEN << character2.getSpeed() << "km/h\n" << RESET;
                cout << "Distancia recorrida: " << LGREEN << character2.getDistance() << "m\n\n\n\n" << RESET;
                Sleep(1000);
                cout << RED << "Ha ganado D.K" << RESET;
                Sleep(4000);

            }
            else if (character1.getDistance() == character2.getDistance())
            {
                system("CLS");
                TDLibrary::TDL::title();
                cout << "Sean:\n";
                cout << "Velocidad: " << LGREEN << character1.getSpeed() << "km/h\n" << RESET;
                cout << "Distancia recorrida: " << LGREEN << character1.getDistance() << "m\n\n" << RESET;
                cout << "Han:\n";
                cout << "Velocidad: " << LGREEN << character3.getSpeed() << "km/h\n" << RESET;
                cout << "Distancia recorrida: " << LGREEN << character3.getDistance() << "m\n\n\n\n" << RESET;
                cout << "D.K:\n";
                cout << "Velocidad: " << LGREEN << character2.getSpeed() << "km/h\n" << RESET;
                cout << "Distancia recorrida: " << LGREEN << character2.getDistance() << "m\n\n\n\n" << RESET;
                Sleep(1000);
                cout << LGREEN << "Ha sido empate" << RESET;
                Sleep(4000);

            }

            break;
        case 3:
            cout << "Esta carrera es entre tu(Sean) con el S15 de Han y D.K con su 350z\nEsta carrera es la ultima carrera de la pelicula, donde se decide quien se queda en la ciudad y quien se va\n\n";
            Sleep(3000);
            do
            {
                if (turno >= 1)
                {
                    system("CLS");
                    TDLibrary::TDL::title();
                    cout << "Sean:\n";
                    cout << "Velocidad: " << LGREEN << character1.getSpeed() << "km/h\n" << RESET;
                    cout << "Distancia recorrida: " << LGREEN << character1.getDistance() << "m\n\n" << RESET;
                    cout << "D.K:\n";
                    cout << "Velocidad: " << LGREEN << character2.getSpeed() << "km/h\n" << RESET;
                    cout << "Distancia recorrida: " << LGREEN << character2.getDistance() << "m\n\n\n\n" << RESET;
                    Sleep(1000);
                }

                turno = turno + 1;
                cout << "Es turno de Sean \n";
                randNum = dis(gen);
                character1.updateSpeed(randNum);
                cout << "Tu velocidad es ahora de " << LGREEN << character1.getSpeed() << "km/h\n\n" << RESET;
                Sleep(1000);
                if (character1.getNitro() != 0)
                {
                    cout << "Quieres usar el nitro(s/n)?\nNitros disponibles = " << LGREEN << character1.getNitro() << "\n" << RESET;
                    cin >> nirtoSN;
                    if (nirtoSN == "s")
                    {
                        character1.setNitro(0);
                        randNum = dat(gen);
                        if (randNum == 2)
                        {
                            character1.updateSpeed(character1.getSpeed());
                            cout << "El nitro ha funcionado correctamente\n\n";
                        }
                        else if (randNum == 1)
                        {
                            int halfvel = character1.getSpeed() / 2;
                            character1.decreaseSpeed(halfvel);
                            cout << "El nitro ha fallado\n";
                            cout << "Tu velocidad es ahora de " << LGREEN << character1.getSpeed() << "km/h\n\n" << RESET;
                        }


                        cout << character1.getSpeed() << "Km/h\n\n";
                        cout << "Ya no te quedan mas nitros\n\n\n";
                    }
                    else if (nirtoSN == "n")
                    {
                        cout << "Recuerda usarlo antes de que acaben tus turnos\n\n";
                    }
                    else
                    {
                        cout << "Esa no es una opcion";
                        return 0;
                    }
                    Sleep(1000);


                }


                Sleep(1000);

                cout << "Es turno de D.K \n";
                randNum = dis(gen);
                character2.updateSpeed(randNum);
                cout << "La velocidad de D.K es de " << LGREEN << character2.getSpeed() << "Km/h\n\n\n" << RESET;
                Sleep(1000);
                if (turno == 5 && character2.getSpeed() < character1.getSpeed())
                {
                    cout << "D.K ha usado el nitro para intentar atraparte\nn";
                    randNum = dis(gen);
                    character2.updateSpeed(randNum);
                    cout << "La velocidad de D.K es de " << LGREEN << character2.getSpeed() << "Km/h\n\n\n" << RESET;
                }
                character1.updateDistance(character1.getSpeed() * 100);
                character2.updateDistance(character2.getSpeed() * 100);
            } while (turno < 5);

            if (character1.getDistance() > character2.getDistance())
            {
                system("CLS");
                TDLibrary::TDL::title();
                cout << "Sean:\n";
                cout << "Velocidad: " << LGREEN << character1.getSpeed() << "km/h\n" << RESET;
                cout << "Distancia recorrida: " << LGREEN << character1.getDistance() << "m\n\n" << RESET;
                cout << "D.K:\n";
                cout << "Velocidad: " << LGREEN << character2.getSpeed() << "km/h\n" << RESET;
                cout << "Distancia recorrida: " << LGREEN << character2.getDistance() << "m\n\n\n\n" << RESET;
                Sleep(1000);
                cout << LGREEN << "Ha ganado Sean" << RESET;
                Sleep(4000);

            }
            else if (character1.getDistance() < character2.getDistance())
            {
                system("CLS");
                TDLibrary::TDL::title();
                cout << "Sean:\n";
                cout << "Velocidad: " << LGREEN << character1.getSpeed() << "km/h\n" << RESET;
                cout << "Distancia recorrida: " << LGREEN << character1.getDistance() << "m\n\n" << RESET;
                cout << "D.K:\n";
                cout << "Velocidad: " << LGREEN << character2.getSpeed() << "km/h\n" << RESET;
                cout << "Distancia recorrida: " << LGREEN << character2.getDistance() << "m\n\n\n\n" << RESET;
                Sleep(1000);
                cout << RED << "Ha ganado D.K" << RESET;
                Sleep(4000);

            }
            else if (character1.getDistance() == character2.getDistance())
            {
                system("CLS");
                TDLibrary::TDL::title();
                cout << "Sean:\n";
                cout << "Velocidad: " << LGREEN << character1.getSpeed() << "km/h\n" << RESET;
                cout << "Distancia recorrida: " << LGREEN << character1.getDistance() << "m\n\n" << RESET;
                cout << "D.K:\n";
                cout << "Velocidad: " << LGREEN << character2.getSpeed() << "km/h\n" << RESET;
                cout << "Distancia recorrida: " << LGREEN << character2.getDistance() << "m\n\n\n\n" << RESET;
                Sleep(1000);
                cout << LGREEN << "Ha sido empate" << RESET;
                Sleep(4000);

            }

            break;
        }
        break;

    case 2:

        while (true)
        {
            int option;
            cout << "Seleccione el coche del que desea ver las estadisticas:\n";
            cout << "1. Nissan Silvia S15\n";
            cout << "2. Nissan 350Z\n";
            cout << "3. Ford Mustang\n";
            cout << "4. Mazda RX-7 FD\n";
            cout << "5. Mitsubishi Lancer Evolution\n";
            cout << "6. Salir del codigo\n";
            cin >> option;
            // Mostrar estadísticas según la opción seleccionada
            switch (option) {
            case 1:
                car1.getStats();
                break;
            case 2:
                car2.getStats();
                break;
            case 3:
                car3.getStats();
                break;
            case 4:
                car4.getStats();
                break;
            case 5:
                car5.getStats();
                break;
            case 6:
                return 0;
                break;
            }
            Sleep(2000);
            cout << "\n\n\n\n";
        }
        cout << "\n\n";
        break;

    case 3:
        TDLibrary::TDL::lore();
        break;
    }
}