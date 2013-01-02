class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        //         // DO NOT write int main() function
        //                 
           long long result;
	   result = 0 ; 
	   int i = 0;
	   int flag;
	   flag = 1;
	
           while ( str[i] != NULL ){
			if (str[i] == '-') {
				flag = -1 ;
				break;
			}

			if ( str[i] == '+') {
					flag = 1;
					break;
				}


			if ( str[i]>='0' && str[i]<='9'){
					break;
			}
			
	                if ( str[i] == ' ' ) i++;
				else return 0;

		}
			
	  if (str[i] == NULL ) return 0;
         

	   if ( !(str[i]>='0' && str[i]<='9')) i++;

	   while ( str[i] != NULL ){

	        if ( !(str[i]>='0' && str[i]<='9')) break;       			
		result = result*10 + str[i] - '0';
                if (flag*result > INT_MAX ) return INT_MAX;
                if ( flag*result < INT_MIN ) return INT_MIN;
	
		i ++ ;
	   }	
		
           result =  result*flag;
           if ( result > INT_MAX ) return INT_MAX;
           if ( result < INT_MIN ) return INT_MIN;
	   return result;
	
	}
};
