#ifndef inmatrix_h
#define inmatrix_h
#include "matrix.h"
#include <fstream>
using namespace std;
class InMatrix
{
	private:
		Mat matrix;
		ifstream listOfMatrix;
		string fileText;
		int x;
		int y;
	
	protected:
	public:
		InMatrix();
		~InMatrix();
		InMatrix(string);
		void setAll();
		void setX();
		void setY();
		void setMatrix();
		double stringToInt(string, int);
		string getToken(int);
		int getX();
		int getY();
		Mat getMat();
		int count_underscores(string);
};

#endif
