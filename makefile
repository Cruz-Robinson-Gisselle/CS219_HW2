assembly: driver.o driver.cpp
	g++ -o assembly driver.o
main.o: driver.cpp
	g++ -c driver.cpp
clean:
	rm *.o assembly
