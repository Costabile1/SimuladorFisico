#include <SFML/Graphics.hpp>
#include <math.h>
using namespace std;

class Plano{
    public:
        const double epsilon0 = 8.854*pow(10,-12);
        const float K = 8.99*pow(10,9);
        sf::RectangleShape shape;
        float densidadCarga;
        float offsetX;
        float x_original;
        float x;
        float potencial_ref;
        const float y=0;
        const float ancho=5;
        const float largo=1100;
    public:
        Plano(float densidadCarga,float offsetX,float offsetY, float x_original,float y_original,float x, float y);
        Plano();
        double cacularCampoElectrico();
        double calcularPotencial(int sig);
        void setearPosicion(float x);
        void setearTamaño();
        void draw(sf::RenderWindow &window);
};