out:	seqCounter.o main.o
	g++ $^ -o $@

main.o:	main.cpp
	g++ -c $^

seqCounter.o:	seqCounter.hpp seqCounter.cpp
	g++ -c $^

clean:
	rm *.o *.gch out
