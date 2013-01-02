#include <iostream>
using namespace std;
	 	
 int find (int A[], int m, int B[], int n , int target) {
		
		   int head , tail , k , i , j , vi , vj, flaga , flagb;
		   // find the target -th element in the two array
		   // the key is to find the first target-1 elements
        
			head = 0 ; //
			if ( n < target )// there are only  target - n elements in A
			   head = target - n;
			tail = m ;// the range of 0..m
			if ( tail > target ) // maximum target elelments in A
			     tail = target;
				 
            while( head <= tail ) {
			      k = ( head + tail ) / 2;
				  i = k -1 ;
				  j = target - k - 1;
				  vi = -99999;
				  vj = - 99999;
                  if ( i >= 0 ) vi = A[i];
                  if ( j >= 0 ) vj = B[j];
				  
                  flaga = 0;//ture if A[i] < B[j+1]
                  if  (  j == n-1 ){
				       flaga = 1;
                  }else {
				       flaga = ( vi <= B[j+1] );
					}
				  flagb = 0;
				  if ( i == m-1 ) {
				        flagb = 1 ;
				  }else{
				       flagb = ( vj < A[i+1]);
				  }
				  
				  if ( flaga && flagb ) break;
				  
				  if ( flaga ) head = k + 1;
				          else tail = k -1;
 				
            }
             if (  vi > vj ){ return vi;}
						else{ return vj;}
		   
	 
		   
		}
		
		
double findMedianSortedArrays(int A[], int m, int B[], int n) {

			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			int head, tail , target  ;
			double result;
			if (  (m + n ) % 2 ){//odd
				target = ( m + n + 1 ) / 2 ;
				result = find ( A , m , B , n , target );
				}else {//even
                    
					 target = ( m + n )/2   ;
					 result = find ( A, m , B , n , target );
					 target = ( m + n ) / 2 +1 ;
					 result += find ( A, m , B , n , target );
                     result /= 2;
					  
				}
			return result;
		}
		
		

int main(){
    int A[] = { };
    int B[] = {2 , 3};
    cout << findMedianSortedArrays(A, 0, B, 2) << endl;
    system("pause");
    return 0;
    
}
