class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m , n , tagi , tagj , i , j ;
	tagi = -1 ;
	m = matrix.size();
	if ( m == 0 ) return;
	n = matrix[0].size();
	for ( i = 0 ; i < m ; i ++ )
		for ( j = 0 ; j < n ; j ++ )
			if ( matrix[i][j] == 0){
			       	tagi = i;
				tagj = j;
			}

	if ( tagi < 0) return;
	// set all lines
	for ( i = 0 ; i < m ; i ++ )
		for ( j = 0 ; j < n ; j ++)
		   if ( matrix[i][j] == 0 ){
			   matrix[tagi][j] = 0 ;
			   matrix[i][tagj] = 0;
  			}

	for ( i = 0 ; i < m ; i ++ )
		if ( i != tagi)
		  if ( matrix[i][tagj] == 0){
			for ( j = 0 ; j < n ; j ++ )
				if ( j!= tagj) matrix[i][j] = 0;
			}

	for ( j = 0; j < n ; j ++ )
		if ( j != tagj)
		  if ( matrix[tagi][j] == 0 )
			  for (i = 0 ; i < m; i ++ )
				  if ( i!=tagi) matrix[i][j] = 0;

	for ( i =0 ; i < m ; i ++ )
		matrix[i][tagj] = 0;

	for ( j = 0 ; j < n ; j++ )
		matrix[tagi][j] = 0;
			

    }
};

