// In the name Of God
// RMQ Naive Algorithm - No preprocessing -  preprocessing O(1)  , query O(n) 
#include <iostream>
#include <stdlib.h>
using namespace std;

const int n = 16 ;
//const int n = 65536 ;
//const int n = 131072 ;
//const int n = 1048576;
int A[n];
void preprocessing() // O(1)
{	
	// no_preprocessing
}
void query ( int L, int R)  // O(n)
{
		if ( ( L >= 0 && L <= R ) )
		{		
			int min = A[L] , index = L ;		
			for ( int p =L ; p <= R ; p++ )
			{
				if ( min > A[p] ) {  min = A[p];  index = p ;  }				
			}	
			cout << " min = " << min << " in A["	<< index << "]" << "\n";
		}
		else
			cout << " not Ranged ! " << "\n";
}
int main()
{	
	for ( int i =0 ; i < n ; i++ )
		A[i] = rand() ;	
	for ( int i =0 ; i < n ; i++ )
		cout << "A [ " << i << " ] =" << A[i] << "\n";				
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

