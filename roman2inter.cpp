class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        //         // DO NOT write int main() function
        //                 
	int result = 0 ,tmp ;
	int numbertable[259];
	int ps;//pointer to s
	numbertable['I'] = 1;
	numbertable['V'] = 5;
	numbertable['X'] = 10;
	numbertable['L'] = 50;
	numbertable['C'] = 100;
	numbertable['D'] = 500;
	numbertable['M'] = 1000;
	ps = 0;
	while ( ps < s.length()){
	    if ( ps == s.length() - 1 ) {
			result = result + numbertable[s[ps]];
			break;
		}
	    if ( numbertable[s[ps]] < numbertable[s[ps+1]] ){
			 tmp = numbertable[s[ps+1]]- numbertable[s[ps]];
			 ps +=2;
		}else{
		 	tmp = numbertable[s[ps]];
			ps ++;
		}
	    result += tmp;		
					
	}
	
	return result;
	
   
       }

   };
