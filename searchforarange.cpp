class Solution {
	public:
	    vector<int> searchRange(int A[], int n, int target) {
		vector<int> result(2,-1);
		int head, tail, k , tmp, tmptail;
		head = 0 ;
		tail = n-1;
		while ( head <= tail ) {
			k = ( head + tail ) / 2;
			if ( A[k] == target) {
				//first determine the start
				tmp = k;
				tmptail = tail;
				tail = k;
				while ( head <= tail ){
					if ( A[head] == target ) {
						result[0] = head;
						break;
					}
					k = ( head + tail ) / 2 ;
					if ( A[k] < target ) head = k + 1;
							else tail = k ;
				}
				head = tmp; 
				tail = tmptail;
				while ( head <= tail ) {

					if ( A[tail] == target ) {
						result[1] = tail;
						return result;
						break;
					}

				//	if ( A[head+1] == target) head ++;
					k = ( head + tail  ) / 2 + 1;

					if ( A[k] !=  target) tail = k -1 ;
						      else {
							       head = k;
						      }

				}
			
			}
			if ( target < A[k] ) tail = k - 1 ;
					else head = k + 1 ;
			
		}		
		return result;	            
        }
};
