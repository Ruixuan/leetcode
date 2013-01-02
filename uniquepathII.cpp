class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m , n , i , j ;
        m = obstacleGrid.size();
        if ( m == 0) return 0;
        n = obstacleGrid[0].size();
        vector<int> oneline( n + 1 , 0 );
        vector< vector<int> > dp( m+1 , oneline );
        for ( i = 1 ; i <= m ; i ++)
            for ( j = 1; j <= n ; j++ ){
                if (obstacleGrid[i-1][j-1] == 1 ){
                    dp[i][j] = 0;
                    continue;
                } 
                if (i ==1 && j == 1){
                    dp[i][j] = 1;
                    continue;
                }   
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        return dp[m][n];
    }
};