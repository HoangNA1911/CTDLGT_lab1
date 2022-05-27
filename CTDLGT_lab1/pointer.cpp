#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int *temp = a;
    *a = *b;
    *b = *temp;
}
int *sum(int *a, int *b)
{
    int *sum = new int;
    *sum = *a + *b;
    return sum;
}
void inputArray(int *a, int &n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "nhap gia tri cho vi tri thu " << i << ": ";
        cin >> *(a + i);
    }
}
int *findMax(int *arr, int n)
{
    int *max = arr;
    for (int i = 1; i < n; i++)
    {
        if (*(arr + i) > *max)
        {
            max = (arr + i);
        }
    }
    return max;
}
int *findLongestAscendingSubarray(int *a, int n, int &length)
{
    length = 0;
    int pos = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int temp = 1;
        for (int j = i + 1; j < n; j++)
            if (a[j] >= a[j - 1])
                temp++;
        if (temp > length)
        {
            pos = i;
            length = temp;
        }
    }
    int *C = new int[length];
    for (int i = 0; i < length; i++)
        C[i] = a[pos + i];
    return C;
}
void swapArrays(int *a, int *b, int &na, int &nb)
{
    int *temp = a;
    a = b;
    b = temp;
    swap(na, nb);
}
int *merge2Arrays(int *a, int *b, int na, int nb, int &nc)
{
    int *c = new int[na + nb];

    int *c = new int[na + nb];
    int ia = 0, ib = 0, i = 0;
    while (ia < na && ib < nb)
    {
        if (a[ia] > b[ib])
        {
            c[i] = b[ib];
            ib++;
            i++;
        }
        else
        {
            c[i] = a[ia];
            ia++;
            i++;
        }
    }
    while (ia < na)
    {
        c[i] = c[ia];
        ia++;
        i++;
    }
    while (ib < nb)
    {
        c[i] = c[ib];
        ib++;
        i++;
    }
    return c;
}
void generateMatrix1(int **A, int &length, int &width)
{
    cout << "nhap chieu dai cua ma tran: ";
    cin >> width;
    cout << "nhap chieu rong cua ma tran: ";
    cin >> length;
    A = new int *[length];
    for (int i = 0; i < length; i++)
    {
        A[i] = new int[width];
    }
    srand(time(0));
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            A[i][j] = rand() % 10;
        }
    }
}
void swapRows(int **a, int length, int width)
{
    int row1, row2;
    cout << "nhap 2 dong: ";
    cin >> row1 >> row2;

    int *temp = a[row1];
    a[row1] = a[row2];
    a[row2] = temp;
}
void swapColumns(int** a, int length, int width){
    int col1 , col2;
    cout<<"nhap 2 dong: ";
    cin>>col1 >>col2;
    int *temp= new int [length];
    for(int i=0;i<length;i++){
    temp[i]= a[i][col1];
    }
    for(int i=0;i<length;i++){
    a[i][col1]=a[i][col2];
    }
    for(int i=0;i<length;i++){
    a[i][col2]=temp[i];
    }
}

int** transposeMatrix(int** a, int length, int width){
    int **b=new int *[width];
    for(int i=0;i<width;i++){
        b[i]=new int[length];
    }
    for(int i=0;i<length;i++){
        for(int j=0;j<width;j++){
            b[j][i]=a[i][j];
        }
    }
    return b;
}
void print(int **a, int length, int width)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << a[i][j] << " ";
        }
    }
}
int **concatenate2MatricesH(int **a, int **b, int length, int width)
{
    int width2 = 2*width;
    int **c;
    c = new int *[length];
    for (int i = 0; i < length; i++)
    {
        c[i] = new int[width2];
    }
    int i = 1;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            c[i][j] = a[i][j];
            c[i][j + width] = b[i][j];
        }
    }
    return c;
}
int** concatenate2MatricesV(int** a, int** b, int length, int width){
    int length2 =2 *length;
     int **c;
    c = new int *[length2];
    for (int i = 0; i < length2; i++)
    {
        c[i] = new int[width];
    }
    for(int i=0;i<length;i++){
        for(int j=0;j<width;j++){
            c[i][j]=a[i][j];
            c[i+length][j]=b[i][j];
        }
    }
    return c;
}
bool multiple2Matrices(int** a, int** b, int lengtha, int widtha, int lengthb, int widthb){
    int **temp=a;
    if(widtha != lengthb){
        return false;
    }
    for(int i=0;i<lengtha;i++){
        for(int j=0;j<widtha;j++){
                a[i][j]=0;
                for(int k=0;k<widtha;k++){
                    a[i][j]+=temp[i][k]* b[k][j];
                }       
        }
    }
    return true;
}
int** findSubmatrix(int** a, int length, int width, int &length_, int &width_){
    
    for(int i=0;i<length;i++){
        for(int j=0;j<width;j++){

        }
    }

}
int main()
{
    // int **a ,**b;
    // int length=3, width=3;
    // a=new int *[length];
    // b=new int *[length];
    // for(int i=0;i<length;i++){
    //     a[i]=new int [width];
    //     b[i]=new int [width];
    // }
    // int **c;
    // c=concatenate2MatricesH(a,b,length, width);
    // print(c,length, width*2);
    // for(int i=0;i<length;i++){
    //     delete[] a[i];
    //     delete[] b[i];
    // }
    // delete[] a;
    // delete[] b;

    return 0;
}