# Auteur : Olivier CARDOSO

# Compilateur
CXX = gcc

# Options de compilation pour gcc (génération du fichier objet .o)
CFLAGS = -c -Wall -Werror -ansi -pedantic -shared -fpic

# Liste des fichiers à compiler
FILES = polynomemain.c polynome.c

# Nom de l'executable du programme
TARGET = polynome_test

# Regle par défaut : Linkage
$(TARGET): $(FILES:.c=.o)
	$(CXX) -o $@ $(FILES:.c=.o)

# Regle de nettoyage (suppression des fichiers issus de la compilation : .o et executable)
clean:
	del *.o $(TARGET)

#Définient si un fichier doit être recompilé ou non
depend:
	makedepend --$(CFLAGS) --$(FILES)
#Compilation et assemblage d'un fichier source .c en fichier objet .o
%.o: %.c
	$(CXX) $(CFLAGS) $*.c

# Commande d'execution propre au package sur atom
run:
	polynome_test $(ARGS)
