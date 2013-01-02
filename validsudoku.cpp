class Solution {
public:

  void fillboard(vector<vector<char> > &board, vector<vector< int > > &row, vector<vector< int > > &col, vector<vector< int > > &mat, vector<vector< int > > &map, int &n , int position, int &flag){
        if (flag == 1){//solution is done , return
            return;
        }
        if (position>= 81){
            flag =1;
            return;
        }
       
    
        int i , j , k ;
        i = (int)(position/n);
        j =  position%n;
        
        if (board[i][j] != '.') {
            fillboard(board,row,col,mat , map , n , position + 1 , flag);
            return;
        }
        //start to fill one blank
        for (k=0;k < 9; k++){
            // skip numbers that are used
            if (row[i][k]) continue;
            if (col[j][k]) continue;
            if (mat[map[i][j]][k]) continue;
            //OK fill this 
            board[i][j] = (char)k + '1';
            row[i][k] = 1;
            col[j][k] = 1;
            mat[map[i][j]][k] = 1;
            fillboard(board,row,col,mat , map , n , position + 1 , flag);
            if (flag == 1) return ;//solution found just return !
            //restore to original status
            board[i][j] = '.';
            row[i][k] = 0;
            col[j][k] = 0;
            mat[map[i][j]][k] = 0;  
            
        }
        
    }
    
    bool isValidSudoku(vector<vector<char> > &board) {
        // using 3 arrays to keep track of which numbers are used
        int n = 9;
        int m = 3; 
        vector<int> oneline(n+1, 0);
        vector<vector< int > > row(n+1, oneline);
        vector<vector< int > > col(n+1, oneline);
        vector<vector< int > > mat(n+1, oneline);
        vector<int> char2int(256,-1);
        vector<vector< int > > map(n+1, oneline);// this map each point to a 3*3 mat
        int i, j, tmp ,flag;
        char a;
        //initialize char2int
        for ( a = '1'; a <= '9' ; a ++)
            char2int[a] = a -'1';
        //initialize map
        for ( i = 0; i < n ; i ++)
            for ( j = 0; j < n ; j ++)
                map[i][j] = m*((int)(i/m)) + ( (int) (j/m));
        
        //initialize row,col, mat
        for (i = 0 ; i < n ; i ++)
            for ( j = 0 ; j < n ; j ++)
                if (char2int[board[i][j]]>=0){
                        tmp = char2int[board[i][j]];
                        if (row[i][tmp] || col[j][tmp] ||mat[map[i][j]][tmp]) return false;
                        row[i][tmp] = 1;
                        col[j][tmp] = 1;
                        mat[map[i][j]][tmp] = 1;
                }
        //start to search 
        flag = 0;// to indicate whether search is done
        fillboard( board, row, col, mat, map , n , 0 , flag);
        return flag;
    }

};