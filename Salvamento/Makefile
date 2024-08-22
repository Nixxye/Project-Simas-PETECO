# Variáveis para o compilador e flags
CXX = g++
CXXFLAGS = -std=c++11 # ou -std=c++17, dependendo da versão do C++

# Alvos principais
all: json csv xml

# Regras para compilar os executáveis
json: json/*.cpp
	$(CXX) $(CXXFLAGS) -o json json/*.cpp

csv: csv/*.cpp
	$(CXX) $(CXXFLAGS) -o csv csv/*.cpp

xml: xml/*.cpp
	$(CXX) $(CXXFLAGS) -o xml xml/*.cpp

# Regra para limpar os arquivos gerados
clean:
	rm -f json csv xml
