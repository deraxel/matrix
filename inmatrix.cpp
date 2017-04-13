#include "inmatrix.h"
using namespace std;

InMatrix::InMatrix(){
};

InMatrix::~InMatrix(){
};

InMatrix::InMatrix(string file){
	listOfMatrix.open(file);
	fileText="";
	char tempC;
	while(listOfMatrix.get(tempC)){
		fileText.append(1,tempC);
	}
	setAll();
};

void InMatrix::setAll(){//initiates and allocates all input matrixes and values
	setX();
	setY();
	setMatrix();
};

void InMatrix::setX(){//sets matrix sizes
	x=stringToInt(getToken(0),0);
};

void InMatrix::setY(){//sets matrix sizes
	y=stringToInt(getToken(0),1);
};

void InMatrix::setMatrix(){//set primary matrix (known)
	int swit=0;
	matrix.makeMatrix(getX(), getY());
	for(int i1=1;i1<getX()+1;i1++){
		for(int i2=0;i2<getY();i2++){
			matrix.setNode(i1-1,i2,stringToInt(getToken(i1),i2));
		}
	}
};

double InMatrix::stringToInt(string tok, int location){//turns a string from a line to a specific integer based on location
	int temp=0;
	int i=0;
	int tens=0;
	double deciTens=1;
	double output=0;
	bool flag=true;
	double sign=1;
	while(i<tok.length()and temp<location){
		if(tok[i]==' '){
			temp++;
		}
		i++;
	}
	while(tok[i]!=' ' and tok[i]){
		if(tok[i]=='-'){
			sign=-1;
		}else if(flag and tok[i]!='.'){
			output=output*tens;
			output=(tok[i]-'0')+output;
			tens=10+tens;
		}else if(tok[i]!='.'){
			deciTens=10.0*deciTens;
			output=((double(tok[i]-'0'))/deciTens)+output;
			flag=false;
		}else{
			flag=false;
		}
		i++;
	}
	output=sign*output;
	return output;
};

int InMatrix::getX(){
	return x;
};

int InMatrix::getY(){
	return y;
};

Mat InMatrix::getMat(){
	return matrix;
};

string InMatrix::getToken(int n){//returns a line string
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

int InMatrix::count_underscores(string s) {
	int count = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '\n') count++;
	}
	return count;
};
