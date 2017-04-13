#ifndef LU_h
#define LU_h
using namespace std;
#include "matrix.h"
#include "gauseelim.h"
class Lu
{
	private:
		Mat first;
		Mat second;
		Mat solve;
		Mat tempY;
		GauseElim tempthing;
		Mat L;
		Mat U;
		int n;
	protected:
	public:
		Lu();
		~Lu();
		Lu(int,Mat,Mat);
		void setGause();
		void setGause2();
		void solveForSecond();
		void solveForSecondX();
		void setN(int);
		int getN();
		Mat getL();
		Mat getU();
		Mat getSec();
		void calcForLU();
		void calcLU();
		double calcU(int,int);
		double calcL(int,int);
		void displayAll();
		void displayAnswer();
		void displayU();
		void displayL();
};

#endif
