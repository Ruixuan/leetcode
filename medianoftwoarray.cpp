      class Solution {
    public:
	    int position ( int A[], int n , int value){
		    int head , tail,k;
			head = 0;
			tail = n -1 ;
			while ( head <= tail ){
			     k = ( head + tail ) / 2;
				 if ( A[k] == value ) return k;
				 if ( A[k] < value) head = k + 1;
				             else   tail = k - 1;	 
			}
			
			return head;// the number smaller than value
			
		}
		
		int find (int A[], int m, int B[], int n , int target) {
		
		   int head , tail , k;
		   
		   head = 0 ;
		   tail = m-1 ;
		   while ( head <= tail){
			  k = ( head + tail ) / 2 ;
			  // position returns the num of elments that smaller than A[k]
			  k = k  + position ( B , n , A[k] );
			  if ( k == target ) return A[k];
			  if ( k < target )  head = ( head + tail ) / 2  + 1;
			  if ( k > target )  tail = ( head + tail ) / 2  - 1;
		   }
		   
		   head = 0; 
		   tail = n-1;
		   
		   while ( head <= tail){
			  k = ( head + tail ) / 2 ;
			  k = k  + position ( A , m , B[k] );
			  if ( k == target ) return B[k];
			  if ( k < target )  head = ( head + tail ) / 2  + 1;
			  if ( k > target ) tail = ( head + tail ) / 2  -1;
		   }
		   
		}
		double findMedianSortedArrays(int A[], int m, int B[], int n) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			int head, tail , target , result;
			if (  (m + n ) % 2 ){//odd
				target = ( m + n + 1 ) / 2 - 1 ;
				result = find ( A, m , B , n , target );
				}else {//even
                    
					 target = ( m + n )/2 - 1 ;
					 result = find ( A, m , B , n , target );
					 target = ( m + n ) / 2  ;
					 result += find ( A, m , B , n , target );
                     result /= 2;
					  
				}
			return result;
		}
	};