class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
         int i, n , len , lastword_len;
		 i =0;
		 len =0;
		 lastword_len = 0;
		 while (s[i] != NULL){
		     if (s[i] == ' ' ) {
			              
			             len = 0;
						 i ++;
						 continue;
						 }else{
						     len ++;
							 lastword_len = len;
							 i++;
						 }
		 }
		  
         return lastword_len; 		 
    }
};