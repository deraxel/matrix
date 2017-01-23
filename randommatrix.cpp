#include <iostream>
#include <sstream>
#include <iomanip>
#include <random>
#include <cmath>
#include <ctime>
using namespace std;
#include "matrix.cpp"
#include "gauseelim.cpp"

int main(){
	string x = "";
	ostringstream oss;
	GauseElim B;
	Mat A;
	Mat C;
	int matSizeInp=0;
	cin>>matSizeInp;
	A.makeMatrix(matSizeInp,matSizeInp);
	C.makeMatrix(matSizeInp,1);
	A.random_mat(10);
	C.random_mat(10);
	oss<<matSizeInp<<endl;
	for(int i1=0;i1<matSizeInp;i1++){
		for(int i2=0;i2<matSizeInp;i2++){
			oss<<(int)A.getNode(i1,i2)<<' ';
		}
		oss<<endl;
	}
	for(int i=0;i<matSizeInp;i++){
		oss<<(int)C.getNode(i,0)<<endl;
	}
	x=oss.str();
	B.setFileString(x);
	B.setGause();
	B.display();
	cout<<endl;
	B.calcGause();
	B.displayAll();
    	return 0;
}
