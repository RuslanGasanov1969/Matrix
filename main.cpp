#include "arraylib.h"
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <algorithm>
#include "point.h"
#include "matrix_lib.h"

#include <iostream>
double* Merge(double *A, int n1, double *B, int n2);
double* Merge2(double *A, int n1, double *B, int n2);
using namespace std;
void matrix1();

int main()
{
    srand(time(NULL));
    cout.setf(ios::fixed);
    cout.precision(2);
    matrix1();

    return 0;
}

void matrix1(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    int** M = createMatrix<int>(m, n);

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            M[i][j] = 10*i;
        }
    }

    showMatrix(M, m, n, 3, 0);
    deleteMatrix(M, m);
}

void matrix0(){
    int m, n;
    cout << " m = "; cin >> m;
    cout << " n = "; cin >> n;

    int** MI = createMatrix<int>(m, n);
    fillMatrixRnd(MI, m, n);
    showMatrix(MI, m, n, 3, 0);

    double** MD = createMatrix<double>(m, n);
    fillMatrixRnd(MD, m, n);
    showMatrix(MD, m, n);


    if (MI){
       showMatrix(MI, m, n, 3, 0);
    }
    if (MD){
       MD[0][0] = 777.0;
       showMatrix(MD, m, n);
    }

    deleteMatrix(MI, m);
    deleteMatrix(MD, m);
}


void array140(){
    int n;
    cout << " n = "; cin >> n;
    Point* A = Point::CreatePointArray(n);
    Point::ShowPoints(A, n);

    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if ( Point::compare2(A[i], A[j]) == -1 ){
                Point tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
    }

    Point::ShowPoints(A, n);
    delete []A;
}

void array139(){
    int n;
    cout << " n = "; cin >> n;
    Point* A = Point::CreatePointArray(n);
    Point::ShowPoints(A, n);

    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if ( Point::compare1(A[i], A[j]) == 1 ){
                Point tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
    }

    Point::ShowPoints(A, n);
    delete []A;
}


void array138(){
    int n;
    cout << " n = "; cin >> n;
    Point* A = Point::CreatePointArray(n);
    Point::ShowPoints(A, n);

    Point a = A[0];
    Point b = A[1];
    Point c = A[2];
    double minperim = Point::GetTrianglePerim(a, b, c);
    for(int i = 0; i < n-2; i++){
        for(int j  = i+1; j < n-1; j++){
            for(int k = j+1; k < n; k++){
                double perim = Point::GetTrianglePerim(A[i], A[j], A[k]);
                if(perim < minperim){
                    minperim = perim;
                    a = A[i];
                    b = A[j];
                    c = A[k];
                }
            }
        }
    }
    cout << " a = " << a << endl;
    cout << " b = " << b << endl;
    cout << " c = " << c << endl;
    cout << " minperim = " << minperim << endl;

    delete []A;
}

void array137(){
    int n;
    cout << " n = ";
    cin >> n;
    Point* A = Point::CreatePointArray(n);
    Point::ShowPoints(A, n);

    Point a = A[0];
    Point b = A[1];
    Point c = A[2];
    double maxperim = Point::GetTrianglePerim(a, b, c);
    for(int i = 0; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){
            for(int k = j+1; k < n; k++){
                double perim = Point::GetTrianglePerim(A[i], A[j], A[k]);
 //               cout << A[i] << A[j] << A[k] << perim << endl;
                if(perim > maxperim){
                    maxperim = perim;
                    a = A[i];
                    b = A[j];
                    c = A[k];
                }
            }
        }
    }

    cout << " a = " << a << endl;
    cout << " b = " << b << endl;
    cout << " c = " << c << endl;
    cout << " maxperim = " << maxperim << endl;

    delete []A;
}


void array136(){
    int n;
    cout << " n = ";
    cin >> n;
    Point* points = Point::CreatePointArray(n);
    Point::ShowPoints(points, n);

    Point answer = points[0];
    double mindist = Point::GetTotalDistance(answer, points, n);
    for(int i = 0; i < n; i++){
        double dist = Point::GetTotalDistance(points[i], points, n);
        cout << " dist = " << dist << endl;
        if(dist < mindist){
            mindist = dist;
            answer = points[i];
        }
    }


    cout << " answer = " << answer << endl;
    cout << " mindist = " << mindist << endl;

    delete []points;
}

void array135(){
    int n1, n2;
    cout << " n1 = ";
    cin >> n1;
    cout << " n2 = ";
    cin >> n2;
    Point* A = Point::CreatePointArray(n1, 0, 10);
    Point::ShowPoints(A, n1);
    Point* B = Point::CreatePointArray(n2, -10, 0);
    Point::ShowPoints(B, n2);

    Point a = A[0];
    Point b = B[0];
    double mindist = Point::GetDistance(a, b);
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            double dist = Point::GetDistance(A[i], B[j]);
            cout << " dist = " << dist << endl;
            if(dist < mindist){
                mindist = dist;
                a = A[i];
                b = B[j];
            }
        }

    }

    cout << " a = " << a << endl;
    cout << " b = " << b << endl;
    cout << " mindist = " << mindist << endl;

    delete []A;
    delete []B;
}


void array134(){
    int n;
    cout << " n = ";
    cin >> n;
    Point* points = Point::CreatePointArray(n);
    Point::ShowPoints(points, n);

    Point a = points[0];
    Point b = points[1] ;
    double maxdist = Point::GetDistance(a, b);
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            double dist = Point::GetDistance(points[i], points[j]);
            if(dist > maxdist){
                maxdist = dist;
                a = points[i];
                b = points[j];
            }
        }
    }

    cout << " maxdist = " << maxdist << endl;
    cout << " a = " << a << endl;
    cout << " b = " << b << endl;

    delete []points;
}


void array133(){
    int n;
    cout << " n = ";
    cin >> n;
    Point* points = Point::CreatePointArray(n);
    Point::ShowPoints(points, n);

    Point zero;
    Point answer;
    double mindist = 0;
    bool first = true;
    for(int i = 0; i < n; i++){
        int quarter = points[i].GetQurter();
        if(quarter == 1 || quarter == 3){
            double dist = Point::GetDistance(zero, points[i]);
            cout << points[i] << " dist = " << dist << endl;
            if(first){
                first = false;
                answer = points[i];
                mindist = dist;
            }
            else if(dist < mindist){
                mindist = dist;
                answer = points[i];
            }
        }
    }

    cout << " mindist = " << mindist << endl;
    cout << " answer = " << answer << endl;

    delete []points;
}


void array132(){
    int n;
    cout << " n = ";
    cin >> n;
    Point* points = Point::CreatePointArray(n);
    Point::ShowPoints(points, n);

    Point zero;
    Point answer;
    double maxdist = 0;
    for(int i = 0; i < n; i++){
        int quarter = points[i].GetQurter();
        if(quarter == 2){
            double dist = Point::GetDistance(zero, points[i]);
            cout << " dist = " << dist << endl;
            if(dist > maxdist){
                maxdist = dist;
                answer = points[i];
            }
        }
    }

    cout << " maxdist = " << maxdist << endl;
    cout << " answer = " << answer << endl;

    delete []points;
}


void array131(){
    int n;
    cout << " n = ";
    cin >> n;
    Point* points = Point::CreatePointArray(n);

    Point::ShowPoints(points, n);

    Point b = Point::createRandomPoint();
    cout << b << endl;

    Point nearest = points[0];
    double mindist = Point::GetDistance(b, nearest);
    for(int i = 0; i < n; i++){
        double dist = Point::GetDistance(b, points[i]);
        cout << " dist = " << dist << endl;
        if(dist < mindist){
            mindist = dist;
            nearest = points[i];
        }
    }

    cout << " nearest = " << nearest << endl;
    cout << " mindist = " << mindist << endl;

    delete []points;
}

void array130()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n, 1, 5);
    ShowIntArray(A, n);

    int N = GetCountOfSeries(A, n);

    int maxlength = 0;
    for(int i = 0; i < N; i++){
        int length = GetSeriesLength(A, n, i);
        if(length > maxlength){
            maxlength = length;
        }
    }

    for(int i = 0; i < N; i++){
        int length = GetSeriesLength(A, n, i);
        if(maxlength == length){
            int pos = GetSeriesPosition(A, n, i);
            A = InsertToArray(A, n, pos, A[pos]);
        }
    }

    ShowIntArray(A, n);

    delete[]A;
}


void array129()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n, 1, 5);
    ShowIntArray(A, n);

    int N = GetCountOfSeries(A, n);

    int maxlength = 1;
    for(int i = 0; i < N; i++){
        int length = GetSeriesLength(A, n, i);
        if(length > maxlength){
            maxlength = length;
        }
    }

    for(int i = N-1; i >= 0; i--){
        int length = GetSeriesLength(A, n, i);
        if(maxlength == length){
            int pos = GetSeriesPosition(A, n, i);
            A = InsertToArray(A, n, pos, A[pos]);
            break;
        }
    }

    ShowIntArray(A, n);

    delete[]A;
}


void array128()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n, 1, 5);
    ShowIntArray(A, n);

    int N = GetCountOfSeries(A, n);

    int maxlength = 1;
    for(int i = 0; i < N; i++){
        int length = GetSeriesLength(A, n, i);
        if(length > maxlength){
            maxlength = length;
        }
    }

    for(int i = 0; i < N; i++){
        int length = GetSeriesLength(A, n, i);
        if(maxlength == length){
            int pos = GetSeriesPosition(A, n, i);
            A = InsertToArray(A, n, pos, A[pos]);
            break;
        }
    }

    ShowIntArray(A, n);

    delete[]A;
}

void array116a()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n, 1, 5);
    ShowIntArray(A, n);

    int N = GetCountOfSeries(A, n);
    cout << " N = " << N << endl;
    int *B = createIntArray(N);
    int *C = createIntArray(N);

    for(int i = 0; i < N; i++){
 //       int pos = GetSeriesPosition(A, n, i);
        B[i] = GetSeriesLength(A, n, i);
        C[i] = GetSeriesValue(A, n, i);
    }

    ShowIntArray(B, N);
    ShowIntArray(C, N);

    delete[]A;
    delete[]B;
    delete[]C;
}


void array127()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n, 1, 5);
    ShowIntArray(A, n);

    int L;
    cout << " L = ";
    cin >> L;

    int N = GetCountOfSeries(A, n);

    int *B = new int[N];
    int *C = new int[N];

    for(int i = 0; i < N; i++){
        B[i] = GetSeriesLength(A, n, i);
        C[i] = GetSeriesValue(A, n, i);
    }

    int NN = 0;
    for(int i = 0; i < N; i++){
        if(B[i] > L){
            NN++;
        }
        else{
            NN+= B[i];
        }
    }

    int *D = new int[NN];
    int j = 0;
    for(int i = 0; i < N; i++){
        if(B[i] > L){
            D[j++] = 0;
        }
        else{
            for(int k = 0; k < B[i]; k++){
                D[j++] = C[i];
            }
        }
    }

    ShowIntArray(D, NN);

    delete[]A;
    delete[]B;
    delete[]C;
    delete[]D;
}


void array126()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n, 1, 5);
    ShowIntArray(A, n);

    int L;
    cout << " L = ";
    cin >> L;

    int N = GetCountOfSeries(A, n);

    int *B = new int[N];
    int *C = new int[N];

    for(int i = 0; i < N; i++){
        B[i] = GetSeriesLength(A, n, i);
        C[i] = GetSeriesValue(A, n, i);
    }

    int NN = 0;
    for(int i = 0; i < N; i++){
        if(B[i] == L){
            NN++;
        }
        else{
            NN+= B[i];
        }
    }

    int *D = new int[NN];
    int j = 0;
    for(int i = 0; i < N; i++){
        if(B[i] == L){
            D[j++] = 0;
        }
        else{
            for(int k = 0; k < B[i]; k++){
                D[j++] = C[i];
            }
        }
    }

    ShowIntArray(D, NN);

    delete[]A;
    delete[]B;
    delete[]C;
    delete[]D;
}


void array123()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n, 1, 5);
    ShowIntArray(A, n);

    int L, k;
    cout << " L = ";
    cin >> L;
    cout << " k = ";
    cin >> k;

    SwapArray(A, n, L, k);

    ShowIntArray(A, n);

    delete[]A;
}


void array125()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n, 1, 5);
    ShowIntArray(A, n);

    int L;
    cout << " L = ";
    cin >> L;

    int N = GetCountOfSeries(A, n);

    int *B = new int[N];
    int *C = new int[N];

    for(int i = 0; i < N; i++){
        B[i] = GetSeriesLength(A, n, i);
        C[i] = GetSeriesValue(A, n, i);
    }

    int NN = 0;
    for(int i = 0; i < N; i++){
        if(B[i] < L){
            NN++;
        }
        else{
            NN+= B[i];
        }
    }

    int *D = new int[NN];
    int j = 0;
    for(int i = 0; i < N; i++){
        if(B[i] < L){
            D[j++] = 0;
        }
        else{
            for(int k = 0; k < B[i]; k++){
                D[j++] = C[i];
            }
        }
    }

    ShowIntArray(D, NN);

    delete[]A;
    delete[]B;
    delete[]C;
    delete[]D;
}

void array122()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n, 1, 5);
    ShowIntArray(A, n);

    int k;
    cout << " k = ";
    cin >> k;

    int pos = GetSeriesPosition(A, n, k);
    if(pos != -1){
        int length = GetSeriesLength(A, n, k);
        for(int i = 0; i < length; i++){
            A = DeleteFromArray(A, n, pos);
        }
    }

    ShowIntArray(A, n);

    delete[]A;
}


void array121()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n, 1, 5);
    ShowIntArray(A, n);

    int k;
    cout << " k = ";
    cin >> k;

    int length = GetSeriesLength(A, n, k);
    if(length > 0){
        int pos = GetSeriesPosition(A, n, k);
        int value = GetSeriesValue(A, n, k);
        for(int i = 0; i < length; i++){
            A = InsertToArray(A, n, pos, value);
        }
    }

    ShowIntArray(A, n);

    delete[]A;
}


void array120()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n, 1, 5);
    ShowIntArray(A, n);

    int N = GetCountOfSeries(A, n);
    cout << " N = " << N << endl;

    for(int i = N-1; i >= 0; i--){
        int pos = GetSeriesPosition(A, n, i);
        A = DeleteFromArray(A, n, pos);
    }

    ShowIntArray(A, n);

    delete[]A;
}


void array119()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n, 1, 5);
    ShowIntArray(A, n);

    int N = GetCountOfSeries(A, n);
    cout << " N = " << N << endl;

    for(int i = N-1; i >= 0; i--){
        int pos = GetSeriesPosition(A, n, i);
        int value = GetSeriesValue(A, n, i);
        A = InsertToArray(A, n, pos, value);
    }

    ShowIntArray(A, n);

    delete[]A;
}


void array118()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n, 1, 5);
    ShowIntArray(A, n);

    int N = GetCountOfSeries(A, n);
    cout << " N = " << N << endl;

    for(int i = N-1; i >= 0; i--){
        int pos = GetSeriesPosition(A, n, i);
         int length = GetSeriesLength(A, n, i);
        A = InsertToArray(A, n, pos+length, 111);
    }

    ShowIntArray(A, n);

    delete[]A;
}


void array117()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n, 1, 5);
    ShowIntArray(A, n);

    int N = GetCountOfSeries(A, n);
    cout << " N = " << N << endl;

    for(int i = N-1; i >= 0; i--){
        int pos = GetSeriesPosition(A, n, i);
        A = InsertToArray(A, n, pos, 111);
    }

    ShowIntArray(A, n);

    delete[]A;
}


void array116()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n, 1, 5);
    ShowIntArray(A, n);

    int N = GetCountOfSeries(A, n);
    cout << " N = " << N << endl;
    int *B = createIntArray(N);
    int *C = createIntArray(N);

    for(int i = 0; i < N; i++){
 //       int pos = GetSeriesPosition(A, n, i);
        B[i] = GetSeriesLength(A, n, i);
        C[i] = GetSeriesValue(A, n, i);
    }

    ShowIntArray(B, N);
    ShowIntArray(C, N);

    delete[]A;
    delete[]B;
    delete[]C;
}


void array115()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    int *I = new int[n];
    for(int i = 0; i < n; i++){
        I[i] = i;
    }
    ShowIntArray(I, n);

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(A[I[j]] < A[I[i]]){
                swap(I[j], I[i]);
            }
        }
    }

    ShowIntArray(I, n);

    delete[]A;
    delete[]I;
}


void array114()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    for(int i = 1; i < n; i++){
        for(int j = i-1; j >= 0; j--){
            if(A[j] > A[j+1]){
                swap(A[j], A[j+1]);
            }
            else{
                break;
            }
        }
        ShowDoubleArray(A, n);
    }

    delete[]A;
}


void array113()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    //sort(A, A+n);
    for(int i = n-1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(A[j] > A[i]){
                swap(A[j], A[i]);
            }
        }
    }

    ShowDoubleArray(A, n);

    delete[]A;
}


void array112()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    for(int p = 0; p < n-1; p++)
    {
        bool ok = true;
        for(int i = 1; i < n-p; i++)
        {
            if( A[i-1] > A[i])
            {
                Swap(A[i-1], A[i]);
                ok = false;
            }
        }
        if(ok){
            break;
        }
        ShowDoubleArray(A, n);
    }


    delete[]A;
}

void array111()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n);
    ShowIntArray(A, n);

    for(int i = n-1 ; i >= 0; i--){
        if(A[i] % 2 != 0){
            A = InsertToArray(A, n, i, A[i]);
            A = InsertToArray(A, n, i, A[i]);
        }
    }

    ShowIntArray(A, n);

    delete[]A;
}


void array110()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n);
    ShowIntArray(A, n);

    for(int i = n-1 ; i >= 0; i--){
        if(A[i] % 2 == 0){
            A = InsertToArray(A, n, i, A[i]);
        }
    }

    ShowIntArray(A, n);

    delete[]A;
}


void array109()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    for(int i = n-1 ; i >= 0; i--){
        if(A[i] < 0){
            A = InsertToArray(A, n, i, 111.0);
        }
    }

    ShowDoubleArray(A, n);

    delete[]A;
}


void array108()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    for(int i = n-1 ; i >= 0; i--){
        if(A[i] > 0){
            A = InsertToArray(A, n, i, 111.0);
        }
    }

    ShowDoubleArray(A, n);

    delete[]A;
}


void array107()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    int N = n / 2 * 2 - 1;
    for(int i = N ; i >= 0; i-=2){
        A = InsertToArray(A, n, i, A[i]);
        A = InsertToArray(A, n, i, A[i]);
    }

    ShowDoubleArray(A, n);

    delete[]A;
}


void array106()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    // int N = n / 2 * 2 - 1;
    int N = (n - 1) / 2 * 2;
    for(int i = N ; i >= 0; i-=2){
        A = InsertToArray(A, n, i, A[i]);
    }

    ShowDoubleArray(A, n);

    delete[]A;
}

void array105()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    int k;
    cout << " k = ";
    cin >> k;
    int m;
    cout << " m = ";
    cin >> m;

    for(int cnt = 0; cnt < m; cnt++){
        A = InsertToArray<double>(A, n, k+1, 0);
    }

    ShowDoubleArray(A, n);

    delete[]A;
}


void array104a()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    int k;
    cout << " k = ";
    cin >> k;
    int m;
    cout << " m = ";
    cin >> m;

    for(int cnt = 0; cnt < m; cnt++){
        A = InsertToArray<double>(A, n, k, 0);
    }

    ShowDoubleArray(A, n);

    delete[]A;
}


void array104()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    int k;
    cout << " k = ";
    cin >> k;
    int m;
    cout << " m = ";
    cin >> m;

    int cnt = 0;
    while(cnt < m){
        A = InsertToArray<double>(A, n, k, 0);
        cnt++;
    }

    ShowDoubleArray(A, n);

    delete[]A;
}


void array103()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    double min = A[0];
    int minidx = 0;
    for(int i = 1; i < n; i++)
    {
        if(A[i] < min)
        {
            min = A[i];
            minidx = i;
        }
    }

    double max = A[0];
    int maxidx = 0;
    for(int i = 1; i < n; i++)
    {
        if(A[i] > max)
        {
            max = A[i];
            maxidx = i;
        }
    }

    if(minidx < maxidx){
        maxidx++;
    }

    A = InsertToArray(A, n, minidx, 0.0);
    A = InsertToArray(A, n, maxidx+1, 0.0);

    ShowDoubleArray(A, n);

    delete[]A;
}


void array102()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    int k;
    cout << " k = ";
    cin >> k;

    A = InsertToArray<double>(A, n, k+1, 333);

    ShowDoubleArray(A, n);

    delete[]A;
}

void array101()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    int k;
    cout << " k = ";
    cin >> k;

    A = InsertToArray<double>(A, n, k, 0);

    ShowDoubleArray(A, n);

    delete[]A;
}


void array100()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n, 1, 7);
    ShowIntArray(A, n);

    for(int i = n-1; i >= 0; i--){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(A[j] == A[i]){
                cnt++;
            }
        }

        if(cnt == 2){
            int x = A[i];
            for(int j = n-1; j >= 0; j--){
                if(A[j] == x){
                    A = DeleteFromArray3(A, n, j);
                }
            }
            i-= (cnt-1);
        }
    }

    ShowIntArray(A, n);

    delete[]A;
}

void array99()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n, 1, 7);
    ShowIntArray(A, n);

    for(int i = n-1; i >= 0; i--){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(A[j] == A[i]){
                cnt++;
            }
        }

        if(cnt > 2){
            int x = A[i];
            for(int j = n-1; j >= 0; j--){
                if(A[j] == x){
                    A = DeleteFromArray3(A, n, j);
                }
            }
            i-= (cnt-1);
        }
    }

    ShowIntArray(A, n);

    delete[]A;
}


void array98()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n, 1, 7);
    ShowIntArray(A, n);

    for(int i = n-1; i >= 0; i--){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(A[j] == A[i]){
                cnt++;
            }
        }

        if(cnt < 3){
            int x = A[i];
            for(int j = n-1; j >= 0; j--){
                if(A[j] == x){
                    A = DeleteFromArray3(A, n, j);
                }
            }
            i-= (cnt-1);
        }
    }

    ShowIntArray(A, n);

    delete[]A;
}

void array97()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n, 1, 7);
    ShowIntArray(A, n);

    ReversArray(A, n);
    for(int i = n-1; i >= 0; i--){
        bool ok = false;
        for(int j = 0; j < i; j++){
            if(A[j] == A[i]){
                ok = true;
                break;
            }
        }

        if(ok){
            A = DeleteFromArray3(A, n, i);
        }
    }

    ReversArray(A, n);
    ShowIntArray(A, n);

    delete[]A;
}

void array96()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n, 1, 7);
    ShowIntArray(A, n);

    for(int i = n-1; i >= 0; i--){
        bool ok = false;
        for(int j = 0; j < i; j++){
            if(A[j] == A[i]){
                ok = true;
                break;
            }
        }

        if(ok){
            A = DeleteFromArray3(A, n, i);
        }
    }

    ShowIntArray(A, n);

    delete[]A;
}

void array95()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n, 1, 7);
    ShowIntArray(A, n);

    for(int i = n-1; i > 0; i--){
        if(A[i-1] == A[i]){
            A = DeleteFromArray3(A, n, i);
        }
    }


    ShowIntArray(A, n);

    delete[]A;
}


void array94()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n);
    ShowIntArray(A, n);

    for(int i = 1; i < n; i++){

            A = DeleteFromArray3(A, n, i);

    }

    ShowIntArray(A, n);

    delete[]A;
}


void array93a()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n);
    ShowIntArray(A, n);

    int N = (n-1) / 2 * 2;
    cout << N << endl;
    for(int i = N; i >= 0; i-=2){

            A = DeleteFromArray3(A, n, i);

    }

    ShowIntArray(A, n);

    delete[]A;
}

void array93()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n);
    ShowIntArray(A, n);

    for(int i = 0; i < n; i++){

            A = DeleteFromArray3(A, n, i);

    }

    ShowIntArray(A, n);

    delete[]A;
}


void array92()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n);
    ShowIntArray(A, n);

    for(int i = n-1; i >= 0; i--){
        if(A[i] % 2 == 0){
            A = DeleteFromArray3(A, n, i);
        }
    }

    ShowIntArray(A, n);

    delete[]A;
}


void array91a()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    int k;
    cout << " k = ";
    cin >> k;

    int L;
    cout << " L = ";
    cin >> L;

    for(int i = L; i >= k; i--){
        A = DeleteFromArray3(A, n, i);
    }

    ShowDoubleArray(A, n);

    delete[]A;
}


void array91()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    int k;
    cout << " k = ";
    cin >> k;

    int L;
    cout << " L = ";
    cin >> L;

    for(int i = k; i <= L; i++){
        A = DeleteFromArray3(A, n, k);
    }

    ShowDoubleArray(A, n);

    delete[]A;
}

void array98a()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n, 1, 7);
    ShowIntArray(A, n);

    for(int i = n-1; i >= 0; i--){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(A[j] == A[i]){
                cnt++;
            }
        }

        if(cnt < 3){
            int x = A[i];
            for(int j = n-1; j >= 0; j--){
                if(A[j] == x){
                    A = DeleteFromArray3(A, n, j);
                }
            }
            i-= (cnt-1);
        }
    }

    ShowIntArray(A, n);

    delete[]A;
}


void array90()//Java
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    int k;
    cout << " k = ";
    cin >> k;

    A = DeleteFromArray3(A, n, k);

    ShowDoubleArray(A, n);

    delete[]A;
}

void array89()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    SortArray2(A, n);
    A[rand()%n] = 7;
    ShowDoubleArray(A, n);

    for( int i = 1; i < n; i++)
    {
        if(A[i-1] < A[i])
        {
            Swap(A[i-1], A[i]);
        }
    }

    for( int i = n-1; i > 0; i--)
    {
        if(A[i-1] < A[i])
        {
            Swap(A[i-1], A[i]);
        }
    }


    ShowDoubleArray(A, n);

    delete[]A;
}


void array88()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    SortArray(A, n);
    A[n-1] = -3;
    ShowDoubleArray(A, n);

    for( int i = n-1; i > 0; i--)
    {
        if(A[i-1] > A[i])
        {
            Swap(A[i-1], A[i]);
        }
    }

    ShowDoubleArray(A, n);

    delete[]A;
}


void array87()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    SortArray(A, n);
    A[0] = 7;
    ShowDoubleArray(A, n);

    for( int i = 1; i < n; i++)
    {
        if(A[i-1] > A[i])
        {
            Swap(A[i-1], A[i]);
        }
    }

    ShowDoubleArray(A, n);

    delete[]A;
}


void array86()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    int k;
    cout << " k = ";
    cin >> k;

    ShiftLeftCircle(A, n, k);

    ShowDoubleArray(A, n);

    delete[]A;
}


void array85()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    int k;
    cout << " k = ";
    cin >> k;

    ShiftRightCircle(A, n, k);

    ShowDoubleArray(A, n);

    delete[]A;
}


void array84()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    ShiftLeftCircle(A, n);

    ShowDoubleArray(A, n);

    delete[]A;
}


void array83()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    ShiftRightCircle(A, n);

    ShowDoubleArray(A, n);

    delete[]A;
}


void array82()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    int k;
    cout << " k = ";
    cin >> k;


    ShiftLeft(A, n, k);

    ShowDoubleArray(A, n);

    delete[]A;
}

void array81()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    int k;
    cout << " k = ";
    cin >> k;


    ShiftRight(A, n, k);

    ShowDoubleArray(A, n);

    delete[]A;
}


void array80()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    ShiftLeft(A, n);

    ShowDoubleArray(A, n);

    delete[]A;
}

void array79()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    ShiftRight(A, n);

    ShowDoubleArray(A, n);

    delete[]A;
}


void array78()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    double *B = new double[n];
    B[0] = (A[0] + A[1]) / 2;
    B[n-1] = (A[n-2] + A[n-1]) / 2;
    for(int i = 1; i < n-1; i++)
    {
        B[i] = (A[i-1] + A[i] + A[i+1]) / 3;
    }

    delete[]A;
    A = B;
    ShowDoubleArray(A, n);

    delete[]A;
}


void array77()//исправить
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    for(int i = 0; i < n; i++)
    {
        if(isLocalMin(A, n, i))
        {
            A[i]= A[i] * A[i];
        }
    }

    ShowDoubleArray(A, n);

    delete[]A;
}


void array76()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    int *Map = new int[n];
    for(int i = 0; i < n; i++)
    {
        Map[i] = 0;
        if(isLocalMax(A, n, i))
        {
            Map[i]= 1;
        }
    }

    ShowIntArray(Map, n);

    for(int i =0; i < n; i++)
    {
        if(Map[i])
        {
            A[i] = 0;
        }
    }

    ShowDoubleArray(A, n);

    delete[]A;
    delete[]Map;
}


void array75()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    int pos1 = GetMinPosition(A, n);
    int pos2 = GetMaxPosition(A, n);
    cout << pos1 << " " << pos2 << endl;

    //    int a = pos1;
    //    if(pos2 < pos1) a = pos2;
    int a = min(pos1, pos2);
    int b = pos1 > pos2 ? pos1 : pos2;

    ReversArray(A, n, a, b);
    ShowDoubleArray(A, n);

    delete[]A;
}

void array74()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    int pos1 = GetMinPosition(A, n);
    int pos2 = GetMaxPosition(A, n);
    cout << pos1 << " " << pos2 << endl;

    //    int a = pos1;
    //    if(pos2 < pos1) a = pos2;
    int a = min(pos1, pos2);
    int b = pos1 > pos2 ? pos1 : pos2;

    for(int i = a+1; i < b; i++)
    {
        A[i] = 0;
    }

    ShowDoubleArray(A, n);

    delete[]A;
}

void array73()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n);
    ShowIntArray(A, n);

    int k, l;
    cout << " k = ";
    cin >> k;
    cout << " l = ";
    cin >> l;

    ReversArray(A, n, k+1, l-1);
    ShowIntArray(A, n);

    delete[]A;
}


void array72()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n);
    ShowIntArray(A, n);

    int k, l;
    cout << " k = ";
    cin >> k;
    cout << " l = ";
    cin >> l;

    ReversArray(A, n, k, l);
    ShowIntArray(A, n);

    delete[]A;
}


void array71a()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n);
    ShowIntArray(A, n);

    int i = 0;
    int j = n -1;
    while(i < j)
    {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
        i++;
        j--;
    }

    ShowIntArray(A, n);

    delete[]A;
}


void array71()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n);
    ShowIntArray(A, n);

    int j = n -1;
    for(int i = 0; i < n/2; i++)
    {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
        j--;
    }

    ShowIntArray(A, n);

    delete[]A;
}


void array70()//?
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n);
    ShowIntArray(A, n);

    int j = n/2;
    for(int i = 0; i < n/2; i++)
    {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
        j++;
    }

    ShowIntArray(A, n);

    delete[]A;
}


void array69()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n);
    ShowIntArray(A, n);

    for(int i = 1; i < n; i+=2)
    {
        int tmp = A[i];
        A[i] = A[i-1];
        A[i-1] = tmp;
    }

    ShowIntArray(A, n);

    delete[]A;
}

void array68()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    double min = A[0];
    int minidx = 0;
    for(int i = 1; i < n; i++)
    {
        if(A[i] < min)
        {
            min = A[i];
            minidx = i;
        }
    }

    double max = A[0];
    int maxidx = 0;
    for(int i = 1; i < n; i++)
    {
        if(A[i] > max)
        {
            max = A[i];
            maxidx = i;
        }
    }

    A[maxidx] = min;
    A[minidx] = max;

    ShowDoubleArray(A, n);

    delete[]A;
}

void array67()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n);
    ShowIntArray(A, n);

    int k = 0;
    for(int i = n-1; i >= 0; i--)
    {
        if(A[i] % 2 != 0)
        {
            k = A[i];
            break;
        }
    }

    if(k != 0)
    {
        for(int i = 0; i < n; i++)
        {
            if(A[i] % 2 != 0)
            {
                A[i] += k;
            }
        }
    }

    ShowIntArray(A, n);

    delete[]A;
}


void array66()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n);
    ShowIntArray(A, n);

    int k = -1;
    for(int i = 0; i < n; i++)
    {
        if(A[i] % 2 == 0)
        {
            k = A[i];
            break;
        }
    }

    if(k != -1)
    {
        for(int i = 0; i < n; i++)
        {
            if(A[i] % 2 == 0)
            {
                A[i] += k;
            }
        }
    }

    ShowIntArray(A, n);

    delete[]A;
}


void array65()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    int k;
    cout << " k = ";
    cin >> k;

    double Ak = A[k];
    for(int i = 0; i < n; i++)
    {
        A[i]+= Ak;
    }

    ShowDoubleArray(A, n);

    delete[]A;
}


double* Merge(double *A, int n1, double *B, int n2)
{
    double *C = createDoubleArray(n1+n2);
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < n1 && j < n2)
    {
        if(A[i] < B[j])
        {
            C[k++] = A[i++];
        }
        else
        {
            C[k++] = B[j++];
        }
    }
    while(i < n1) C[k++] = A[i++];
    while(j < n2) C[k++] = B[j++];

    return C;
}

double* Merge2(double *A, int n1, double *B, int n2)
{
    double *C = createDoubleArray(n1+n2);
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < n1 && j < n2)
    {
        if(A[i] > B[j])
        {
            C[k++] = A[i++];
        }
        else
        {
            C[k++] = B[j++];
        }
    }
    while(i < n1) C[k++] = A[i++];
    while(j < n2) C[k++] = B[j++];

    return C;
}


void array64()
{
    int a, b, c;
    cout << " a = ";
    cin >> a;
    cout << " b = ";
    cin >> b;
    cout << " c = ";
    cin >> c;

    double *A = new double[a];
    FillDoubleArray(A, a);

    SortArray2(A, a);
    ShowDoubleArray(A, a);

    double *B = new double[b];
    FillDoubleArray(B, b);

    SortArray2(B, b);
    ShowDoubleArray(B, b);

    double *C = new double[c];
    FillDoubleArray(C, c);

    SortArray2(C, c);
    ShowDoubleArray(C, c);


    double *D = Merge2(A, a, B, b);
    ShowDoubleArray(D, a+b);

    double *E = Merge2(D, a+b, C, c);
    ShowDoubleArray(E, a+b+c);

    delete[]A;
    delete[]B;
    delete[]C;
    delete[]D;
    delete[]E;
}


void array63()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    FillDoubleArray(A, n);
//   ShowDoubleArray(A, n);

    SortArray(A, n);
    ShowDoubleArray(A, n);

    double *B = new double[n];
    FillDoubleArray(B, n);
    //  ShowDoubleArray(B, n);

    SortArray(B, n);
    ShowDoubleArray(B, n);

    double *C = Merge(A, n, B, n);

    ShowDoubleArray(C, n+n);

    delete[]A;
    delete[]B;
    delete[]C;
}

void array62()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = createDoubleArray(n);
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    int n1 = 0;
    int n2 = 0;
    for(int i = 0; i < n; i++)
    {
        if(A[i] > 0)
            n1++;
        if(A[i] < 0)
            n2++;
    }

    double *B = createDoubleArray(n1);
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        if(A[i] > 0)
        {
            B[j] = A[i];
            j++;
        }
    }

    double *C = createDoubleArray(n2);
    j = 0;
    for(int i = 0; i < n; i++)
    {
        if(A[i] < 0)
        {
            C[j] = A[i];
            j++;
        }
    }

    ShowDoubleArray(B, n1);
    ShowDoubleArray(C, n2);

    delete []A;
    delete []B;
    delete []C;
}

void array61()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n);
    ShowIntArray(A, n);

    int *B = createIntArray(n);

    int sum = 0;
    int N = 0;
    for(int i = n-1; i >= 0; i--)
    {
        sum = sum + A[i];
        N++;
        B[i] = sum / N;
    }

    ShowIntArray(B, n);

    delete[]A;
    delete[]B;
}


void array60()// запомнить!!
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n);
    ShowIntArray(A, n);

    int *B = createIntArray(n);

    int sum = 0;
    for(int i = n-1; i >= 0; i--)
    {
        sum = sum + A[i];
        B[i] = sum;
    }

    ShowIntArray(B, n);

    delete[]A;
    delete[]B;
}

void array59()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n);
    ShowIntArray(A, n);

    int *B = createIntArray(n);

    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum = sum + A[i];
        B[i] = sum / (i+1);
    }

    ShowIntArray(B, n);

    delete[]A;
    delete[]B;
}

void array58()// запомнить!!
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n);
    ShowIntArray(A, n);

    int *B = createIntArray(n);

    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum = sum + A[i];
        B[i] = sum;
    }

    ShowIntArray(B, n);

    delete[]A;
    delete[]B;
}

void array57()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n);
    ShowIntArray(A, n);

    int *B = new int[n];

    int j = 0;
    for(int i = 0; i < n; i+=2)
    {
        B[j] = A[i];
        j++;
    }
    for(int i = 1; i < n; i+=2)
    {
        B[j] = A[i];
        j++;
    }

    ShowIntArray(B, n);

    delete[]A;
    delete[]B;
}


void array56()// запомнить!!
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n);
    ShowIntArray(A, n);

    int N = (n - 1) / 3 + 1;
    int *B = new int[N];

    int j = 0;
    for(int i = 0; i < n; i+=3)
    {
        B[j] = A[i];
        j++;
    }

    ShowIntArray(B, N);

    delete[]A;
    delete[]B;
}

void array55()//?
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n);
    ShowIntArray(A, n);

    int N = n / 2;
    int *B = new int[N];
    int j = 0;
    for(int i = 0; i < n; i+=2)
    {
        B[j] = A[i];
        j++;
    }

    ShowIntArray(B, N);

    delete[]A;
    delete[]B;
}


void array54()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n);
    ShowIntArray(A, n);

    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(A[i] % 2 == 0)
        {
            cnt++;
        }
    }

    int *B = new int[cnt];

    int j = 0;
    for(int i = 0; i < n; i++)
    {
        if(A[i] % 2 == 0)
        {
            B[j++] = A[i];
        }
    }

    ShowIntArray(B, cnt);

    delete[]A;
    delete[]B;
}

void array53()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = createDoubleArray(n);
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    double *B = createDoubleArray(n);
    FillDoubleArray(B, n);
    ShowDoubleArray(B, n);

    double *C = createDoubleArray(n);
    for(int i = 0; i < n; i++)
    {
        if( A[i] > B[i])
        {
            C[i] = A[i];
        }
        else
        {
            C[i] = B[i];
        }
    }

    ShowDoubleArray(C, n);

    delete []A;
    delete []B;
    delete []C;
}


void array52()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = createDoubleArray(n);
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    double *B = createDoubleArray(n);

    for(int i = 0; i < n; i++)
    {
        if(A[i] >= 5)
        {
            B[i] = A[i] / 2;
        }
        else
        {
            B[i] = A[i] * 2;
        }
    }

    ShowDoubleArray(B, n);

    delete []A;
    delete []B;
}


void array51a()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = createDoubleArray(n);
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    double *B = createDoubleArray(n);
    FillDoubleArray(B, n);
    ShowDoubleArray(B, n);

    double *temp = A;
    A = B;
    B = temp;

    ShowDoubleArray(A, n);
    ShowDoubleArray(B, n);

    delete []A;
    delete []B;
}


void array51()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = createDoubleArray(n);
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    double *B = createDoubleArray(n);
    FillDoubleArray(B, n);
    ShowDoubleArray(B, n);

    for(int i = 0; i < n; i++)
    {
        double temp = A[i];
        A[i] = B[i];
        B[i] = temp;
    }

    ShowDoubleArray(A, n);
    ShowDoubleArray(B, n);

    delete []A;
    delete []B;
}


void array49()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n);
    ShowIntArray(A, n);

    for(int i = 0; i < n; i++)
    {
        if(A[i-1] != A[i])
        {
            cout << 0 << endl;
        }
        else
        {
            cout << i << endl;
            break;
        }
    }

    delete[]A;
}


void array48()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n);
    ShowIntArray(A, n);

    int cnt = 1;
    for(int i = 1; i < n; i++)
    {
        if(A[i-1] == A[i])
        {
            cnt++;
        }
    }

    cout << " cnt = " << cnt << endl;
    delete[]A;
}


void array47()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n);
    ShowIntArray(A, n);

    int cnt = 1;
    for(int i = 1; i < n; i++)
    {
        if(A[i-1] != A[i])
        {
            cnt++;
        }
    }

    cout << " cnt = " << cnt << endl;
    delete[]A;
}

//void array46()
//{
//    int n;
//    cout << " n = ";
//    cin >> n;
//
//    double *A = createDoubleArray(n);
//    FillDoubleArray(A, n);
//    ShowDoubleArray(A, n);
//
//    double r;
//    cout << " r = ";
//    cin >> r;
//
//    double a = A[0];
//    double b = A[1];
//    double nearestsum = a + b;
//    double mindif = fabs(nearestsum-r);
//    for(int i = 0; i < n-1; i++)
//    {
//        for(int j = 1; j < n; j++){
//
//        }
//        double sum = A[i-1] + A[i];
//        double dif = fabs(sum - r);
//        cout << A[i-1] << " " << A[i] << "  " << sum << " " << dif << endl;
//        if(dif < mindif)
//        {
//            mindif = dif;
//            nearestsum = sum;
//            a = A[i-1];
//            b = A[i];
//        }
//    }
//
//    cout << " mindif = " << mindif <<endl;
//    cout << " nearestsum = " << nearestsum <<endl;
//    cout << " a = " << a <<endl;
//    cout << " b = " << b <<endl;
//    delete []A;
//}

void array45()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = createDoubleArray(n);
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    double a = A[0];
    double b = A[1];
    double mindif = fabs(a-b);
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            double dif = fabs(A[i] - A[j]);
            //         cout << A[i] << " " << A[j] << "  " << dif << endl;
            if(dif < mindif)
            {
                mindif = dif;
                a = A[i];
                b = A[j];
            }

        }
    }

    cout << " mindif = " << mindif <<endl;
    cout << " a = " << a <<endl;
    cout << " b = " << b <<endl;
    delete []A;
}

void array44()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArrayTrasposition(A, n);
    A[rand()%n] = A[rand()%n];
    ShowIntArray(A, n);

    int idx1 = -1;
    int idx2 = -1;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
//            cout << i << " " << j << endl;
            if(A[i] == A[j])
            {
                idx1 = i;
                idx2 = j;
                break;
            }
        }
    }


    cout << " idx1 = " << idx1 << endl;
    cout << " idx2 = " << idx2 << endl;
    delete[]A;
}

void array43()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    FillIntArray(A, n, 0, 5);
    ShowIntArray(A, n);

    SortArray(A, n);
    ShowIntArray(A, n);

    int cnt = 1;
    for(int i = 1; i < n; i++)
    {
        if(A[i-1] != A[i])
        {
            cnt++;
        }
    }

    cout << " cnt = " << cnt << endl;
    delete[]A;//отдать память
}

void array42()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = createDoubleArray(n);
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    double r;
    cout << " r = ";
    cin >> r;

    double a = A[0];
    double b = A[1];
    double nearestsum = a + b;
    double mindif = fabs(nearestsum-r);
    for(int i = 1; i < n; i++)
    {
        double sum = A[i-1] + A[i];
        double dif = fabs(sum - r);
        cout << A[i-1] << " " << A[i] << "  " << sum << " " << dif << endl;
        if(dif < mindif)
        {
            mindif = dif;
            nearestsum = sum;
            a = A[i-1];
            b = A[i];
        }
    }

    cout << " mindif = " << mindif <<endl;
    cout << " nearestsum = " << nearestsum <<endl;
    cout << " a = " << a <<endl;
    cout << " b = " << b <<endl;
    delete []A;
}

void array41()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = createDoubleArray(n);
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    double max1 = A[0];
    double max2 = A[1];
    int idx = 0;
    double maxsum = max1 + max2;
    for(int i = 0; i < n-1; i++)
    {
        double sum = A[i] + A[i+1];
        cout << " sum = " << sum <<endl;
        if(maxsum < sum )
        {
            maxsum = sum;
            idx = i;
        }
    }

    cout << A[idx] << " " << A[idx + 1] << endl;
    cout << " maxsum = " << maxsum <<endl;
    delete []A;
}


void array40()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = createDoubleArray(n);
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    double r;
    cout << " r = ";
    cin >> r;

    double nearest = A[0];
    double mindif = fabs(A[0] - r);
    for(int i = 1; i < n; i++)
    {
        double dif = fabs(A[i] - r);
        if(dif < mindif)
        {
            mindif = dif;
            nearest = A[i];
        }
    }

    cout << " mindif = " << mindif <<endl;
    cout << " nearest = " << nearest <<endl;
    delete []A;
}

void array39()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = createDoubleArray(n);
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 1; i < n; i++)
    {
        if(isLocalMin(A, n, i))
        {
            cnt1++;
        }
        if(isLocalMax(A, n, i))
        {
            cnt2++;
        }
    }

    int cnt = cnt1 + cnt2;

    cout << " cnt1 = " << cnt1 << " " << endl;
    cout << " cnt2 = " << cnt2 << "\n";
    cout << " cnt = " << cnt <<endl;
    delete []A;
}


void array38()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = createDoubleArray(n);
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    int cnt = 0;
    for(int i = 1; i < n; i++)
    {
        if(isLocalMin(A, n, i))
        {
            cnt++;
        }
    }

    cout << " cnt = " << cnt <<endl;
    delete []A;
}


void array37()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = createDoubleArray(n);
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    int cnt = 0;
    for(int i = 1; i < n; i++)
    {
        if(isLocalMax(A, n, i))
        {
            cnt++;
        }
    }

    cout << " cnt = " << cnt <<endl;
    delete []A;
}


void array36()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = createDoubleArray(n);
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    int N = 0;
    for(int i = 0; i < n; i++)
    {
        if(isNoLocal<double>(A, n, i))
        {
            N++;
        }
    }

    double *B = createDoubleArray(N);

    int j = 0;
    for(int i = 0; i < n; i++)
    {
        if(isNoLocal(A, n, i))
        {
            B[j] = A[i];
            j++;
        }
    }

    ShowDoubleArray(B, N);

    double max = B[0];
    for(int i = 1; i < N; i++)
    {
        if(B[i] > max)
        {
            max = B[i];
        }
    }

    cout << " max = " << max <<endl;
    delete []B;
    delete []A;
}


void array35()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = createDoubleArray(n);
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    int N = 0;
    for(int i = 0; i < n; i++)
    {
        if(isLocalMax<double>(A, n, i))
        {
            N++;
        }
    }

    double *B = createDoubleArray(N);

    int j = 0;
    for(int i = 0; i < n; i++)
    {
        if(isLocalMax(A, n, i))
        {
            B[j] = A[i];
            j++;
        }
    }

    ShowDoubleArray(B, N);

    double min = B[0];
    for(int i = 1; i < N; i++)
    {
        if(B[i] < min)
        {
            min = B[i];
        }
    }

    cout << " min = " << min <<endl;
    delete []B;
    delete []A;
}


void array34()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = createDoubleArray(n);
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    int N = 0;
    for(int i = 0; i < n; i++)
    {
        if(isLocalMin<double>(A, n, i))
        {
            N++;
        }
    }

    double *B = createDoubleArray(N);

    int j = 0;
    for(int i = 0; i < n; i++)
    {
        if(isLocalMin(A, n, i))
        {
            B[j] = A[i];
            j++;
        }
    }

    ShowDoubleArray(B, N);

    double max = B[0];
    for(int i = 1; i < N; i++)
    {
        if(B[i] > max)
        {
            max = B[i];
        }
    }

    cout << " max = " << max <<endl;
    delete []B;
    delete []A;
}


void array33a()
{
    int n;
    cout << " n = ";
    cin >> n;

    int*A = createIntArray(n);
    FillIntArray(A, n);
    ShowIntArray(A, n);

    int maxPos = -1;
    for(int i = n-1; i >= 0; i--)
    {
        if(isLocalMax(A, n, i))
        {
            maxPos = i;
            break;
        }
    }
    cout << " maxPos = " << maxPos <<endl;
    delete []A;
}


void array33()
{
    int n;
    cout << " n = ";
    cin >> n;

    int*A = createIntArray(n);
    FillIntArray(A, n);
    ShowIntArray(A, n);

    int maxPos = 0;
    for(int i = 0; i < n; i++)
    {
        if(isLocalMax(A, n, i))
        {
            maxPos = i;
        }
    }
    cout << " maxPos = " << maxPos <<endl;
    delete []A;
}


void array32()
{
    int n;
    cout << " n = ";
    cin >> n;

    int*A = createIntArray(n);
    FillIntArray(A, n);
    ShowIntArray(A, n);

    int max = 0;
    for(int i = 0; i < n; i++)
    {
        if(isLocalMin(A, n, i))
        {
            max = A[i];
            break;
        }
    }
    cout << " min = " << max <<endl;
    delete []A;
}

void array31()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = createDoubleArray(n);
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    int cnt = 0;
    for(int i = n-1; i > 0; i--)
    {
        if(A[i-1] < A[i])
        {
            cout << i << " ";
            cnt++;
        }
    }
    cout << endl;
    cout << " cnt = " << cnt << endl;

    delete []A;
}


void array30()
{
    int n;
    cout << " n = ";
    cin >> n;

    int*A = createIntArray(n);
    FillIntArray(A, n);
    ShowIntArray(A, n);

    int cnt = 0;
    for(int i = 0; i < n-1; i++)
    {
        if(A[i]> A[i+1])
        {
            cnt++;
            cout << i << " ";
        }
    }

    cout << endl << " cnt = " << cnt <<endl;
    delete []A;
}

void array29()
{
    int n;
    cout << " n = ";
    cin >> n;

    int*A = createIntArray(n);
    FillIntArray(A, n);
    ShowIntArray(A, n);
    int max = A[1];
    for(int i = 3; i < n; i+=2)
    {
        if(A[i] > max)
        {
            max = A[i];
        }
    }

    cout << " max = " << max <<endl;
    delete []A;
}


void array28()
{
    int n;
    cout << " n = ";
    cin >> n;

    int*A = createIntArray(n);
    FillIntArray(A, n);
    ShowIntArray(A, n);
    int max = A[0];
    for(int i = 2; i < n; i+=2)
    {
        if(A[i] < max)
        {
            max = A[i];
        }
    }

    cout << " min = " << max <<endl;
    delete []A;
}

void array27()
{
    int n;
    cout << " n = ";
    cin >> n;

    int*A = createIntArray(n);
    FillIntArray(A, n);
    ShowIntArray(A, n);

    bool ok = true;
    for(int i = 0; i < n-1; i++)
    {
        //      if(A[i] > 0 && A[i+1] > 0 || A[i] < 0 && A[i+1] < 0){
        if(A[i] * A[i+1] >= 0)
        {
            ok = false;
            break;
        }
    }

    cout << " ok = " << ok <<endl;
    delete []A;
}


void array26()
{
    int n;
    cout << " n = ";
    cin >> n;

    int*A = createIntArray(n);
    FillIntArray(A, n);
    ShowIntArray(A, n);

    bool ok = true;
    for(int i = 0; i < n-1; i++)
    {
        if(A[i] % 2 == A[i+1] % 2)
        {
            ok = false;
            break;
        }
    }

    cout << " ok = " << ok <<endl;
    delete []A;
}

void array25()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = createDoubleArray(n);
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    bool ok = true;
    int D = A[1] / A[0];
    for(int i = 0; i < n-1; i++)
    {
        int d = A[i+1] / A[i];
        if(d != D)
        {
            ok = false;
            break;
        }
    }
    cout << " ok = " << ok <<endl;

    if(ok)
        cout << " D = " << D << endl;
    delete []A;
}

void array24() // заполнить прогрессией!!
{
    int n;
    cout << " n = ";
    cin >> n;

    int*A = createIntArray(n);
    FillIntArray(A, n);
    ShowIntArray(A, n);

    bool ok = true;
    int D = A[1] - A[0];
    for(int i = 0; i < n-1; i++)
    {
        int d = A[i+1] - A[i];
        if(d != D)
        {
            ok = false;
            break;
        }
    }

    cout << " ok = " << ok <<endl;
    if(ok)
        cout << " D = " << D << endl;
    delete []A;
}

//void array23(){
//    int n, k, L;
//    cout << " n = "; cin >> n;
//
//    double *A = createDoubleArray(n);
//    FillDoubleArray(A, n);
//    ShowDoubleArray(A, n);
//
//    cout << " k = "; cin >> k;
//    cout << " L = "; cin >> L;
//
//    double sum = 0;
//    int cnt = 0;
//    double suma = 0;
//    for(int i > k; i < L; i++){
//        sum = sum + A[i];
//        cnt++;
//        suma = sum / cnt;
//    }
//    cout << " suma " << suma << endl;
//    delete []A;
//}


//void array22(){
//    int n, k, L;
//    cout << " n = "; cin >> n;
//
//    double *A = createDoubleArray(n);
//    FillDoubleArray(A, n);
//    ShowDoubleArray(A, n);
//
//    cout << " k = "; cin >> k;
//    cout << " L = "; cin >> L;
//
//    double sum = 0;
//    for(int i > k; i < L; i++){
//        sum = sum + A[i];
//    }
//    cout << " sum " << sum << endl;
//    delete []A;
//}

void array21()
{
    int n, k, L;
    cout << " n = ";
    cin >> n;

    double *A = createDoubleArray(n);
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    cout << " k = ";
    cin >> k;
    cout << " L = ";
    cin >> L;

    double sum = 0;
    int cnt = 0;
    double suma = 0;
    for(int i = k; i <= L; i++)
    {
        sum = sum + A[i];
        cnt++;
        suma = sum / cnt;
    }
    cout << " suma " << suma << endl;
    delete []A;
}

void array20()
{
    int n, k, L;
    cout << " n = ";
    cin >> n;

    double *A = createDoubleArray(n);
    FillDoubleArray(A, n);
    ShowDoubleArray(A, n);

    cout << " k = ";
    cin >> k;
    cout << " L = ";
    cin >> L;

    double sum = 0;
    for(int i = k; i <= L; i++)
    {
        sum = sum + A[i];
    }
    cout << " sum " << sum << endl;
    delete []A;
}


void array19()
{
    int n;
    cout << " n = ";
    cin >> n;

    int*A = createIntArray(n);
    FillIntArray(A, n);
    ShowIntArray(A, n);

    int result = -1;
    for(int i = 0; i < n-1; i++)
    {
        if(A[0] < A[i] && A[i] < A[n-1])
        {
            result = i;
        }
    }
    cout << " result " << result;
    cout << endl;
    delete []A;
}


void array18()
{
    int n;
    cout << " n = ";
    cin >> n;

    int*A = createIntArray(n);
    FillIntArray(A, n);
    ShowIntArray(A, n);

    int result = 0;
    for(int i = 0; i < n-1; i++)
    {
        if(A[i] < A[n-1])
        {
            result = A[i];
            break;
        }
    }
    cout << " result " << result;
    cout << endl;
    delete []A;
}


void array17()
{
    int n;
    cout << " n = ";
    cin >> n;

    int*A = createIntArray(n);
    FillIntArray(A, n);
    ShowIntArray(A, n);

    int i = 0;
    int j = n -1;
    int t = 0;
    while(i <= j)
    {
        if(t == 0)
        {
            cout << A[i] << " ";
            i++;
        }
        if(t == 1)
        {
            cout << A[i] << " ";
            i++;
        }
        if(t == 2)
        {
            cout << A[j] << " ";
            j--;
        }
        if(t == 3)
        {
            cout << A[j] << " ";
            j--;
        }
        t++;
        if(t == 4)
            t = 0;
    }
    cout << endl;
    delete []A;
}


void array16()
{
    int n;
    cout << " n = ";
    cin >> n;

    int*A = createIntArray(n);
    FillIntArray(A, n);
    ShowIntArray(A, n);

    int i = 0;
    int j = n -1;
    while(i <= j)
    {
        cout << A[i] << " ";
        if(i != j)
            cout << A[j] << " ";
        i++;
        j--;
    }
    cout << endl;
    delete []A;
}


void array15()
{
    int n;
    cout << " n = ";
    cin >> n;

    int*A = createIntArray(n);
    FillIntArray(A, n);
    ShowIntArray(A, n);

    for(int i = 1; i < n; i+= 2)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    //int N = n / 2 * 2 - 1;//последний  нечетный индекс массива - формула
    int N = (n - 1) / 2 * 2;//последний  четный индекс массива - формула
    for(int i = N; i >= 0; i-= 2)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    delete []A;
}

void array14() //?
{
    int n;
    cout << " n = ";
    cin >> n;

    int*A = createIntArray(n);
    FillIntArray(A, n);
    ShowIntArray(A, n);

    for(int i = 0; i < n; i++)
    {
        if(A[i] % 2 == 0)
        {
            cout << A[i] << " ";
        }
    }
    cout << endl;
    for(int i = 1; i < n; i++)
    {
        if(A[i] % 2 != 0)
        {
            cout << A[i] << " ";
        }
    }
    cout << endl;
    delete []A;
}


void array13()
{
    int n;
    cout << " n = ";
    cin >> n;

    int*A = createIntArray(n);
    FillIntArray(A, n);
    ShowIntArray(A, n);

    for(int i = n -1; i >= 0; i-= 2)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    delete []A;
}


void array12()
{
    int n;
    cout << " n = ";
    cin >> n;

    int*A = createIntArray(n);
    FillIntArray(A, n);
    ShowIntArray(A, n);

    for(int i = 2; i < n; i+= 2)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    delete []A;
}


void array11()
{
    int n, k;
    cout << " n = ";
    cin >> n;

    int*A = createIntArray(n);
    FillIntArray(A, n);
    ShowIntArray(A, n);
    cout << " k = ";
    cin >> k;

    for(int i = 0; i < n; i+= k)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    delete []A;
}


void array10()
{
    int n;
    cout << " n = ";
    cin >> n;

    int*A = createIntArray(n);
    FillIntArray(A, n);
    ShowIntArray(A, n);

    for(int i = 0; i < n; i++)
    {
        if(A[i] % 2 == 0)
        {
            cout << A[i] << " ";
        }
    }
    cout << endl;
    for(int i = n-1; i >= 0; i--)
    {
        if(A[i] % 2 != 0)
        {
            cout << A[i] << " ";
        }
    }
    cout << endl;
    delete []A;
}

void array9()
{
    int n;
    cout << " n = ";
    cin >> n;

    int*A = createIntArray(n);
    //ShowIntArray(A, n);
    FillIntArray(A, n);
    ShowIntArray(A, n);

    int k = 0;
    for(int i = n-1; i >= 0; i--)
    {
        if(i % 2 == 0)
        {
            cout << A[i] << " ";
            k++;
        }
    }
    cout << endl;
    cout << " k = " << k << endl;
    delete []A;
}


void array8()
{
    int n;
    cout << " n = ";
    cin >> n;

    int*A = createIntArray(n);
    //ShowIntArray(A, n);
    FillIntArray(A, n);
    ShowIntArray(A, n);

    int k = 0;
    for(int i = 0; i < n; i++)
    {
        if(i % 2 != 0)
        {
            cout << A[i] << " ";
            k++;
        }
    }
    cout << endl;
    cout << " k = " << k << endl;
    delete []A;
}


void array7()
{
    int n;
    cout << " n = ";
    cin >> n;

    int*A = createIntArray(n);
    //ShowIntArray(A, n);
    FillIntArray(A, n);
    ShowIntArray(A, n);

    for(int i = n-1; i >= 0; i--)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    delete []A;
}

void array6()
{
    double a, b;
    cout << " a = ";
    cin >> a;
    cout << " b = ";
    cin >> b;
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    A[0] = a;
    A[1] = b;//3 4 7 14 28
    A[2] = a + b;
    for (int i = 3; i < n; i++)
    {
        A[i] = A[i-1] * 2;
    }

    for(int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    delete[]A;//отдать память
}


void array5()
{
    int n;
    cout << " n = ";
    cin >> n;

    double *A = new double[n];
    A[0] = 1;
    A[1] = 1;
    for (int i = 2; i < n; i++)
    {
        A[i] = A[i-2] + A[i-1] ;
    }

    for(int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    delete[]A;//отдать память
}

void array4()
{
    double a, d;
    int n;
    cout << " a = ";
    cin >> a;
    cout << " d = ";
    cin >> d;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    int k = a;
    for (int i = 0; i < n; i++)
    {
        A[i] = k;
        k = k * d;
    }

    for(int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    delete[]A;//отдать память
}


void array3()
{
    double a, d;
    int n;
    cout << " a = ";
    cin >> a;
    cout << " d = ";
    cin >> d;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    int k = a;
    for (int i = 0; i < n; i++)
    {
        A[i] = k;
        k = k + d;
    }

    for(int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    delete[]A;//отдать память
}


void array2()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n + 1];
    int k = 1;
    for (int i = 0; i <= n; i++)
    {
        A[i] = k;
        k = k * 2;
    }
    for(int i = 0; i <= n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    delete[]A;//отдать память
}


void array1()
{
    int n;
    cout << " n = ";
    cin >> n;

    int *A = new int[n];
    int k = 1;
    for (int i = 0; i < n; i++)
    {
        A[i] = k;
        k = k + 2;
    }
    for(int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    delete[]A;//отдать память
}
