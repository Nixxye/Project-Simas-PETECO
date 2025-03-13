# Diretório de destino para os arquivos .o
OBJ_DIR = objects

# Lista de todos os arquivos .cpp no diretório src
CPP_FILES := $(wildcard src/*.cpp)

# Lista de arquivos .o gerados a partir dos arquivos .cpp
OBJ_FILES := $(patsubst src/%.cpp,$(OBJ_DIR)/%.o,$(CPP_FILES))

# Regra para criar o diretório de objetos
# EXEMPLO:
# $(OBJ_DIR)/%.o: src/%.cpp
#	g++ -c -Iinclude \
#	-ISFML/include \
#	-Iinclude/Entidades \
#	-Iinclude/Entidades/Personagens \
#	-Iinclude/Entidades/Personagens/Inimigos \
#	-Iinclude/Entidades/Projetil \
#	-Iinclude/Entidades/Obstaculos \
#	$< -o $@


# SEMPRE QUE FOR ADICIONAR MAIS UMA PASTA NO INCLUDE LISTAR AQUI ASSIM COMO FEITO NO EXEMPLO ACIMA
# Compilação dos arquivos .cpp para arquivos .o 
$(OBJ_DIR)/%.o: src/%.cpp
	g++ -c	-Iinclude \
	-ISFML/include \
    $< -o $@

# Regra para criar o diretório de objetos caso não exista
create_obj_dir:
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)

# Regra padrão para construir o executável
all: create_obj_dir clean compile link

compile: $(OBJ_FILES)

link:
	g++ $(OBJ_FILES) -o main -LSFML/lib -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lsfml-audio

# Regra para rodar o executável
run:
	./main

# Limpar os arquivos .o e o executável
clean:
	@if exist $(OBJ_DIR)/*.o main rm -rf $(OBJ_DIR)/*.o main

# USE ESTE CLEAN SE O ANTERIOR ESTIVER DANDO ERRO
# # Limpar os arquivos .o e o executável
# clean:
# 	@if exist $(OBJ_DIR)/*.o del /Q $(OBJ_DIR)\*.o
#	@if exist main del main


