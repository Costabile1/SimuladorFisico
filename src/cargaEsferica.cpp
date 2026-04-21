#include "CargaEsferica.hpp"
#include <cmath>

float CargaEsferica::x_static = 0;
float CargaEsferica::y_static = 0;

CargaEsferica::CargaEsferica(float x, float y, float valor, float masa, float radio, float offsetX, float offsetY, float radio_int){
    this->offsetX = offsetX;
    this->offsetY = offsetY;
    this->x_original = x;
    this->y_original = y;
    this->x = x_original + this->offsetX; 
    this->y = y_original + this->offsetY;
    this->valor = valor;
    this->radio = radio;
    this->masa = masa;
    this->radio_int = radio_int;

    shape.setRadius(radio);
    shape_int.setRadius(radio_int);
    actualizarPosicion(x,y);

}

CargaEsferica::CargaEsferica(){
    this->offsetX = 0;
    this->offsetY = 0;
    this->x_original = NULL;
    this->y_original = NULL;
    this->x = this->x_original + this->offsetX; 
    this->y = this->y_original + this->offsetY;
    this->valor = 0;
    this->radio = 0;
    this->masa = 0;
    this->radio_int=0;

    shape.setRadius(radio);
    shape_int.setFillColor(sf::Color::Black);
    actualizarPosicion(x,y);
}


void CargaEsferica::actualizarPosicion(float x, float y){
    shape.setPosition({x-this->radio,y-this->radio});
    shape_int.setPosition({x-this->radio_int,y-this->radio_int});
}

void CargaEsferica::draw(sf::RenderWindow &window){
    window.draw(this->shape);
    window.draw(this->shape_int);
    
}