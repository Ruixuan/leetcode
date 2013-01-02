class Solution {
public:
    void search( int i , int j , int & m, int &n , int k , vector<vector<int> > &map , vector<vector<char> > &board, int &flag, string &word){
        if (flag == 1) return ;
        if ( k>= word.length()) {
            flag = 1; 
            return ;
        }
        if ( i <0 || j <0 || i >=m || j>=n ) return ;// out of range
        if (board[i][j] != word[k]) return ;
        if (map[i][j]) return;
        map[i][j] = 1 ;
        search( i+1 , j , m , n , k + 1 , map , board , flag , word);
        search( i-1 , j , m , n , k + 1 , map , board , flag , word);
        search( i , j+1 , m , n , k + 1 , map , board , flag , word);
        search( i , j-1 , m , n , k + 1 , map , board , flag , word);
        map[i][j] = 0;       
    }
    
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int flag = 0;
        int i , j , m , n;
        
        m = board.size();
        if ( m == 0 ) return word.length() == 0;
        n = board[0].size();
        vector<int> oneline(n , 0 );
        vector<vector<int> > map(m, oneline);// to indicate whether one point is used
        for ( i = 0 ; i < m ; i ++)
            for ( j = 0 ; j < n ; j ++ ) 
                search( i , j , m , n , 0 , map, board , flag , word);
        return flag;
    }
};