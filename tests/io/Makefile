CC = gcc
CFLAGS = -Wall -W -Wextra -Werror -O2

CPPC = g++
CPPFLAGS = -std=c++11 -Wall -W -Wextra -Werror -O2
#CFLAGS = -pedantic -std=c++11 -w -MMD -g3 -g -fPIC\
		 -W -Wall -Wextra -Wshadow -Wcast-align -Wcast-qual -Wctor-dtor-privacy\
		 -Wdisabled-optimization -Wformat=2 -Wlogical-op -Wmissing-declarations\
		 -Wmissing-include-dirs -Wnoexcept -Woverloaded-virtual -Wredundant-decls\
		 -Wsign-promo -Wstrict-null-sentinel -Wswitch-default -Wundef\
		 -Wzero-as-null-pointer-constant -Wuseless-cast -Wnon-virtual-dtor

INCLUDES = -I../../ -I../../algorithms

JAVAC = javac
CLASSPATH = ../../

SRC = ${wildcard *.cpp}
TESTS = ${SRC:.cpp=.exe}

CSRC = ${wildcard *.c}
CTESTS = ${CSRC:.c=.exe}

JSRC = ${wildcard *.java}
JTESTS = ${JSRC:.java=.class}

# To execute a java test: 
# $ java -cp .:../../ Test < in

.PHONY: clean depend dist-clean dist
.SUFFIXES: .java

all:
	$(MAKE) $(JTESTS) $(TESTS) $(CTESTS)

%.exe: %.c
	@echo Building $@
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

%.exe: %.cpp
	@echo Building $@
	$(CPPC) $(CPPFLAGS) $(INCLUDES) $< -o $@

%.class: %.java
	@echo Building $@
	$(JAVAC) -classpath $(CLASSPATH) $<

clean:
	@echo Cleaning...
	@rm -rf *~ *.o prog out.txt *.d *.class

dist-clean: clean
	@rm -rf *.exe
