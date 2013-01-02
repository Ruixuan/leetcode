class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() 
	// Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
	// (ie, buy one and sell one share of the stock multiple times).
	// However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
       int len = prices.size();
       //int * * dp;
       int i, j , max;
       
       /*dp = new int*[len+1];
       for ( i = 0; i< len+1 ; i ++ ){
	       dp[i] = new int[len+1];
	       for (j=0; j<len+1; j ++)
		       dp[i][j] = -99999;
       }*/
       int dp[500][500];
       dp[0][0] = 0;
       for (i=1; i <= len ; i++)
	       dp[0][i] = -99999;
       for ( i=1; i <= len; i++ )
	       for (j=0; j <= i; j++){
		      // do nothing
                      dp[i][j] = -9999;


		  // buy stock at day i
		     if (j>0)
			if ((dp[i-1][j-1] - prices[i-1] ) > dp[i][j] )
				dp[i][j] = dp[i-1][j-1] - prices[i-1];
		     
		     //at day i, at most have i shares

		     if ( (i-1) >= j ) 
			if ( dp[i-1][j] > dp[i][j] )
		               dp[i][j] = dp[i-1][j];
                     
                     
		     // sell a stock
		     if ( (i-1) >= (j+1) )
		       if ((dp[i-1][j+1] + prices[i-1]) > dp[i][j] )
			     dp[i][j] = dp[i-1][j+1] + prices[i-1];

	       }

       max = 0;
       for ( i = 0 ; i < len+1 ; i++ )
	       if (dp[len][i] > max)
		       max = dp[len][i];
     return max;
    }
};

