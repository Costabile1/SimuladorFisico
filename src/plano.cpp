#include "Plano.hpp"
#include <iostream>
Plano::Plano(float densidadCarga,float offsetX,float offsetY, float x_original,float y_original,float x, float y){
    this->densidadCarga = densidadCarga;
    this->offsetX = offsetX;
    this->x_original = x_original;
    this->x = x;

}

Plano::Plano(){
    this->densidadCarga = 0;
    this->offsetX = 0;
    this->x_original = 0;
    this->x = 0;
    this->potencial_ref=0;
}

double Plano::cacularCampoElectrico(){
    return (this->densidadCarga/(2*epsilon0));
}

void Plano::setearPosicion(float x){
    shape.setPosition({x+offsetX,this->y});
}

void Plano::draw(sf::RenderWindow &window){
    window.draw(this->shape);
}
void Plano::setearTamaño(){
    shape.setSize({ancho,largo});
}

double Plano::calcularPotencial(int dist){
    return (-1*(abs(dist))*2*M_1_PI*K*densidadCarga)+ potencial_ref;
}