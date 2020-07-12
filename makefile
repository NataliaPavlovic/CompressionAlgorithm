objects = main.o frequencyOrder.o huffmanCoding.o Node.o output.o
          

parser : $(objects)
	g++ -Wall -o main $(objects)

main.o : main.hpp frequencyOrder.hpp Node.hpp huffmanCoding.hpp output.hpp
frequencyOrder.o: frequencyOrder.hpp
huffmanCoding.o: huffmanCoding.hpp
Node.o: Node.hpp 
output.o: output.hpp

.PHONY : clean
clean :
	-rm main $(objects)