# GUIA
## Programa Detenido
- nos aparecerá la ventana de control o menú el cual nos permitirá trabajar con el programa, podemos agrandar y mover el menú a placer, haciendo click en él y arrastrando.
![alt text](docs/img/ventanaControl.png)
- lo primero que vemos es que podemos cambiar el valor tiempo con el que se ejecuta los cálculos, este valor representa la precisión con la que se van a realizar los movimientos. Un valor alto será poco preciso y un valor muy bajo será muy preciso. (poner un valor muy bajo hará al programa muy preciso en las simulaciones de movimiento pero también, el movimiento será muy lento.)
- primero tenemos el eje de coordenadas. podemos setear el origen en cualquier lado de la pantalla ingresando las coordenadas, en principio el mapa tiene 1900 de ancho y 1000 de alto. donde x crece hacia la derecha e Y hacia abajo.
![alt text](docs/img/EjeCordenado.png)
- el factor escala nos permite escalar el sistema para poder ver con precisión, cuando las distancias son muy pequeñas.
![alt text](docs/gifs/factorEscala-gif.gif)
### Punto estudio
- Punto estudio permite calcular el campo eléctrico en componentes y mostrarlo en forma de vectores, además de calcular el Potencial, colocamos sus coordenadas respecto al eje que hayamos elegido.
- clickear mostrar datos, mostrará un punto en las coordenadas elegidas los vectores y los datos numéricos, !importante, para que se muestre correctamente, previamente se deberá haber iniciado la simulación o mostrado el campo eléctrico de las cargas.
![alt text](docs/img/PuntoEstudio.png)
- Ingresar cantidad de cargas Fijas: estas no se mueven a lo largo de la simulación, y cargamos sus datos respetando el eje de coordenadas. Representadas con color azul o naranja según el signo de su carga
- Ingresar Datos carga Libre: esta carga es la sentirá las fuerzas generadas por el campo eléctrico y se moverá respecto a ellas. Representada siempre con un color amarillo independientemente de su carga.
![alt text](docs/img/cargasFijasLibres.png)
- Ingresar Plano Infinito: te permitirá ingresar su coordenada en X según el eje,(los planos solo pueden moverse sobre el eje x) y su densidad superficial de carga.
![alt text](docs/img/Plano.png)
### Ingresar Conductores Esféricos
- el objetivo de este apartado es mostrar la inducción de conductores y cargas centradas en el eje de simetría.
- al aumentar la cantidad de cargas Conductoras cambia la ventana de configuración
- mientras tengas cargas conductoras No podrás ingresar cargas libres, y solo se permitirá una carga fija ligada a los conductores
- las cargas conductoras y la carga fija ligada comparten todas la misma posición. (cambiar una cambia las demás)
- se cargan valores normalmente y según la carga del conductor, verás las cargas colocarse en la superficie del mismo.
![alt text](docs/img/CargasEsfericas.png)
- Ingresar carga fija en el centro: colocará una carga que comparte posición y puede inducir carga en los conductores.
### dibujar campo Eléctrico:
- disponible en todo momento que permite visualizar el campo Eléctrico con vectores: los cuales indican su sentido con el color rojo. el blanco es el  origen.
![alt text](docs/gifs/campoElectrico-gif.gif)
- en el caso de estar trabajando con conductores el botón dibujar campo Eléctrico, también actualizará y mostrará la inducción de cargas generadas por el sistema.
![alt text](docs/gifs/cargasEsfericas-gif(2).gif)
### dibujar HeatMap Potencial Eléctrico:
- calcula el potencial eléctrico en todo el mapa solo para las cargas Fijas no conductoras, representa con colores mas fuertes los valores altos de potencial
![alt text](docs/gifs/potencial-gif.gif)
### guardar cambios e iniciar simulación
- cuando tenemos una carga libre, se comenzará a calcular las fuerzas y su movimiento. te lleva a la ventana [programa Ejecutándose](#venta-programa-ejecutandose)
![alt text](docs/gifs/SimulacionParticulaLibre-gif.gif)


## Venta Programa Ejecutándose
- Botones dibujar vector fuerza y velocidad: muestran en tiempo real los vectores de fuerza y velocidad que siente la partícula libre
- Datos partícula libre: muestra todos los datos de posición,fuerza y velocidad en módulo
- también permite ingresar un punto de estudio mientras el programa se ejecuta [ver punto estudio](#punto-estudio)
- dibujar campo Electrico y potencial Eléctrico [Campo Electrico](#dibujar-campo-electrico) [Potencial](#dibujar-heatmap-potencial-electrico)
- Pausar Y Reanudar Programa
- Detener Simulación: retorna la carga Libre a su punto inicial y te devuelve a la ventana Programa Detenido [ver Programa Detenido](#programa-detenido)
- El programa se detendrá Automáticamente cuando la partícula Libre colisione, ya sea con una carga fija o un Plano Infinito.










