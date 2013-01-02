class Solution {
	public:
	    int removeDuplicates(int A[], int n) {
	        int indent = 0;
		int i , tmp;
		for ( i = 1 ; i < n ; i ++ ){
			if ( A[i] == A[i-1] ) indent ++;
			//swap i  i- indent
			A[i-indent] = A[i] ;
		}

		return n - indent;

	    }

};
