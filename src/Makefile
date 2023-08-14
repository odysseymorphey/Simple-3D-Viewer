CXX = g++ -Wall -Wextra -std=c++17
LFLAGS = -lraylib
SOURCE = main.cc
SOURCE += view/view.cc
SOURCE += model/model.cc
SOURCE += controller/controller.cc
TEST_SOURCE = tests/test.cc
TFLAGS = -lgtest
PROJECT_NAME= viewer.app
OS= $(shell uname)

all: app

app: install
	./build/$(PROJECT_NAME)

install: uninstall
	mkdir build
	$(CXX) $(SOURCE) $(LFLAGS) -o $(PROJECT_NAME)
	mv $(PROJECT_NAME) build

uninstall:
	rm -rf build

test: clean
	$(CXX) model/model.cc controller/controller.cc $(LFLAGS) $(TEST_SOURCE) $(TFLAGS) -o test
	./test

dvi:
	cd Doxygen; doxygen
	open doxygen/html/index.html

dist: 
	tar  -zcvf viewer.tar . 

clean:
	rm -f a.out test $(PROJECT_NAME) *.tar

