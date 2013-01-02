class Solution {
public:
   void creatsubset ( int i,vector<int> &oneresult, vector<vector<int > > &result , vector<int > &S ){

	   result.push_back(oneresult);
	   if ( i == S.size()){
		   return;
	   }
	   int j; 
	   for ( j = 0 ; j < oneresult.size(); j ++ ) {
		   if ( i!=0)
			   if ( oneresult[i-1] > S[j]) continue;
		   oneresult.push_back(S[j]);
		   creatsubset( i + 1 , oneresult , result , S);
		   oneresult.pop_back();
	   }
   }
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< vector <int> > result;
	vector<int> oneresult;
	int i , j , tmp; 
	int n ;
        n = S.size();
	for ( i = 0 ; i < n ; i ++)
	   for ( j = n-1; j > i ; j --)
		if ( S[j] < S[j-1]){
			tmp = S[j];
			S[j] = S[j-1];
			S[j-1] = S[j];
		}
	creatsubset ( 0, oneresult, result , S );
	return result;
    }
};
