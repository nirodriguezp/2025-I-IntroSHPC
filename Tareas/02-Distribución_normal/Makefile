SOURCES := $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

random_pdf.pdf : script.gp data1.txt data2.txt data5.txt
	gnuplot $< 

random_pdf.x : $(OBJECTS)
	g++ $^ -o $@

data5.txt : random_pdf.x
	./$< 5 5000 3.5 0.4 2.7 4.6 50 > $@

data2.txt : random_pdf.x
	./$< 2 5000 3.5 0.4 2.7 4.6 50 > $@

data1.txt : random_pdf.x
	./$< 1 5000 3.5 0.4 2.7 4.6 50 > $@

clean : 
	rm -f *.x a.out *.txt *.pdf
