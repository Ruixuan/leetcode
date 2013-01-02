class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	rowIndex ++;
     	vector < int > result(rowIndex,0 );

	if (rowIndex == 0 ) return result;
	result[0] = 1;
	int i , j , pre , tmp ;
	for ( i = 1; i < rowIndex; i ++ ){
	     pre = 0;
             for ( j = 0; j < i ; j ++ ){
		     result[j] += pre;
		     pre = result[j] - pre;
	     } 
	     result[i] = 1;
	}

	return result;

    }
};

