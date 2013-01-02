class Solution {
	public:
	    void rotate(vector<vector<int> > &matrix) {
		int n;
		n = matrix.size();
		int i , j , ni , nj, tmp ,tmp2;				            
		for ( i = 0; i < (n)/2; i ++ )
			for ( j = 0; j <= (n-1)/2; j++){
				
				ni 
				= n - i - 1;
				nj = n - j - 1;
				//i j -> j ni
				tmp = matrix[j][ni];
				matrix[j][ni] = matrix[i][j];
				//j ni -> ni nj
				tmp2 = tmp;
				tmp = matrix[ni][nj];		
				matrix[ni][nj] = tmp2;
				// ni nj nj i
				tmp2= tmp;
				tmp = matrix[nj][i];
				matrix[nj][i] = tmp2;
				// nj i -> i j
				matrix[i][j] = tmp;
			}
         }
};
