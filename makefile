CC=g++
CFLAGS=-std=c++17 -c -Wall -O3
LDFLAGS=-lstdc++fs -pthread -lgpiod
SOURCES=main.cpp gpio.cpp gpio_input.cpp gpio_output.cpp gpio_blinking_output.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=gpioBoardTest

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) *.o *~ $(EXECUTABLE)

