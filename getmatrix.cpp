#include "getmatrix.h"
using namespace std;

GetMatrix::GetMatrix(){
};

GetMatrix::~GetMatrix(){
};

GetMatrix::GetMatrix(string file){
	listOfMatrix.open(file);
	fileText="";
	char tempC;
	while(listOfMatrix.get(tempC)){
		fileText.append(1,tempC);
	}
	setGause();
};

void GetMatrix::setGause(){//initiates and allocates all input matrixes and values
	setN();
	setGause1();
	setGause2();
//	first.display();
//	second.display();
};

void GetMatrix::setN(){//sets matrix sizes
	n=stringToInt(getToken(0),0);
};

void GetMatrix::setGause1(){//set primary matrix (known)
	first.makeMatrix(
	getN(), getN());
	for(int i1=1;i1<getN()+1;i1++){
		for(int i2=0;i2<getN();i2++){
			first.setNode(i1-1,i2,double(stringToInt(getToken(i1),i2)));
		}
	}
};

void GetMatrix::setGause2(){//set other side of matrix equation(known)
	second.makeMatrix(getN(),1);
	if (getN()*2<count_underscores(fileText)){
		for(int i1=getN()+1;i1<(2*getN())+1;i1++){
			second.setNode((i1-n-1),0,double(stringToInt(getToken(i1),0)));
		}
	}
};

int GetMatrix::getN(){
	return n;
};

Mat GetMatrix::getMat1(){
	return first;
}

Mat GetMatrix::getMat2(){
	return second;
}

int GetMatrix::stringToInt(string tok, int location){//turns a string from a line to a specific integer based on location
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
};

string GetMatrix::getToken(int n){//returns a line string
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
};

int GetMatrix::count_underscores(string s) {
  int count = 0;

  for (int i = 0; i < s.size(); i++)
    if (s[i] == '\n') count++;

  return count;
}
