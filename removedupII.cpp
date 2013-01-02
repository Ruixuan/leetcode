class Solution {
	public:
	    int removeDuplicates(int A[], int n) {
		            // Start typing your C/C++ solution below
			    //
			    //         // DO NOT write int main() function
			    int indent = 0 ;
			    int i,pre; 
			    pre = A[0];                
			    for ( i = 2; i < n ; i ++ ){
				    if ( A[i] == pre ) indent ++;
				    pre = A[i-1];
				    A[i-indent] = A[i];
			    }
			    return n - indent;

	}
};
