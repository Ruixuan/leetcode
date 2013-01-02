class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector <int> result;
	int i, j , m , n , l, k;
	if (matrix.size() == 0 ) return result;
	m = matrix.size();
	n = matrix[0].size();
	k = 0;
        while (result.size() < m*n ){

		for ( j = k ; j < n - k ; j ++ )
			result.push_back(matrix[k][j]);

		if (result.size() >= m*n) break;

		for ( i = k+1; i < m - k ; i ++)
			result.push_back(matrix[i][n-k-1]);
		
		if (result.size() >= m*n) break;

		for ( j = n-k-2; j >= k; j --)
			result.push_back( matrix[m-k-1][j]);

		if (result.size() >= m*n) break;

		for ( i = m-k-2; i > k; i --)
			result.push_back( matrix[i][k]);

		k++;

	}

	return result;


    }
};

