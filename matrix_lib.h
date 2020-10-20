#ifndef MATRIX_LIB_H_INCLUDED
#define MATRIX_LIB_H_INCLUDED
#include <iomanip>
#include <iostream>

using namespace std;

template <class T>
void deleteMatrix(T**& matr, int m){
    for (int i=0; i<m; i++)
    {
        delete[] matr[i];
    }
    delete[] matr;
    matr = NULL;
}

template <class T>
void fillMatrixRnd(T** matr, int m, int n, int from=-5, int to=20){
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++){
            matr[i][j] = (from*100 + rand()%((to-from)*100))/100.0;
        }
    }
}

template <class T>
void showMatrix(T** matr, int m, int n, int w=6, int frac=2){
    cout.setf(ios::fixed);
    cout.precision(frac);
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++){
            cout << setw(w) << matr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template <class T>
T** createMatrix(int m, int n){
    T** matr = new T*[m];
    for (int i=0; i<m; i++)
    {
        matr[i] = new T[n];
    }

    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++){
            matr[i][j] = 0;
        }
    }
    return matr;
}



#endif // MATRIX_LIB_H_INCLUDED
