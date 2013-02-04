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
// this is another solution 


class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( n == 0) return 1;
        if ( n < 0 ) {
            n = -n;
            x = 1/x;
        }
        double result, tmp;
        int index;
        index  = n;
        result = 1;
        tmp = x;
        while(index>0){
            if (index&1){
                result = result * tmp;
            }
            tmp = tmp*tmp;
            index = index >> 1;
        }
         
        return result;
        
    }
};

