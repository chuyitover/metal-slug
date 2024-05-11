#include <iostream>
#include <thread>
#include <ftxui/screen/screen.hpp>
#include <sstream>
#include "Dibujo.hpp"

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    Screen pantalla = Screen::Create(
        Dimension::Full(),
        Dimension::Full()
    );

    string dibujo_path = "./assets/images/mono.txt";
    Dibujo dibujo(dibujo_path);
    string contenido = dibujo.GetContenido();

   
    istringstream ss(contenido);
    vector<string> lineas;
    string linea;
    while (getline(ss, linea, '\n')) {
        lineas.push_back(linea);
    }
    int dibujo_width = lineas[0].size();
    int dibujo_height = lineas.size();

    int x = 0;

    while (true)
    {
        pantalla.Clear();
        this_thread::sleep_for(100ms);

        
        for (int i = 0; i < dibujo_height; ++i) {
           
            for (int j = 0; j < dibujo_width; ++j) {
            
                int pos_x = (x + j) % dibujo_width;
            
                pantalla.PixelAt(pos_x, i).character = lineas[i][j];
            }
        }

        
        x++;

        pantalla.Print();
        cout << pantalla.ResetPosition();
    }

    return 0;
}