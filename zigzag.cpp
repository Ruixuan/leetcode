class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int n = s.length();
        vector<char> oneline(s.length(), 0);
        vector<vector<char> > map(nRows, oneline);
        int direction = 0;
        int i , j , k;
        i = 0;
        j = 0;
        k = 0;
        while( k < s.length()){
            for ( i = 0; i < nRows ; i ++ ){
                map[i][j] = s[k];
                k ++;
                if (k >= s.length()) break;
            }
            i = nRows-1;
            
            for ( i = nRows-2; i >0 ; i -- ){
                j ++;
                map[i][j] = s[k];
                k ++;
                if (k >= s.length()) break;               
            }
            j ++;
            i = 0;
        }
        
        string result = "";
        for ( i = 0 ; i <nRows; i ++)
            for ( j = 0 ; j <s.length(); j ++)
                if (map[i][j] != 0)
                    result= result + map[i][j];
        return result;
            
    }
};