CPPC = g++
CPPFLAGS = -std=c++11 -Wall -W -Wextra -Werror -O2
INCLUDES = -I../../ -I../../algorithms

SRC = ${wildcard *.cpp}
TESTS = ${SRC:.cpp=.exe}

.PHONY: clean dist-clean dist

all:
	$(MAKE) $(TESTS) 

%.exe: %.cpp
	@echo Building $@
	$(CPPC) $(CPPFLAGS) $(INCLUDES) $< -o $@

clean:
	@echo Cleaning...
	@rm -rf *~ *.o prog out.txt *.d *.class

dist-clean: clean
	@rm -rf *.exe
