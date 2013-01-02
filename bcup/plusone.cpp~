class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       int i , flag , n ;
       flag = 1;
       n = digits.size();
       for ( i = n-1; i >=0 ; i --){
           digits[i]+=flag;
	   flag = digits[i]/10;
	   digits[i] = digits[i] % 10;
       }
       
       if (flag) digits.insert( digits.begin(), 1 );

       return digits;

    }
};

