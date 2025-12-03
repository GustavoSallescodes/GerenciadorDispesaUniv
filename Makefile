# Nome do executável final
TARGET = programa_republica

# Compilador e flags
CXX = g++
# -Iinclude diz ao compilador para procurar os .hpp dentro da pasta 'include'
CXXFLAGS = -std=c++11 -Wall -g -Iinclude

# Diretórios
SRC_DIR = src
OBJ_DIR = obj

# Encontra todos os arquivos .cpp dentro de src/ (ex: src/despesa.cpp src/main.cpp)
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Gera a lista de arquivos objeto correspondentes (ex: obj/despesa.o obj/main.o)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Regra principal (default): compila o executável
all: $(TARGET)

# Regra para "linkar" os objetos e gerar o executável final
$(TARGET): $(OBJS)
	@echo "Ligando o executável: $@"
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra genérica para compilar qualquer .cpp em .o
# Verifica se a pasta obj existe, se não, cria.
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "Compilando: $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para rodar o programa
run: all
	./$(TARGET)

# Regra de limpeza (remove executável e pasta de objetos)
clean:
	@echo "Limpando arquivos gerados..."
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: all clean run
