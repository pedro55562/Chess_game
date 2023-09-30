# Variáveis
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include
ASSETS_DIR = assets
EXE = main

# Diretório de assets
ASSETS = $(ASSETS_DIR)/images/chess_pieces/ $(ASSETS_DIR)/sounds/ $(ASSETS_DIR)/fonts/ $(ASSETS_DIR)/config/ $(ASSETS_DIR)/other_assets/

# Opções de compilação para debug
DEBUG_FLAGS = -O0 -g -DEBUG

# Bibliotecas da Raylib e flags de compilação e vinculação
RAYLIB_LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
RAYLIB_INCLUDE = -I/usr/local/include/ 

# Objetos
OBJ = $(addprefix $(BUILD_DIR)/, main.o Chessboard.o Piece.o King.o Queen.o Rook.o Bishop.o Knight.o Pawn.o Player.o ChessRenderer.o)

# Compilação e linkagem padrão
$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXE) $(RAYLIB_LIBS)

# Compilação dos arquivos fonte
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(RAYLIB_INCLUDE) -I$(INCLUDE_DIR) -c $< -o $@

# Compilação e linkagem para debug
debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: $(EXE)

# Limpeza dos arquivos de build
clean:
	rm -rf $(BUILD_DIR)

# Limpeza da build (apenas dentro do diretório)
clean_build:
	rm -rf $(BUILD_DIR)/*

# Execução do programa
run:
	./$(EXE)

# Diretório de assets
assets:
	mkdir -p $(ASSETS)

.PHONY: debug clean clean_build run assets
