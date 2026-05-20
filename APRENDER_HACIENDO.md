# Aprende Haciendo
- Aca vas a poder crear tu primer Programa paso a paso y aprender en el camino ;).


## Que vamos a crear?
![alt text](docs/AprenderHaciendo/Objetivo.png)
- podemos ver 3 cargas Fijas, Azul (con carga negativa) y Naranja(carga positiva), 2 Planos en los extremos. Y la carga libre (Amarillo), que sera la que sentira las fuerzas y se movera por el sistema.
- Nuestro objetivo es crear el sistema de la imagen paso a paso, y darle a simular para ver como se comporta el sistema.


## Primer paso: Setear los Ejes y variable tiempo
- Lo primero que veras será la ventana de trabajo donde sucederán las simulaciones.
- También verás la ventana de configuración. Puedes moverla clickeando y arrastrando o modificando su tamaño.
- colocar y trabajar sobre un eje de coordenadas siempre es lo recomendable.
- para poner un eje vamos a: colocar eje de coordenadas.
![](docs/AprenderHaciendo/Menu.png)
- ingresamos el valor: 500 en ambos ejes y se desplegará la checkbox: dibujar eje coordenado, la clickeamos para agregar el eje
![](docs/AprenderHaciendo/Eje.png)
- Vamos a configurar la variable tiempo, la cual le dice al programa con que precisión simular los movimientos de la partícula libre. Arriba de todo de la ventana config y seteamos la variable Tiempo de 1 (como estaba por default) a 0.1.
![](docs/AprenderHaciendo/Menu_varTiempo.png)




## Ingresar Cargas:
- ahora vamos a ingresar todas nuestras cargas fijas. para eso iremos a:
![](docs/AprenderHaciendo/Menu01.png)
- le damos al símbolo '+' 3 veces para agregar nuestras 3 cargas.
- se desplegará dentro de la ventana de configuración un menú para ingresar los datos para cada una de tus cargas.
![](docs/AprenderHaciendo/MenuCargas1.png)
- Para ingresar los datos simplemente seteamos los valores de del menú desplegado.
- Ingresamos nuestra primera carga. Ingresa los siguientes datos en tu carga número 1:
- Radio=10.
- Posición X=0.
- Posición Y=-250.
- Carga: -0.0003.
- Masa (la dejamos como esta en 0).
![](docs/AprenderHaciendo/PrimeraCarga.png)
- hacemos lo mismo con las 2 cargas restantes. con los siguientes datos:
- Carga 2:
- Radio=30.
- Posición X=720.
- Posición Y=-30.
- Carga: 0.0005.
- Masa (la dejamos como esta en 0).
-Carga 3:
- Radio=10.
- Posición X=350.
- Posición Y=300.
- Carga: -0.0039999997.
- Masa (la dejamos como esta en 0).
- Con esto ya tenemos gran parte del sistema.
- Podes probar dibujar el campo Eléctrico y el potencial para ver cómo se comportan con esta disposición de cargas


### Ingresamos los PLanos Infinitos
- similar a como hicimos con las cargas, buscamos: Ingrese la cantidad de planos y le damos 2 veces a '+'.
![](docs/AprenderHaciendo/MenuCargasPlanos.png)
- se desplegará un menú dentro de la ventana, para que podamos ingresar los datos.
- Ingresamos los siguientes datos:
- Plano 1:
- Posición X: -300.
- Densidad de Carga: 0.0000000008
- el valor del potencial: 0.
- Plano 2:
- Posición X: 900.
- Densidad de Carga: -0.0000000008
- el valor del potencial: 0.
![](docs/AprenderHaciendo/MenuPLanos.png)
- ya tenemos casi todo el sistema armado, si mostramos el campo eléctrico deberiamos ver lo mismo que en la primera imagen que tomamos como objetivo para este tutorial


## Ultimo Paso: La Carga Libre.
- Esta es por lejos la más interesante
- Esta es la carga que sentirá las fuerzas Eléctricas y se moverá por nuestro sistema.
- El menú de la carga Libre siempre está desplegado en nuestro menú.
- Ingresamos los siguientes valores:
- Radio=5.
- Posición X=-280.
- Posición Y=-400.
- Carga: 0.004.
- Masa : 1.
![](docs/AprenderHaciendo/CargaLibre.png)


## Simular
- Ahora solo queda darle a guardar Cambios e iniciar simulación.
- Una vez con la simulación funcionando nuestra ventana de configuración que conociamos desaparecerá y veremos una nueva, que será nuestra ventana mientras el programa está corriendo.
- Allí podrás ver datos importantes.
- Si le damos a dibujar vector velocidad y vector Fuerza
![](docs/AprenderHaciendo/ProgramaCorriendo.png)
- Veremos cómo se dibuja sobre nuestra Carga libre estos vectores, además de mostrarnos los datos en módulo y componente de los mismos
- También podemos Pausar el Programa cuando queramos, para analizar la situación mejor en estático.
- Luego podes cerrar el Programa en Cerrar Programa.
