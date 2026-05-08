BIN_DIR=bin


%: %.cpp $(BIN_DIR)
	g++ -std=c++14 -O2 -o ${BIN_DIR}/$@ $<
	${BIN_DIR}/$@

bin:
	mkdir bin