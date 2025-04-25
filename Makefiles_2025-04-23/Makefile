SOURCES := $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

fig.pdf : script.gp data.txt
	gnuplot $<

%.o : %.cpp
	g++ $< -c 

sumupdown.x : $(OBJECTS)
	g++ $^ -o $@

data.txt : sumupdown.x
	./$< > $@

clean : 
	rm -f *.x a.out *.txt *.pdf

