CC = g++
IP = M.cpp
CFLAGS = -Wall -g

all: output

output: $(IP)
	$(CC) $(CFLAGS) $(IP) -o output
	./output

clean:
	rm -f output
