# Tutorial Basico

## instalacion.
- Primer paso, tener todo instalado
- installa el zip MLyMSimuladorFisicovx.x.x.zip
- Descomprimilo
- haz cli en el ejecutable sfml-simulador_fisico-app.exe
- se arbira una interfaz y lo primer que deberias ver es:
![alt text](docs/img/Mapa.png)
- si ves eso podes seguir

## Entorno
- La ventana Principal de fondo negro sera nuestra area de trabajo, ahi va a pasar todo
- La ventana mas pequeña sera nuestra Ventana de Configuracion, ahi vamos a ingresar todos los datos.
- Podes hacerle click a la ventana de conf, moverla y achicarla por toda la ventana principal

## Primeros Pasos
- Siempre es recomendable ingresar un Eje.
- Una de las Primeras cosas que veras sera ingresar un eje, donde ingresaras las cordenadas.
- Clikea mostrar Eje para setearlo correctamente.
- proba varios valores para familiarizarte y ver como se mueve el eje por la ventana principal.

## Cargas, Planos Y Esferas
- Podes Agregar tu Carga Movil directamente desde el la venta conf (aparecera en color amarillo)
- Podes Agregar cargas fijas y planos haciendo click en el +.
- Se desplegara un menu ahi mismo en la vetana conf. donde ingresaremos los datos.
- Podes Agregar cargas y planso juntos. Pero Agregar Cargas Esfericas Imposibilita agregar planos o cargas Fijas
- Dibujar Campo Electrico  y Dibujar Potencial
- Dibujar campo Electrico con Conductores esfericos hara que se induzcan cargas entre ellos.
- Iniciar simulacion hara que empieze a correr el tiempo para tu carga Libre y comenzara a simular su movimiento.

# Factores
- la variable tiempo que nos sale al principio indica con la presicion que el programa hara la solucion. Un valor mas bajo, hara que las cargas se muevan mas lento pero de forma mas precisa.
- Factor Escala escala el sistema para que podamos verlo mejor. !Importante: factor escala Escala todo respecto al eje que pusiste, es recomendable trabajar con un eje si vas a escalar el sistema y poner alguna de tus cargas en el 0,0 para que se escale respecto a esa carga.