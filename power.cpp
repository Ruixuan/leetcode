class Solution {
public:
    
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int half, flag;
        double tmp, power_half;
       if ( n == 0 ) return 1;
       if ( x == 0 ) return 0;
        
       flag = 1;
          if ( n == 1 ) return x;
        if ( n < 0 ) {
		flag = -1;
		n  = - n;
	}
       tmp = 1;
       half = n / 2;
       if ( n - half != half ) tmp = x;
       power_half = pow(x, half);
       if (flag == 1 )  
       		return   power_half * power_half * tmp;       
             else 
		return 1/(   power_half * power_half * tmp );  
    }
};


