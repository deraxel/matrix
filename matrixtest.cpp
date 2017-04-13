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
 	string things="inmatrices/testoutgoingmatrix.txt";
 	OutMatrix C("outmatrices/testoutgoingmatrix.txt",B.getMat());
 	InMatrix D("outmatrices/testoutgoingmatrix.txt");
 	D.getMat().display();
 	InMatrix E("inmatrices/answersolve.txt");
 	Lu F(E.getX(), D.getMat(), E.getMat());
	F.setGause();
 	OutMatrix("outmatrices/testLOutmat.txt", F.getL());
 	OutMatrix("outmatrices/testUOutmat.txt", F.getU());
 	OutMatrix("outmatrices/testAN.txt", F.getSec());
 	Mat randomMat;
 	randomMat.makeMatrix(10,10);
 	randomMat.random_mat(3.14);
 	Mat randoma;
 	randoma.makeMatrix(100,1);
 	Lu randomStuff(randomMat.getrow(), randomMat, randoma);
 	OutMatrix("outmatrices/randomMatrix.txt", randomMat);
 	OutMatrix("outmatrices/randomL.txt", randomStuff.getL());
 	OutMatrix("outmatrices/randomU.txt", randomStuff.getU());
    	return 0;
}
