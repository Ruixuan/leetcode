class Solution {
public:
    void creat( vector<string> &result , string oneresult, int num_l, int num_r, int n){
	 if (num_r > num_l) return ;
	 if (num_l > n) return ;
	 if (num_r > n) return ;
	 if ( num_r == n ){
	      result.push_back(oneresult);
	      return;
	 }
	 creat(result, oneresult+'(' , num_l + 1 , num_r , n );
	 creat(result, oneresult+')' , num_l, num_r+1, n);
    }
    vector<string> generateParenthesis(int n) {
		string oneresult="";
		vector<string> result;
		creat ( result , oneresult , 0 , 0 , n);		
		return result;
	            
     
         }
};
