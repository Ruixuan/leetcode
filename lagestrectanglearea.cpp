 class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	int n = height.size();
	int i,j,max;
        max = 0;
        vector<int> min(n+1,-1);
	 
	for (i = 0; i <n ; i ++){

		min[i] = height[i];
		if (i>0)
		  if ( height[i] <= height[i-1] ) continue;

		  

                if (min[i] > max) max = min[i];
		  
		for ( j = i+1; j < n ; j++){
			if (i >  0)
			if (height[i-1] > min[j] ) continue;
			min[j] = height[j];
			if ( min[j] > min[j-1] )
				min[j] = min[j-1];
			if ( max <  (j-i+1)*min[j] )
				max = (j-i+1)*min[j];
			
		}

	}
	return max;
    }
};

