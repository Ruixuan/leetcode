class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> dp(n,0);
        dp[0] = 1;
	int i,k,max;
	max = 0;
 	for (i=0; i < n ; i++){
		if (dp[i]== 0 ) return false;
                for ( k = max+1-i ; k <= A[i]; k++){
		    if ( k+i >= n ) break;
		    dp[k+i] = 1;
		    max = k+i;
		}
		 
	}
 
	//solution 2
 
	return dp[n-1];

    }
};

