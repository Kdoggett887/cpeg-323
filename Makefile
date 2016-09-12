all: hello-cpp-world hello-c-world HW1/hw1

%: %.cc
	g++ -std=c++11 $< -o $@

%: %.c
	gcc $< -o $@
	

