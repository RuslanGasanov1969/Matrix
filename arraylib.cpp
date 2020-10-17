#include "arraylib.h"
#include <stdlib.h>

#include <iostream>
using namespace std;



int* createIntArray(int n){
    int *A = new int[n];
    for(int i = 0; i < n; i++){
        A[i] = 0;
    }
    return A;
}

double* createDoubleArray(int n){
    double *A = new double[n];
    for(int i = 0; i < n; i++){
        A[i] = 0;
    }
    return A;
}

void FillIntArray(int*A, int n, int from, int to){
    for(int i = 0; i < n; i++){
        A[i] = from + rand() % (to - from);
    }
}

void FillIntArrayTrasposition(int*A, int n){
    for(int i = 0; i < n; i++ ) A[i] = 0;

    for(int i = 1; i <= n; i++){
        int pos = rand() % n;
        while(A[pos] != 0) pos = rand() % n;
        A[pos] = i;
    }
}

void FillDoubleArray(double *A, int n, int from, int to){
    for(int i = 0; i < n; i++){
        A[i] = (from * 100 + rand() % ((to - from) * 100)) / 100.0 ;
    }
}

void ShowIntArray(int*A, int n){
    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}


void ShowDoubleArray(double *A, int n){
    cout.setf(ios::fixed);
    cout.precision(4);
    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

int GetCountOfSeries(int *A,int n){
    int cnt = 1;
    for(int i = 1; i < n; i++){
        if(A[i-1] != A[i]){
            cnt++;
        }
    }
    return cnt;
}

int GetSeriesPosition(int *A, int n, int ns){
    if(ns == 0){
        return 0;
    }
    int cnt = 0;
    for(int i = 1; i < n; i++)
    {
        if(A[i-1] != A[i])
        {
            cnt++;
            if(cnt == ns){
                return i;
            }
        }
    }
    return -1;
}

int GetSeriesLength(int *A, int n, int ns){
    int pos = GetSeriesPosition(A, n, ns);
    if(pos == -1){
        return 0;
    }
    int cnt = 0;
    for(int i = pos; i < n; i++){
        if(A[i] == A[pos]){
            cnt++;
        }
        else{
            break;
        }
    }
    return cnt;
}

int GetSeriesValue(int *A, int n, int ns){
    int pos = GetSeriesPosition(A, n, ns);
    if(pos == -1){
        return 0;
    }
    return A[pos];
}
