class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m,n , i, j , max , x, y;
        m = matrix.size();
        if ( m ==0 ) return 0;
		n = matrix[0].size();
		vector<int> position_last_zero( m ,-1 );
		vector<vector<int> >  x_max(m);
		vector<vector<int> > y_max(n);
		// initialize
	    for ( i =0 ; i < m ; i++)
		   for ( j = 0 ; j < n ; j++ ){
		        
		         x_max[i][j].push_back(i);
				 y_max[i][j].push_back(j);
				 
		   }
		// initialize the first colum
		for ( i = 0; i < m ; i ++){
		     if ( maxtrix[i][0] == '0'){
			     position_last_zero[0] = i;
				 x_max[i][0] = -1;
				}else{
				      
					 x_max[i][0] = position_last_zero[0] + 1;
					 y_max[i][0] = 0;  
					 
				}
        }
        // start
         for ( i =0; i < n ; i ++)
			for ( j = 1; j < m ; j++ ){
			    if (matrix[i][j] == '0'){
				      x_max[i][j] = -1;
					  position_last_zero[j] = i;
					   
				}else{//
				      x = x_max[i][j-1];
					  y = y_max[i][j-1];
					  if (x == -1){// 
					      x = i;
						  y = j;
					  } 
					  if ()
				}
				
			}
		
		}
};