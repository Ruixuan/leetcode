class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		 int i , j , m , n , k , max , local_max , tmp ;
		 
		 m = matrix.size();
		 if ( m == 0 )  return 0 ;
		 n = matrix[0].size();
		 
		 vector<int> height( n , 0 );
		 
		 vector<int> pre( n , -1);
		 vector<int> after( n , n);
		 
		 max = 0 ;
		 for ( i = 0 ; i < m ; i ++){
		 
		    //update heights
		    for ( j = 0 ; j < n ; j ++ ){
			     if ( matrix[i][j] == '1') height[j] ++;
				         else height[j] = 0;			 
			}
			// start the largest histogram algorithm
			pre[0] = -1;
			for ( j =1 ;  j < n; j ++){
			     if ( height[j] > height[j-1]) {
				     pre[j] = j-1;
				 }else{
				       k = j-1;					   
				      while ( k >= 0 ){
					     k = pre[k];
						 if ( height[k] < height[j]) break;// we find the first height that smaller than i 
					  }
					  pre[j] = k;
				 }	 
			}// end pre
			
			//start find after
			
			after[n-1] = n;
			for ( j = n-2 ; j >=0; j--){
			     if (height[j] > height[j+1] ) {
						after[j] = j+1;
					}else{
						k = j+1 ;
						while ( k < n ) {
						     k = after[k];
							 if ( height[j] > height[k] ) break;						
						}
						after[j] = k;
					}					
			}
			// start to find the largest are in histogram
			local_max = 0;
			for ( j = 0; j < n ; j ++ ){
			    tmp = (  j - pre[j]  + after[j] - j -1) * height[j];
				if ( tmp > local_max ) local_max = tmp;
			}
			if ( local_max > max ) max = local_max;
		 }
        return max;
    }
};