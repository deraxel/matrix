#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include "outmatrix.h"
using namespace std;

OutMatrix::OutMatrix(){
};

OutMatrix::~OutMatrix(){
};

OutMatrix::OutMatrix(string file, Mat matri){
	fileText=file;
	matrix=matri;
	setAll();
};

void OutMatrix::setAll(){//initiates and allocates all input matrixes and values
	setX();
	setY();
	fileWrite();
};

void OutMatrix::setX(){//sets matrix sizes
	x=matrix.getrow();
};

void OutMatrix::setY(){//sets matrix sizes
	y=matrix.getcol();
};

int OutMatrix::getX(){
	return x;
};

int OutMatrix::getY(){
	return y;
};

void OutMatrix::fileWrite(){//todo: do an output stream saved to file
	bool flag=false;
	matrixOut<<fixed;
	matrixOut.open(fileText);
	matrixOut<<getX()<<" "<<getY()<<endl;
	for(int i1=0;i1<getX();i1++){
		for(int i2=0;i2<getY();i2++){
			if(flag){
				matrixOut<<" ";
			}
			matrixOut<<matrix.getNode(i1,i2);
			flag=true;
		}
		matrixOut<<endl;
		flag=false;
	}
	matrixOut.close();
};


