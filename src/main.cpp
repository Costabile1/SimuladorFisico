#include <SFML/Graphics.hpp>
#include "Carga.hpp"
#include "CargaLibre.hpp"
#include "Plano.hpp"
#include "CargaEsferica.hpp"
#include <typeinfo>
#include <iostream>
#include <string>
#include <cmath>
#include <optional>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include "imgui.h"
#include "imgui-SFML.h"

//funciones auxilares
float calcularDistancia(float x1, float y1, float x2, float y2);
float calcularDistanciaX(float x1, float x2);
float calcularDistanciaY(float y1, float y2);


//funciones para las Esferas
void organizadorCEEsferaConductora(sf::RenderWindow &window);
void gestiondibujarCargas(sf::RenderWindow &window,float cargaInterior, float cargaExterior, int n_esfera);
void dibujarCargasNegativas(sf::RenderWindow &window,float radio,int i, int cant=50);
void dibujarCargasPositivas(sf::RenderWindow &window,float radio, int i,int cant=50);
//funciones PLano
void planoConfi(int i);

//funciones relacionadas con el movmiento y fuerzas
void calculoFuerzas(sf::VertexArray* vectorFuerza,sf::VertexArray *vectorVelocidad);
void verificarColisiones();
void calcularVectorFuerza(sf::VertexArray* vectorFuerza,float fuerzaX, float fuerzaY, Carga* carga);
void calcularVectorVelocidad(sf::VertexArray* vectorVelocidad,float velocidadX, float velocidadY, Carga* carga);
//funciones calculo de potencial
void calcularPotencialElectrico(sf::Vector2f posCal, float &potencial);
std::vector<std::vector<float>> potencialElectrico();
sf::Texture drawPotencialHeatMap(sf::Texture &textura);
std::map<float,std::string> mapaPotencialElectrico(std::vector<std::vector<float>> potenciales);
//funciones calculo de campoElectrico
void calcularCampoElectricoEnPunto(sf::Vector2f posCal,sf::Vector2f &campoElectrico);
void drawVectoresCE(sf::RenderWindow &window,std::vector<std::vector<sf::Vector2f>> *vectorCE);
void calcularCampoElectrico(std::vector<std::vector<sf::Vector2f>> *vectorCE,std::vector<std::vector<sf::Vector2f>> &vectorCEPlano);
void escalarVector(sf::VertexArray &vector);
std::vector<std::vector<sf::Vector2f>> calcularCEPlano();
//funciones Auxiliares para colores
std::string rgbToHex(int* rgb);
string decimalAHexadecimal(int decimal);
char getHex(int n);
int getnum(char c);
void hexTorgb(std::string hexa, int rgb[3]);
//funciones confi de vetana
bool VentanaConfi();
void representarEjECartesiano(sf::VertexArray *ejeX,sf::VertexArray *ejeY,sf::Vector2f origen);
void cargasConfi(int i);
void actualizarPosSegunOffset();
void cargaLibreConfi();
void manejoProgramaCorriendo(bool &cambio);
void manejoProgramaPausado(bool &cambio);
void manejoProgramaDetendio(bool &cambio);
void mostrarDatosCargaLibre();
void puntoEstudioConfi();
void gestionCargasFijas();
void gestionPlanos();
void gestionCargasLigadasEsfera();
void gestionCargasEsfericas();
void esferaConfi(int i, int id);

//funciones para la puntoEstudio:
void calcularCEPE();
void calcularPEPE();
void drawVectorCEPE(sf::RenderWindow &window);
const float K = 8.99*pow(10,9);
const int _ANCHO=1900,_LARGO=1000;
const int cant_cuadriculasX = 50;
const int cant_cuadriculasY = 50;
const sf::Vector2i cant_cuadriculas(cant_cuadriculasX,cant_cuadriculasY);
float tiempo=1.0; // constante que indica cada cuantos segundos actualizo la ventana
const sf::Color _color_cargaFija(0,0,255);
const sf::Color _color_cargaLibre(255,247,0);

Carga *cargaEstudio = new Carga();
std::vector<Carga*> cargasFijas;
std::vector<CargaLibre*> cargasLibres = {new CargaLibre()};
std::vector<Plano*> planos;
std::vector<CargaEsferica*> esferas;


//variables configurables
float factorEscala=1.0;
float nivelPresicion = 1*pow(10,-12);
float origenX=0;
float origenY=0;
int cantCargasFijas=0;
const int cantCargasLibres=1;
int cantidadPlanos=0;
int cantidadCargasEsfericas=0;
bool mostrarVectorVelocidad=false;
bool mostrarVectorFuerza=false;
bool mostrarMapaPotencial=false;
bool programaPausado=false;
bool programaDetenido=true;
bool cerrarPrograma=false;
bool mostrarEjeCordenado=false;
bool mostrarCampoELectrico=false;
bool mostrarCEconEsferas=false;
bool mostrarDatosPuntoEstudio=false;
bool PonerCargaFijaCentro=false;
sf::Vector2f vectorPosicionDeEstudio(0,0);
sf::Vector2f campoElectricoPuntoEstudio(0,0);
float potencialPuntoEstudio=0;
sf::VertexArray vectorFuerza(sf::PrimitiveType::LineStrip, 2);
sf::VertexArray vectorVelocidad(sf::PrimitiveType::LineStrip, 2);
sf::VertexArray ejeX(sf::PrimitiveType::LineStrip, 2);
sf::VertexArray ejeY(sf::PrimitiveType::LineStrip, 2);

int primera = 1;

int main(){
    // Crea la ventana principal

    sf::RenderWindow window(sf::VideoMode({_ANCHO, _LARGO}), "MLyM Simulador Fisico!");
    ImGui::SFML::Init(window);
    //limita los fps
    window.setFramerateLimit(60);


    //bluce sencuario o de seteo
    while(true){

        //crea la textura del gradiente de potencial
        sf::Texture texture;
        if(mostrarMapaPotencial){
            texture = drawPotencialHeatMap(texture);
        }
        sf::Sprite fondo(texture);
  
        //calcula el campo electrico
        std::vector<std::vector<sf::Vector2f>> vectorCE;
        std::vector<std::vector<sf::Vector2f>> vectorePlano;
        void *p_vectorCE;
        if(mostrarCampoELectrico){
            if(cantidadPlanos!=0){
                vectorePlano = calcularCEPlano();
            }
            if(cargasFijas.size()==0){
                p_vectorCE = &vectorePlano;
            }else{
                calcularCampoElectrico(&vectorCE,vectorePlano);
                p_vectorCE=&vectorCE;
            }
        }
        //LOOP PRINCIPAL
      
        sf::Clock clock;
        while (window.isOpen())
        {
            while (const std::optional event = window.pollEvent()) //pollEvento ejecuta los procesos en cola, sino devuevle null
            {
                ImGui::SFML::ProcessEvent(window, *event);
                if (event->is<sf::Event::Closed>()) //verifica si en el evento es de cierre
                    window.close();
            }

            ImGui::SFML::Update(window, clock.restart());

            //dibujamos primero esto para que todo este por encima
            

            if(VentanaConfi()){
                //salimos del while para cambiar los datos e iniciar otra vez la simulacion
                break;
            }
            
          
           
            if(mostrarEjeCordenado && origenX!=0 && origenY!=0){
               
                representarEjECartesiano(&ejeX,&ejeY,sf::Vector2f(origenX,origenY));  
            }
            
            
            //se genera el movimeinto y se hace la simulacion
            if(!programaPausado && !programaDetenido){
                calculoFuerzas(&vectorFuerza,&vectorVelocidad);
                verificarColisiones();
            }
 
            window.clear();
            for(int i=0;i<cantidadCargasEsfericas;i++){
                esferas[i]->draw(window);
                if(!mostrarCEconEsferas){
                    if(esferas[i]->valor>0){
                        dibujarCargasPositivas(window,esferas[i]->radio,i);
                    } else if(esferas[i]->valor<0){
                        dibujarCargasNegativas(window,esferas[i]->radio,i);
                    }
                }
                
            }
            if(mostrarEjeCordenado){
                window.draw(ejeX);
                window.draw(ejeY);
            }
            
            if(mostrarCampoELectrico){
                drawVectoresCE(window,(std::vector<std::vector<sf::Vector2f>> *)p_vectorCE);
            }
            
            window.draw(fondo);

            for(int i=0;i<cantCargasFijas;i++){
                (*(cargasFijas)[i]).draw(window);
            }
            for(int i=0;i<cantCargasLibres;i++){
                (*(cargasLibres[i])).draw(window);
            }
            for(int i=0;i<cantidadPlanos;i++){
                planos[i]->draw(window);
            }
            
            if(cantidadCargasEsfericas!=0 && mostrarCEconEsferas){
                organizadorCEEsferaConductora(window);
            }
            
            if(mostrarDatosPuntoEstudio){
                cargaEstudio->draw(window);
                calcularCEPE();
                calcularPEPE();
                drawVectorCEPE(window);
            }

            window.draw(vectorFuerza);
            window.draw(vectorVelocidad);

            ImGui::SFML::Render(window);
            window.display();
            
        }
        ImGui::SFML::Render(window);
        window.display();
        if(cerrarPrograma){
            break;
        }
    }
    ImGui::SFML::Shutdown();
    return 0;
}



float calcularDistancia(float x1, float y1, float x2, float y2){
    float distancia = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    return distancia;
}

float calcularDistanciaX(float x1, float x2){
    float distancia = x2-x1;
    return distancia;
}

float calcularDistanciaY(float y1, float y2){
    float distancia = y2-y1;
    return distancia;
}


void calculoFuerzas(sf::VertexArray* vectorFuerza,sf::VertexArray* vectorVelocidad){

    float distanciaTotal,distanciaX,distanciaY;
    
    float fuerzaX,fuerzaY;
    for(int i=0;i<cantCargasLibres && cargasLibres[i]->x!=NULL && cargasLibres[i]->y!=NULL;i++){
        sf::Vector2f campoElectrico(0,0);
        float CEPlano=0;
        ///PLANOS
        for(int k=0;k<cantidadPlanos;k++){
            float dist = ((cargasLibres[i]->x)-(planos[k]->x_original*factorEscala+planos[k]->offsetX))/factorEscala;
            float sig = dist/std::abs(dist);
            if(std::abs(sig)!=1){
                std::cout<<"NO di uno"<<std::endl;
            }
            CEPlano += planos[k]->cacularCampoElectrico()*sig;
        }
        //CARGAAS PUNTUALES
        for(int j=0;j<cantCargasFijas && cargasFijas[j]->x!=NULL && cargasFijas[j]->y!=NULL ;j++){
            
            distanciaTotal = calcularDistancia(cargasLibres[i]->x,cargasLibres[i]->y,cargasFijas[j]->x,cargasFijas[j]->y)/factorEscala;
            distanciaX = calcularDistanciaX(cargasFijas[j]->x,cargasLibres[i]->x)/factorEscala;
            distanciaY = calcularDistanciaY(cargasFijas[j]->y,cargasLibres[i]->y)/factorEscala;
            (*(cargasFijas[j])).cacularCampoElectrico(campoElectrico,distanciaTotal,distanciaX,distanciaY);

        }
        //sumamos el campo de generado por los planos:
        campoElectrico.x += CEPlano;
        //calculo componentes fuerza
        fuerzaX = campoElectrico.x*cargasLibres[i]->valor;
        fuerzaY = campoElectrico.y*cargasLibres[i]->valor;
        if(mostrarVectorFuerza){
            calcularVectorFuerza(vectorFuerza,fuerzaX,fuerzaY,cargasLibres[i]);
        }
        if(mostrarVectorVelocidad){
            calcularVectorVelocidad(vectorVelocidad,(*(cargasLibres[i])).vX,(*(cargasLibres[i])).vY,cargasLibres[i]);
        }
        (*(cargasLibres[i])).update(fuerzaX,fuerzaY,tiempo);
        
    }
}

void verificarColisiones(){
    float distancia,sumaradios;
    for(int i=0;i<cantCargasLibres;i++){
        for(int j=0;j<cantCargasFijas;j++){
            distancia = calcularDistancia(cargasFijas[j]->x,cargasFijas[j]->y,cargasLibres[i]->x,cargasLibres[i]->y);
            sumaradios=cargasFijas[j]->radio+cargasLibres[i]->radio;
            if(distancia<sumaradios){
                //hay conolision
                std::cout<<"hay colision"<<std::endl;
                
                cargasLibres[i]->x = 10.f;
                cargasLibres[i]->y = 10.f;
                cargasLibres[i]->shape.setPosition({cargasLibres[i]->x,cargasLibres[i]->y});
                (*(cargasLibres[i])).aX = 0;
                (*(cargasLibres[i])).aY = 0;

                programaDetenido=true;
            }
        }
        for(int k=0;k<cantidadPlanos;k++){
            distancia=cargasLibres[i]->x-(planos[k]->x_original*factorEscala+planos[k]->offsetX);
            if(std::abs(distancia)<cargasLibres[i]->radio){
                std::cout<<"hay colision"<<std::endl;
                (*(cargasLibres[i])).aX = 0;
                (*(cargasLibres[i])).aY = 0;
                programaDetenido=true;
                std::cout<<"Velocidad Final enX= "<<cargasLibres[i]->vX<<std::endl;
                std::cout<<"Velocidad Final enY= "<<cargasLibres[i]->vY<<std::endl;
            }
        }   
    }
    
}

std::vector<std::vector<float>> potencialElectrico(){
    /****Objetivo de la funcion
     * dividir la ventana total en n cuadriculas
     * en cada cuadricula obtener el valor central que representaria el centro geometrico de cada cuadricula cuadrada
     * es punto sera utiliado para calcular el potencial
     *  */ 
    //float potenciales[10][10];
    std::vector<std::vector<float>> potenciales;
    std::vector<float> fila;
    int anchoCuadriculado = _ANCHO/cant_cuadriculas.x;

    int largoCuadriculado = _LARGO/cant_cuadriculas.y;

    
    float distancia,potencial;
    float x_calcular,y_calcular;
    int i,j;


    for(i=1;i<=cant_cuadriculas.x;i++){



        for(j=1;j<=cant_cuadriculas.y;j++){
            potencial=0;
            float potencialaux=0;
            x_calcular=((i-1)*anchoCuadriculado)+(anchoCuadriculado/2);
            y_calcular=((j-1)*largoCuadriculado)+(largoCuadriculado/2);
            for(int p=0;p<planos.size();p++){
                float dist = (x_calcular)-(planos[p]->x_original*factorEscala+planos[p]->offsetX);
                float sig = dist/std::abs(dist);
                
                potencial+=planos[p]->calcularPotencial(dist);
            }
            for(int k=0;k<cantCargasFijas && cargasFijas[k]->x!=NULL && cargasFijas[k]->y!=NULL;k++){
                // el punto va a ser la mitad de la cuadricula
                
                distancia = calcularDistancia(cargasFijas[k]->x,cargasFijas[k]->y,x_calcular,y_calcular);

                //calculamos el potencial
                
                cargasFijas[k]->calcularPotencial(potencialaux,distancia);
                potencial+=potencialaux;
            }
            fila.push_back({potencial});
            
        }
        potenciales.push_back(fila);
        fila.clear();
    }

    return potenciales;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
std::map<float,std::string> mapaPotencialElectrico(std::vector<std::vector<float>> potenciales){
    //std::map<float,sf::Vector2<int>> mapaPotencialPosicion;
    std::map<float,std::string> mapaColor;
    float arrAux[cant_cuadriculas.x*cant_cuadriculas.y];

    sf::Vector2<int> posicion;
    int i,j,k=0;

    for(i=0;i<cant_cuadriculas.x;i++){
        for(j=0;j<cant_cuadriculas.y;j++,k++){
            //ordenar un arreglo bidimencional en una dimencion
            arrAux[k]=potenciales[i][j];  
        }
    }

    //ordenado de mayor a menor
    for(i=0;i<sizeof(arrAux)/sizeof(float);i++){
        for(j=i+1;j<sizeof(arrAux)/sizeof(float);j++){
            if(arrAux[i]<arrAux[j]){
                float aux = arrAux[i];
                arrAux[i]=arrAux[j];
                arrAux[j]=aux;
            }
        }
    }    
    int bandera=1;
    int rgb[3];
    int rgbAux[3];
    int control=0;
    std::string hexaString;
    for(i=0;i<sizeof(arrAux)/sizeof(float);i++){ 
        if(bandera==1){
            rgb[0]=255;
            rgb[1]=0;
            rgb[2]=0;
            bandera=0;
        }else{
            if(i<=255){
                rgb[1]+=1;
            }else if(i<=255*2){
                rgb[0]-=1;
            }else if(i<=255*3){
                rgb[2]+=1;
            }else if(i<=255*4){
                rgb[1]-=1;
            }
            //else if(i<=255*5){
            //     rgb[0]+=1;
            // }else if(i<(255*6)/2){
            //     rgb[2]-=1;
            // }else{
            //     rgb[0]=0;
            //     rgb[1]=0;
            //     rgb[2]=0;
            // }
            hexaString = rgbToHex(rgb);
            hexTorgb(hexaString,rgbAux);
            mapaColor.insert({arrAux[i],hexaString});
        }
        control++;
    }
    return mapaColor;
}


std::string rgbToHex(int* rgb) {
    int n;
    std::string aux;
    std::string hex;
    for(int i=0;i<3;i++){
        hex+=decimalAHexadecimal(rgb[i]);
    }
    return hex;
}

string decimalAHexadecimal(int decimal) {
    if (decimal == 0) return "00";

    string hex = "";
    string caracteresHex = "0123456789ABCDEF";

    while (decimal > 0) {
        int resto = decimal % 16;      // Obtenemos el resto (el dígito hex)
        hex += caracteresHex[resto];   // Buscamos el carácter equivalente
        decimal /= 16;                 // Dividimos el número para la siguiente iteración
    }

    // Como los restos se obtienen de derecha a izquierda, hay que dar vuelta el string
    reverse(hex.begin(), hex.end());
    if(hex.length()==1){
        hex="0"+hex;
    }
    
    return hex;
}

char getHex(int n){
    if(n<10){
        return n + '0';
    }else{
        if(n==10){
            return 'A';
        }else if(n==11){
            return 'B';
        }else if(n==12){
            return 'C';
        }else if(n==13){
            return 'D';
        }else if(n==14){
            return 'E';
        }else if(n==15){
            return 'F';
        }else{
            return -1;
        }
    }
}

int getnum(char c){
    if(c=='0'){
        return 0;
    }else if(c=='A'){
        return 10;
    }else if(c=='B'){
        return 11;
    }else if(c=='C'){
        return 12;
    }else if(c=='D'){
        return 13;
    }else if(c=='E'){
        return 14;
    }else if(c=='F'){
        return 15;
    }else{
        return (int) (c - '0');
    }
}

void hexTorgb(std::string hexa, int rgb[3]){
    int n1,n2;
    for(int i=0;i<hexa.length();i+=2){
        n1=getnum(hexa[i]);
        n2=getnum(hexa[i+1]);
        rgb[i/2]=n1*16+n2;
    }
        
}


void calcularVectorFuerza(sf::VertexArray* vectorFuerza,float fuerzaX, float fuerzaY, Carga* carga){
    sf::Vector2f origen(carga->x,carga->y);
    sf::Vector2f destino(carga->x+fuerzaX,carga->y+fuerzaY);
    
    //sf::VertexArray vectores(sf::PrimitiveType::LineStrip, 2);
    (*vectorFuerza)[0].position=origen;
    (*vectorFuerza)[0].color=sf::Color::Red;
    (*vectorFuerza)[1].position=destino;
    (*vectorFuerza)[1].color=sf::Color::Red;
    
}
//podria hacer que estas 2 funciones sean una sola: verterFuerzaCarga y calcularVectorVelocidad
void calcularVectorVelocidad(sf::VertexArray* vectorVelocidad,float velocidadX, float velocidadY, Carga* carga){
    sf::Vector2f origen(carga->x,carga->y);
    sf::Vector2f destino(carga->x+velocidadX,carga->y+velocidadY);

    //sf::VertexArray vectores(sf::PrimitiveType::LineStrip, 2);
    (*vectorVelocidad)[0].position=origen;
    (*vectorVelocidad)[0].color=sf::Color::Green;
    (*vectorVelocidad)[1].position=destino;
    (*vectorVelocidad)[1].color=sf::Color::Green;

    //(*window).draw(vectores);
}




sf::Texture drawPotencialHeatMap(sf::Texture &textura){
    std::vector<std::vector<float>> potenciales = potencialElectrico();
    std::map<float,std::string> mapaColor = mapaPotencialElectrico(potenciales);
    sf::Image fondo({_ANCHO, _LARGO});
    
    int hexa;
    int rgb[4];
    int control=0;
    int i,j;
    unsigned int x=0;
    unsigned int y=0;
    for( i=1;i<cant_cuadriculas.x;i++){
        for( j=1;j<cant_cuadriculas.y-1;j++){

            
            std::string hexaString = mapaColor[potenciales[i-1][j-1]];
            hexTorgb(hexaString,rgb);                

            sf::Color color(rgb[0],rgb[1],rgb[2],100);
            
            for(x=(i-1)*(_ANCHO/cant_cuadriculas.x);x<(i)*(_ANCHO/cant_cuadriculas.x);x++){
                for(y=(j-1)*(_LARGO/cant_cuadriculas.y);y<(j)*(_LARGO/cant_cuadriculas.y);y++){
                    
                    fondo.setPixel({x,y},color);
                }
            }
            
        }
    }

    //sf::Texture texture;

    
    bool success = textura.loadFromImage(fondo);
    std::cout<<"success: "<<success<<std::endl;
    return textura;
}


bool VentanaConfi(){
    bool cambio=false;
    bool cambiar_valorLibre;
    
    ImGui::Begin("Ventana de Control");
    ImGui::InputFloat("Seg Tiempo: ",&tiempo,0.0f,0.0f,"%.15f");
    if(programaDetenido){
        manejoProgramaDetendio(cambio);
    }else if(programaPausado){
        manejoProgramaPausado(cambio);
    }else if(!programaDetenido && !programaPausado){
        manejoProgramaCorriendo(cambio);
    }else{
        std::cout<<"explote, no estoy ni pausado, ni detenido, ni corriendo"<<std::endl;
        exit(-1);
    }
    ImGui::End();
    return cambio;

}

void cargasConfi(int i){
    if(i<0){
        return;
    }
    ImGui::PushID(i);
    bool radio =ImGui::InputFloat("Metros radio ",&(cargasFijas[i]->radio));
    ImGui::InputFloat("Metros posicion en x",&(cargasFijas[i]->x_original),0.0f,0.0f,"%.10f");//es un areglo de Cargas
    if(ImGui::InputFloat("Metros posicion en y",&(cargasFijas[i]->y_original),0.0f,0.0f,"%.10f")){
        cargasFijas[i]->y_original = cargasFijas[i]->y_original*(-1); //cambiamos el signo para que el eje y sea positivo para arriba
    } 
    bool valor = ImGui::InputFloat("C valor",&(cargasFijas[i]->valor),0.0f,0.0f,"%.10f");
    bool masa = ImGui::InputFloat("Kg masa",&(cargasFijas[i]->masa),0.0f,0.0f,"%.10f");
    
    
    
    if(mostrarEjeCordenado){
        cargasFijas[i]->offsetX=origenX;
        cargasFijas[i]->offsetY=origenY;
    }
    if(programaDetenido || programaPausado){
        cargasFijas[i]->shape.setRadius(cargasFijas[i]->radio);
        cargasFijas[i]->actualizarPosicion((cargasFijas[i]->x_original*factorEscala + cargasFijas[i]->offsetX),(cargasFijas[i]->y_original*factorEscala + cargasFijas[i]->offsetY));
    
    }
    if(cargasFijas[i]->valor<0){
        cargasFijas[i]->shape.setFillColor(_color_cargaFija);
    } else{
        cargasFijas[i]->shape.setFillColor(sf::Color(255,123,56));
    }
    
    ImGui::PopID();
}

void manejoProgramaDetendio(bool &cambio){
  
    ImGui::Text("Coloca un eje de cordenadas");
    ImGui::InputFloat("Origen en x",&origenX);
    ImGui::InputFloat("Origen en y",&origenY);
    ImGui::InputFloat("Factor Escala: ",&factorEscala,0.0f,0.0f,"%.1f");
    if(origenX!=0 && origenY!=0){
        if(ImGui::Checkbox("dibujar eje cordenado",&mostrarEjeCordenado)){
            cambio=true;
            if(mostrarEjeCordenado==false){
                origenX==0;
                origenY==0;
            }
        }
    } 
    
    //esquema de if para Aislar a la cargas Esfericas Conductoras.
    puntoEstudioConfi();
    if(cantidadPlanos==0 && cantidadCargasEsfericas==0){
        gestionCargasFijas();
        cargaLibreConfi();
        gestionPlanos();
        gestionCargasEsfericas();
        if(ImGui::Checkbox("dibujar campo electrico",&mostrarCampoELectrico)){
            actualizarPosSegunOffset();
            cambio=true;
        }
    }else if(cantidadPlanos!=0){
        gestionCargasFijas();
        cargaLibreConfi();
        gestionPlanos();
        if(ImGui::Checkbox("dibujar campo electrico",&mostrarCampoELectrico)){
            actualizarPosSegunOffset();
            cambio=true;
        }
    } else if(cantidadCargasEsfericas!=0){
        gestionCargasEsfericas();
        gestionCargasLigadasEsfera();
        if(ImGui::Checkbox("dibujar campo electrico Esferas",&mostrarCEconEsferas)){
            //actualizarPosSegunOffset();
            cambio=true;
        }
    }
    
    
    if(ImGui::Checkbox("dibujar heatMap potencial",&mostrarMapaPotencial)){
        actualizarPosSegunOffset();
        cambio=true;
    }
   

    if(ImGui::Checkbox("guardar cambios y reiniciar simulacion",&cambio)){
        cambio=true;
        programaDetenido=false;
        programaPausado=false;
        //mostrarCampoELectrico=false;
        actualizarPosSegunOffset();
    }
    if(ImGui::Checkbox("Cerrar Programa",&cerrarPrograma)){
        cambio=true;
        programaDetenido=true;
    }

}

void manejoProgramaPausado(bool &cambio){
    bool aux=false;
    if(ImGui::Checkbox("dibujar vector velocidad",&mostrarVectorVelocidad)){
        cambio=true;
    }
    if(ImGui::Checkbox("dibujar vector fuerza",&mostrarVectorFuerza)){
        cambio=true;
    }
    mostrarDatosCargaLibre();
    puntoEstudioConfi();
    if(ImGui::Checkbox("dibujar heatMap potencial",&mostrarMapaPotencial)){
        cambio=true;
    }
    if(ImGui::Checkbox("dibujar campo electrico",&mostrarCampoELectrico)){
        cambio=true;
    }
    if(ImGui::Checkbox("Reanudar Programa",&aux)){
        cambio=true;
        mostrarCampoELectrico=false;
        programaPausado=false;
    }
    if(ImGui::Checkbox("Detener Simulacion",&programaDetenido)){
        cambio=true;
        programaDetenido=true;
    }
    if(ImGui::Checkbox("Cerrar Programa",&cerrarPrograma)){
        cambio=true;
        programaDetenido=true;
    }
}

void manejoProgramaCorriendo(bool &cambio){
    if(ImGui::Checkbox("dibujar vector velocidad",&mostrarVectorVelocidad)){
        cambio=true;
    }
    if(ImGui::Checkbox("dibujar vector fuerza",&mostrarVectorFuerza)){
        cambio=true;
    }
    mostrarDatosCargaLibre();
    puntoEstudioConfi();
    if(ImGui::Checkbox("dibujar heatMap potencial",&mostrarMapaPotencial)){
        cambio=true;
    }
    if(ImGui::Checkbox("dibujar campo electrico",&mostrarCampoELectrico)){
        cambio=true;
    }
    if(ImGui::Checkbox("Pausar Simulacion",&programaPausado)){
        cambio=true;
    }
    if(ImGui::Checkbox("Detener Simulacion",&programaDetenido)){
        cambio=true;
        programaDetenido=true;
    }
    if(ImGui::Checkbox("Cerrar Programa",&cerrarPrograma)){
        cambio=true;
        programaDetenido=true;
    }
}

void gestionCargasFijas(){
    ImGui::Text("Ajusta los valores fisicos:");
    if(ImGui::InputInt("cantidad de cargas fijas (maximo 3)", &cantCargasFijas,1,3)){
        if(cantCargasFijas<0){
            cantCargasFijas=0;
            return;
        } 
        if(cantCargasFijas>cargasFijas.size()){
            for(int i=0;i<cantCargasFijas-cargasFijas.size();i++){
                cargasFijas.push_back(new Carga());
            }
        }else if(cantCargasFijas<cargasFijas.size()){
            for(int i=0;i<cargasFijas.size()-cantCargasFijas;i++){
                cargasFijas.pop_back();
            }
        }
    }
   
    if(cantCargasFijas!=0){
        if(cantCargasFijas>=1){
            ImGui::Text("carga los valores de tus cargas 1 fijas");
            cargasConfi(0);
        }
        if(cantCargasFijas>=2){
            ImGui::Text("carga los valores de tus cargas 2 fijas");
            cargasConfi(1);
        }
        if(cantCargasFijas>=3){
            ImGui::Text("carga los valores de tus cargas 3 fijas");
            cargasConfi(2);
        }
    }
}

void gestionPlanos(){
    if(ImGui::InputInt("ingrese cantidad de Planos Infinitos (maximo 4)",&cantidadPlanos,1,4)){   
        if(cantidadPlanos<0){
            cantidadPlanos=0;
            return;
        } 
        if(cantidadPlanos>planos.size()){
            for(int i=0;i<cantidadPlanos-planos.size();i++){
                planos.push_back(new Plano());
            }
        }else if(cantidadPlanos<planos.size()){
            for(int i=0;i<cargasFijas.size()-cantidadPlanos;i++){
                planos.pop_back();
            }
        }
    }

    if(cantidadPlanos!=0){
        if(cantidadPlanos>=1){
            ImGui::Text("carga los valores de tu plano 1");
            planoConfi(0);
        }
        if(cantidadPlanos>=2){
            ImGui::Text("carga los valores de tu plano 2");
            planoConfi(1);
        }
        if(cantidadPlanos>=3){
            ImGui::Text("carga los valores de tus plano 3");
            planoConfi(2);
        }
        if(cantidadPlanos>=4){
            ImGui::Text("carga los valores de tus plano 3");
            planoConfi(3);
        }
    }
}
   
void gestionCargasEsfericas(){
    
    if(ImGui::InputInt("ingrese cantidad de Cargas Esfericas",&cantidadCargasEsfericas,1,2)){  
        if(cantidadCargasEsfericas<0){
            cantidadCargasEsfericas=0;
            return;
        } 
        if(cantidadCargasEsfericas>esferas.size()){
            for(int i=0;i<cantidadCargasEsfericas-esferas.size();i++){
                esferas.push_back(new CargaEsferica());
            }
        }else if(cantidadCargasEsfericas<esferas.size()){
            for(int i=0;i<esferas.size()-cantidadCargasEsfericas;i++){
                esferas.pop_back();
            }
        }
    }

    if(cantidadCargasEsfericas!=0){
        if(cantidadCargasEsfericas>=1){
            ImGui::Text("carga los valores de tu Esfera 1");
            esferaConfi(0,20);
        }
        if(cantidadCargasEsfericas>=2){
            ImGui::Text("carga los valores de tu Esfera 2");
            esferaConfi(1,21);
        }
    }

}

void gestionCargasLigadasEsfera(){
    if(ImGui::Checkbox("ingresar una carga Fija en el Centro",&PonerCargaFijaCentro)){
        if(cargasFijas.size()==0){
            cantCargasFijas=1;
            cargasFijas.push_back(new Carga());
        }else{
            cantCargasFijas=0;
            cargasFijas.pop_back();
        }
    }
    if(PonerCargaFijaCentro){
        ImGui::InputFloat("radio",&(cargasFijas[0]->radio));
        // ImGui::InputFloat("posicion en x",&(cargasFijas[0]->x_original));//es un areglo de Cargas
        // if(ImGui::InputFloat("posicion en y",&(cargasFijas[0]->y_original))){
        //     cargasFijas[0]->y_original = cargasFijas[0]->y_original*(-1); //cambiamos el signo para que el eje y sea positivo para arriba
        // } 
        cargasFijas[0]->x_original = esferas[0]->x_static;
        cargasFijas[0]->y_original = esferas[0]->y_static;
       
        ImGui::InputFloat("C valor",&(cargasFijas[0]->valor),0.0f,0.0f,"%.10f");
        ImGui::InputFloat("Kg masa",&(cargasFijas[0]->masa),0.0f,0.0f,"%.10f");
        
        
        
        if(mostrarEjeCordenado){
            cargasFijas[0]->offsetX=origenX;
            cargasFijas[0]->offsetY=origenY;
        }
        if(programaDetenido || programaPausado){
            cargasFijas[0]->shape.setRadius(cargasFijas[0]->radio);
            cargasFijas[0]->actualizarPosicion(cargasFijas[0]->x_original + cargasFijas[0]->offsetX,cargasFijas[0]->y_original + cargasFijas[0]->offsetY);
        
        }
        if(cargasFijas[0]->valor<0){
            cargasFijas[0]->shape.setFillColor(_color_cargaFija);
        } else{
            cargasFijas[0]->shape.setFillColor(sf::Color(255,123,56));
        }
        
    }
    
    
}

void esferaConfi(int i,int id){
    ImGui::PushID(id);
    ImGui::InputFloat("M radio Exterior",&(esferas[i]->radio));
    ImGui::InputFloat("M radio Interior",&(esferas[i]->radio_int));
    ImGui::InputFloat("M posicion en x",&(esferas[i]->x_static),0.0f,0.0f,"%.10f");
    if(ImGui::InputFloat("M posicion en y",&(esferas[i]->y_static),0.0f,0.0f,"%.10f")){
        esferas[i]->y_static = esferas[i]->y_static*(-1); //cambiamos el signo para que el eje y sea positivo para arriba
    } 
    ImGui::InputFloat("C valor",&(esferas[i]->valor),0.0f,0.0f,"%.10f");
    ImGui::InputFloat("Kg masa",&(esferas[i]->masa),0.0f,0.0f,"%.10f");
    
    
    
    if(mostrarEjeCordenado){
        esferas[i]->offsetX=origenX;
        esferas[i]->offsetY=origenY;
    }
    if(programaDetenido || programaPausado){
        esferas[i]->shape.setRadius(esferas[i]->radio);
        esferas[i]->shape_int.setRadius(esferas[i]->radio_int);
        esferas[i]->actualizarPosicion(esferas[i]->x_static + esferas[i]->offsetX,esferas[i]->y_static + esferas[i]->offsetY);
    }
    esferas[i]->shape.setFillColor(sf::Color(136,136,136));
    
    //esferas[i]->shape_int.setFillColor(sf::Color::Black);
    
    ImGui::PopID();
}



void cargaLibreConfi(){

    ImGui::Text("carga los valores de tu cargas libres");

    ImGui::InputFloat("Metros radio",&(cargasLibres[0]->radio));
   
        ImGui::InputFloat("Metros posicion en x",&(cargasLibres[0]->x_original),0.0f,0.0f,"%.10f");//es un areglo de Cargas
        if(ImGui::InputFloat("Metros posicion en y",&(cargasLibres[0]->y_original),0.0f,0.0f,"%.10f")){
            cargasLibres[0]->y_original = cargasLibres[0]->y_original * (-1);
        }
        ImGui::InputFloat("C valor",&(cargasLibres[0]->valor),0.0f,0.0f,"%.10f");
        ImGui::InputFloat("Kg masa",&(cargasLibres[0]->masa),0.0f,0.0f,"%.10f");
        
        if(mostrarEjeCordenado){
            cargasLibres[0]->offsetX=origenX;
            cargasLibres[0]->offsetY=origenY;
        };
        if(programaDetenido ){
            cargasLibres[0]->actualizarPosicion(cargasLibres[0]->x_original*factorEscala + cargasLibres[0]->offsetX,cargasLibres[0]->y_original*factorEscala + cargasLibres[0]->offsetY);
            (*(cargasLibres[0])).aX=0;
            (*(cargasLibres[0])).aY=0;
            (*(cargasLibres[0])).vX=0;
            (*(cargasLibres[0])).vY=0;

            cargasLibres[0]->shape.setFillColor(_color_cargaLibre);
            cargasLibres[0]->shape.setRadius(cargasLibres[0]->radio);
        }
        
}

void puntoEstudioConfi(){
    ImGui::Text("Punto de Estudio");
    if(ImGui::InputFloat("Metros Posicion en X: ",&(cargaEstudio->x_original))){
    }
    if(ImGui::InputFloat("Metros Posicion en Y: ",&(cargaEstudio->y_original))){
        cargaEstudio->y_original = cargaEstudio->y_original*(-1);
    }
    if(mostrarEjeCordenado){
            cargaEstudio->offsetX=origenX;
            cargaEstudio->offsetY=origenY;
    }
    if(programaDetenido || programaPausado){
        cargaEstudio->shape.setRadius(4);
        cargaEstudio->radio=4;
        cargaEstudio->actualizarPosicion((cargaEstudio->x_original + cargaEstudio->offsetX),(cargaEstudio->y_original + cargaEstudio->offsetY));
    }
    ImGui::Checkbox("Mostrar Datos del punto",&mostrarDatosPuntoEstudio);
    if(mostrarDatosPuntoEstudio){
        ImGui::InputFloat("C Componente X Campo Elextrico",&campoElectricoPuntoEstudio.x);
        float valorY = (campoElectricoPuntoEstudio.y*(-1));
        ImGui::InputFloat("C Componente Y Campo Elextrico",&(valorY));
        ImGui::InputFloat("V Valor Potencial",&potencialPuntoEstudio);
    }
}

void planoConfi(int i){
    ImGui::PushID(i);
    if(ImGui::InputFloat("M Posicion en X: ",&(planos[i]->x_original)),0.0f,0.0f,"%.10f"){
        planos[i]->setearTamaño();
    }
    ImGui::InputFloat("C/M^2 Densidad de Carga",&(planos[i]->densidadCarga),0.000f,0.0f,"%.15f");
    if(mostrarEjeCordenado){
        planos[i]->offsetX=origenX;
    }
    ImGui::Text("Ingrese Valor de Potencial de Referencia V0 del Plano");
    ImGui::InputFloat("V",&(planos[i]->potencial_ref),0.000f,0.0f,"%.15f");
    if(programaDetenido || programaPausado){
        planos[i]->setearPosicion(planos[i]->x_original*factorEscala);
    }
    if(planos[i]->densidadCarga<0){
        planos[i]->shape.setFillColor(_color_cargaFija);
    } else{
        planos[i]->shape.setFillColor(sf::Color(255,123,56));
    }

    ImGui::PopID();
}

void representarEjECartesiano(sf::VertexArray *ejeX,sf::VertexArray *ejeY,sf::Vector2f origen){
    sf::Vector2f inicioRectaX(0,origen.y);
    sf::Vector2f finalRectaX(_ANCHO,origen.y);
    sf::Vector2f inicioRectaY(origen.x,0);
    sf::Vector2f finalRectaY(origen.x, _LARGO);
    (*ejeX)[0].position=inicioRectaX;
    (*ejeX)[0].color=sf::Color::White;
    (*ejeX)[1].position=finalRectaX;
    (*ejeX)[1].color=sf::Color::White;
    (*ejeY)[0].position=inicioRectaY;
    (*ejeY)[0].color=sf::Color::White;
    (*ejeY)[1].position=finalRectaY;
    (*ejeY)[1].color=sf::Color::White;
}

void actualizarPosSegunOffset(){
    for(int i=0;i<cantCargasFijas;i++){
        cargasFijas[i]->x = cargasFijas[i]->x_original*factorEscala + cargasFijas[i]->offsetX;
        cargasFijas[i]->y = cargasFijas[i]->y_original*factorEscala + cargasFijas[i]->offsetY;
        cargasFijas[i]->actualizarPosicion(cargasFijas[i]->x,cargasFijas[i]->y);
    }
    cargasLibres[0]->x = cargasLibres[0]->x_original*factorEscala + cargasLibres[0]->offsetX;
    cargasLibres[0]->y = cargasLibres[0]->y_original*factorEscala + cargasLibres[0]->offsetY;
    cargasLibres[0]->actualizarPosicion(cargasLibres[0]->x,cargasLibres[0]->y);
}

void mostrarDatosCargaLibre(){
    for(int i=0;i<cantCargasLibres;i++){
        ImGui::PushID(i);
        ImGui::Text("Datos de la carga: ");
        float posx=(cargasLibres[i]->x-origenX);
        float posy = (cargasLibres[i]->y-origenY)*(-1); //le cambiamos de signo para que se el eje y sea positivo para arriba como lo veria el usuario
        ImGui::InputFloat("M Posicion X : ",&posx);
        ImGui::InputFloat("M Posicion Y : ",&posy);
        float velocidadModulo = calcularDistancia(vectorVelocidad[0].position.x,vectorVelocidad[0].position.y,vectorVelocidad[1].position.x,vectorVelocidad[1].position.y);
        ImGui::InputFloat("M/s Velocidad Modulo : ",&(velocidadModulo));
        float velocidadcompX = vectorVelocidad[1].position.x-vectorVelocidad[0].position.x;
        float velocidadcompY = (vectorVelocidad[1].position.y-vectorVelocidad[0].position.y)*-1; //le cambiamos de signo para que se el eje y sea positivo para arriba como lo veria el usuario
        ImGui::InputFloat("M/s Velocidad componenteX : ",&(velocidadcompX),0.000f,0.0f,"%.10f");
        ImGui::InputFloat("M/s Velocidad componenteY : ",&(velocidadcompY),0.000f,0.0f,"%.10f");
        float fuerzaModulo = calcularDistancia(vectorFuerza[0].position.x,vectorFuerza[0].position.y,vectorFuerza[1].position.x,vectorFuerza[1].position.y);
        float fuerzacompX =vectorFuerza[1].position.x - vectorFuerza[0].position.x;
        float fuerzacompY = (vectorFuerza[1].position.y - vectorFuerza[0].position.y)*(-1); //le cambiamos de signo para que se el eje y sea positivo para arriba como lo veria el usuario
        ImGui::InputFloat("N Fuerza Modulo",&fuerzaModulo,0.000f,0.0f,"%.10f");
        ImGui::InputFloat("N Fuerza componenteX",&fuerzacompX,0.000f,0.0f,"%.10f");
        ImGui::InputFloat("N Fuerza componenteY",&fuerzacompY,0.000f,0.0f,"%.10f");
        ImGui::PopID();
    }
    
}

std::vector<std::vector<sf::Vector2f>> calcularCEPlano(){
    std::vector<std::vector<sf::Vector2f>> vectorCE;
    std::vector<sf::Vector2f> fila;
    float distanciaTotal, distanciaX, distanciaY;
    float x_calcular,y_calcular;
    int anchoCuadriculado = _ANCHO/cant_cuadriculas.x;
    int largoCuadriculado = _LARGO/cant_cuadriculas.y;
    for(int i=1;i<cant_cuadriculas.x;i++){
        for(int j=1;j<cant_cuadriculas.y;j++){
            sf::Vector2f vectorCampoElectrico(0,0);
            for(int k=0;k<cantidadPlanos;k++){
                x_calcular = (i-1)*(anchoCuadriculado)+(anchoCuadriculado/2);
                float dist = x_calcular-(planos[k]->x_original*factorEscala+planos[k]->offsetX);
                float sig = dist/std::abs(dist);
                if(std::abs(sig)!=1){
                    std::cout<<"no doy uno "<<std::endl;
                }
                float aux = planos[k]->cacularCampoElectrico()*sig;
                vectorCampoElectrico.x+=aux;
            }
            fila.push_back(vectorCampoElectrico);
        }
        (vectorCE).push_back(fila);
        fila.clear();
    }
    return vectorCE;
}

void calcularCampoElectrico(std::vector<std::vector<sf::Vector2f>> *vectorCE,std::vector<std::vector<sf::Vector2f>> &vectorCEPlano){
    
    
    std::vector<sf::Vector2f> fila;
    
    float distanciaTotal, distanciaX, distanciaY;
    float x_calcular,y_calcular;
    int anchoCuadriculado = _ANCHO/cant_cuadriculas.x;
    int largoCuadriculado = _LARGO/cant_cuadriculas.y;
    int i=1;
    for(i;i<cant_cuadriculas.x;i++){
        for(int j=1;j<cant_cuadriculas.y;j++){
            sf::Vector2f vectorCampoElectrico(0,0);
            
            for(int k=0;k<cantCargasFijas;k++){
                x_calcular = (i-1)*(anchoCuadriculado)+(anchoCuadriculado/2);
                y_calcular = (j-1)*(largoCuadriculado)+(largoCuadriculado/2);
    
                distanciaTotal = calcularDistancia(x_calcular,y_calcular,cargasFijas[k]->x,cargasFijas[k]->y)/factorEscala;
                distanciaX = calcularDistanciaX(cargasFijas[k]->x,x_calcular)/factorEscala;
                distanciaY = calcularDistanciaY(cargasFijas[k]->y,y_calcular)/factorEscala;
                sf::Vector2f vectorCampoElectricoAux(0,0);
                (*(cargasFijas[k])).cacularCampoElectrico(vectorCampoElectricoAux,distanciaTotal,distanciaX,distanciaY);
                if(vectorCEPlano.size()!=0){
                    vectorCampoElectrico.x += (vectorCampoElectricoAux.x + vectorCEPlano[i-1][j-1].x);
                    vectorCampoElectrico.y += (vectorCampoElectricoAux.y +vectorCEPlano[i-1][j-1].y);
                } else{
                    vectorCampoElectrico.x += (vectorCampoElectricoAux.x);
                    vectorCampoElectrico.y += (vectorCampoElectricoAux.y );
                }
            }
            fila.push_back(vectorCampoElectrico);
        }
        (*vectorCE).push_back(fila);
        fila.clear();
    }
    
}

void drawVectoresCE(sf::RenderWindow &window,std::vector<std::vector<sf::Vector2f>> *vectorCE){
    int k=0;
    for(int i=1;i<cant_cuadriculas.x;i++){
        for(int j=1;j<cant_cuadriculas.y;j++,k++){
            sf::Vector2f origen((i-1)*(_ANCHO/cant_cuadriculas.x) + (_ANCHO/cant_cuadriculas.x)/2,(j-1)*(_LARGO/cant_cuadriculas.y) + (_LARGO/cant_cuadriculas.y)/2);       
        
            sf::Vector2f destino(origen.x+(*vectorCE)[i-1][j-1].x ,origen.y+(*vectorCE)[i-1][j].y);
          
            sf::VertexArray vectores(sf::PrimitiveType::LineStrip, 2);
            vectores[0].position=origen;
            vectores[0].color=sf::Color::White;
            vectores[1].position=destino;
            vectores[1].color=sf::Color::Red;
           
            if(calcularDistancia(origen.x,origen.y,destino.x,destino.y)>60){
              
                escalarVector(vectores);
         
            }
            window.draw(vectores);
        }
    }
}

void escalarVector(sf::VertexArray &vector){
    float largoVector = calcularDistancia(vector[0].position.x,vector[0].position.y,vector[1].position.x,vector[1].position.y);
    //float componenteUnitariaX = calcularDistanciaX(vector[0].position.x,vector[1].position.x)/largoVector;
    //float componenteUnitariaY = calcularDistanciaY(vector[0].position.y,vector[1].position.y)/largoVector;

    float factorScalar = 60/largoVector;

    float xPrima =  (vector[1].position.x - vector[0].position.x ) * factorScalar;
    float yPrima = (vector[1].position.y - vector[0].position.y) * factorScalar;

    float disTotalX= xPrima + vector[0].position.x;
    float disTotalY = yPrima + vector[0].position.y;

    vector[1].position.x = disTotalX;
    vector[1].position.y = disTotalY;

   
}


void calcularCEPE(){
    float distanciaTotal,distanciaX,distanciaY;
    campoElectricoPuntoEstudio.x=0;
    campoElectricoPuntoEstudio.y=0;
    float posX=cargaEstudio->x_original+cargaEstudio->offsetX;
    float posY = cargaEstudio->y_original+cargaEstudio->offsetY;
    float CEPlano=0;
    ///PLANOS
    for(int k=0;k<cantidadPlanos;k++){
        float dist = (posX)-(planos[k]->x_original*factorEscala+planos[k]->offsetX);
        float sig = dist/std::abs(dist);
        if(std::abs(sig)!=1){
            std::cout<<"no doy uno"<<std::endl;
        }
        CEPlano += planos[k]->cacularCampoElectrico()*sig;
    }

    
    for(int i=0;i<cantCargasFijas;i++){
        distanciaTotal = calcularDistancia(posX,posY,cargasFijas[i]->x,cargasFijas[i]->y)/factorEscala;
        distanciaX = calcularDistanciaX(cargasFijas[i]->x,posX)/factorEscala;
        distanciaY = calcularDistanciaY(cargasFijas[i]->y,posY)/factorEscala;
     
        
        sf::Vector2f aux(0,0);
        (*(cargasFijas[i])).cacularCampoElectrico(aux,distanciaTotal,distanciaX,distanciaY);
        campoElectricoPuntoEstudio.x+=aux.x;
        campoElectricoPuntoEstudio.y+=aux.y;
    }
    campoElectricoPuntoEstudio.x+=CEPlano;
}

void calcularPEPE(){
    float distanciaTotal,distanciaX,distanciaY;
    potencialPuntoEstudio=0;
    float aux=0;
    float posX=cargaEstudio->x_original+cargaEstudio->offsetX;
    float posY = cargaEstudio->y_original+cargaEstudio->offsetY;
    for(int p=0;p<planos.size();p++){
        float dist = (posX)-(planos[p]->x_original+planos[p]->offsetX);
        float sig = dist/std::abs(dist);
                
        potencialPuntoEstudio+=planos[p]->calcularPotencial(dist);
    }
    for(int i=0;i<cantCargasFijas;i++){
        distanciaTotal = calcularDistancia(posX,posY,cargasFijas[i]->x,cargasFijas[i]->y);
        distanciaX = calcularDistanciaX(cargasFijas[i]->x,posX);
        distanciaY = calcularDistanciaY(cargasFijas[i]->y,posY);

        (*(cargasFijas[i])).calcularPotencial(aux,distanciaTotal);
        potencialPuntoEstudio+=aux;
    }
}

void drawVectorCEPE(sf::RenderWindow &window){
    
    sf::VertexArray vectorCEtotal(sf::PrimitiveType::LineStrip, 2);
    sf::VertexArray vectorCEX(sf::PrimitiveType::LineStrip, 2);
    sf::VertexArray vectorCEY(sf::PrimitiveType::LineStrip, 2);

   
    float posX=cargaEstudio->x_original+cargaEstudio->offsetX;
    float posY = cargaEstudio->y_original+cargaEstudio->offsetY;

    vectorCEtotal[0].position = {posX , posY};
    vectorCEtotal[0].color=sf::Color::White;
    vectorCEtotal[1].position = {posX + campoElectricoPuntoEstudio.x , posY + campoElectricoPuntoEstudio.y};
    vectorCEtotal[1].color=(sf::Color::Red);
    window.draw(vectorCEtotal);
    vectorCEX[0].position = {posX,posY};
    vectorCEX[0].color=sf::Color::White;
    vectorCEX[1].position = {posX + campoElectricoPuntoEstudio.x,(posY)};
    vectorCEX[1].color=(sf::Color::Red);
    window.draw(vectorCEX);
    vectorCEY[0].position = {posX,posY};
    vectorCEY[0].color=sf::Color::White;
    vectorCEY[1].position = {((posX)),posY + (campoElectricoPuntoEstudio.y)};
    vectorCEY[1].color=(sf::Color::Red);
    window.draw(vectorCEY);
}

//esta funcion hace magia
void organizadorCEEsferaConductora(sf::RenderWindow &window){
    if(cantCargasFijas>1){
        std::cout<<"no acepto mas de 1 carga fija en el mapa"<<std::endl;
    }
    float cargaExterior_inducida = esferas[0]->valor;
    sf::VertexArray vectorCE(sf::PrimitiveType::LineStrip, 2);
    if(cantidadCargasEsfericas>1 || cantCargasFijas!=0){
       //balance de cargas inducidas
        int i=esferas.size() -1;
        cargaExterior_inducida=esferas[i]->valor;
        
        if(cantCargasFijas==1){
            float cargaDentro = cargasFijas[0]->valor;
            float cargaInterior_inducida = cargaDentro*(-1); //induce cargas del otro signo
            cargaExterior_inducida = esferas[i]->valor + cargaInterior_inducida*(-1);
            gestiondibujarCargas(window,cargaInterior_inducida,cargaInterior_inducida*(-1),i);
            //itero dentro de todo el radio interior (osea lo negro) de la carga Esferica conductora, y voy calculando el campo todo lo que se me pinte (podria calcularlo mucho mas de lo que lo vengo haciendo)
            sf::VertexArray vectorCE(sf::PrimitiveType::LineStrip, 2);
            
            float x_inicial=(esferas[i]->x_static+esferas[i]->offsetX)-esferas[i]->radio_int;
            float y_inicial=(esferas[i]->y_static+esferas[i]->offsetY)-esferas[i]->radio_int; 
            
            float posX= esferas[i]->x_static+esferas[i]->offsetX;
            float posY = esferas[i]->y_static+esferas[i]->offsetY;
            
            for(float x=x_inicial;x<(esferas[i]->x_static+esferas[i]->offsetX)+esferas[i]->radio_int;x+=20){
                for(float y=y_inicial;y<(esferas[i]->y_static+esferas[i]->offsetY)+esferas[i]->radio_int;y+=20){
                    sf::Vector2f campoElectricoInterior(0,0);
                    if(esferas[i]->radio_int>=sqrt((pow(posX-x,2)+pow(posY-y,2)))){
                        float distanciaTotal = calcularDistancia(x,y,posX,posY);
                        float distanciaX = calcularDistanciaX(posX,x);
                        float distanciaY = calcularDistanciaY(posY,y);

                        cargasFijas[0]->cacularCampoElectrico(campoElectricoInterior,distanciaTotal,distanciaX,distanciaY);

                        vectorCE[0].position = {x , y};
                        vectorCE[0].color=sf::Color::White;
                        vectorCE[1].position = {x + campoElectricoInterior.x , y + campoElectricoInterior.y};
                        vectorCE[1].color=(sf::Color::Red);
                        if(calcularDistancia(x,y,x + campoElectricoInterior.x,y + campoElectricoInterior.y)>60){
                            escalarVector(vectorCE);
                        }
                        window.draw(vectorCE);
                    }
                }
            }
        }else{
            if(cargaExterior_inducida>0){
                dibujarCargasPositivas(window,esferas[i]->radio,i);
            }else{
                dibujarCargasNegativas(window,esferas[i]->radio,i);
            }
        }
        sf::VertexArray vectorCE(sf::PrimitiveType::LineStrip, 2);
        if(i!=0){
            for(int j=i-1;j>=0;j--){
                if(cargaExterior_inducida>0){
                    if(cargaExterior_inducida<nivelPresicion){
                        cargaExterior_inducida=0;
                    }
                }else{
                    if(cargaExterior_inducida>nivelPresicion*(-1)){
                        cargaExterior_inducida=0;
                    }
                }
                float cargaDentro = cargaExterior_inducida;
                float cargaInterior_inducida = cargaDentro*(-1); //induce cargas del otro signo
                cargaExterior_inducida = esferas[j]->valor + cargaInterior_inducida*(-1);
                gestiondibujarCargas(window,cargaInterior_inducida, cargaInterior_inducida*(-1),j); //en teoria va eso pero tambien parece funcionar con : cargaExterior_inducida
                float posX= esferas[j]->x_static+esferas[j]->offsetX;
                float posY = esferas[j]->y_static+esferas[j]->offsetY;
                
                float x_inicial=(esferas[j]->x_static+esferas[j]->offsetX)-esferas[j]->radio_int;
                float y_inicial=(esferas[j]->y_static+esferas[j]->offsetY)-esferas[j]->radio_int;
                
                for(float x=x_inicial;x<(esferas[j]->x_static+esferas[j]->offsetX)+esferas[j]->radio_int;x+=20){
                    for(float y=y_inicial;y<(esferas[j]->y_static+esferas[j]->offsetY)+esferas[j]->radio_int;y+=20){
                        sf::Vector2f campoElectricoInterior(0,0);
                        if(esferas[j]->radio_int>=sqrt((pow(posX-x,2)+pow(posY-y,2))) && esferas[j+1]->radio<=sqrt((pow(posX-x,2)+pow(posY-y,2)))){
                            float distanciaTotal = calcularDistancia(x,y,posX,posY);
                            float distanciaX = calcularDistanciaX(posX,x);
                            float distanciaY = calcularDistanciaY(posY,y);

                            campoElectricoInterior.x += K*(cargaDentro/pow(distanciaTotal,2))*distanciaX/distanciaTotal;
                            campoElectricoInterior.y += K*(cargaDentro/pow(distanciaTotal,2))*distanciaY/distanciaTotal;

                            vectorCE[0].position = {x , y};
                            vectorCE[0].color=sf::Color::White;
                            vectorCE[1].position = {x + campoElectricoInterior.x , y + campoElectricoInterior.y};
                            vectorCE[1].color=(sf::Color::Red);
                            if(calcularDistancia(x,y,x + campoElectricoInterior.x,y + campoElectricoInterior.y)>60){
              
                                escalarVector(vectorCE);
                        
                            }
                            window.draw(vectorCE);
                        }
                    }
                }
            }
        }
    }else{
        cargaExterior_inducida = esferas[0]->valor;
    }
        
    float posX= esferas[0]->x_static+esferas[0]->offsetX;
    float posY = esferas[0]->y_static+esferas[0]->offsetY;
    float x_inicial=0;
    float y_inicial=0;
        
    for(float x=x_inicial;x<_ANCHO;x+=20){
        for(float y=y_inicial;y<_LARGO;y+=20){
            sf::Vector2f campoElectricoInterior(0,0);
            if(esferas[0]->radio<=sqrt((pow(posX-x,2)+pow(posY-y,2)))){
                float distanciaTotal = calcularDistancia(x,y,posX,posY);
                float distanciaX = calcularDistanciaX(posX,x);
                float distanciaY = calcularDistanciaY(posY,y);

                campoElectricoInterior.x += K*(cargaExterior_inducida/pow(distanciaTotal,2))*distanciaX/distanciaTotal;
                campoElectricoInterior.y += K*(cargaExterior_inducida/pow(distanciaTotal,2))*distanciaY/distanciaTotal;

                vectorCE[0].position = {x , y};
                vectorCE[0].color=sf::Color::White;
                vectorCE[1].position = {x + campoElectricoInterior.x , y + campoElectricoInterior.y};
                vectorCE[1].color=(sf::Color::Red);
                if(calcularDistancia(x,y,x + campoElectricoInterior.x,y + campoElectricoInterior.y)>60){
                    escalarVector(vectorCE);
                }
                window.draw(vectorCE);
            }
        }
    }
}


void gestiondibujarCargas(sf::RenderWindow &window,float cargaInterior, float cargaExterior, int n_esfera){
    if(cargaExterior/abs(cargaExterior) == esferas[n_esfera]->valor/abs(esferas[n_esfera]->valor)){
        if((esferas[n_esfera]->valor+cargaExterior)>0){
            //dibujo mas positivas
            dibujarCargasPositivas(window,esferas[n_esfera]->radio,n_esfera,100);
        }else if((esferas[n_esfera]->valor+cargaExterior)<0){
            //dubujo mas negativas
            dibujarCargasNegativas(window,esferas[n_esfera]->radio,n_esfera,100);
        }else{
            dibujarCargasNegativas(window,esferas[n_esfera]->radio,n_esfera);
        }
    }else{
        double suma= esferas[n_esfera]->valor+cargaExterior;
        int cant=25;
        if(suma>0){
            if(suma<nivelPresicion){
                cant=0;
            }
        }else{
            if(suma>nivelPresicion*(-1)){
                cant=0;
            }
        }
        if(suma==esferas[n_esfera]->valor){
            cant=50;
        }
        if(suma/abs(suma)>0){
             //dibujo menos positivas
             dibujarCargasPositivas(window,esferas[n_esfera]->radio,n_esfera,cant);
        }else{
            //dibujo menos negativas
            dibujarCargasNegativas(window,esferas[n_esfera]->radio,n_esfera,cant);
        }
 
    }
    if(cargaInterior<0){
        dibujarCargasNegativas(window,esferas[n_esfera]->radio_int,n_esfera);
        //dibujarCargasPositivas(window,esferas[n_esfera]->radio,n_esfera);
    }else if(cargaInterior>0){
       // dibujarCargasNegativas(window,esferas[n_esfera]->radio,n_esfera);
        dibujarCargasPositivas(window,esferas[n_esfera]->radio_int,n_esfera);    
    }
}

void dibujarCargasNegativas(sf::RenderWindow &window,float radio,int n_esfera,int cant){
    int i=0;
    for(float titha=0;i<cant;titha+=85,i++){
        float radian_titha = titha*(M_PI/180);
        float x =radio*cos(radian_titha)  + esferas[n_esfera]->x_static + esferas[n_esfera]->offsetX;
        float y= radio*sin(radian_titha) + esferas[n_esfera]->y_static + esferas[n_esfera]->offsetY;
        //float punto = sqrt(pow(esferas[n_esfera]->radio_int,2)*(pow(cos(titha),2)+pow(sin(titha),2)));
        int largo=8,alto=3;
        sf::RectangleShape menos({largo,alto});
        menos.setFillColor(sf::Color::Blue);
        menos.setPosition({x,y});
        window.draw(menos);
    }
}

void dibujarCargasPositivas(sf::RenderWindow &window,float radio,int n_esfera, int cant){
    int i=0;
    for(float titha=0;i<cant;titha+=85,i++){
        float radian_titha = titha*(M_PI/180);
        float x =radio*cos(radian_titha) + esferas[n_esfera]->x_static + esferas[n_esfera]->offsetX;
        float y= radio*sin(radian_titha)+ esferas[n_esfera]->y_static + esferas[n_esfera]->offsetY;
        //float punto = sqrt(pow(esferas[n_esfera]->radio_int,2)*(pow(cos(titha),2)+pow(sin(titha),2)));
        sf::ConvexShape mas(12);
        int radio=4;
        int eje=1;
        int ancho=1;
        mas.setPoint(1,{-radio,-ancho});
        mas.setPoint(2,{-radio,+ancho});
        mas.setPoint(3,{-eje,+eje});
        mas.setPoint(4,{-ancho,+radio});
        mas.setPoint(5,{+ancho,+radio});
        mas.setPoint(6,{+eje,+eje});
        mas.setPoint(7,{+radio,+ancho});
        mas.setPoint(8,{+radio,-ancho});
        mas.setPoint(9,{+eje,-eje});
        mas.setPoint(10,{+ancho,-radio});
        mas.setPoint(11,{-ancho,-radio});
        mas.setPoint(12,{-eje,-eje});

        mas.setFillColor(sf::Color::Red);
        mas.setPosition({x,y});
        window.draw(mas);
    }
}
