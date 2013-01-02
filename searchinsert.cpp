class Solution {
	public:
	    int searchInsert(int A[], int n, int target) {
		int head, tail, k ;
		head = 0 ;
		tail = n-1;
		while ( head <= tail) {
			if ( A[head] > target ) return head;
			if ( A[tail] < target ) return tail;
			k = ( head + tail ) / 2 ;
			if ( A[k] == target ) return k;
			if ( target > A[k] ) head = k + 1 ;
				      else   tail = k - 1 ;
		}
		return head;
        }
};
