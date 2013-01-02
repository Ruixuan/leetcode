class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector <int> dp(n+1, -1);
        dp[0] = 0;
	int i, max , k;
	max = 0;
        for ( i = 0; i< n ; i++){
		if (dp[i]<0 ) continue;
	        for ( k = max+1; k <= A[i]+i; k++){
		      if (k >= n ) continue;
		      
		      dp[k] = dp[i] + 1;	
		      max = k;
		}	
	}

	return dp[n-1];
	
    }
};

