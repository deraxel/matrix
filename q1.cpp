#include <iostream>
using namespace std;
#include "matrix.cpp"
#include "gauseelim.cpp"
#include "LU.cpp"
#include "getmatrix.cpp"
#include "inmatrix.cpp"
#include "outmatrix.cpp"

int main(int argc, char* argv[]){
 	InMatrix B(argv[1]);
 	B.getMat().display();
 	cout<<endl<<B.getX()<<"   "<<B.getY()<<endl;
 	OutMatrix C("outmatrices/testoutgoingmatrix.txt",B.getMat());
   	return 0;
}
