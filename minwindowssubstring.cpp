class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> position( 259, -1 ); // indicates each position for it
		vector<int> 
		string result;
		//-1 means not exist  in T 
		int m,n;
		int min_i , min_tail, tail,i , j ,sum ;
		int min;
		m = S.length();
		n = T.length();
		for ( i = 0 ; i < n ; i ++ ){
		    position[T[i]] = m;// set 0 , means 
		}
		vector <int> next(m, -1);// to keep tracks the next apperance position of S[i]
		
		for ( i = m-1; i >=0 ; i --){
		    if ( position[S[i]] < 0 ) continue;
			next[i] = position[S[i]];
			position[S[i]] = i;
		}
		// find how many charactars have appeared in T
		sum = 0;
		for ( i = 0 ; i < 256 ; i ++)
		   if ( position[i] >= 0 ) sum ++;
		if ( sum == 0 ) return "";
		//first find a window start at 0
		for ( i = 0 ; i < m ; i ++){
		    if ( position[S[i]]>=0) {
			    sum --;
				position[S[i]] = -2;
				if ( sum == 0 ) break;
			}
        }
        tail = i ;
        if ( tail >= m ) return "";
        //now we find the shortest window start at 0
        min = tail+1;
		min_i = 0;
		min_tail = tail;
        for ( i = 0 ; i < m ; i ++){
		   if ( position[S[i]] == -1 ) continue;// means this character is unuseful
		   if ( (tail - i + 1) < min ){
				min =(tail - i + 1) ;
				min_i = i;
				min_tail = tail;
				}
		   // update tail
		   if ( next[i] > tail ) tail = next[i];// means from i+1 to tail , no S[i] appear
		   if ( tail >= m ) break;
        } 		
		
		result = S.substr( i , min );
		return result;
    }
};  	