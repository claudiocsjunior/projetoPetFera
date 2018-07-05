PROG = executavel
CC = g++
CPPFLAGS = -Wall -pedantic -std=c++11 -g -O0 -I./include
LDFLAGS = -L./lib 
BUILD = ./build/
BIN = ./bin/
OBJS = $(BUILD)main.o $(BUILD)tratador.o $(BUILD)veterinario.o $(BUILD)funcionario.o $(BUILD)petfera.o $(BUILD)animal.o $(BUILD)anfibio.o $(BUILD)mamifero.o $(BUILD)reptil.o $(BUILD)ave.o
$(PROG):$(OBJS)
	$(CC) $(LDFLAGS) -o $(BIN)$(PROG) $(OBJS)
./build/main.o:
	$(CC) $(CPPFLAGS) -c src/main.cpp -o $(BUILD)main.o
./build/tratador.o:./include/tratador.h
	$(CC) $(CPPFLAGS) -c src/tratador.cpp -o $(BUILD)tratador.o
./build/veterinario.o:./include/veterinario.h
	$(CC) $(CPPFLAGS) -c src/veterinario.cpp -o $(BUILD)veterinario.o
./build/funcionario.o:./include/funcionario.h
	$(CC) $(CPPFLAGS) -c src/funcionario.cpp -o $(BUILD)funcionario.o
./build/petfera.o:./include/petfera.h
	$(CC) $(CPPFLAGS) -c src/petfera.cpp -o $(BUILD)petfera.o
./build/animal.o:./include/animal.h
	$(CC) $(CPPFLAGS) -c src/animal.cpp -o $(BUILD)animal.o
./build/anfibio.o:./include/anfibio.h
	$(CC) $(CPPFLAGS) -c src/anfibio.cpp -o $(BUILD)anfibio.o		
./build/mamifero.o:./include/mamifero.h
	$(CC) $(CPPFLAGS) -c src/mamifero.cpp -o $(BUILD)mamifero.o	
./build/reptil.o:./include/reptil.h
	$(CC) $(CPPFLAGS) -c src/reptil.cpp -o $(BUILD)reptil.o	
./build/ave.o:./include/ave.h
	$(CC) $(CPPFLAGS) -c src/ave.cpp -o $(BUILD)ave.o							
clean:
	rm -f core $(BIN)$(PROG) $(OBJS) 

