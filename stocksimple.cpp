class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       int len = prices.size();
       //int * * dp;
	int i, j , max , min;
	max = prices[0];
	min = prices[0];
        
	for (i = 0; i < len; i ++){
		if (prices[i]>max) max = prices[i];
		if (prices[j]< min) min = prices[i];
	}

	return max-min;

       
      
    }
};


