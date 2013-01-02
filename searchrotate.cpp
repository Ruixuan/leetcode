class Solution {
	public:
	    int search(int A[], int n, int target) {
		int head, tail , k;
		head = 0;
		tail = n-1;
		if ( target >= A[0]){
			while (head <= tail){
				k = ( head + tail ) /2 ;
				if (A[k] == target ) return k;
				if ( A[k] >= A[0] ){
					if (target > A[k] ) head = k + 1;
							else tail = k -1; 
				}else{
					tail = k -1 ;					
				}

			}
		}else{
			while ( head <= tail) {
				k = ( head + tail ) / 2;
				if ( A[k] == target ) return k;
				if ( A[k] < A[0] ){
					if ( target > A[k] ) head = k + 1 ;
							else tail = k - 1 ;

				}else head = head + 1 ;
			}
		}
				            
		return -1;
        }
};
