#ifndef matrix_h
#define matrix_h
class Mat
{

private:
	int row;
	int col;
	double ** A;
protected:
public:
	Mat();
	~Mat();
	int getrow();
	int getcol();
	void display();
	void ident();
        void random_mat(double);
	void setNode(int,int,double);
	double getNode(int,int);
	void makeMatrix(int, int);
};

#endif
