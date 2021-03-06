#ifndef CMATRIX_H
#define CMATRIX_H
#include <iostream>
#include <cstring>
using namespace std;
class CMatrix
{
	int nR, nC;
	double** values;
public:
	CMatrix();
	~CMatrix();
	enum MI{ MI_ZEROS, MI_ONES, MI_EYE, MI_RAND, MI_VALUE };
	CMatrix(int nR, int nC, int initialization = MI_ZEROS, double initializationValue = 0.0);
	CMatrix(int nR, int nC, double first, ...);
	CMatrix(CMatrix& m);
	CMatrix(double d);
	CMatrix(string s);
	void copy(CMatrix& m);
	void copy(double d);
	void copy(string s);
	void reset();
	string getString();
	CMatrix& operator=(CMatrix& m);
	CMatrix& operator=(double d);
	CMatrix& operator=(string s);
	CMatrix& add(CMatrix& m);
	void operator+=(CMatrix& m);
	void operator+=(double d);
	CMatrix& operator+(CMatrix& m);
	CMatrix& operator+(double d);
	 CMatrix& sub(CMatrix& m);
	void operator-=(CMatrix& m);
	void operator-=(double d);
	CMatrix& operator-(CMatrix& m);
	CMatrix& operator-(double d);
    CMatrix& mul(CMatrix& m);
	void operator*=(CMatrix& m);
	void operator*=(double d);
	CMatrix& operator*(CMatrix& m);
	CMatrix& operator*(double d);
    CMatrix& div(CMatrix& m);
	void operator/=(CMatrix& m);
	void operator/=(double d);
	CMatrix& operator/(CMatrix& m);
	CMatrix& operator/(double d);
	CMatrix& operator++(); //Pre Increment
	CMatrix& operator++(int); //Post Increment, int is not used
	CMatrix& operator--(); //Pre Increment
	CMatrix& operator--(int); //Post Increment, int is not used
	CMatrix& operator-();
	CMatrix& operator+();
    friend istream& operator >> (istream &is, CMatrix& C); //Stream
	friend ostream& operator << (ostream &os, CMatrix& C); //Stream
	void setSubMatrix(int iR, int iC, CMatrix& m);
	CMatrix& getSubMatrix(int r, int c, int nr, int nc);
	CMatrix& getCofactor(int r, int c);
	void addColumn(CMatrix& m);
	void addRow(CMatrix& m);
	double& operator[](int i){ return values[i / nC][i%nC]; }
	double& operator()(int i){ return values[i / nC][i%nC]; }
	double& operator()(int r, int c){ return values[r][c]; }
	int getn(){ return nR*nC; };
	int getnR(){ return nR; };
	int getnC(){ return nC; };
	double getDeterminant();
	double FastestDeterminant();
    CMatrix& getTranspose();
	CMatrix& getInverse();
	friend CMatrix& division_by_element(double d,CMatrix& X);
	friend CMatrix& eye(int nr,int nc);
	friend CMatrix& rand(int nr,int nc);
	friend CMatrix& zeros(int nr,int nc);
	friend CMatrix& ones(int nr,int nc);
	friend CMatrix & power_by_element (CMatrix& l , double pow);
	CMatrix& sin_matrix();
	CMatrix& cos_matrix();
	CMatrix& tan_matrix();
	CMatrix& sec_matrix();
	CMatrix& csc_matrix();
	CMatrix& cot_matrix();
	CMatrix& asin_matrix();
	CMatrix& acos_matrix();
	CMatrix& atan_matrix();
	CMatrix& asec_matrix();
	CMatrix& acsc_matrix();
	CMatrix& acot_matrix();
	CMatrix& log_matrix();
	CMatrix& exp_matrix();
	friend CMatrix &power_matrix(CMatrix &matrix, int number);
	friend CMatrix &sqrt_matrix(CMatrix &matrix);
	friend float getTrace(CMatrix &mat);
	friend CMatrix &unityMatrix(int num);
	double get_values (int r , int c);
	bool operator==(CMatrix mat);
	};
#endif // CMATRIX_H
