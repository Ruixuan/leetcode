class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
       int value[] = {1, 5 , 10 , 50 , 100 , 500 , 1000 };
       char symbol[] = {'I','V','X','L','C','D','M'};
       string patten[] = {"I","II","III","IV","V","VI","VII","VIII","IX"};
       int k,tmp,j;
       string result = "";
       string digit_str;
       k = 1 ; 
       while ( num > 0 ){
	       tmp = (num % 10) - 1;
	       num = (num / 10);
	       if (tmp >= 0 ){
                       digit_str = patten[tmp];

		       for (j = 0 ; j < digit_str.length(); j ++ ){
		             if (digit_str[j] == 'I'){
				     digit_str[j] = symbol[k-1];
				     continue;
				     }
	                     if (digit_str[j] == 'V'){
				     digit_str[j] = symbol[k];
				     continue;
				     }
		             if (digit_str[j] == 'X'){
				     digit_str[j] = symbol[k+1];
				     continue;
				     }			     
		       }

		       result = digit_str + result;

	       }
	       k += 2;	        
       }

       return result;
        
    }
};

