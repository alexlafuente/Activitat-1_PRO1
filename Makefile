CXX = g++
CXXFLAGS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11


program: program.o Plataforma.o Usuari.o Film.o
	$(LINK.cc) -o $@ $^
	
program.o: program.cpp Plataforma.hpp Usuari.hpp Film.hpp

Plataforma.o: Plataforma.cpp Plataforma.hpp Usuari.hpp Film.hpp

Usuari.o: Usuari.cpp Usuari.hpp Film.hpp

Film.o: Film.cpp Film.hpp


.PHONY: clean
clean:
	rm -vf program.o Plataforma.o Usuari.o Film.o program

.PHONY: test
test1: 
	./program < registres1.inp | diff - registres1.cor
	
test:
#	Descomenteu les següents línies si voleu executar tots
#	els jocs de proves.
#	./program < registres1.inp | diff - registres1.cor
#	./program < registres2.inp | diff - registres2.cor
# 	./program < registres3.inp | diff - registres3.cor
# 	./program < registres4.inp | diff - registres4.cor
# 	./program < registres5.inp | diff - registres5.cor