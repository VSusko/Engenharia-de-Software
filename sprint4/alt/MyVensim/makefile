#======== Variables ========

#----[Compilation]
compiler = g++
flags = -g -Wall -O2
optional_settings = 

#----[Paths]
binPath = bin
executablesPath = $(binPath)
objectsPath = $(binPath)

sourcePath = src
unitTestsPath = test/unit
funcionalTestsPath = test/funcional
headersPath = $(sourcePath)

#----[Files list with path]
Path_sourceFiles = $(wildcard $(sourcePath)/*.cpp)
Path_unitTestFiles = $(wildcard $(unitTestsPath)/*.cpp)
Path_funcionalTestFiles = $(wildcard $(funcionalTestsPath)/*.cpp)

#----[Object files]
Path_objectFiles = $(patsubst $(sourcePath)/%.cpp, $(objectsPath)/%.o, $(Path_sourceFiles))
Path_unitObjectFiles = $(patsubst $(unitTestsPath)/%.cpp, $(objectsPath)/unit_%.o, $(Path_unitTestFiles))
Path_funcObjectFiles = $(patsubst $(funcionalTestsPath)/%.cpp, $(objectsPath)/func_%.o, $(Path_funcionalTestFiles))

#----[Targets]
mainExecutable = $(executablesPath)/MyVensim.exe
unitTestExecutable = $(executablesPath)/unit_tests.exe
funcTestExecutable = $(executablesPath)/func_tests.exe

#======== OS-Manager ========

ifeq ($(OS), Windows_NT)
mkdir = if not exist "$(1)" mkdir "$(1)"
cmd_remove = del /q "$(1)"
else
mkdir = mkdir -p $(1)
cmd_remove = rm -f $(1)
endif

#======== Directories Creation ========
$(binPath):
	@$(call mkdir,$(binPath))

#======== Building Targets ========

.PHONY: build
build: $(binPath) $(mainExecutable)
	@echo Projeto principal compilado.

# Compilação do projeto principal
$(mainExecutable): $(filter-out $(objectsPath)/unit_main.o $(objectsPath)/func_main.o, $(Path_objectFiles))
	$(compiler) $^ -o $@ $(flags)

$(objectsPath)/%.o: $(sourcePath)/%.cpp
	$(compiler) -c $< -o $@ -I $(headersPath) $(optional_settings) $(flags)

#======== Unit Tests ========

.PHONY: unit_tests
unit_tests: $(unitTestExecutable)
	@echo Testes unitários compilados.

# Compilação dos testes unitários
$(unitTestExecutable): $(Path_unitObjectFiles) $(filter-out $(objectsPath)/main.o, $(Path_objectFiles))
	$(compiler) $^ -o $@ $(flags)

$(objectsPath)/unit_%.o: $(unitTestsPath)/%.cpp
	$(compiler) -c $< -o $@ -I $(headersPath) $(optional_settings) $(flags)

#======== Functional Tests ========

.PHONY: func_tests
func_tests: $(funcTestExecutable)
	@echo Testes funcionais compilados.

# Compilação dos testes funcionais
$(funcTestExecutable): $(Path_funcObjectFiles) $(filter-out $(objectsPath)/main.o, $(Path_objectFiles))
	$(compiler) $^ -o $@ $(flags)

$(objectsPath)/func_%.o: $(funcionalTestsPath)/%.cpp
	$(compiler) -c $< -o $@ -I $(headersPath) $(optional_settings) $(flags)

#======== Clean ========

.PHONY: clean
clean:
	@$(call cmd_remove,$(objectsPath)/*.o)
	@$(call cmd_remove,$(executablesPath)/*.exe)
	@echo Objetos e executáveis limpos.

.PHONY: clean-all
clean-all: clean
	@$(call cmd_remove,$(objectsPath)/*)
	@echo Todos os arquivos em bin limpos.

#======== Run ========

.PHONY: run
run: build
	@./$(mainExecutable)

.PHONY: run-unit
run-unit: unit_tests
	@./$(unitTestExecutable)

.PHONY: run-func
run-func: func_tests
	@./$(funcTestExecutable)

#======== Rebuild ========

.PHONY: rebuild
rebuild: clean build
