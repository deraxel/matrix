#ifndef getmatrix_h
#define getmatrix_h
#include "matrix.h"
#include <fstream>
using namespace std;
class GetMatrix
{
	private:
		Mat first;
		Mat second;
		ifstream listOfMatrix;
		string fileText;
		int n;
	
	protected:
	public:
		GetMatrix();
		~GetMatrix();
		GetMatrix(string);
		void setGause();
		void setN();
		void setGause1();
		void setGause2();
		int stringToInt(string, int);
		string getToken(int);
		int getN();
		int count_underscores(string);
		Mat getMat1();
		Mat getMat2();
};

#endif
