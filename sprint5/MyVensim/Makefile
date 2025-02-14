# Diretórios
SRC_DIR         := src/
F_TEST_DIR      := test/funcional/
U_TEST_DIR      := test/unit/
BIN_DIR         := bin/

CXX             := g++
CXXFLAGS        := -Wall -O2 -g -fPIC -I"$(BIN_DIR)"
LDFLAGS         := -shared

# Nome da biblioteca
LIB_NAME        := libmyvensim
LIB_SO          := $(BIN_DIR)$(LIB_NAME).so  # Para Linux/macOS
LIB_DLL         := $(BIN_DIR)$(LIB_NAME).dll # Para Windows

# Arquivos fonte
SRC_FILES       := $(wildcard $(SRC_DIR)*.cpp)
F_TEST_FILES    := $(wildcard $(F_TEST_DIR)*.cpp)
U_TEST_FILES    := $(wildcard $(U_TEST_DIR)*.cpp)
OBJ_FILES       := $(patsubst $(SRC_DIR)%.cpp, $(BIN_DIR)%.o, $(SRC_FILES))

# Executáveis de teste
EXEC_MAIN       := $(BIN_DIR)test.exe
EXEC_FUNC       := $(BIN_DIR)ftest.exe
EXEC_UNIT       := $(BIN_DIR)utest.exe

# Alvo padrão
build: $(LIB_SO) $(EXEC_FUNC) $(EXEC_UNIT)
	@echo "Compilação concluída!"

# Criando a biblioteca dinâmica no Linux/macOS
$(LIB_SO): $(OBJ_FILES)
	$(CXX) $(LDFLAGS) -o $@ $^

# Criando a biblioteca dinâmica no Windows
$(LIB_DLL): $(OBJ_FILES)
	$(CXX) $(LDFLAGS) -o $@ $^ -Wl,--out-implib,$(BIN_DIR)/libmysim.a

# Compilando arquivos objeto
$(BIN_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilação dos testes funcionais
$(EXEC_MAIN): $(SRC_FILES) $(LIB_SO)
	$(CXX) $^ -o $@ -L"$(BIN_DIR)" -lmyvensim $(CXXFLAGS)

# Compilação dos testes funcionais
$(EXEC_FUNC): $(F_TEST_FILES) $(LIB_SO)
	$(CXX) $^ -o $@ -L"$(BIN_DIR)" -lmyvensim $(CXXFLAGS)

# Compilação dos testes unitários
$(EXEC_UNIT): $(U_TEST_FILES) $(LIB_SO)
	$(CXX) $^ -o $@ -L"$(BIN_DIR)" -lmyvensim $(CXXFLAGS)

# Limpeza
clean:
	@rm -f $(BIN_DIR)/*.o $(BIN_DIR)/*.so $(BIN_DIR)/*.dll $(BIN_DIR)/*.a $(EXEC_MAIN) $(EXEC_FUNC) $(EXEC_UNIT)
	@echo "Arquivos limpos!"

# Rodar testes
run_main: $(EXEC_MAIN)
	@./$(EXEC_MAIN)

run_functional: $(EXEC_FUNC)
	@./$(EXEC_FUNC)

run_unit: $(EXEC_UNIT)
	@./$(EXEC_UNIT)
