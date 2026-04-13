#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include <optional>

using namespace std;


class Carga{
    public:
        sf::CircleShape shape;
        float offsetX,offsetY;
        float x_original,y_original;
        float x,y; //posicion actual
        float valor;
        float masa;
        float aX,aY; //aceleracion
        float vX,vY; //velocidad
        float radio;
    public:
        Carga(float x, float y, float valor, float masa,float radio, float offsetX, float offsetY);
        Carga();
        void draw(sf::RenderWindow &window);
        void update(float fuerzaEX, float fuerzaEY,float fuerzaSX, float fuerzaSY, const float tiempo);
        void actualizarPosicion(float x, float y); //funcion que tiene en cuenta el radio para corregir el desfase creado por sfml.


};

