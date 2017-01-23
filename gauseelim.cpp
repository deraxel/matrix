#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>
#include <ctime>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
#include "gauseelim.h"

GauseElim::GauseElim(){
	n=0;
	fileText="";
};

GauseElim::~GauseElim(){
};

GauseElim::GauseElim(string file){
	listOfMatrix.open(file);
	fileText="";
	char tempC;
	while(listOfMatrix.get(tempC)){
		fileText.append(1,tempC);
	}
	setGause();
};

void GauseElim::setFileString(string x){
	fileText=x;
}

void GauseElim::setGause(){
	setN();
	setGause1();
	setGause2();
	setSolveGause();
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

string GauseElim::getToken(int n){
	int things=0;
	for(int i=0;i<=fileText.length();i++){
		if(((char)fileText[i])=='\n'){
			things++;
		}
	}
	string token[things];
	int temp=0;
	for(int i=0;i<things;i++){
		temp=0;
		token[i]="";
		for(int i2=0;i2<i;i2++){//counts returns and sets reader at start of newline
			while(fileText[temp]!='\n'){
				temp++;
			}
			temp++;
		}
		while(fileText[temp]!='\n'){
			token[i].append(1,fileText[temp]);
			temp++;
		}
	}
	return token[n];
}
								//  01234567  length is 8
int GauseElim::stringToInt(string tok, int location){//stringToInt("20 30 40",1) get 30 
	int temp=0;
	int i=0;
	int tens=0;
	int output=0;
	while(i<tok.length()and temp<location){
		if(tok[i]==' '){
			temp++;
		}
		i++;
	}
	while(tok[i]!=' ' and tok[i]){
		output=output*tens;
		output=(tok[i]-'0')+output;
		tens=10+tens;
		i++;
	}
	return output;	
}

void GauseElim::setN(){
	n=stringToInt(getToken(0),0);
};

int GauseElim::getN(){
	return n;
};

void GauseElim::setGause1(){
	first.makeMatrix(getN(), getN());
	for(int i1=1;i1<n+1;i1++){
		for(int i2=0;i2<n;i2++){
			first.setNode(i1-1,i2,double(stringToInt(getToken(i1),i2)));
		}
	}
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

void GauseElim::setSolveGause(){
	solve.makeMatrix(getN(),1);
	for(int i1=n+1;i1<(2*n)+1;i1++){
		solve.setNode((i1-n-1),0,double(stringToInt(getToken(i1),0)));
	}
	cout<<endl;
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


















