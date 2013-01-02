class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> Tcount( 259, 0);//count the appear time in T
    	vector<int> Scount( 259, 0 );
	    int i , tail ,  m , n ;
		int min , min_i , sum ;
		string result;
		m = S.length();
		n = T.length();
		
		if ( n == 0 ) return "";
		if ( m < n ) return "";
		
		for ( i = 0 ; i <  n ; i ++ )
		    Tcount[T[i]] ++;
		//sum means how many different characters appear in T
		sum = 0;
		
		for ( i = 0 ; i < 256 ; i++)
		   if (Tcount[i] > 0 ) sum ++ ;
		
	    
		//now find the shortest window start at 0
		for ( i = 0 ; i < m ; i ++){
		    Scount[S[i]] ++;
			if ( Tcount[S[i]] > 0 ){
				if ( Scount[S[i]] == Tcount[S[i]] ) sum --;
				}
			if (sum == 0 ) break;
		}
		
		if ( i == m ) return "";
		
		tail = i;
		min = tail + 1;
		min_i = 0;
        
	
		// start to search
		for ( i = 0 ; i < m ; i ++){
		
			if ( (tail-i  ) < min ) {
			     min = tail - i +1 ;
				 min_i = i ;
			}
			
		    //remove Scount[i]
			Scount[S[i]] --;
			if ( Tcount[S[i]] == 0 ) continue;// this char is useless
			
			while ( Scount[S[i]] < Tcount[S[i]]){
					tail ++;
					if ( tail == m ) break;
					Scount[S[tail]] ++;
				}
			 
             if ( tail == m ) break;
		}
		
		result = S.substr( min_i , min );
		return result;
		
    }
};  	