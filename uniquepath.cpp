class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> oneline( n + 1 , 0);
        vector<vector<int> > dp( m + 1 , oneline);
        int i , j ;
        for ( i = 1 ; i <= m ; i ++)
            for ( j = 1; j <=n ; j ++ ){
                if ( i ==1 && j == 1 ){
                        dp[i][j] = 1;
                        continue;
                    }
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        return dp[m][n];
    }
};