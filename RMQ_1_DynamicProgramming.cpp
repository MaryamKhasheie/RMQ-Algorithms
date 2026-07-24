// In the name Of God
// RMQ Dynamic programming - full preprocessing -  preprocessing O(n^2)  , query O(1) 
#include <iostream>
#include <stdlib.h>
using namespace std;

const int n = 8 ;
//const int n =22000;
//const int n =22334;
//const int n =22335; // no answer
//const int n =23000;  // no answer
//const int n = 65536 ; // no answer

int A[n] , B[n][n];

void preprocessing()  // O(n^2)
{
	int i , j ,d;
	for ( i =0 ; i < n ; i++ )	
		 B[i][i] = A[i] ;		 
    int t = n-1;       			
	for ( d = 1 ; d < n ; d++ ){
		j = d ;	
		for ( i = 0 ; i < t ; i++)	
		{		
			B[i][j]=min(  B[i][j-1] , B[i+1][j]  );	
			j = j +1 ;
		}		
        t = t -1 ;
	}
//	for ( i = 0 ; i < n ; i++ )	
//	{	
//		for ( j = 0 ; j < n ; j++)	
//			cout  << B[i][j] << " ";
//		cout << "\n";
//	}
}
void query ( int L, int R) // O(1)
{
		if ( ( L >= 0 && L <= R ) )
		{			
			cout << " min = " << B[L][R] << "\n";
		}
		else
			cout << " not Ranged ! " << "\n";
}
int main()
{	
	for ( int i =0 ; i < n ; i++ )
		A[i] = rand()%9;		
	for ( int i =0 ; i < n ; i++ )
		cout << "A [ " << i << " ] =" << A[i] << "\n";
	preprocessing();			
	cout << "Size Array is " << n << "\n";
	cout << "Enter Range from 0 to " << n-1 << "\n";		
	int m , L , R ;
	cout << " Enter Number Query = " ;
	cin >> m ;	
	for ( int j =0 ; j < m ; j++ )
	{
		cout << "query " << j+1 << "\n";	
		cout << "L = " ;
		cin >> L ;	
		cout << "R = " ;
		cin >> R ;
		query(L,R);	
	}		
	return 0;
}

