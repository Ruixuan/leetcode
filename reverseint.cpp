class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       int result;
       result = 0;
       while ( x != 0){
	       result = result * 10 + x%10;
	       x = x / 10;

       } 
       return result;
    }
};

