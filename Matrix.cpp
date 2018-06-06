#include "Matrix.h"
#include <string>
string error_size = "Different sizes";

void Matrix::allocSpace() {
    a = new double*[m];
    for (int i=0; i < m; i++){
        a[i] = new double[n];
        for(int j=0; j < n; j++){
            a[i][j]=0;
        }
    }
}

Matrix::Matrix() {
    allocSpace();
}

Matrix::Matrix(int _m, int _n) {
    m=_m; n=_n;
    allocSpace();
}

Matrix::Matrix(const Matrix &object) {
    m=object.m; n=object.n;
    allocSpace();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = object.a[i][j];
        }
    }
}

ostream& operator<<(ostream &out, const Matrix &object) {
    for (int i=0; i < object.m; i++){
        out<<"| ";
        for(int j=0; j < object.n; j++){
            out<<object.a[i][j]<<" ";
        }
        out<<"|"<<endl;
    }
    return out;
}

istream& operator>>(istream &in, const Matrix &object){
    for (int i=0; i < object.m; i++){
        for(int j=0; j < object.n; j++){
            in>>object.a[i][j];
        }
    }
    return in;
}

Matrix& Matrix::operator+=(const Matrix& object) {
    if(CheckPlus(object)) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                a[i][j] += object.a[i][j];
            }
        }
        return *this;
    }
    else{
        throw error_size;
    }
}

Matrix& Matrix::operator-=(const Matrix& object) {
    if(CheckPlus(object)) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                a[i][j] -= object.a[i][j];
            }
        }
        return *this;
    } else{
        throw error_size;
    }
}

Matrix& Matrix::operator*=(const Matrix& object) {
    if(CheckMultiply(object)) {
        Matrix temp(m, object.n);
        for (int i = 0; i < temp.m; ++i) {
            for (int j = 0; j < temp.n; ++j) {
                for (int k = 0; k < n; ++k) {
                    temp.a[i][j] += (a[i][k] * object.a[k][j]);
                }
            }
        }
        return (*this = temp);
    }else{
        throw error_size;
    }
}

Matrix& Matrix::operator*=(double num) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] *= num;
        }
    }
    return *this;
}

Matrix& Matrix::operator/=(double num) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] /= num;
        }
    }
    return *this;
}

Matrix Matrix::operator^(int num) {
    if(CheckPlus(*this)){
        Matrix temp(*this);
        return expHelper(temp, num);
    }else{
        throw error_size;
    }
}

Matrix operator+(const Matrix &left, const Matrix &right){
    Matrix temp(left);
    return (temp+= right);
}

Matrix operator-(const Matrix &left, const Matrix &right){
    Matrix temp(left);
    return (temp-= right);
}

Matrix operator*(const Matrix &left, const Matrix &right){
    Matrix temp(left);
    return (temp*= right);
}

Matrix operator*(const Matrix &left, double right){
    Matrix temp(left);
    return (temp*= right);
}

Matrix operator/(const Matrix &left, double right){
    Matrix temp(left);
    return (temp*= right);
}

Matrix Matrix::expHelper(const Matrix& m, int num)
{
    if (num == 0) {
        return createIdentity(m.m);
    } else if (num == 1) {
        return m;
    } else if (num % 2 == 0) {  // num is even
        return expHelper(m * m, num/2);
    } else {                    // num is odd
        return m * expHelper(m * m, (num-1)/2);
    }
}

Matrix Matrix::createIdentity(int size) {
    Matrix temp(size, size);
    for (int i = 0; i < temp.m; ++i) {
        for (int j = 0; j < temp.n; ++j) {
            if (i == j) {
                temp.a[i][j] = 1;
            } else {
                temp.a[i][j] = 0;
            }
        }
    }
    return temp;
}

Matrix Matrix::transpose()
{
    Matrix temp(m, n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            temp.a[j][i] = a[i][j];
        }
    }
    return temp;
}

bool Matrix::CheckPlus(const Matrix& object) {
    if(m==object.m&&n==object.n){
        return true;
    } else {
        return false;
    }
}

bool Matrix::CheckMultiply(const Matrix& object) {
    if(n==object.m){
        return true;
    } else {
        return false;
    }
}
