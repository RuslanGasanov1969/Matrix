#ifndef ARRAY_LIB_H_INCLUDED
#define ARRAY_LIB_H_INCLUDED

int* createIntArray(int n);
double* createDoubleArray(int n);
void FillIntArray(int*A, int n, int from = -5, int to = 10);
void FillIntArrayTrasposition(int*A, int n);
void FillDoubleArray(double *A, int n, int from = -5, int to = 10);
void ShowIntArray(int*A, int n);
void ShowDoubleArray(double *A, int n);
int GetCountOfSeries(int *A, int n);
int GetSeriesPosition(int *A, int n, int ns);
int GetSeriesLength(int *A, int n, int ns);
int GetSeriesValue(int *A, int n, int ns);
template <class T> void ShiftLeft(T* A, int n);
template <class T> void ShiftRight(T* A, int n);
template <class T> void ShiftRightCircle(T* A, int n, int k);



template <class T> bool isLocalMin(T *A, int n, int idx)
{
    if(idx == 0) return A[0] < A[1];
    if(idx == n-1) return A[n-2] > A[n-1];
    return A[idx-1] > A[idx] && A[idx] < A[idx+1];
}

template <class T>
bool isLocalMax(T *A, int n, int idx)
{
    if(idx == 0) return A[0] > A[1];
    if(idx == n-1) return A[n-2] < A[n-1];
    return A[idx-1] < A[idx] && A[idx] > A[idx+1];
}

template <class T>
bool isNoLocal(T *A, int n, int idx)
{
    return !isLocalMax(A, n, idx) && !isLocalMin(A, n, idx);
}

template <class T>
void SortArray(T *A, int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(A[i] > A[j])
            {
                T tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;//запомнить
            }
        }
    }
}

template <class T>
void SortArray2(T *A, int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(A[j] > A[i])
            {
                T tmp = A[j];
                A[j] = A[i];
                A[i] = tmp;//запомнить
            }
        }
    }
}

template <class T>
void ReversArray(T* A, int n, int from = 0, int to = -1)
{
    if(to == -1) to = n-1;
    int i = from;
    int j = to;
    while(i < j)
    {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
        i++;
        j--;
    }

}

template <class T>
int GetMinPosition(T* A, int n){
    T min = A[0];
    int pos = 0;
    for(int i = 0; i < n; i++){
        if(A[i] < min){
            min = A[i];
            pos = i;
        }
    }
    return pos;
}

template <class T>
int GetMaxPosition(T* A, int n){
    T max = A[0];
    int pos = 0;
    for(int i = 0; i < n; i++){
        if(A[i] > max){
            max = A[i];
            pos = i;
        }
    }
    return pos;
}

template <class T>
void ShiftLeft(T* A, int n){
    for(int i = 1; i < n; i++){
        A[i-1] = A[i];
    }
    A[n-1] = 0;
}

template <class T>
void ShiftRight(T* A, int n){
    for(int i = n-1; i > 0; i--){
        A[i] = A[i-1];
    }
    A[0] = 0;
}

template <class T>
void ShiftRight(T* A, int n, int k){
    for(int i = 0; i < k; i++){
        ShiftRight(A, n);
    }
}

template <class T>
void ShiftLeft(T* A, int n, int k){
    for(int i = 0; i < k; i++){
        ShiftLeft(A, n);
    }
}

template <class T>
void ShiftRightCircle(T* A, int n){
    T tmp = A[n-1];
    ShiftRight(A, n);
    A[0] = tmp;
}

template <class T>
void ShiftLeftCircle(T* A, int n){
    T tmp = A[0];
    ShiftLeft(A, n);
    A[n-1] = tmp;
}

template <class T>
void ShiftRightCircle(T* A, int n, int k){
    for(int i = 0; i < k; i++){
        ShiftRightCircle(A, n);
    }
}

template <class T>
void ShiftLeftCircle(T* A, int n, int k){
    for(int i = 0; i < k; i++){
        ShiftLeftCircle(A, n);
    }
}

template <class T>
void Swap(T &a, T &b){
    T tmp = a;
    a = b;
    b = tmp;
}

template <class T>
T* DeleteFromArray(T *A, int &n, int pos){
    T *B = new T[n-1];
    for(int i = 0; i < pos; i++){
        B[i] = A[i];
    }
    for(int i = pos+1; i < n; i++){
        B[i-1] = A[i];
    }
    n--;
    delete []A;
    return B;
}

template <class T>
void DeleteFromArray(T **A, int &n, int pos){
    T *B = new T[n-1];
    for(int i = 0; i < pos; i++){
        B[i] = (*A)[i];
    }
    for(int i = pos+1; i < n; i++){
        B[i-1] = (*A)[i];
    }
    n--;
    delete [](*A);
    *A = B;
}

template <class T>
T* DeleteFromArray2(T *A, int &n, int pos){
    T *B = new T[n-1];
    int j = 0;
    for(int i = 0; i < n; i++){
        if(i != pos){
            B[j++] = A[i];
        }
    }
    n--;
    delete []A;
    return B;
}

template <class T>
T* DeleteFromArray3(T *A, int &n, int pos){
    n--;
    T *B = new T[n];
    for(int i = 0; i < n; i++){
        if(i < pos){
            B[i] = A[i];
        }
        else{
            B[i] = A[i+1];
        }
    }
    delete []A;
    return B;
}

template <class T>
T* InsertToArray(T *A, int &n, int pos, T x){
    T *B = new T[n+1];
    for(int i = 0; i < n; i++){
        if(i < pos){
            B[i] = A[i];
        }
        else{
            B[i+1] = A[i];
        }
    }
    B[pos] = x;
    delete []A;
    n++;
    return B;
}

template <class T>
void SwapArray(T *A, int n, int ns1, int ns2){
    T *B = new T[n];
    int N = GetCountOfSeries(A, n);
    int j = 0;
    for(int i = 0; i < N; i++){
        int s = i;
        if(i == ns1) s = ns2;
        if(i == ns2) s = ns1;
        int pos = GetSeriesPosition(A, n, s);
        int length = GetSeriesLength(A, n, s);
        T value = A[pos];
        for(int k = 0; k < length;k++){
            B[j++] = value;
        }
    }
    for(int i = 0; i < n; i++){
        A[i] = B[i];
    }
    delete []B;
}

#endif // ARRAY_LIB_H_INCLUDED
