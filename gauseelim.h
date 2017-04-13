#ifndef gauseelim_h
#define gauseelim_h
using namespace std;
#include "matrix.h"
class GauseElim
{
	private:
		Mat first;
		Mat second;
		Mat solve;
		Mat temp;
		int n;
	protected:
	public:
		GauseElim();
		~GauseElim();
		GauseElim(int, Mat, Mat);
		void setGause2();
		void setN(int);
		int getN();
		Mat getFirst();
		Mat getSecond();
		Mat getSolve();
		void display();
		void setGauseTemp();
		void gausingElemination();
		void solveForSecond();
		void displayAll();
		void displayAnswer();
		void calcGause();
};
#endif
