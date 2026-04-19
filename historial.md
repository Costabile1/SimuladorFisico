## este Documento representa lo echo dia a dia

# 29/03/2026
-creacion del proyecto
-intalacion de smfl
-creacion de la clase carga
-actualemten existen 1 carga fija y otra que se mueve
-se ah logrado que una carga sienta la fuerza generada por el campo Electrico de otra y se meuva en base a la leyes de la electroEstatica
-se crearons las funciones calcularDistancia y calcular Aceleracion que siguen el patron:
    calcular distancia_total, distnaica en x, diantancia en y
    luego se calcula las compoentes del campo electrico
    luego las compoentnes de la fuerza
    luego la acelelracion y se actualizan los valores de aceleracion en la clase carga
    mediante una funcion update(), se calcula la nueva posicion utilzando la clasica formula de movmiento uniformemetne acelrado en ambas cordenadas

--A resolver:
    -como sulucionar cuando la disntaica=0;
    -colisiones
    -probar poner otra carga y de distintos signos
    -signos de la aceleracion (nose porque funciona, pero funciona)

# 31/3/2026
cambios:
    -ahora los objetos se encuentran en 2 arreglos, cargasFijas y cargasLibres.
    -actualizarAceleracion (que no hace lo que dice) => ahora itera por cada elemento en las cargasLibres y por cada elemento en CargasLibres por ende, hace cada cargaLibre contra todas las Cargasfijas de la libre, por cada fija calcula distancia con la libre de referencia y calcula los componentes del campo electrico y los suma en una variable por cada fija, para obtener el campo total en el punto de la libre de referencia. luego por cada libre de referencia toma el campo total, calcula la fuerza en cada componente y llama a update que calcula la aceleracion y actualiza la posicion.
    -UPDATE() antes estaba mal la ecuacion de cinematica, le pasaba deltaT desde t=0 a t=t, lo que no predecia el movimeinto en cada instante.
    -ahora la ecuacion de cinematica es => posicion actual(no es mas la inicial) + 1/2 aceletacion por un deltaT^2 (donde deltaT esta definido arbitrariamente)
    -luego actualiza la posicion en el graficador y actuliza la nueva posicion setenadoa a la posicion actuaal, para el proximo movimeinto.
    -cree la funcion vereficarColision, que compara cada libre con todas las fijas.(mismo bucle for que actualizarAceletacion)
    -por ahora solo detecta la colision, seta la aceltacion de la libre a 0 y la manda a otro punto del mapa.

    por ende actualemtne la logica es:
        -calcular distancia
        -calcular campo total
        -calcular componentes fuerazas
        -pasarlas a  UPdate() => donde va a resivir las fuerzas de el campo y tiene 2 parametros mas para fuerzas por colision
        -Update() => deberia sumar todas las fuerzas 
        -leugo calcualr la acelracion
        -calcular el movimeito
        -actualizar el moviento en el graficador


    Objetivos cumplidos de la anterior:
        -como sulucionar cuando la disntaica=0; => con la implenetacion de colison
        -colisiones => implementado 

    A resolver:
        -poner mas de 2 crgas fijas o libres
        -implementar colisiones realistas, con rebote y movmineto real
        -probar poner otra carga y de distintos signos
        -signos de la aceleracion (nose porque funciona, pero funciona) 

## cambio de objetivos
    =>centrarse en hacer un simulador fisico de electrodinamica
    =>mostrar un mapa con los potenciales y vectores cmapo electrico en toda la ventada
    =>mostrar los vectores fuerza que se ejercen en la carga puntual
    =>la simulacion termina cuando hay una colision
    =>los rebotes quedan mas para adelante.

# noche 31/3/2026
    =>implemente la funcion PotencialElectrico
    =>investigue como escribir y poner letras y numeros en la ventana, para podes representar los valores del potencial en pantalla

# 01/04/2026
    =>Complete y deje funcionando correctamente la funcion potencialELectrico
    =>esta mismta tiene una complejidad n^3 => ya que se necesitan 3 bucles for anidados, los 2 primeros para recorrer el ancho y largo del mapa dividiendolo en cuadriculas iguales, de las cuales tomo el centro como distancia, y el ultimo para iterar por todas las particulas fijas que por el principio de superposicion calculamos el potencial
    =>agrege el archivo arial.ttf para poder tomarlo de fuente si necesito escribir en la ventana.(nose si realmente funciona o se usa la fuente base)
    
    problemas:
        =>los valores del potencial son muy altos y dificiles de ver en la ventana.
        =>seria mejor probar con colores gradientes o cuadriculas coloreadas para representar el potencial
        =>las particulas no puede oscilar por que actualmente el movimento solo depende de la poscion actual y la aceleracion
        =>necesito tener en cuenta la velocidad.


# 02/04/2026
    =>arregle la ecuaciones cinematicas, ahora tengo en cuenta la velocidad, Carga tiene como atributo vX y vY
    =>como es le proceso: calculo la aceleracion, aplico la ecuacion cinematica clasica, y actualizo la velocidad para la proxima iteracion
    =>se representa correctamente el movmiento oscilatorio
    =>los movimientos ya se ven realmente increibles...
    =>impementacion de vector fuerza, muestra el modulo de la fuerza en la direccion correcta que siente la carga movil

    Siguiente:
        =>los valores del potencial son muy altos y dificiles de ver en la ventana.
        =>seria mejor probar con colores gradientes o cuadriculas coloreadas para representar el potencial
        =>mostrar vectores de la fuerza, para saber que pasa en todo momento

    
    Problema:
        =>el centro geometrico de las esferas no cioncide con el setPosition() => cuanto ams grande es el radio mator es la diferencia.
        
# 3/04/2026
    =>solucionado el problema de que el centro geometrico no coincidia con el real cuando se aplicaba un aumento de radio a las cargas
    =>fue solucionado con la funcion actualizarPosicion que llama a setPosition() con los valores en x,y -radio ingresado a la carga
    =>implementada la funcion vectorVelocidadCarga 

    siguientes pasos:
        =>los valores del potencial son muy altos y dificiles de ver en la ventana.
        =>seria mejor probar con colores gradientes o cuadriculas coloreadas para representar el potencial
        =>la funcion vectorVelocidaCarga y vectorVelocidadCarga son muy similares y podia reutilizar una sola funcion
        =>campo Electrico vectorial.
        =>otro tipo de cargas.


# 4/04/2026
    => trabaje en poder mapear los valores de los potenciales en toda la ventana a un gradiente de colores
    =>logica de el proceos:
        =>recorro el vector de 2 dimenciones y guardo en un diccionario los key:potencial y value:posicione en la ventana
        =>creo otro diccionario mapaColor <float,string> será el valor del potencial y un string hexadecimal que significa el color.
        =>implemente las funciones rgbTOHex() y getHex()
        =>la logica de los colores es que arracamos con (255,0,0) (rojo) y voy aumentando g y b de formalineal +1 para ir aclarando los colores
        =>luego el color hex se utilizara para ponerle el color a la ventana
        =>reccorro el diccionario anterior ordenado de menor a mayor y los guardo en el diccionario mapaColor
        
        problemas:
            =>para la posicion utilizo el tipo de dato Vector2(), el cual no tiene funcion hash y no puede ser utilizado en un tipo map ni en un timepo unorder_map.
            =>lo que imposibilita recorrer la ventana y acceder a los diccionarios por posiccion para obtemer el valor del color
            
        posibles soluciones:
            =>implementar funcion hash
            =>implementar otra logica ej: recorrer los colores y obtener las posiciones.
            
        siguientes pasos:
            =>cambiar la forma de dar el gradiente de colores, que no sea lineal, que depende de la diferencia de potenciales
             =>la funcion vectorVelocidaCarga y vectorVelocidadCarga son muy similares y podia reutilizar una sola funcion
            =>campo Electrico vectorial.
            =>otro tipo de cargas.

# 6/04/2026
    =>al final la logica es asi para crear el gradiente de colores
        =>recorro el arreglo multidimencional y lo pongo en un arreglo arrAux de una dimencion
        =>ordeno de mayor a menor el arrAUX
        =>y creo un diccionario con <potencial,color>
        =>luego recorro la ventana y en cada lugar accedo al diccionario para obtener el color con la key[potencial] en ese lugar

    problemas:
        no funcionan correcctamente los colores


    =>se solicionaron los problemas y se muestran los colores correctamente en la ventana.
    =>se implmento pasar de hexTorgb para obtener poder pasarle cada valor rgb a la clas sf::Color
    =>se corrigio la funcion rgbToHex que funcionaba mal
    
    observaciones:
        =>aun que se muestra bien los colores, el patron no se codice correctamente lo que esperaria ver en el potencial de una esfera.

    suiguiente:
        =>implementar toda la logica en una funcion que muestr lso colores y que se hagan los calculos una sola vez la primera vez que se recoore el primer while infinito.


# 07/04/2026
    =>finalemente se muestra el potencial de forma correcta en la ventana
    =>se implemento la funcion drawPotencialHeatMap, que se encarga de retornar un sf::texture, con los colores adecuados segun el valor del potencial
        -logica de la misma:
            =>llamamos a potencialElectrico (retorna el arreglo multicimencional de potenciales) y se lo pasamos mapaPotencialElectrico (que ordena el el arreglo multicimencional de potenciales en un arreglo de una sola dimecion, luego crea un mapa con los potencuales y le asocia un color hex, y retorna este mismo diccionario)
            luego rrecorremos el largo y alto de la ventana seguno la cantidad de cuadriculas
            por cada cuadricula, obtenemos el potencial, el usamos como key para obtener su valor hex asociado.
            convertimos hex->rgb
            cremamos una varivale sf::color donde almacenamos cada uno de los colores en rgb y agregapos opacidad arbitrariamente
            -finalmente recorremos el objeto sf:.imagen fondo (que tiene el mismo tamaño que al ventana) y asignamos a cada cuadricula pixle x pixel el color asociado
            finalmente retornamos la textura y la guardamos en la funciona principal

            observacion: hacemos el calco una sola vez, y dejamos guardada la textura y esta es la que usamos para pintar la ventana en cada iteracion, (ahorramos tener que llamar a esta funcion pesada muchas veces.)

            
    =>se modificaron las funciones:
        std::string rgbToHex(int* rgb);
        string decimalAHexadecimal(int decimal);
        char getHex(int n);
        int getnum(char c);
        void hexTorgb(std::string hexa, int rgb[3]);
        -se hace uso de la libreria <algorithm>
        (ahora se pasa de forma correcta de rgbTorgb y hexTorgb)


    siguientes pasos:
        =>contamos con muy pocos colores (solo 255), si queremso mas cuadriculas para mas prescicion nos quedamso sin colores
        =>solucionar eso y tener el cuenta la cantidad de cuadriculas para los colores
        =>obj: mostrar el mayor gradiente de color posible para visualizar de forma simple
        =>agregar el ejecutrar a la rutina
        =>fascilitar y ordenar el main
        =>documentar correctamente el proyecto
        =>agregar campo electrico vectorial y otras formas


    noche:
        => me mande directamente a hacer la interfaz GUI para adelantar todo
        =>despues de muchas vueltas me quede con la mas simple de todas ImGui
        =>la cual hay que descargar desde github imgui y imgui-sflm
        => copiar las carpetas .cpp y .h en de ambas en el directorio (yo lo hice en una carpeta dentrode del mismo)
        =>luego cambie toda la rutia de copilacion y ejecucuin para para que agregara el motor de ImGUi
        =>se hicieron algunos cambios para en el codgio para que todo funcionara:
            IMPORTANTE: por problemas de vercionado se hizo el sigueinte cmabio:
            ImGui/imgui-SFML.cpp linea 959=> se comento:  //assert(io.Fonts->TexID != (ImTextureID) nullptr); 
                                        => se agrego:  assert(true); // Parche temporal: Conflicto de tipos en SFML 3
            #include "imgui.h"
            #include "imgui-SFML.h"
            //leugo de inicializar la ventana
            ImGui::SFML::Init(window);
  
            sf::Clock clock; =>=importnate
            while (window.pollEvent(event)) {
                ImGui::SFML::ProcessEvent(window, event); // <--- OBLIGATORIO

                if (event.type == sf::Event::Closed)
                    window.close();
            }

            ImGui::SFML::Update(window, deltaClock.restart());

            // 2. Definir la interfaz
            ImGui::Begin("Propiedades de la Carga");
            ImGui::Text("Ajusta los valores fisicos:");
            ImGui::SliderFloat("Masa", &miVariableMasa, 0.0f, 100.0f); 
            ImGui::End();


            ImGui::SFML::Render(window); => antes de windoy display

            ImGui::SFML::Shutdown(); =>al terminar el programa

        comentarios:
            =>adelantare esta parte para tener un proyecto principal lo antes posible.
            =>plantiare los obejtivos de deste GUI
            =>luego seguire con las tareas pendientes en un futuro.

# 08/04/2026
    que parametros se van a poder ingresar desde el GUI:
        -cantidad de cargas fijas
        -posicion,valor,masa y radio de ambas
        -si quiero ver:
            -vector velocidad
            -vector fuerza
            -mapa potencial


    cambios:
        cambie el fujo del programa agreando otro while, ver diagrama
        implemente una funcion VentanaConfi()
        que se encarga de manejar toda al configuracion, le paso por parametros variables y deja actualizar todos los valores de las cargas.
        la funcion retora true si hubo algun cambio en elgun input, sale del bucle principal, se actualizan los datos y se vuelve al principal

    observaciones:
        un largo variable de la cantida de cargas fijas hace que tenga que gestiona la memoria en tiempo de ejecucion, o podria simplemente usar un vector de gestiona utoamtica de memoria
        
    problemas:
        los for no funcionan en imgui por que desaparecen
        todavia nose si se cambian bien los datos de las cargas
        el realloc explota el programa !!


    =>problemas con el id de las label
    =>problemas con la carga libre, la poscion de nan
    =>cuadno calculo al fuerza da NaN, nose por que

# 09/04/2026
    =>se completo la integracion de ImGui para el ingreso de datos por pantalla de forma correcta con todas las fucionalidades que tenia el programa hasta la fecha
    =>las simulaciones ocurren de forma correcta

    =>esta tranquilamente podria ser la primera version del programa ya que todo funciona
    haasta la fecha esta es la v1.0.0
    =>mentira:
    cosas a arreglar:
        =>tamaño de ventana (listo)
        =>cerrar el programa de un click (listo)
        =>que el vector fuerza y velociadad se sigan mostrando por mas que se detenga la simulacion.
        

    problema con el tamaño de ventana:
        =>cuando se muestra el potencial con un ancho distinto a 1000x1000 se rompa texture
        =>el problema nace de la funcion potencialElectrico() en esta linea:
        nt anchoCuadriculado = _ANCHO/cant_cuadriculas.x; => si se harcodea 1000 funciona
        =>intento rastrear el error pero todo parece funcionar bien
        =>pero cuando se carga la textura da este error: Failed to resize texture, invalid size (0x1000).

# 10/04/2026
    =>nada, dia terrible, no encontraba de ninfuna forma por que explotada el sife,
    cuestioen que me rendi y le tuve que mandar la funcion a gemini
    =>cuestion que pasaba por parametro un arr rgb[3], a una funcion hextorgb que retornaba los colores en rgb, cuestion que esta funcion aveces retornaba 4 colores, rgba, el ultimo de opasidad, eso hacia que se pisara la memoria de la llamada a size, que estaba literalemnte al lado en memoria.

    =>cuestion solucionado eso, funciona todo como piña,

    porximo:
    =>cambiar el algoritmo que da colores al potencial para que sean maas visibles, actualmente si pongo una cantidad de cuadrantes muy peqieña ni se ve el color potencial
    => tambien no estoy teniendo en cuenta el tamaño de la particula(pero bueno eso seria para manda adelate creo con cargas no puntuales)

    =>que el vector fuerza y velociadad se sigan mostrando por mas que se detenga la simulacion.
    =>para eso deberia hacer varios cambios en elbuclo while

    final:
    se hicieron varios cambios:
        se agrego otra variable de control para poder pausar la simulacion y volver a reanudar la simulacion
        a difenreic a de detenerprograma que setea la acelracion de la aprticula, ideal para moverla y ponerla en otro lugar
        ordene un poco el main
        y ya el vector velocidad y aceleracion se ven correctametne con el programa corriendo, ya que cree unas variables vectores y las paso por parametro a las respectivas funciones, asi puedo almacenar el vector y seguir dibujandolo por si solos
        en general un re quilombo este dia, no preseste100% atencion a lo que hacia, asi que pued haber quedado todo raro

        actualizacion(al final todo quedo bien) 12/04/2026


    Temas:
        muchas variables globales se siguen pasando por aprametro
        hya muchas variables que podrias ser globales y evitar pasarse por aprametro

    siguientes pasos:
        campo vectorial ElectricoS


# 11/04/2026
    impleemnte la funcion que te permite crear un eje cordenado y poner el origen 0,0 donde quiera
    haciendo que las cargas inicien en la posicion correcta con respecto al eje
    este poscionamiento se hace una sola vez cuando hay un cambio en el boton de iniciar simulacion

    Problema:
        el eje cordenado y esta dado vuelta.


    implemente las funciones de calculo de campo Electrico y la funcion que lo dibuja, funcionan bien
    utilize un arreglo bidimecional que almacena Vectores2F con los compoentes del campo electrio
    luego itero por ellos y los dibujo

    problema a resolver:
        =>serca de la carga los vectores se van re al carajo, quiero limitar que si el vector es muy largo, se acorte, pero nose aun como ahcer esa funcion si que el vector cambie de diresccion.

# 12/04/2026
    resolvi el tema que los vectores se iban al re carajo cerca de las aprticulas implementando una funncion escalarVector()
    lo que hace es que si el largo de un vector es mayor a algun parametro, actuamente 60, lo rescala para que tenga el maximo de alrgo permitivo que claramente tambien es 60
    =>mostrar el campo vectorial tiene una complejidad computacional que hace qeu todo vaya muy lento o hasta que no responda.
    =>el tema con eso es la longitud de los vectores, a mayor sea el campo, mayor es la longitud media de los vectores, lo que repercute en gran medida en la fluides del programa, pero con cargas razonables puede usarse sin problema
    =>>!!lo unico es que es imposible simular mientras es campo electrico se muestra, va muy lento
    Opcional: podria buscar la forma de guardar el campo vectorial como fondo textura, lo que haria que no haya que recorrer el arreglo de campos electricos y calcualr cada uno de los vectores como hacemos con el potencial

    Implementaciones:
        =>mejore la visualizacion del mapa potencial, ahora hay una gama de colores mucha mas amplica y alcanza para mostrar con fidelidad el campo potencial
        
        =>mejore y optimize el gran medida el Gui, ahora esmucho mas claro, solo se te permite realizar acciones que realmente tenga sentido
        ahora el programa tiene 3 estados, detenido, pausado o corriendo, cada uno tiene sus acciones que puede ahcer y las muestra y las que no estan ocultas.

        => implemente que se pueda ver la posicion,velocidad y fueza en modulo y componentes de la particula libre
        =>solucione el tema de que el ejeY esta dado vuelta, ahora el ingreso de datos es con el eje Y hacia arriba, al igual que como se muetran los datos. multiplique todo lo que se muestra +(-1) y ya al usuario le va aparentar que el eje y esta hacia arriba.

    Siguiente:
        =>poder calcular campo, potencial en un punto
        =>poder poner una particula ficticia en algun punto, para poder calcular la fuerza que siente y demas cositas
        :nose como hacer lo de la particula, ya que muetra los datos una vez el programa se dispara.
        =>!!!tal vex podria hacer configurable el valor del tiempo para que el programa pueda ir a distintas velocidades, una velocidad muy lenta te dejaria ver los valores iniciales, pero no con tanta precicion
        =>deberia implementar una particula ficticcia que no este en el arreglo de cargasLibres, que se use y se tire.

    
# 13/04/2026
    =>agrege que se pueda poner un punto para calcular el campo eelectrico en componentes y potencial, pero da cualqueir cosa
    =>cambie el orde y ahora los vectores velocidad y potencia se ven correctamente arriba de la particula


# 14/04/2026
    =>hacer una particula artificial aparte, funciona como el orto, si quiero que se comporte bien tendria que utilizar las funciones ya creadas que si funcionan bien, nose por que con lo nuevo que hice se rompe todo.
    ahora que lo pienso nisiquiera se como funciona el tema de la posiccione en la particual libre
    por que seteo x-original, le agrego el ofset, y mando a actualizar movimiento, pero en que momento seteo cargalibre.x, ni puta idea, nose como funciona eso.
    el codigo ya adquirio cierta complejidad, y con lo de agregar un punto de estudio solo complique las cosas, por que quise hacerlo tipo parche y nose por que las cosas andan re raras, el sistema esta echi para funcionar con las clases y la carga, deberia seguir por ahora
    pero ya cerca de las 1000 lineas el codgio se hace mas enrevedado y dficil de seguir, por mas que intente mantener las cosa moduladas

# 16/04/2026
    =>cambie los arreglos de cargas por vectores de clase, carga para las fijas y cargaLibre para las libres, basicamente cambie absolutamente todo el codigo, casi que para nada por que la idea era hacer un vector cargaLibre que contenga la carga libre como la carga de estudio, la cual no tendria metodo update(), pero creo que no es posible eso, porlomenos con lo que se ahora.
    pornde fue medio al pedo, vectores y punteros por todos lados para que haga lo mismo
    pero ahora se comporta distinto, el vector velocidad es mucho menor que antes, acelera menos la aprticula, tengo que corroborar si eso es correcto o esra roto.
    polomenos aprendi a agregar una clase hija y ahora todas las funciones calcualrCampoElectrico y potencual como van a depender de la forma de la carga es un metodo de la clase, no esta mas suelto en el codigo.
    y ahora al ser un vector el vector de cargasFijas es dinamico.
    faltaria la tarea mas aburrida que es corroborar que todo funcione
    al final el objetivo era meter una carga de estudio sin hacer funciones especificas para eso pero no lo logre.
    imagino que c permite eso pero creo que es muy dificil, necesiyaria un conocimiento de POO en c que no tengo lamentablemente.

    Proximos pasos:
        hacer todas las funciones para que de informacion de una particula de estudio en un punto fijo. podria hacer una variable que controle si es de estuido, que haga que no llame a update, para poder ver las fuerzas en ese punto y safo de agreagr otra carga
        y despues tengo que ver lo del punto de estuido que te de el valor del campo y del potencial, que nose porque estaba todo roto antes, borre todas las funciones asi que tengo que hacerlo otra vez.

    el programa copila pero ahora nose por vscode no me reconoce SFML asi que tengo que ver eso tambie.

    proximos pasos:
        =>dibujar el vector en x en Y y el total en el punto estudio
        =>hacer que el punto de estudio este centrado
        =>dibujar el numero del potencial en la pantalla?


# 17/04/2026
    Logica de Plano infinito:
        lo vamos a crear un muchas cargas ordenadas en una columna larga de largo =largo de la ventana(tal vex mas para evitar problemas con el campo de las otras cargas), solo se podra mover en X, en Y esta fijo
        para calcular el campo vamos a hacer la particula, contra todas las demas? (computacionalmente dificil) ya que vamos a iterar continuamente por un montont de cargas.
        Ademas solo va a haber carga por celda, por ende el margen de error puede ser mas alto
        para dibujar los vectores del campo electrico va a ser mas facil ya que vamos a iterar por las celdas en x,y, dependiendo de la fila en la que estemos solo vamos a calcular el campo contra la carga en su fila, de esa forma solo habra campo en X, lo cual coincide con el campo de un plano
        (MENTIRA) por que me acorde que hay uan ecuacion fija para el campo electrico y ademas el campo electrico de un plano Infinito es constante.

        =>finalize lo de mostrar los vectores campo electrico en el punto de estudio en modulo y componente y el punto ya esta centado.
        =>poner el numero del potencial en la patalla me parece una grasada.
        =>queda arrancar con el plano infinito.

    noche:
        ya arrme las clases Plano para menjar los planos
        =>al final va a ser un rectableshape larguisimo como todo el largo de la pantalla
        y para el campo simplemente voy a usar la ecuacion de planoInfito, solo se necesita pedir la densidad de carga
        =>voy a calcular el campo electrico en todos los puntos, para que se pueda crear un Capasitor con extio,
        =>el maximo de planos infinitos es 4 por ahora y el size de los planos esta totalmente harcodeado en unos valores que se me ocurriones, en ancho=5 y el largo es de 1100 que seria el alrgo de la pantalla.


# 18/04/2026
    =>termine de hacer la funcion que calcula el cmapo electrico con las placas, funciona Perfecto
    =>pude hacer que vaya en coherencia con el campo de las particulas (PARA DIBUJAR LOS VECTORES NOMAS)
    =>las particulas de estudio y las libres no las sienten ya que tienen sus propias funciones e iteran por solo las cargas fijas
    =>tambien cambie los vectores para darme cuenta para donde van(es temprar creo pero veo imposible hacer una flecha ya que dependeria mucho de para donde va el vector)

    a realizar:
        =>que las aprticulas y punto estudio tengan en cuenta las fuerzas de los planos
        =>opcion: calcular el campo total, con todos los chiches que lo pueden cambiar (QUE YA LO HAGO)
        y directamente pasarse por parametro a las funciones de estas
        =>tambien deberia aclarar y esclarificar todo el proceso de calculo de campos, ya que aveces es un puntero y otra vezces es literalmente el campo, es un nudo terrible
        ASI QUE PRIMERO TENGO QUE ARREGLAR ESO.

    !!inportante: me di cuenta que los std::cout relentizan una locura el programa. en especial cuando enstan en loop(obviamente)

# 19/04/2026
    => pude con exito hacer que las cargas libres y los puntos de estudio sintieran enl campo generado por los planos.
    => al final cambie las funciones que calculan el campo para las cargas y los puntos de estudio, simplemente agregre el calculo del campo para el plano y solo sumo ese campo a las componentes X en cada iteracion al campo total
    =>tambien cambie la funcion verificarColision para que detecte con exito las colisiones de las cargas contra los planos
    =>todo funciona correctamente asi que esta seria la version beta
    =>ya hay varias de las funcionalidades finales que me gustaria para sacar la primera version.

    siguientes Pasos:
        =>cargas con radio, potencial constante dentro,
        =>cargas con 2 radios
        =>cargas Huecas. con todo lo que ello conlleva, que adentro no haya campo si no encerramos carga para respetar la ley de gauss
        =>por ahora el radio solo es visual y para verificar colisiones, estamos trabajando con las cargas puntuales.
        =>para cargas con radio real tendria que usar otra ecuacion, ej la de gaus para calcular el campo Electrico, pero nose como lo voy a ahacer aun
        =>es algo complejo pero me pareece importante agregarlo.
        