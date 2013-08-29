# vars
CC=g++
CFLAGS=#-I/usr/include
ODIR=obj
LIBS=-lcurses 
# object and dep files
_OBJ = main.o hitbox.o bullet.o Dodger.o display.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
# target builds
$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
CursesGame: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
clean:
	rm -f $(ODIR)/*.o *~ CursesGame
