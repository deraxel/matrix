#ifndef outmatrix_h
#define outmatrix_h
#include "matrix.h"
#include <fstream>
using namespace std;
class OutMatrix
{
	private:
		Mat matrix;
		ofstream matrixOut;
		string fileText;
		int x;
		int y;
	
	protected:
	public:
		OutMatrix();
		~OutMatrix();
		OutMatrix(string, Mat);
		void setAll();
		void setX();
		void setY();
		int getX();
		int getY();
		void fileWrite();
};

#endif
