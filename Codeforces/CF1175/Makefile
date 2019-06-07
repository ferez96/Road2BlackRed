# CPP makefile template

CC=g++ -std=c++11 -O2

init-%:
	$(eval Problem := $(patsubst init-%,%, $@))
	$(eval SourceFile := $(Problem).cpp)
	$(eval InputFile := $(Problem).inp)

	@echo 0 > $(InputFile)

	@echo \
	"#include <bits/stdc++.h>\n"\
	"using namespace std;\n"\
	"\n"\
	"int main(){\n"\
	"	freopen(\"$(Problem).inp\",\"r\",stdin), freopen(\"$(Problem).out\",\"w\",stdout);\n"\
	"	cout<<\"Hello World!\";\n"\
	"}" >$(SourceFile)

	@echo Done!

prob-%: bin bin/%.o %.inp
	$(eval Problem := $(patsubst prob-%,%, $@))
	@cp $(Problem).inp bin/	
	@echo 
	@echo
	@echo Result:
	@bin/$(Problem).o
	@cat $(Problem).out
	@echo %
	
bin:
	mkdir bin

bin/%.o: %.cpp
	$(CC) -o $@ $<

clean:
	rm -rf bin *.out *.exe *.o