class Solution {
public:
    void permute_generate ( vector<int> & num ,vector<vector<int> > &result , vector<int> & used, vector<int > & pre, vector<int> oneresult , int i, int n ){
	    if ( i ==n ){
		    //we've got a new result
		    result.push_back(oneresult);
		    return;
	    }
	    int j;
	    for ( j = 0; j < n ; j ++ ) 
		    if ( (0==used[j]) && ( used[pre[j]] )){//not used i, and it's pre is not used  
		    	oneresult[i] = num[j];
			used[j] = 1;
			permute_generate( num ,  result , used , pre , oneresult , i+1 , n );
			used[j] = 0;
		    }
        
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
 
        int n = num.size();
        vector<vector < int > > result;
	vector<int> oneresult(num);
	vector<int > used( n + 2 , 0);
	vector< int> pre( n + 2 , n );
       
	used[n] = 1;
        int i , j; 
        //set the pre array to point to the previous same value
	for ( i = 0; i < n ; i ++ )
	   for ( j = i -1 ; j >=0; j -- ){
	   	if ( num[j] == num[i] ){//find the nearest pre
		       	pre[i] = j;
			break;
			}
	   }
	//start to recursive
	permute_generate( num ,  result , used , pre , oneresult , 0 , n );
	return result;
    }
};


