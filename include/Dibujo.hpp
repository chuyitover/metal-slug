
#include <string>
#include <fstream>

using namespace std;

class Dibujo
{
private:
    ifstream archivo;
    string contenido;

public:
    Dibujo(string path)
    {
        archivo.open(path);

        string linea;
        while (getline(archivo, linea))
        {
            contenido += linea + "\n";
        }
        archivo.close();
    }
    
    string GetContenido() const {
        return contenido;
    }
    
    ~Dibujo() {}
};