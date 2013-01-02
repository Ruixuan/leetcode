class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function-1
		vector<vector<int> > dp( grid );
		int i, j , m , n;
		m = dp.size();
		n = dp[0].size();
		if ( m == 0 ) return 0;
		dp[0][0] = grid[0][0];
		
		for ( i = 1 ; i < n ; i ++)
		   dp[0][i] = dp[0][i-1] + grid[0][i];
		 
		for ( i = 1 ; i < m ; i ++ )
		   dp[i][0] = dp[i-1][0]  + grid[i][0];
		   
		for ( i = 1; i < m; i ++)
		   for ( j = 1 ; j < n ; j ++){
				if (dp[i-1][j] < dp[i][j-1] )
							dp[i][j] = dp[i-1][j] + grid[i][j];
						  else 
							dp[i][j] = dp[i][j-1]  + grid[i][j];
		   
		   }
        return dp[m-1][n-1];
    }
};