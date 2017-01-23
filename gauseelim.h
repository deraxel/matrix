#ifndef gauseelim_h
#define gauseelim_h
using namespace std;
#include "matrix.h"
#include <fstream>
class GauseElim
{
	private:
		Mat first;
		Mat second;
		Mat solve;
		Mat temp;
		int n;
		ifstream listOfMatrix;
		string fileText;
	protected:
	public:
		GauseElim();
		~GauseElim();
		GauseElim(string);
		void setGause();
		void setGause1();
		void setGause2();
		void setSolveGause();
		void setN();
		int getN();
		string getToken(int);
		int stringToInt(string,int);
		void display();
		void setGauseTemp();
		void gausingElemination();
		void solveForSecond();
		void displayAll();
		void displayAnswer();
		void calcGause();
		void setFileString(string);
};

#endif
