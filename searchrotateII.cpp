class Solution {
	public:
	    bool search(int A[], int n, int target) {
		int head, tail , k , tmp ; 
		head = 0;
		tail = n-1;
		if ( A[0] == target ) return true;
		while (A[head] == A[0] ){
			 head ++;
			 if ( head == n ) break;
		}
		if ( head ==n ) return false;


		if ( A[0] < target ) {
			while ( head <= tail){
				k = ( head + tail ) / 2 ;
				if ( A[k] == target ) return true;

				if ( A[k] > A[0] ) {
					if ( target> A[k] ) head = k + 1 ;
							else tail = k - 1;
				}else 
					tail = k - 1 ;
			}



		}else{
			while ( head<= tail) {
				k = ( head + tail ) / 2 ;
				if ( A[k] == target) return true;


			if ( A[k] <= A[0] ) {
				if ( target > A[k] ) head = k + 1 ;
						else tail = k - 1;

				}else head = k + 1;
			}
					
	    	return false;
	     }
	    
	
};
