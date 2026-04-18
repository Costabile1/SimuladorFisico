# Requisitos
-instalar MingWL
-isntalar SMFL para windos
-incluir el paht del archivo include, descargado en SFML en properties.json
-crear el archivo makefile con:
    compile con la ruta al archivo include de SFML
    ejecutar: con la ruta al lib del archivo SFML 



### Objetivos de este Repo ###
-Simular correctamente las interaciones Electrodinamicas entre cargas de dsititnas formas y tamaños, utilizando las ecuaciones fisicas de la electroestatica y electrodinamica clasica.
-el obetivo es representar de forma visual las intearcciones entre las cargas y campos Electricos para que los estudiantes puedan visualizar de facilmente los ejercicios que se dan en materias como fisica3
-el principal objetivo es poder visualizar las interacciones para facilitar el entedimiento y el estudio de topicos dificiles de entender por su nivel de abstraccion y al ser cosas que no nos encontramos en el dia a dia, como campos vectoriales Electricos, interacciones entre cargas, relacion entre carga=>campoElectrico=>potencial=>fuerzadeCoulomb=>movimiento.

### Objetivos version 0.0.1 ### TITULO: El Origen de la carga puntual y los vectores
cosas que ya tenemos:
    colocar cargas fijas y moviles en la pantalla
    graficar correctamente el mapa potencial
    graficar los vectores fuerza y velocidad (falta dimencionarlos correctamente) y que sean una flechita
    sistema GUI basico (falta revisar y toquetear todo para que no se rompa, mostrarles a los usuarios las unidades)

que neceitaria tener para que sea una buena herramienta de estudio y enseñanza de campos ELectricos
    mostrar vectores campo electrico en todo el mapa
    poder elegir un punto y ver valores del campo electrico y potencial
    tener a vista los valores modulares de vector velocidad y aceleracion y fuerza (opcinal mostrar en componentes x,y)
    poder representar un eje.

    Objetivos a terminar:
        1-mejorar la visualizacion del potencial (completado)
        2-mostrar vectores campo electrico en todo el mapa (completado)
        3-poder elegir un punto y ver valores del campo electrico y potencial 
        3,5-intentar poner los vectores fuerza y velocidad arriba de la particula para que se vean mejor. (completado)
        4-tener a vista los valores modulares de vector velocidad y aceleracion y fuerza (opcinal mostrar en componentes x,y) (completado)
        5-poder representar un eje. (completado)
        6-Ordenar el gui, para que solo puedas tocar las cosas que debes (completado)

    Nuevos Objetivos:
        1-cmabiar las clases, crear clase general, =>cargaMovil, CargaFija e implementarlo en el codigo (completado)
        2-la carga de estudio no va tener aceleracion ni funcion update() (completado)
        



## v0.0.2  TITULO: Saliendo de lo Puntual hacia el Infinito y mas alla
    planos infinitos y fragmentos finitos largos
    cargas con radio, potencial constante dentro,
    cargas con 2 radios
    que cada tipo de carga tenga su propiafuncion calculoCampoElectrioc(), ya que depende de la forma.


#### Objetivos ranqueados ##
# Basico (Completado)
    -crear un programa que siga las relgas de la POO
    -Simular con exito el moviento de una sola carga con respecto a una o mas cargas Estaticas de ambos signos
    -Solo interactuaran 1 carga en movimiento a la vez
    -representar los vectores fuerza y velocidad

# 2,5 
    -representar de forma visual el campo Electrico y los vectores
    -representar el potencial en la ventana de facil visualizacion, (no numero enormes o diminutos) 
    -mejorar la visualizacion de los vectores

# 3
    -repersentar otro tipo de cuerpos que no sean solo particulas puntuales
    -representar hilos infinitos, planos (todos con gran simetria)
    -elementos como cilindros infinitos y esferas huecas(hay muchos ejercicios de eso en las materias de fisica3)
    -acomodar y consensuar tamaños para que puedan representar de la mejor forma las situaciones reales o como minimo que sea coherentes y representativos para ejercicios de fiscia3 nivel universitario

# 4
    -realizar calculos complejos para poder resolver los ejercicios
    -Representar cuerpos que no sean simetricos, como varillas cortas o cruvas
    -integrar el campo magnetico en la simulacion
    -considerar simulaciones 3d
