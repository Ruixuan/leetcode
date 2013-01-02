class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        //         // DO NOT write int main() function
	//
	
	
        int m,n;
	//set a virtual charactor at the start
        word1 = ' ' + word1;
	word2 = ' ' + word2;
	m = word1.length();
	n = word2.length();

	int i,j,min;
	vector< int > empty(n,0);
        vector< vector<int > > dp(m,empty);

	dp[0][0] = 0;
       // only do insert if word1 =""
	for (i = 1 ; i < n; i++  ) {
		dp[0][i] = dp[0][i-1] + 1;
	}

	for (i = 1; i < m ; i++ ){
		dp[i][0] = dp[i-1][0] +1 ;
	}

	for (i=1; i < m ; i++ )
		for ( j =1 ; j < n ; j++){
			min = m + n;
			// we can delete the i-th charactor
			if ( dp[i-1][j]+1 < min ) min = dp[i-1][j] + 1;
			// also add a charactor to math word2[j]
			if ( dp[i][j-1]+1 < min ) min = dp[i][j-1] + 1 ;
			// or replace word1[i] with word2[j]
			if ( dp[i-1][j-1] +1 < min ) min = dp[i-1][j-1] + 1 ;
			// if the word1[i] == word2[j]
			if ( word1[i] == word2[j])
				if (dp[i-1][j-1] < min ) min = dp[i-1][j-1];

			dp[i][j] = min;
	}
	return dp[m-1][n-1];
        }
};
