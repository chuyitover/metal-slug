bin/metal-slug : src/test.cpp
	g++ -o bin/metal-slug src/main.cpp -Iinclude -lftxui-screen -lftxui-dom -lftxui-component
output = bin
source = src
include = -Iinclude
dependencias = -lftxui-screen -lftxui-dom -lftxui-component
flags = -std=c++2a $(dependencias) $(include)


run : $(output)/metal-slug 
	./$<

$(output)/metal-slug : $(source)/main.cpp 
	g++ -o $@ $< $(flags)


runPantalla : $(output)/pantalla 
	./$<

$(output)/pantalla : $(source)/pantalla.cpp
	g++ -o $@ $< $(flags)