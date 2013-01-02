class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        //         // DO NOT write int main() function    
        int ls , lp ;
	int i,j;
         ls = 0;
	 lp = 0;
	 while ( s[ls] ) ls ++;
	 while ( p[lp] ) lp ++;
	 
	 vector<int> oneline( lp+1 , 0 );
	 vector<vector< int> > dp( ls + 1 , oneline );

	 // initialize the first line and first colum
          
	dp[0][0] = 1;

	for ( i = 0; i <= ls; i ++ )
		for ( j = 1; j <= lp ; j ++ ){

			dp[i][j] = 0;
			if ( i > 0 ){
				if (( p[j-1] == s[i-1]) || ( p[j-1] == '.')  ) dp[i][j] = (dp[i-1][j-1]) ;
				}

			if ( p[j-1] == '*') {
				dp[i][j] = dp[i][j-2]; 
			        if ( i > 0)
			        	if (( p[j-2] == s[i-1]) ||( p[j-2] == '.' ))
						dp[i][j] = (dp[i][j] || (dp[i-1][j] || dp[i-1][j-1]  ) );
					}
		}
	 
	 return dp[ls][lp];

        }
};
