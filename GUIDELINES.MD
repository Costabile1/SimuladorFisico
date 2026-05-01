# Pautas Seguidas en la Creacion del Proyecto
- Este proyecto fue creado con fines educativos, no solo para ayudar a estudiantes y profesores como se planteo en los [objetivos], sino tambien para mi propio aprendizaje sobre el lenguaje C++, librerias y mas importante enfrentarme a crear un proyecto solos.
- Este proyecto fue creado desde 0 por mi, con la intecios de enfrentarme a los problemas que eso implica uno a vez y poder superarlos sin ayuda de la Inteligencia Artifical.
- Tenia prohibido hacer preguntas a la IA de logica o de infraestructura del proyeto como por ej: como crear las clases de este pryecto, como organizar correctamene el IMGUI, como dibujar todas las cargas en un condutor de radio x, etc.

# Por que no usea IA en este proyecto?
### Una de las pautas era enfrentarme SOLO desde 0 a un proyecto Real
- considero que usar AI hubiera opacado esta pauta.
- en especial si delegaba cosas a la IA como pensar la estrucutraa del proyecto, las clases, o las logicas mas importantes. actividades que considero seran de gran importancia en el futuro.
### Logica y Estructuras pensadas por mi.
- considero que a fines de poder resolver problemas utilizando mi razonamiento y nivel de abtraccion fue la mejor decicion. Desde el nivel mas alto de abtraccion com por ej: como seria las Clases y que atributos tendrias, hasta los niveles mas bajos como ej: como recorrer todo el mapa, elejir un punto y calcular el campo electrico respecto a la cargas que tengo en el mapa. Tareas y desafios como estos fueron lo que mas me hicieron crecer y avanzar en el proyecto.
- Creo que ese tipo de situaciones son las que mas te hacen crecer y aprender, ya que considero que las tareas de abstrqacion, reordenar el problema en partes mas pequeñas y pensar y estrucutrar todo antes de hacer una linea de codigo son las mas importantes en un proyecto y las mas enriquesedoras a nivel personal.
- Aun que las logicas y estructuras no sean ni las mejores ni las mas eficientes, son 100% autenticas.

# Cosas que Aprendi a lo largo del Proyecto
- Pensar, organizar, diagramar ideas y logica antes de empezar a escribir una linea de codigo fue con lo que mas me encontre en este proyecto, por lo gereral iba escribiendo codigo mientras pensaba la logica, lo que no solo me hacia mas lento, sino que a largo plazo hacer un cambio era cada vez mas dificil. en las ocasiones que me tome el tiempo de pensar una logica eficiente y diagramar las ideas, los cambios a futuro fueron faciles, casi como si todo fuera encajando perfectamente.
- aprendi que haccer funciones que hagan muchas cosas no siempre es lo mejor, ya que muchas funciones aveces pueden ser requeridas por otra funcion
- Aprendi a documentar aun que sea de forma muy simple lo echo en el dia y los cambios implementados, cosas que solucione o que rompi, y las tareas pendeitentes para el proximo dia. Esto me permitio ser mucho mas eficiente, siendo que era mucho ams facil ponerme a tono cada vez que me sentaba, leyendo lo documetad de los dias anteriores, que intentando recordar lo echo o leyendo todo el codigo.
- siempre intente hacer el codgio los mas simple posible, pero me encontre con casos en que simplemente era imposible o muy dificl simplificar logica compleja, aprendi que hay tareas y funciones que simplemente son complejas y necesitan un codgio asi.
- Aunque siempre intentaba terminar la itercion o el trabajo echo en el dia con el codigo funcinando, hubo muchas veces que tube que enfrentarme a que simplemento no podia resolver tal problema en ese momento, documentando lo echo y lo que faltaba por hacer, los problemas por los que no funcionaba y posibles soluciones para implementar otro dia.
# por que SFML?

# por que IMGUi?


### Objetivos version ALFA 0.0.1 ### TITULO: El Origen de la carga puntual y los vectores
- cosas que ya tenemos:
    colocar cargas fijas y moviles en la pantalla
    graficar correctamente el mapa potencial
    graficar los vectores fuerza y velocidad (falta dimencionarlos correctamente) y que sean una flechita
    sistema GUI basico (falta revisar y toquetear todo para que no se rompa, mostrarles a los usuarios las unidades)

- que neceitaria tener para que sea una buena herramienta de estudio y enseñanza de campos ELectricos
    mostrar vectores campo electrico en todo el mapa
    poder elegir un punto y ver valores del campo electrico y potencial
    tener a vista los valores modulares de vector velocidad y aceleracion y fuerza (opcinal mostrar en componentes x,y)
    poder representar un eje.

- Objetivos a terminar:
        1-mejorar la visualizacion del potencial (completado)
        2-mostrar vectores campo electrico en todo el mapa (completado)
        3-poder elegir un punto y ver valores del campo electrico y potencial (completado)
        3,5-intentar poner los vectores fuerza y velocidad arriba de la particula para que se vean mejor. (completado)
        4-tener a vista los valores modulares de vector velocidad y aceleracion y fuerza (opcinal mostrar en componentes x,y) (completado)
        5-poder representar un eje. (completado)
        6-Ordenar el gui, para que solo puedas tocar las cosas que debes (completado)

- Nuevos Objetivos:
        1-cmabiar las clases, crear clase general, =>cargaMovil, CargaFija e implementarlo en el codigo (completado)
        2-la carga de estudio no va tener aceleracion ni funcion update() (completado)
        



### BETA v0.1.0  TITULO: Saliendo de lo Puntual hacia el Infinito y mas alla
- planos infinitos (completado)
- que cada tipo de carga tenga su propiafuncion calculoCampoElectrioc(), ya que depende de la forma. (completado)


### v1.0.0 final: Cargas con radio 💀
- cargas con radio, potencial constante dentro. (completado)
- cargas con 2 radios (comletado)

# Objetivos ranqueados 
- progreso actual: objetivo 3
## Basico (Completado)
- crear un programa que siga las relgas de la POO
- Simular con exito el moviento de una sola carga con respecto a una o mas cargas Estaticas de ambos signos
- Solo interactuaran 1 carga en movimiento a la vez
- representar los vectores fuerza y velocidad

### 2,5 
- representar de forma visual el campo Electrico y los vectores
- representar el potencial en la ventana de facil visualizacion, (no numero enormes o diminutos) 
- mejorar la visualizacion de los vectores

### 3
- repersentar otro tipo de cuerpos que no sean solo particulas puntuales
- representar hilos infinitos, planos (todos con gran simetria)                                                       
- elementos como cilindros infinitos y esferas huecas(hay muchos ejercicios de eso en las materias de fisica3)
- acomodar y consensuar tamaños para que puedan representar de la mejor forma las situaciones reales o como minimo que sea coherentes y representativos para ejercicios de fiscia3 nivel universitario

### 4
- realizar calculos complejos para poder resolver los ejercicios
- Representar cuerpos que no sean simetricos, como varillas cortas o cruvas
- integrar el campo magnetico en la simulacion
- considerar simulaciones 3d
