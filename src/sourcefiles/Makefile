# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CXX=g++
LDFLAGS=-lpthread
CXXFLAGS=-Wall -g
EXEC=raspberry
vpath %.h ../headers
# ****************************************************
# Targets needed to bring the executable up to date

all: $(EXEC)

carrefour: Starting_Class.o CoeurCarrefour.o Calcul_Carrefour.o Sortie_Distante.o Temporisation.o Client.o
	$(CXX) $(CXXFLAGS) -o $@ $(LDFLAGS) $^

chenillard: Starting_Class.o CoeurChenillard.o Calcul_Chenillard.o Sortie_Distante.o  Client.o
	$(CXX) $(CXXFLAGS) -o $@ $(LDFLAGS) $^

# The main.o target can be written more simply

Starting_Class.o: Starting_Class.cpp Coeur.h
	$(CXX) $(CXXFLAGS) -c Starting_Class.cpp

CoeurCarrefour.o: Coeur.cpp Coeur.h Calcul.h Calcul_Carrefour.h GPIO.h
	$(CXX) $(CXXFLAGS) -c -o CoeurCarrefour.o -DCARREFOUR Coeur.cpp

CoeurChenillard.o: Coeur.cpp Coeur.h Calcul.h Calcul_Chenillard.h GPIO.h
	$(CXX) $(CXXFLAGS) -c -o CoeurChenillard.o -DCHENILLARD Coeur.cpp

Calcul_Chenillard.o: Calcul_Chenillard.cpp Calcul_Chenillard.h Sortie_Distante.h
	$(CXX) $(CXXFLAGS) -c Calcul_Chenillard.cpp

Calcul_Carrefour.o: Calcul_Carrefour.cpp Calcul_Carrefour.h Sortie_Distante.h Temporisation.h
	$(CXX) $(CXXFLAGS) -c Calcul_Carrefour.cpp
	
Sortie_Distante.o: Sortie_Distante.cpp GPIO.h Client.h
	$(CXX) $(CXXFLAGS) -c Sortie_Distante.cpp

Temporisation.o: Temporisation.cpp Temporisation.h
	$(CXX) $(CXXFLAGS) -c Temporisation.cpp

Client.o: Client.cpp Client.h
	$(CXX) $(CXXFLAGS) -c Client.cpp
	
clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
