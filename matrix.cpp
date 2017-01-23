#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>
#include <ctime>
#include "matrix.h"
using namespace std;

Mat::Mat(){
	row=col=0;
	A=NULL;
};

Mat::~Mat(){
};

void Mat::makeMatrix(int r, int c){
	row=r; col=c;

        A=new double *[row];
	for(int i=0; i<row; i++){
		A[i]=new double[col];
		}
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
                       	setNode(i,j,0.0);
		}
	}
};

int Mat::getrow(){
	return row;
};

int Mat::getcol(){
	return col;
};

void Mat::display(){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			cout<<setw(8)<<getNode(i,j);
		}
		cout<<endl;
	}
	cout<<endl;
};

void Mat::ident(){
	if(col==1){
		setNode(0,0,1.0);
		}
	else{
		for(int i=0; i<row; i++)
		setNode(i,i,1.0);
	}
};

void Mat::setNode(int x, int y, double value){
	A[x][y]=value;
};

double Mat::getNode(int x, int y){
	return A[x][y];
};

void Mat::random_mat(double m){
	double sum=0.0;
	double r;
	default_random_engine gen(time(NULL));
	uniform_real_distribution<double> rdist(-1*m, m);
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			r=rdist(gen);
			setNode(i,j,r);
			sum = sum+abs(r);
		}
		setNode(i,i,r);
		sum=0.0;
	}
};
