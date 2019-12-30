OBJ := $(patsubst %.c, %.o, $(wildcard *.c))
text_indexer.exe : $(OBJ)
	gcc -o $@ $^
clean:
	rm *.o *.exe
