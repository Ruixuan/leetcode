class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m,n, i , j  ;
        const char* ps , *pp;
        m = 0 ;
        while(s[m] != NULL) m ++;
        n = 0;
        while( p[n] != NULL) n ++;
         
        
        vector<bool> pre(n+1, 0);
        vector<bool> next(n+1, 0);
        vector<bool> tmp(n+1, 0);
    
        
        pre[0] = 1; 
                    
        for ( j = 1 ; j <=n ; j ++)
            pre[j] = (p[j-1] == '*') && (pre[j-1]);
            
        for (i = 1; i <= m ; i++){
            next[0] = 0;
            for ( j = 1 ; j <= n ; j ++ ){
                next[j] = 0;
                if ( p[j-1] =='?'){
                            next[j] = pre[j-1];
                            continue;
                    }
                if ( p[j-1] == '*'){ 
                        if (pre[j-1]) next[j] = 1;
                        if (pre[j]) next[j] = 1;
                        if (next[j-1]) next[j] = 1;
                        continue;
                    }
                    
                next[j] = pre[j-1] && (s[i-1] == p[j-1]);
                if ( !next[j]) break;
                
            }
            pre = next;
         }
                
        return pre[n];
    }
};