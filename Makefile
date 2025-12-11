.PHONY: build run dbn show clean
.DEFAULT_GOAL=run

CC=g++
INCLUDE=.
CFLAGS=-Wall -std=c++23
CFLAGS+=-O3
DEBUG=-Dlolainta

TEST=$(sort $(wildcard *.in))
OUTS=$(TEST:.in=.out)
DBNS=$(TEST:.in=.dbn)

build: code debug
code: code.cpp
	$(CC) -I$(INCLUDE) $(CFLAGS) code.cpp -o code
debug: code.cpp
	$(CC) -I$(INCLUDE) $(CFLAGS) $(DEBUG) code.cpp -o debug
run: code
	@echo "Read from standard input"
	./code
dbn: debug
	./debug
%.out: %.in code
	./code < $< > $@ 
%.dbn: %.in debug
	./debug < $< 2> $@ > /dev/null
	cat $<
	cat $@
show: $(OUTS)
	@for f in $(OUTS); do\
		echo ====$$f====;\
		cat $$f;\
		echo =============;\
	done
clean:
	@rm -f code debug
	@rm -f *.out *.dbn
new: clean
	@rm -f *.in
	cp template.cpp code.cpp

copy: build
	cat code.cpp | osc52

