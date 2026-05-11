# Simulador Fisico Electroestatica y Electrodinamica en C++


![Induccion](docs/img/inducciones.png)

![Potencial](docs/img/poteenciales.png)

![Cargas](docs/img/2cargas.png)

# Que es esto?
- Permite crear simulaciones en un entorno 2D con cargas puntuales,planos y esferas.
- Visualizar el Campo ELectrico como vectores.
- Visualizar el Pontecial Electrico .
- Simular el movimiento de una carga libre sometido a distintos campos Electricos.
- Simular y visualizar el comportamiento de las cargas inducidas en conductores.

# Objetivos 
- Crear una Herramienta para ayudar a estudiantes y Profesores a entender y explicar de forma mas facil conceptos de Elextrodinamica y Electroestatica, de forma dinamica, podiendo ajustar los valores para representar problemas tipicos y situaciones tipicas dictadas en clases.
- Simular correctamente las interaciones Electrodinamicas entre cargas de distintas formas y tamaños, utilizando las ecuaciones fisicas de la electroestatica y electrodinamica clasica.
- Facilitar el Entendimiento de topicos como:
- movimiento de una carga en un Campo Electrico.
- Campos Generados por cargas, Planos y conductores.
- Interacciones entre cargas.
- Potenciale Electrico.
- Induccion de carga en conductores.
- interaccion de campos generados por planos infinitos
- para faciliar el estudio y aprendizaje de estos topicos dificiles de entender por su nivel de abstraccion y por ser cosas que no nos encontramos en el dia a dia.

# Caracteristicas Principales
- Representacion de campo electrico en forma de campo vectorial y potencial electrico en forma de mapa de calor, de cargas fijas puntuales, planos Infinitos y Conductores Esfericos
- Simulacion de una carga Libre sometida a campos Electricos generados por otras cargas Y planos Infinitos.
- Calcula y Dibuja el vector velocidad y fuerza que siente la particula Libre en modulo y compontentes.
- Calcula y Dibuja el campo electrico y potencial en un punto fijo.
- Representa la induccion de carga de forma intuitiva en conductores Esfericos huecos con una carga fija.
- Permite colocar un eje coordenado.
- Permite escalar el sistema para representar distancias muy pequeñas.

# Decargar Y usar Ejecutable
### Descargar ultima version
- [Descargar Ultima Versión para Windows ](https://github.com/Costabile1/SimuladorFisico/releases)
- [Descargar Ultima Version para MACos](https://github.com/Costabile1/SimuladorFisico/releases)



# Requisitos para Usar la Repo
- instalar MingWL
- instalar SMFL para windows
- incluir el payh del archivo include, descargado en SFML en properties.json
- crear el archivo makefile con:
- compile con la ruta al archivo include de SFML
- ejecutar: con la ruta al lib del archivo SFML 

# Guia de Uso
## Como instalalrme?
- ve a [descargar ultima version](https://github.com/Costabile1/SimuladorFisico/releases)
- installa el zip MLyMSimuladorFisicovx.x.x.zip 
- haz cli en el ejecutable sfml-simulador_fisico-app.exe
- se arbira una interfaz y lo primer que deberias ver es:
![alt text](docs/img/Mapa.png)
- si llegaste aca, lo intalaste y ejecutaste correctamente y deberias ir [Explicacion funciones Principales](#programa-detendio)
- O podes ir a ver [Ejemplos de como utilizamos este programa para entender y solucionar ejercicios reales](/GALLERY.md).


## Programa Detendio
- nos aparecera la ventana de control o menu el cual nos permitira trabajar con el programa, podemos agrandar y mover el menu a placer, haciendo clik en el y arrastrando.
![alt text](docs/img/ventanaControl.png)
- lo primero que vemos es que podemos cambiar el valor tiempo con el que se ejecuta los calculos, este valor representa la presicion con la que se van a realizar los movimientos. Un valor alto sera poco preciso y un valor muy bajo sera muy preciso. (poner un valor muy bajo hara al programa muy preciso en las simulaciones de movimiento pero tambien, el movimiento sera muy lento.)
- primero tenemos el eje de cordenadas. podemos setear el origen en cualquier lado de la pantalla ingresando las cordenadas, en principio el mapa tiene 1900 de ancho y 1000 de alto. donde x crece hacia la derecha e Y hacia abajo.
![alt text](docs/img/EjeCordenado.png)
- el factor escala nos permite escalar el sistema para poder ver con presicion, cuando las distacias son muy pequeñas.
![alt text](docs/gifs/factorEscala-gif.gif)
### Punto estudio
- Punto estudio permite calcular el campo electrico en componentes y mostrarlo en forma de vetores, ademas de calcular el Potencial, colocamos sus cordenadas respeco al eje que hayamos elegido.
- clikear mostrar datos, mostrara un punto en las cordenadas elegidas los vectores y los datos numericos, !importante, para que se muestre correctamente, previamente se debera haber iniciado la simulacion o mostrado el campo electrico de las cargas.
![alt text](docs/img/PuntoEstudio.png)
- Ingresar cantidad de cargas Fijas: estas no se mueven a lo largo de la simulacion, y cargamos sus datos respetando el eje de cordenadas. Represetadas con color azul o naranja segun el signo de su carga
- Ingresar Datos carga Libre: esta carga es la sentira las fuerzas generadas por el campo electrico y se movera respecto a ellas. Representada siempre con un color amarillo independientemente de su carga
![alt text](docs/img/cargasFijasLibres.png)
- Ingresar Plano Infinito: te permitira ingresar su cordenada en X segun el eje,(los planos solo pueden moverse sobre el eje x) y su densidad superficial de carga.
![alt text](docs/img/Plano.png)
### Ingresar Conductores Esfericos
- el objetivo de este apartado es mostrar la induccion de conductores y cargas centradas en el eje de simetria.
- al aumentar la cantidad de cargas Conductoras cambia la ventana de configuracion
- mientras tengas cargas conductoras No podras ingresar cargas libres, y solo se permitira una carga fija ligada a los conductores
- las cargas conductoras y la carga fija ligada comparten todas la misma posicion. (cambair una cambia las demas)
- se cargan valores normalmente y segun la carga del conductor, veras las cargas colocarce en la superficie del mismo.
![alt text](docs/img/CargasEsfericas.png)
- Ingresar carga fija en el centro: colocara una carga que comparte posicion y puede inducir carga en los conductores.
### dibujar campo Electrico:
- disponible en todo momento que permite visualizar el campo Electrico con vectores: los cuales indican su sentido con el color rojo. el blanco es el  origen.
![alt text](docs/gifs/campoElectrico-gif.gif)
- en el caso de estar trabajando con conductores el boton dibujar campo Electrico, tambien actualizara y mostrara la induccion de cargas generadas por el sistema.
![alt text](docs/gifs/cargasEsfericas-gif(2).gif)
### dibujar HeatMap Potencial Electrico:
- calcula el potencial electrio en todo el mapa solo para las cargas Fijas no conductoras, representa con colores mas fuertes los valores altos de potenial
![alt text](docs/gifs/potencial-gif.gif)
### guardar cambios e iniciar simulacion
- cuando tenemos una carga libre, se comensara a calcular las fuerzas y su movimiento. te lleva a la ventana [programa Ejecutandose](#venta-programa-ejecutandose)
![alt text](docs/gifs/SimulacionParticulaLibre-gif.gif)

## Venta Programa Ejecutandose
- Botones dibujar vector fuerza y velocidad: muestran en tiempo real los vectores de fuerza y velocidad que siente la particula libre
- Datos particula libre: muestra todos los datos de posicion,fuerza y velocidad en modulo
- tambien permite ingresar un punto de estudio mientras el programa se ejecuta [ver punto estudio](#punto-estudio)
- dibuajar campo Electrico y potencial Electrico [Campo Electrico](#dibujar-campo-electrico) [Potencial](#dibujar-heatmap-potencial-electrico)
- Pausar Y Reanudar Programa
- Detener Simulacion: retorna la carga Libre a su punto incial y te devuelve a la ventana Programa Detenido [ver Programa Detendio](#programa-detendio)
- El programa se detendra Automaticamente cuadno la particula Libre colisione, ya sea con una carga fija o un Plano Ifinito.


# Estructura del Proyecto
## Diagrama de Clases
![diagrama clases](docs/diagramas/Simulador_Fisico-Página-3.drawio.png)
## Arquitectura principal
![arquitectura Principal](docs/diagramas/Simulador_Fisico-Página-2.drawio.png)
## Orden de IMGUI
![orden Imgui](docs/diagramas/Simulador_Fisico-Página-5.drawio.png)
## diagrama Induccion de Cargas
![induccion de cagras diagrama](docs/diagramas/Simulador_Fisico-Página-4.drawio.png)