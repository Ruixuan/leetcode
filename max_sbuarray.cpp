class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int i;
		vector<int> sum( n , 0 );
		vector<int> min( n+1 , 0 );
		sum[0] = A[0];
		//min[0] = A[0];
		for ( i = 1 ; i < n ; i ++){
		     sum[i] = sum[i-1] + A[i];
			 min[i] = min[i-1];
			 if ( sum[i-1] < min[i] ) min[i] = sum[i-1];
			}
		
		int max = A[0];
		for ( i = 0 ; i < n ; i ++ )
			if ( sum[i] - min[i] > max ) 
			    max = sum[i] - min[i];
				
		return max;
    }
};