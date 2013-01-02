class Solution {
public:
    void creat( string * table  , vector < string > &result , string  s , int i , string & digits){
	  if ( i >= digits.length() ){
	    result.push_back(s);
		return;
	  }
	  int j,k;
	  k = (int) digits[i] - '0';
	   
	  for ( j= 0; j<table[k].length(); j ++ ){
	    creat(table,result,s+table[k][j],i+1,digits);
	  }
	}
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string table[] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
		string s;
		vector <string> result;
		s = "";
		
        creat(table,result,s,0,digits);
		return result;
    }
};