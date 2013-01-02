class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n, i, max , j;
        n = s.length();
        vector < int> dp ( n , 0);
        max = 0;
        for ( i = 1 ; i < n ; i++ ){
		     dp[i] = 0;
		     if (s[i] == '(') continue;
		     // find the pair of this ')' 
		 	 if (s[i-1] == '(' ) {
			     dp[i] = 2;
		         //if ( (i-2) >= 0  ) dp[i] += dp[i-2];
				  j = i -2; 
				}else{
				   if ( dp[i-1] == 0 ) continue;
				   if ( i - dp[i-1] == 0 ) continue;
				   if ( s[i-dp[i-1]-1] == ')' ) continue;
				    dp[i] = dp[i-1] + 2;
                   j = i-dp[i-1]- 2;					
				}
				if (j >=0) dp[i] += dp[j];
			    
        }
         

        for ( i =  0; i < n ; i++ )
            if (dp[i] > max ) max = dp[i];
        return max;			
    }
};