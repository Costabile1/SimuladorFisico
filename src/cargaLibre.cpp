#include "CargaLibre.hpp"
#include <iostream>
#include <cmath>

CargaLibre::CargaLibre(float x, float y, float valor, float masa, float radio, float offsetX, float offsetY){
    this->offsetX = offsetX;
    this->offsetY = offsetY;
    this->x_original = x;
    this->y_original = y;
    this->x = x_original + this->offsetX; 
    this->y = y_original + this->offsetY;
    this->valor = valor;
    this->radio = radio;
    this->masa = masa;
    this->aX=0;
    this->aY=0;
    this->vX=0;
    this->vY=0;

    shape.setRadius(radio);
    actualizarPosicion(x,y);

}

CargaLibre::CargaLibre(){
    this->offsetX = 0;
    this->offsetY = 0;
    this->x_original = NULL;
    this->y_original = NULL;
    this->x = this->x_original + this->offsetX; 
    this->y = this->y_original + this->offsetY;
    this->valor = 0;
    this->radio = 0;
    this->masa = 0;
    this->aX=0;
    this->aY=0;
    this->vX=0;
    this->vY=0;

    shape.setRadius(radio);
    actualizarPosicion(x,y);
}

void CargaLibre::update(float fuerzaEX, float fuerzaEY, const float tiempo){
    float nuevox,nuevoy;

    float fuerzaTotalX = fuerzaEX;
    float fuerzaTotalY = fuerzaEY;

    //std::cout<<"fuerzas"<<fuerzaTotalX<<","<<fuerzaTotalY<<std::endl;


    float aceleracionX = fuerzaTotalX/masa;
    float aceleracionY = fuerzaTotalY/masa;

    this->aX = aceleracionX;
    this->aY = aceleracionY;
    


    nuevox = x + vX*(tiempo) + (0.5)*aX*pow(tiempo,2);
    nuevoy = y + vY*(tiempo) + (0.5)*aY*pow(tiempo,2);

    this->vX = vX + aX*tiempo;
    this->vY = vY + aY*tiempo;
    

    this->x = nuevox;
    this->y = nuevoy;
    actualizarPosicion(x,y);
}
