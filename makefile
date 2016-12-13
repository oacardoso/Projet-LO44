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
	rm  *.o $(TARGET)

# Regles de dépendance : définissent si un fichier doit être recompilé ou non
depends:
	make $(FILES)

# Regle générique : Compilation & Assemblage d'un fichier source .c en fichier objet .o
%.o: %.c
	$(CXX) $(CFLAGS) $*.c
