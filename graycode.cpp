class Solution {
public:
    vector<int> grayCode(int n) {
       vector<int> result;
       int i,j,k;
       result.push_back(0);
       if (n==0) return result;

       result.push_back(1);
  
  k = 1;
       for ( i=1; i< n; i++){
            k *= 2;
	    for (j=k-1;j>=0;j--)
	       result.push_back(k+result[j]);

       }
       return result;
    }
 };
