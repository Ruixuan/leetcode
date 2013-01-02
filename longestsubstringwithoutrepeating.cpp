class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int position[256];//an array keeps tracks of the last appear position of a charactor
		int i,n,max,min;
		n = s.length();
		if ( n == 0) return 0;
		for (i=0; i<256 ; i++)
		    position[i] = -1;
		     
		
		
		//dp[i] means the longest length of substring end with s[i]
		vector<int> dp( n, 1 );
	    max = 1;
		position[s[0]] = 0;
	    for( i =1 ; i < n ; i++) {
		
		    min = dp[i-1] + 1;
			if (position[s[i]] >= 0)
			 if ( i - position[s[i]] < min ) min = i- position[s[i]];
			
			if ( min > max ) max = min;
			
			position[s[i]] = i;
			dp[i] = min;
		}
		
		return max;
        
    }
};