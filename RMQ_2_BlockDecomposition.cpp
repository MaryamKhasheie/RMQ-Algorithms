// In the name Of God
// RMQ Block Decomposition - preprocessing O(n), query O(sqrt(n)), b = sqrt(n)

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <climits>

using namespace std;

const int n = 16;
//const int n = 65536;
//const int n = 131072;

const int b = sqrt(n);

int A[n], A2[n / b];

void preprocessing() // O(n)
{
    int t = n / b, s = 0, b1 = b, min1, j;

    for (int i = 0; i < t; i++)
    {
        min1 = A[s];

        for (j = s; j < b1; j++)
            if (min1 > A[j])
                min1 = A[j];

        A2[i] = min1;

        s += b;
        b1 += b;
    }
}

void query(int L, int R)   // O(sqrt(n))
{
    if (L < 0 || R >= n || L > R)
    {
        cout << " not Ranged !\n";
        return;
    }

    int minValue = INT_MAX;

    int block_L = L / b;
    int block_R = R / b;

    
    if (block_L == block_R)
    {
        for (int i = L; i <= R; i++)
            if (A[i] < minValue)
                minValue = A[i];
    }
    else
    {
        
        for (int i = L; i < (block_L + 1) * b; i++)
            if (A[i] < minValue)
                minValue = A[i];

        
        for (int i = block_L + 1; i <= block_R - 1; i++)
            if (A2[i] < minValue)
                minValue = A2[i];

        
        for (int i = block_R * b; i <= R; i++)
            if (A[i] < minValue)
                minValue = A[i];
    }

    cout << " min = " << minValue << "\n";
}

int main()
{
    for (int i = 0; i < n; i++)
        A[i] = rand() % 9;

    for (int i = 0; i < n; i++)
        cout << "A[" << i << "] = " << A[i] << "\n";

    preprocessing();

    cout << "\nSize Array is " << n << "\n";
    cout << "Enter Range from 0 to " << n - 1 << "\n";

    int m, L, R;

    cout << "Enter Number Query = ";
    cin >> m;

    for (int j = 0; j < m; j++)
    {
        cout << "\nQuery " << j + 1 << "\n";

        cout << "L = ";
        cin >> L;

        cout << "R = ";
        cin >> R;

        if (L >= 0 && R < n)
            query(L, R);
        else
            cout << "not Ranged!\n";
    }

    return 0;
}
