EXEFILE = MyDuckApplication
CXXFLAGS = -c -Wall

$(EXEFILE): Duck.o MallardDuck.o DecoyDuck.o RubberDuck.o QuackBehavior.o MuteQuack.o Quack.o Squeak.o main.o
	g++ $^ -o $@

Duck.o: Duck.h Duck.cpp
	g++ -c Duck.cpp

DecoyDuck.o: Duck.h DecoyDuck.h DecoyDuck.cpp
	g++ -c DecoyDuck.cpp

%.o: %.cpp
	g++ $(CXXFLAGS) $^ -o $@

clean:
	rm *.o $(EXEFILE)
.PHONY: clean
