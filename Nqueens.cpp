class Solution {
public:
    void Solve_NQueens( int n , vector<int> &row , vector<int> &left_slan , vector<int> &right_slan , vector<vector<string> > &result , vector<string> &one_result , int i ){
	    if ( n == i ) {
		    //we got one result ,add it 
		    result.push_back(one_result);
		    //then return;
		    return;
	    }
	    int j ; 
	    for ( j = 0 ; j < n ; j ++ ){
		    if ( (row[j] >=0 ) || ( left_slan[i-j+n] >=0) || ( right_slan[i+j]>=0) ) 
			    continue;
                    row[j] = i;
		    left_slan[i-j+n] = i ;
		    right_slan[i+j] = i;
		    one_result[i][j] = 'Q';
		    Solve_NQueens( n , row , left_slan , right_slan , result , one_result , i + 1 );
                    row[j] = -1;
		    left_slan[i-j+n] = -1 ;
		    right_slan[i+j] = -1;
		    one_result[i][j] = '.';
			    
	    }

    }
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector< vector <string> > result ;
	vector<int> row( n , -1 );
	vector<int> left_slan ( 2*n+2 , -1 );
	vector<int> right_slan ( 2*n+2 , -1 );
	vector<string> one_result;
	string oneline;
	int i;
	oneline = "";
	for ( i = 0 ; i < n ; i  ++ )
		oneline = oneline + '.';
	for ( i = 0 ; i < n ; i ++)
		one_result.push_back( oneline );


        Solve_NQueens( n , row , left_slan , right_slan , result , one_result , 0 );
        return result;   

    }
};

