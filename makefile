FLAGS = -Wall -ansi -pedantic
OBJS = base64_main.o binary_enc.o base64_enc.o
EXEC = base64_main

$(EXEC): $(OBJS)
	gcc $(FLAGS) -o $(EXEC) $(OBJS)

$(EXEC).o: $(EXEC).c
	gcc $(FLAGS) -c $(EXEC).c

base64_enc.o: base64_enc.c
	gcc $(FLAGS) -c base64_enc.c

binary_enc.o: binary_enc.c
	gcc $(FLAGS) -c binary_enc.c -lm

clean: 
	rm -f *.o $(EXEC) $(OBJS)