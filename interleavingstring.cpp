class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        // for convenience ,add a space before string to 
	// make sure the index starts at 1 rather than 0
	s1 = ' ' + s1;
        s2 = ' ' + s2;
        s3 = ' ' + s3;	

	int m,n, i , j;

	m = s1.length();
	n = s2.length();
         
	if ( (m+n-1) != s3.length() ) return false;
        
	vector <int> oneline(n+1,0);
	vector < vector<int> >  dp(m+1,oneline);

	dp[0][0] = 1;

	for ( i= 0; i< m ; i++)
	  for (j=0; j< n ; j++){
                // s1[i] is at position i+j
		  if (i>0)
	            if (s1[i]==s3[i+j] && dp[i-1][j] == 1)
			    dp[i][j] =1;
		  //s2[j] is at position i+j 
		  if (j>0)
	            if (s2[j]==s3[i+j] && dp[i][j-1] == 1)
			    dp[i][j] =1;


	  }

        return dp[m-1][n-1];
    
    }
};

