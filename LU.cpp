using namespace std;
#include "LU.h"

Lu::Lu(){//constructor
	n=0;
};

Lu::~Lu(){//destructor
};

Lu::Lu(int x, Mat ma1, Mat ma2){//use add the matrices when invoking Lu
	first=ma1;
	solve=ma2;
	n=x;
	calcForLU();
};

void Lu::calcForLU(){
	setGause2();
	calcLU();
};

void Lu::setGause(){//initiates and allocates all input matrixes and values
	solveForSecond();
	solveForSecondX();
};

void Lu::setGause2(){//set secondary matrix (unknown)
	second.makeMatrix(getN(),1);
};


void Lu::setN(int x){//sets matrix sizes
	n=x;
};

void Lu::solveForSecond(){
	tempthing=GauseElim(getN(), L, solve);
	tempY=tempthing.getSecond();
};

void Lu::solveForSecondX(){
	tempthing=GauseElim(getN(), U, tempY);//thing
	second=tempthing.getSecond();//thing
};

int Lu::getN(){//gets matrix sizes
	return n;
};

Mat Lu::getL(){
	return L;
};

Mat Lu::getU(){
	return U;
};

Mat Lu::getSec(){
	return second;
};

void Lu::calcLU(){//set up for calculatoins in LU matrices
	L.makeMatrix(getN(), getN());
	U.makeMatrix(getN(), getN());
	L.ident();
	for(int i=0;i<getN();i++){
		for(int i2=0;i2<i+1;i2++){
			U.setNode(i2,i,calcU(i2,i));
		}
		for(int i2=i+1;i2<getN();i2++){
			L.setNode(i2,i,calcL(i2,i));
		}
	}
};

double Lu::calcU(int x,int y){//2,1
	double temp1=0.0;
	for(int i=0;i<getN();i++){
		if(x!=i){
			temp1=temp1+(L.getNode(x,i)*U.getNode(i,y));
		}
	}
	temp1=first.getNode(x,y)-temp1;
	return temp1;
};

double Lu::calcL(int x, int y){//(3,1
	double temp=0.0;
	for(int i=0;i<getN();i++){
		if(y!=i){
			temp=temp+(L.getNode(x,i)*U.getNode(i,y));
		}
	}
	temp=first.getNode(x,y)-temp;
	temp=temp/U.getNode(y,y);
	return temp;
};

void Lu::displayAll(){
	displayAnswer();
	displayL();
	displayU();
	
};

void Lu::displayAnswer(){
	second.display();	
};

void Lu::displayU(){
	U.display();
};

void Lu::displayL(){
	L.display();
};
