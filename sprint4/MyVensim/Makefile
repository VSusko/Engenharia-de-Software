# Diretórios
SRC_DIR 		:= src/
F_TEST_DIR 		:= test/funcional/
U_TEST_DIR 		:= test/unit/
BIN_DIR 		:= bin/

CXX 			:= g++
CXXFLAGS 		:= -std=c++17 -Wall -O2 -g -I"$(BIN_DIR)"
LDFLAGS 		:= 

EXEC_FUNC 		:= $(BIN_DIR)ftest.exe
EXEC_UNIT 		:= $(BIN_DIR)utest.exe

# Arquivos fonte
SRC_FILES 		:= $(wildcard $(SRC_DIR)*.cpp)
F_TEST_FILES 	:= $(wildcard $(F_TEST_DIR)*.cpp)
U_TEST_FILES	:= $(wildcard $(U_TEST_DIR)*.cpp)
objetos			:= $(foreach object,$(subst .cpp,.o,$(subst $(SRC_DIR),,$(SRC_FILES))),$(BIN_DIR)$(object))

biblioteca_nome	:= bibvictor.lib
biblioteca		:= $(BIN_DIR)$(biblioteca_nome)

ftest			:= $(BIN_DIR)ftest.exe
utest			:= $(BIN_DIR)utest.exe

build_and_run: build 

build: $(ftest) $(utest)
	@echo Tudo certo.
	

$(ftest): $(biblioteca) $(F_TEST_FILES)
	@g++ $(F_TEST_DIR)*.cpp -o $@ -L"$(BIN_DIR)" -l:"$(biblioteca_nome)" $(CXXFLAGS)

$(utest): $(biblioteca) $(U_TEST_FILES)
	@g++ $(U_TEST_DIR)*.cpp -o $@ -L"$(BIN_DIR)" -l:"$(biblioteca_nome)" $(CXXFLAGS)

# g++ $(CXXFLAGS) -shared -o $@ $(objetos)
$(biblioteca): $(objetos)
	@ar cr $@ $^ 

$(BIN_DIR)%.o: $(SRC_DIR)%.cpp
	@g++ -c $^ -o $@ $(CXXFLAGS)

# Limpeza dos arquivos objeto e executáveis
clean:
	@rm -f $(BIN_DIR)/*.o $(EXEC)

run_functional: $(EXEC_FUNC)
	@./$(EXEC_FUNC)

run_unit: $(EXEC_UNIT)
	@./$(EXEC_UNIT)