objects = main.o frequencyOrder.o huffmanCoding.o Node.o output.o Pair.o
          

parser : $(objects)
	g++ -o main $(objects)

main.o : main.hpp frequencyOrder.hpp Node.hpp huffmanCoding.hpp output.hpp
frequencyOrder.o: frequencyOrder.hpp Pair.hpp
huffmanCoding.o: huffmanCoding.hpp
Node.o: Node.hpp Pair.hpp
output.o: output.hpp
Pair.o: Pair.hpp

.PHONY : clean
clean :
	-rm main $(objects)