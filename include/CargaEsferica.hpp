#include "Carga.hpp"
#include <SFML/Graphics.hpp>

class CargaEsferica: public Carga{
    public:
        sf::CircleShape shape_int;
        float radio_int;
        static float x_static,y_static;
    public:
        CargaEsferica(float x, float y, float valor, float masa,float radio, float offsetX, float offsetY,float radio_int);
        CargaEsferica();
        void draw(sf::RenderWindow &window);
        void actualizarPosicion(float x, float y);
};