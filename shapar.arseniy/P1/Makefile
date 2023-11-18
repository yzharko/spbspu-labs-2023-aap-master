out:	main1.o	var1.o
	g++ $^ -o $@

main.o:	main1.cpp
	g++ -c $^

var1.o:	var1.hpp var1.cpp
	g++ -c $^

clean:
	rm *.o out
