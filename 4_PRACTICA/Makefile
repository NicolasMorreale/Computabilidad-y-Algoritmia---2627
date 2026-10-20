# Compilador y opciones
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Nombre del ejecutable
TARGET = p04_html_analyzer

# Archivos de código fuente (.cc) -> Estos SÍ se compilan a .o
SRCS = p04_cliente_main.cc \
       p04_html_analyzer.cc \
       p04_html_document.cc \
       p04_atributo.cc \
       p04_etiqueta.cc \
       p04_comentario.cc

# Archivos de cabecera (.h) -> Para vigilar si cambian
HDRS = p04_html_analyzer.h \
       p04_html_document.h \
       p04_atributo.h \
       p04_etiqueta.h \
       p04_comentario.h

# Archivos objeto generados
OBJS = $(SRCS:.cc=.o)

# Regla principal
all: $(TARGET)

# Enlazado final
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regla de compilación: si cambia un .cc O un .h, recompila el .o
%.o: %.cc $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpieza
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean