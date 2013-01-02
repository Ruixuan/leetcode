class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> oneline(n,0);
	vector<vector<int>  > matrix( n, oneline);
	int i, j , k , l ,m;
	if (n == 0 ) return matrix;
	 m = n;
	k = 0;
	l = 1;
       for ( k =0; k<n; k++){

		for ( j = k ; j < n - k ; j ++ ){
			 matrix[k][j]= l;
			 l ++;
		}
 

		for ( i = k+1; i < m - k ; i ++){
			 matrix[i][n-k-1] = l;
			 l ++;
		}
		
		

		for ( j = n-k-2; j >= k; j --){
			 matrix[m-k-1][j] = l;
			 l ++;
		}

 

		for ( i = m-k-2; i > k; i --){
			 matrix[i][k]= l;
			 l ++;
		}

	 

	}

	return matrix;


    }
};


