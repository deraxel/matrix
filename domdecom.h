#ifndef domdecom_h
#define domdecom_h
using namespace std;
#include "matrix.h"
class DomDecom
{
	private:
		Mat matrix;
	protected:
	public:
		DomDecom();
		~DomDecom();
		DomDecom(Mat);
};

#endif
