class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i, profit, max ;
	int len = prices.size();
	profit = 0;
	max = 0;
	
	if (len > 1)
	if (prices[0] < prices[1] ) profit -= prices[0];

	for (i =1 ; i < len-1 ; i ++ ){
	     if (prices[i-1] >= prices[i] && prices[i+1]> prices[i]) profit -= prices[i];
	     if (prices[i-1] < prices[i] && prices[i+1] <= prices[i]) profit += prices[i];
	     if (profit > max) max = profit;	
	}
        if (len >= 2 )    
	if (prices[len-1] > prices[len-2] ) profit += prices[len-1];
        if (profit > max) max = profit;
	return max; 


    }
};

