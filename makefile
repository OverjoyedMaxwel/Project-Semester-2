target: MU_Person.h student.h main.cpp
	g++ LL_test.cpp -o inh

test: MU_Person.h student.h main.cpp
	g++ main.cpp -o a.out
run: inh
	 ./inh