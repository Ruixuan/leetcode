class Solution {
	public:
	    bool searchMatrix(vector<vector<int> > &matrix, int target) {
		  int i , j ;
		  int m , n;
		  m = matrix.size();
		  if ( m == 0 ) return false;
		  n = matrix[0].size();
		  int row, colum;
		  int head, tail , k , flag;
		  head = 0;
		  tail = m-1;
		  //first determine row
		  flag = 0;
		  while ( head <= tail ) {
			  k = ( head + tail ) / 2;
			  if ( matrix[k][0]<=target && matrix[k][n-1]>=target){
				  flag = 1;
				  break;
			  }
			  if ( matrix[k][0] < target) head = k + 1;
			  			else tail = k-1;

		  }
		  if (!flag) return false;

		  row = k;
		  head = 0;
		  tail = n-1;
		  while ( head <= tail ) {
			  k = ( head + tail ) / 2;
			  if ( matrix[row][k] == target) return true;
			  if ( matrix[row][k] < target ) head = k + 1;
			  			else     tail = k - 1; 
		  }

		  return false;

	
				            
        }
};
