class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       int min, i, j,k,l , tmp, len, sum3, sum;
       vector<vector<int> > result;

       // first we want to sort it
       len = num.size(); 
       for (i=0; i < len; i ++ )
	      for ( j = len-1; j > i; j--)
		     if (num[j]< num[j-1]){
			 tmp = num[j];
			 num[j] = num[j-1];
			 num[j-1] = tmp;
		     } 
        //emulating all possible result
	for (i = 0; i < len-3; i++){
		if (i>0)
			if (num[i]== num[i-1]) continue;
		for (j=i+1; j < len-2; j++ ){
			if (j>i+1)
				if (num[j]== num[j-1]) continue;
			for (k = j+1; k < len-1; k ++){
				if (k>j+1)
					if (num[k]== num[k-1]) continue;
		
				sum3 = num[i] + num[j] + num[k];
				if ((sum3 + num[k+1] > target) || ( sum3 + num[len-1] < target)) continue;
				for (l= k+1; l < len; l ++){
				   sum = sum3 + num[l];
				   if (sum == target){
					   vector<int> oneresult(4,0);
					   oneresult[0]= num[i];
					   oneresult[1] = num[j];
					   oneresult[2]= num[k];
					   oneresult[3] = num[l];
					   result.push_back(oneresult);
					   break;
				   }
				   if (sum > target) break;
				  }

				}

			}
		}
	return result;
    }
	
   
};

