PROG = executavel
CC = g++
CPPFLAGS = -Wall -pedantic -std=c++11 -g -O0 -I./include
LDFLAGS = -L./lib 
BUILD = ./build/
BIN = ./bin/
OBJS = $(BUILD)main.o $(BUILD)tratador.o $(BUILD)veterinario.o $(BUILD)funcionario.o $(BUILD)petfera.o $(BUILD)animal.o $(BUILD)anfibio.o $(BUILD)mamifero.o $(BUILD)reptil.o $(BUILD)ave.o $(BUILD)anfibio_exotico.o $(BUILD)anfibio_nativo.o $(BUILD)animal_silvestre.o $(BUILD)exotico.o $(BUILD)nativo.o $(BUILD)mamifero_exotico.o $(BUILD)mamifero_nativo.o $(BUILD)reptil_exotico.o $(BUILD)reptil_nativo.o $(BUILD)ave_exotica.o $(BUILD)ave_nativa.o
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
./build/anfibio_exotico.o:./include/anfibio_exotico.h
	$(CC) $(CPPFLAGS) -c src/anfibio_exotico.cpp -o $(BUILD)anfibio_exotico.o	
./build/anfibio_nativo.o:./include/anfibio_nativo.h
	$(CC) $(CPPFLAGS) -c src/anfibio_nativo.cpp -o $(BUILD)anfibio_nativo.o	
./build/animal_silvestre.o:./include/animal_silvestre.h
	$(CC) $(CPPFLAGS) -c src/animal_silvestre.cpp -o $(BUILD)animal_silvestre.o	
./build/exotico.o:./include/exotico.h
	$(CC) $(CPPFLAGS) -c src/exotico.cpp -o $(BUILD)exotico.o	
./build/nativo.o:./include/nativo.h
	$(CC) $(CPPFLAGS) -c src/nativo.cpp -o $(BUILD)nativo.o		
./build/mamifero_exotico.o:./include/mamifero_exotico.h
	$(CC) $(CPPFLAGS) -c src/mamifero_exotico.cpp -o $(BUILD)mamifero_exotico.o		
./build/mamifero_nativo.o:./include/mamifero_nativo.h
	$(CC) $(CPPFLAGS) -c src/mamifero_nativo.cpp -o $(BUILD)mamifero_nativo.o	
./build/reptil_nativo.o:./include/reptil_nativo.h
	$(CC) $(CPPFLAGS) -c src/reptil_nativo.cpp -o $(BUILD)reptil_nativo.o
./build/reptil_exotico.o:./include/reptil_exotico.h
	$(CC) $(CPPFLAGS) -c src/reptil_exotico.cpp -o $(BUILD)reptil_exotico.o	
./build/ave_exotica.o:./include/ave_exotica.h
	$(CC) $(CPPFLAGS) -c src/ave_exotica.cpp -o $(BUILD)ave_exotica.o	
./build/ave_nativa.o:./include/ave_nativa.h
	$(CC) $(CPPFLAGS) -c src/ave_nativa.cpp -o $(BUILD)ave_nativa.o	
clean:
	rm -f core $(BIN)$(PROG) $(OBJS) 

