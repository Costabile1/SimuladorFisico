#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include <optional>
#include <math.h>

using namespace std;


class Carga{
    public:
        const float K = 8.99*pow(10,9);
        sf::CircleShape shape;
        float offsetX,offsetY;
        float x_original,y_original;
        float x,y; //posicion actual
        float valor;
        float masa;
        //float aX,aY; //aceleracion
        //float vX,vY; //velocidad
        float radio;
    public:
        Carga(float x, float y, float valor, float masa,float radio, float offsetX, float offsetY);
        Carga();
        virtual void draw(sf::RenderWindow &window);
        virtual void cacularCampoElectrico(sf::Vector2f &campoElectrico,float distanciaTotal, float distanciaX, float distanciaY);
        virtual void calcularPotencial(float &potencial,float distancia);
        virtual void actualizarPosicion(float x, float y); //funcion que tiene en cuenta el radio para corregir el desfase creado por sfml.

};



