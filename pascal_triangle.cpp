class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	vector<vector<int> > result;
    	vector<int> oneline(1,1);

	if ( numRows <= 0 ) return result;
	result.push_back( oneline );
	int i , j ;
	for ( i = 2 ; i <= numRows ; i ++ ){
	        vector<int> newline(oneline);
		
		for  ( j = 1 ; j < oneline.size(); j ++ )
			newline[j] += oneline[j-1];

		newline.push_back(1);
		oneline = newline;
		result.push_back(oneline);

	}

	return result;
     
    }
};

