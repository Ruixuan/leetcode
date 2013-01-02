 class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	int n = height.size();
	int i,j,max,tmp;
    vector<int> pre( n+1 , 0 );
	vector<int> after( n+1 , 0 );
	
	pre[0] = -1 ;
	
	for ( i = 1 ; i < n ; i ++ ){
	     j = i-1;
		 pre[i] = j;
		 while ( height[j] >= height[i] ){
		    j = pre[j];
			pre[i] = j;			
			if ( j< 0 ) break;
		 }
	}
	
	after[n] = n;
	
	for ( i = n-1; i >=0 ; i--){
	
	     j = i + 1;
		 after[i] = j;
		 
		 while( height[j] >= height[i] ){
		     j = after[j];
			 after[i] = j;
			 if ( j >= n) break;
		 }
		 
	}
	
	max = 0;
	for ( i =0; i < n ; i++){
	    tmp = ( (i - pre[i]) + ( after[i] - i) - 1 ) * height[i];
		if (tmp > max) max =tmp;
	}
	
	return max;
    }
};

