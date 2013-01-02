class Solution {
	public:
	    bool isScramble(string s1, string s2) {
		    int m , n , i , j ,k , l ;
		    m = s1.length();
		    n = s2.length();
		    vector<int> oneline(m, 0);
		    vector< vector<int> > one_oneline ( m , oneline );
		    vector<vector < vector <int> > > dp(m, one_oneline);
		    //dp[i][j][l] means s2[j..j+l] is a scramble of s1[i..i+l]
		    for ( i = 0 ; i < n ; i ++)
			    for ( j = 0; j < n ; j++ )		  
				    dp[i][j][0] =( s1[i] == s2[j]);

		    
		    for ( l =1  ; l < n ; l ++ )
			    for ( i = 0 ; i < n-l; i ++ )
				    for ( j = 0 ; j < n-l ; j ++)
				  	   for ( k = 0 ; k < l ; k ++ ){
						   //split s1[i..i+l] into s1[i..i+k]
						   //                 and  s1[i+k+1.. i+k]
						   dp[i][j][l] = (dp[i][j][l] || ( dp[i][j][k] && dp[i+k+1][j+k+1][l-k-1]) ||
						   		( dp[i][j+l-k][k] && dp[i+k+1][j][l-k-1] ));
						   
					   }

				   		    
		    return dp[0][0][n-1];
		   	    				            
          }
};
