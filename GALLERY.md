# Usaremos el Programa para ayudarnos a entender y resolver algunos Ejericios

## Problema 1
![problema1](docs/ejercicios/Problema1/Enunciado.png)
- En el inciso b especificamente nos piden encontrar las cordenadas donde el campo Electrico sobre el eje x se anula.
- En primer lugar ingresamos y dibujamos el eje para trabajar mas ordenados. (Es recomedable siempre trabajar con un eje definido)
- En seguno ingresamos todos los datos en las unidades que el problema nos proporciona, al ser distancias tan pequeñas nos conviene cambiar el factor escala hasta un punto sean apreciables las distancias entre las cargas, por ejemplo factorEscala= 100000.0 . (Es necesario colocar una de las cargas en eje (0,0) para poder escalar de forma correcta y que todo se vea en la pantalla)
- Luego dibujamos el campo Electrico.
- vamos a poder apreciar siguiendo los vectores dibujados que a la derecha de la carga Positiva es muy probable que el campo se haga =0, por como se dibujaron los vectores en ese punto. Esto nos da una idea visual muy rapida de por donde van los tiros.
![imagenProblema1](docs/ejercicios/Problema1/CamppoDibujado.png)
- Con esta informacion podemos empezar a buscar el punto igualando los compontentes del campo y despejando X.
- En esta ocacion nos dispondremos a buscar la distancia X a mano en el programa.
- Probamos cordenadas distitnas de X con la funcion Punto Estudio y ponemos mostrar datos punto estudio.
- Ya tenemos una referencia visual de donde el campo puede anularse, asi que probamos valors de X en esa zona
- Haciendo prueba y error encontramos un valor muy cercano a 0 en x=341.412 (recordemos que tenemos el sistema escalado por 10^5, por ende nuestro X real encontrado seria 314x10^(-5))
![imagenProblema1](docs/ejercicios/Problema1/Solucion.png)
- chequeamos que la solucion es corrercta y que las diferencias son despreciables debidas a como la computadora redondea decimales.
![alt text](docs/ejercicios/Problema1/SolucionZemba.png)
- Confirmamos que el campo Dibujado con el programa se condice con el presentado en la solucion
![solucion campo](docs/ejercicios/dibujasConfirmacion.png)


## Problema 2
![problema](docs/ejercicios/Problema2/3Placas.png)
- Tenemos un sistema formado por 3 placas que pueden considerarse infinitas, en problema no especifica valores especificos pero si los suficientes como para recrear el problema.
- Ingresamos las 3 placas Infinitas, y le asignamos a cada una la relaciones de cargas que da el problema.
![sols](docs/ejercicios/Problema2/Solucion1.png)
- el punto a) nos pregunta por el campo Electrico generado por las placas. vamos a tener 4 zonas donde el campo va a ser disitinto. Para Ayudar con este inciso simplemente vamos a mostrar el campo Electrico.
![sol2](docs/ejercicios/Problema2/Solucion2.png)
- Elejimos a drede esos valores de densidad de carga respetando lo propuesto por el problemaa para ver con mayor presicion como los vectores del campo electrico cambian entre las distintas zonas.
- el punto b) nos pide averiguar el potencial sobre todo el eje x. Podemos ayudarnos de la funcion dibujar Heatmap Potencial para poder ver y entender como se distribuyen los valores del Potencial
![sol3](docs/ejercicios/Problema2/Solucion3.png)
- Adicionalmente podemos usar el Punto Estudio y moverlo por todo el eje x, para averiguar los valores presicion se campo Electrico y Potencial.
