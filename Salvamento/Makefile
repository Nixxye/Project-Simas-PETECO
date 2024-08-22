# Variáveis para o compilador e flags
CXX = g++
CXXFLAGS = -std=c++11 # ou -std=c++17, dependendo da versão do C++
PROTOC = protoc
PROTO_DIR = protobuf
INCLUDES = -I"C:\ProgramData\chocolatey\lib\protoc\tools\include" -I. -I$(PROTO_DIR)
LIBS = -L"C:\ProgramData\chocolatey\lib\protoc\tools\bin" -lprotobuf # Ajuste para onde as bibliotecas estão

# Alvos principais
all: json csv xml proto

# Regras para compilar os executáveis
json: json/*.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o json.exe json/*.cpp $(LIBS)

csv: csv/*.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o csv.exe csv/*.cpp $(LIBS)

xml: xml/*.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o xml.exe xml/*.cpp $(LIBS)

proto: $(PROTO_DIR)/jogador.pb.cc $(PROTO_DIR)/*.cpp
	$(PROTOC) --cpp_out=$(PROTO_DIR) $(PROTO_DIR)/jogador.proto
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o proto.exe $(PROTO_DIR)/*.cpp $(PROTO_DIR)/jogador.pb.cc $(LIBS)

# Regra para limpar os arquivos gerados
clean:
	del /f json.exe csv.exe xml.exe proto.exe $(PROTO_DIR)/jogador.pb.cc $(PROTO_DIR)/jogador.pb.h
