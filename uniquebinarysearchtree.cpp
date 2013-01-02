class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result(n+1,0);
        if ( n == 0) return 0;
        result[1] = 1;
        result[0] = 1;
        int i, j;
        for (i = 2; i <=n ; i ++){
            for( j =1; j <=i ; j ++ )
                result[i] = result[i] + result[j-1] * result[i-j];
        }
        
        return result[n];
        
    }
};