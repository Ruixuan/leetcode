class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       int i , n , j ;
       n = num.size();
       if ( n < 2) return;
       int max, max_i;
       int m,tmp;

   
       for (i=n-2; i >= 0; i--){
	       if ( num[i+1] <= num[i] ) continue;
	                   else
				   break;                         
       }
          
       m = i;

       //start to sort from m + 1  to n 
       for ( i = m+1; i < n ; i ++)
	       for ( j = n-1; j > i ; j --)
		       if ( num[j] < num[j-1] ){
			       tmp = num[j];
			       num[j]= num[j-1];
			       num[j-1] = tmp;
		       }


       if ( m >= 0 ) {
             j = m + 1;
             while ( num[m] >= num[j] ) j++;
	    tmp  = num[m];
             num[m] = num[j];
             num[j] = tmp;
       }
    
       
      return;
    }
};

