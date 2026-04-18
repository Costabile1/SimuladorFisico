#include <SFML/Graphics.hpp>
#include <math.h>
using namespace std;

class Plano{
    public:
        const double epsilon0 = 8.854*pow(10,-12);
        sf::RectangleShape shape;
        float densidadCarga;
        float offsetX,offsetY;
        float x_original,y_original;
        float x,y;
    public:
        Plano(float densidadCarga,float offsetX,float offsetY, float x_original,float y_original,float x, float y);
        Plano();
        double calcularCEPLano();
};