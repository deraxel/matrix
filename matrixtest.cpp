#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>
#include <ctime>
using namespace std;
#include "matrix.cpp"
#include "gauseelim.cpp"

int main(int argc, char* argv[]){
	GauseElim B(argv[1]);
	B.display();
	cout<<endl;
	B.calcGause();
	B.displayAll();
    	return 0;
}
