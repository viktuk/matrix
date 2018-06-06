#include "stdafx.h"

class Matrix {
private:
    double** a;
    int m=2,n=2;
    void allocSpace();
    Matrix expHelper(const Matrix&, int);
    bool CheckPlus(const Matrix&);
    bool CheckMultiply(const Matrix&);
public:
    Matrix();
    Matrix(int, int);
    Matrix(const Matrix&);
    friend ostream& operator<<(ostream&, const Matrix&);
    friend istream& operator>>(istream&, const Matrix&);
    Matrix& operator+=(const Matrix&);
    Matrix& operator-=(const Matrix&);
    Matrix& operator*=(const Matrix&);
    Matrix& operator*=(double);
    Matrix& operator/=(double);
    Matrix operator^(int);
    Matrix createIdentity(int);
    Matrix transpose();
};

Matrix operator+(const Matrix&,const Matrix&);
Matrix operator-(const Matrix&,const Matrix&);
Matrix operator*(const Matrix&,const Matrix&);
Matrix operator*(const Matrix&, double);
Matrix operator/(const Matrix&, double);