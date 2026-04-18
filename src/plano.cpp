#include "Plano.hpp"

Plano::Plano(float densidadCarga,float offsetX,float offsetY, float x_original,float y_original,float x, float y){
    this->densidadCarga = densidadCarga;
    this->offsetX = offsetX;
    this->offsetY = offsetY;
    this->x_original = x_original;
    this->y_original = y_original;
    this->x = x;
    this->y=y;
}

Plano::Plano(){
    this->densidadCarga = 0;
    this->offsetX = 0;
    this->offsetY = 0;
    this->x_original = 0;
    this->y_original = 0;
    this->x = 0;
    this->y=0;
}

double Plano::calcularCEPLano(){
    return (this->densidadCarga/(2*epsilon0));
}