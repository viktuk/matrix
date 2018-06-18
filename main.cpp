#include <iostream>
#include <string>

using namespace std;
#include "Matrix.h"

int main() {
    Matrix<double> A(2,3), B(3,3);
    cout<<"A"<<endl;
    cin>>A;
    cout<<"B"<<endl;
    cin>>B;
    cout<<"A"<<endl<<A<<endl<<"B"<<endl<<B<<endl;
    cout<<"Results"<< endl;
    cout << "A+B" << endl;
    try {
        cout << A + B << endl;
    }catch(string e){
        cout<<e<<endl;
    }
    cout << "B+E" << endl;
    try {
        Matrix<double> E = Matrix<double>().createIdentity(3);
        cout << B + E << endl;
    }catch(string e){
        cout<<e<<endl;
    }
    cout << "AB" << endl;
    try {
        cout<< A * B << endl;
    }catch(string e){
        cout<<e<<endl;
    }
    cout << "BA" << endl;
    try{
        cout << B * A<< endl;
    }catch(string e){
        cout<<e<<endl;
    }
    cout << "A*5" << endl << (A * 5)<< endl;
    cout << "A^3" << endl;
    try{
        cout << (A^3) << endl;
    }catch(string e){
        cout<<e<<endl;
    }
    cout << "B^3" << endl;
    try{
        cout << (B^3) << endl;
    }catch(string e){
        cout<<e<<endl;
    }
    return 0;
}