class Solution {
public:
   int compare(string a, string b){
       if (a.length()!= b.length()) return 0;
       int i;
       for (i=0;i<a.length();i++)
		   if (a[i]!= b[i]) return 0;
	   return 1;
   }

   string sortstring(string s) {
	    string result;
 
	    char tmp;
	    int i,j,len;
	    len = s.length();
	    
	    for (i = 0; i< len; i++)
		    for (j = len-1; j > i; j--)
			    if ( s[j] > s[j-1] ){
				    tmp = s[j];
				    s[j] = s[j-1];
				    s[j-1] = tmp;
			    }

            return s;

    }
	int creat_hash(string s){
	    int i, len, prime, result;
		len = s.length();
		prime = 17151347;
		result = 0;
		for (i=0; i< len; i++){
		    result = (result * 27 + s[i] - 'a' ) % prime;
		}
        return result;
		
	}

    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       
	         
       int i, j , len,k, tag;
       len = strs.size();
        vector<string> result;
       string tmp;
       vector <int>  lenstring;
       vector <int>  hash(len,0);
       vector<int> flag(len,0);
       vector<string> sorted;
        
    
       for (i=0; i< len; i++){
	       sorted.push_back( this->sortstring(strs[i]));
		   hash[i] = this-> creat_hash( sorted[i] );
	       lenstring.push_back (strs[i].length());
       }
       
       for (i = 0; i< len; i++){
	      // if (flag[i]) continue;
	       for (j = i+1; j< len ; j++)
		       if ((!flag[j]) && (lenstring[i] == lenstring[j]) && (hash[i]==hash[j])){
			       tag = 0;
			    for (k = 0 ; k< lenstring[i]; k++ ){
			    
    		             if (sorted[i]!=sorted[j]) {
    		                      tag= 1; 
                                  break;
    		             }   
			    }   
			    
				if ( tag == 0) {
				     flag[i] = 1;
				     flag[j] = 1; 
				}					

		       }
	     }
    
     

     for (i =0; i<len; i++)
	     if (flag[i])
		     result.push_back(strs[i]);
     return result;
    }
};


