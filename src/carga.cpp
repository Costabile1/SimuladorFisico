#include "Carga.hpp"
#include <iostream>
#include <chrono>
#include <cmath>



Carga::Carga(float x, float y, float valor, float masa, float radio, float offsetX, float offsetY){
    this->offsetX = offsetX;
    this->offsetY = offsetY;
    this->x_original = x;
    this->y_original = y;
    this->x = x_original + this->offsetX; 
    this->y = y_original + this->offsetY;
    this->valor = valor;
    this->radio = radio;
    this->masa = masa;


    shape.setRadius(radio);
    actualizarPosicion(x,y);

}

Carga::Carga(){
    this->offsetX = 0;
    this->offsetY = 0;
    this->x_original = NULL;
    this->y_original = NULL;
    this->x = this->x_original + this->offsetX; 
    this->y = this->y_original + this->offsetY;
    this->valor = 0;
    this->radio = 0;
    this->masa = 0;


    shape.setRadius(radio);
    actualizarPosicion(x,y);
}


void Carga::draw(sf::RenderWindow &window){

    window.draw(this->shape);
}



void Carga::actualizarPosicion(float x, float y){
    shape.setPosition({x-this->radio,y-this->radio});
}

void Carga::cacularCampoElectrico(sf::Vector2f &campoElectrico,float distanciaTotal, float distanciaX, float distanciaY){
    campoElectrico.x += K*(this->valor/pow(distanciaTotal,2))*distanciaX/distanciaTotal;
    campoElectrico.y += K*(this->valor/pow(distanciaTotal,2))*distanciaY/distanciaTotal;
}

void Carga::calcularPotencial(float &potencial,float distancia){
    potencial = K*((this->valor)/distancia);
}