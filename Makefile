#cambiar esta linea por la ruta donde tengas tus archivos sfml
SFML_DIR = C:\Users\santi\OneDrive\Escritorio

SFML_PATH = "$(SFML_DIR)\SFML-3.0.2-windows-gcc-14.2.0-mingw-64-bit\SFML-3.0.2"
IMGUI_DIR = ImGui

all: compile link ejecute

main: compileMain link ejecute

compileMain:
	g++ -Iinclude -I$(IMGUI_DIR) -c src/main.cpp -I$(SFML_PATH)\include -DSFML_STATIC    


compile:
	g++ -Iinclude -I$(IMGUI_DIR) -c src/Carga.cpp -I$(SFML_PATH)\include -DSFML_STATIC    
	g++ -Iinclude -I$(IMGUI_DIR) -c src/CargaLibre.cpp -I$(SFML_PATH)\include -DSFML_STATIC 
	g++ -Iinclude -I$(IMGUI_DIR) -c src/CargaEsferica.cpp -I$(SFML_PATH)\include -DSFML_STATIC   
	g++ -Iinclude -I$(IMGUI_DIR) -c src/Plano.cpp -I$(SFML_PATH)\include -DSFML_STATIC 
	g++ -Iinclude -I$(IMGUI_DIR) -c src/main.cpp -I$(SFML_PATH)\include -DSFML_STATIC    

	g++ -I$(IMGUI_DIR) -c $(IMGUI_DIR)/imgui.cpp -o imgui.o
	g++ -I$(IMGUI_DIR) -c $(IMGUI_DIR)/imgui_draw.cpp -o imgui_draw.o
	g++ -I$(IMGUI_DIR) -c $(IMGUI_DIR)/imgui_widgets.cpp -o imgui_widgets.o
	g++ -I$(IMGUI_DIR) -c $(IMGUI_DIR)/imgui_tables.cpp -o imgui_tables.o

	g++ -I$(IMGUI_DIR) -I$(SFML_PATH)\include -c $(IMGUI_DIR)/imgui-SFML.cpp -o imgui-SFML.o -DSFML_STATIC
	
	windres recursos.rc -O coff -o recursos.o
link:
	g++ main.o Carga.o CargaLibre.o CargaEsferica.o Plano.o imgui.o imgui_draw.o imgui_widgets.o imgui_tables.o imgui-SFML.o recursos.o -o INICIAR_PROGRAMA -L$(SFML_PATH)\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -lsfml-main

ejecute:
	./INICIAR_PROGRAMA.exe
	

clean:
	del *.o
	del INICIAR_PROGRAMA.exe
	