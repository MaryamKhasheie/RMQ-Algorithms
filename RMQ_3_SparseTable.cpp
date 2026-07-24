// In the name Of God
// RMQ Sparse Table - preprocessing O(nlogn) , query O(1)

#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

const int n = 8;
//const int n = 65536 ;
//const int n = 131072 ;
//const int n = 1048576;

const int k = log2(n);

int A[n], B[n][k+1];

void preprocessing() // O(nlogn)
{
    int i, j;
    for (i = 0; i < n; i++)
        B[i][0] = A[i];
    for (j = 1; j <= k; j++)
    {
        for (i = 0; i < n; i++)
        {
            if (i + (1 << (j - 1)) < n)
                B[i][j] = min(B[i][j - 1],
                              B[i + (1 << (j - 1))][j - 1]);
            else
                B[i][j] = B[i][j - 1];
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= k; j++)
            cout << B[i][j] << " ";
        cout << "\n";
    }
}

void query(int L, int R) // O(1)
{
    if (L >= 0 && R < n && L <= R)
    {
        int j = (int)log2(R - L + 1);

        int minn = min(B[L][j],
                       B[R - (1 << j) + 1][j]);

        cout << " min = " << minn << "\n";
    }
    else
        cout << " not Ranged ! " << "\n";
}

int main()
{
//  for (int i = 0; i < n; i++)
//      A[i] = rand()%9;
    A[0]=31;
    A[1]=41;
    A[2]=59;
    A[3]=26;
    A[4]=53;
    A[5]=58;
    A[6]=97;
    A[7]=93;
    for (int i = 0; i < n; i++)
        cout << "A [ " << i << " ] =" << A[i] << "\n";
    cout << "k=" << k << "\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= k; j++)
            B[i][j] = 0;
    preprocessing();
    cout << "Size Array is " << n << "\n";
    cout << "Enter Range from 0 to " << n-1 << "\n";
    int m, L, R;
    cout << " Enter Number Query = ";
    cin >> m;
    for (int j = 0; j < m; j++)
    {
        cout << "query " << j+1 << "\n";
        cout << "L = ";
        cin >> L;
        cout << "R = ";
        cin >> R;
        query(L, R);
    }
    return 0;
}


