class Solution {
	public:
	    void creat_ip( vector<string> &result,string oneresult ,string &s , int  p_s , int i ){
		    if ( i > 3 ) { 	
			        if ( p_s == s.length())
				    	result.push_back( oneresult );
				return;
			    }

		    if ( p_s == s.length()) return;
	            // check the remaining string is  OK to creat ip segments
		    
		    if ( 3*(4-i) < ( s.length() - p_s )) return;
		   if ( i > 0)
  			    oneresult = oneresult + ".";
		    //now start to split the string
		    int j, k;
		    string tmp;
		    for ( j = 1 ; j <=3 ; j ++ ){
			tmp = s.substr( p_s, j );
			istringstream( tmp ) >> k;
			if ( k > 255) continue;
			
			if ( j>1 && tmp[0]=='0'  ) continue;
			creat_ip ( result , oneresult+tmp, s, p_s + j, i+1);
		    }

		    

	    }
	    vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		string oneresult;
		int n = s.length();
		int p_oneresult = 0;
		int p_s = 0;
		creat_ip( result, oneresult , s , p_s , 0 );
		return result;
	   }
};
