using namespace std;
#include "gauseelim.h"

GauseElim::GauseElim(){
	n=0;
};

GauseElim::~GauseElim(){
};

GauseElim::GauseElim(int x, Mat ma1, Mat ma2){
	first=ma1;
	solve=ma2;
	n=x;
	setGause2();
	calcGause();
};

void GauseElim::calcGause(){
	setGauseTemp();
	gausingElemination();
	solveForSecond();
};

void GauseElim::displayAnswer(){
	temp.display();
	second.display();	
};

void GauseElim::displayAll(){
	display();
	displayAnswer();
};
							
void GauseElim::setN(int x){
	n=x;
};

int GauseElim::getN(){
	return n;
};

Mat GauseElim::getFirst(){
	return first;
};

Mat GauseElim::getSecond(){
	return second;
};

Mat GauseElim::getSolve(){
	return solve;
};

void GauseElim::setGause2(){
	second.makeMatrix(getN(),1);
};

void GauseElim::solveForSecond(){
	double temp1;
	double temp2;
	for(int i=getN()-1;i>=0;i--){
		temp2=0.0;
		for (int i2=i+1;i2<getN();i2++){
			temp2=second.getNode(i2,0)*temp.getNode(i,i2)+temp2;
		}
		temp1=(temp.getNode(i,getN())-temp2)/temp.getNode(i,i);
		second.setNode(i,0,temp1);
	}
};

void GauseElim::display(){
	cout<<n<<endl;
	first.display();
	solve.display();
};

void GauseElim::setGauseTemp(){
	temp.makeMatrix(getN(), getN()+1);
	for(int i1=0;i1<getN();i1++){
		for(int i2=0;i2<getN();i2++){
			temp.setNode(i1,i2,first.getNode(i1,i2));
		}
	}
	for(int i=0;i<getN();i++){
		temp.setNode(i,getN(),solve.getNode(i,0));
	}
};

void GauseElim::gausingElemination(){
	double temp1, temp2;
	for(int i=0; i<getN(); i++){
		for(int i1=i; i1<getN()+1; i1++){
			temp2=temp.getNode(i,i1);
			if(i1==i){
				temp1=temp2;
			}
			temp.setNode(i,i1,temp2/temp1);
		}
		for(int i2=i+1;i2<getN();i2++){
			temp1=temp.getNode(i,i)*temp.getNode(i2,i);
			for(int i1=0; i1<(getN()+1); i1++){
				temp2=(temp1*temp.getNode(i,i1))-temp.getNode(i2,i1);
				temp.setNode(i2,i1,temp2);
			}
		}
	}
};
