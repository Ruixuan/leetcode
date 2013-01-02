class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = triangle.size();
        vector<int> oneline( n , 0);
        vector<vector<int> > dp(2, oneline);
        int  i , j , pre , current;
        pre = 0;
        current = 1;
        
        for( i = 0 ; i < n ; i ++){
            for(j = 0; j < i; j ++){
                dp[current][j] = dp[pre][j];
                if (j-1>=0)
                    if (dp[pre][j-1]<dp[current][j])
                        dp[current][j] = dp[pre][j-1];
                dp[current][j] = dp[current][j] + triangle[i][j];               
            }
            
            if (i>0) dp[current][i] = dp[pre][i-1] + triangle[i][i];
                else dp[current][i] = triangle[i][i];
            
            current = 1 - current;
            pre = 1 - pre;
        }
        int min = dp[pre][0];
        for ( i = 1; i < n; i ++)
            if (min > dp[pre][i])
                min = dp[pre][i];
        
        return min;
    }
};