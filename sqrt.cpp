class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	long long head, tail ,k;
	head = 1; 
        tail = x;
	 
	while ( head <= tail ) {
		
		k = ( head + tail ) /2;
	        //k = k*k;
		if ( k*k == x ) return k;
		if ( k*k > x ) tail = k - 1;
			else head = k + 1;
	}
       
	return tail;	
    }
};

