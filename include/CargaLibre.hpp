
#include "Carga.hpp"
using namespace std;

class CargaLibre: public Carga{
    public:
        float aX, aY;
        float vX,vY;
    public:
        CargaLibre(float x, float y, float valor, float masa,float radio, float offsetX, float offsetY);
        CargaLibre();
        void update(float fuerzaEX, float fuerzaEY, const float tiempo);
};


