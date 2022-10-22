result: ElementaryParticle.o analyzer.o
	g++ ElementaryParticle.o analyzer.o -o result

ElementaryParticle.o: ElementaryParticle.cpp
	g++ -c ElementaryParticle.cpp

analyzer.o: analyzer.cpp
	g++ -c analyzer.cpp

clean: 
	rm *.o result *.exe