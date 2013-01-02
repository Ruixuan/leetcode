    class Solution {
    public:
        bool isMatch(const char *s, const char *p) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            //step: 1 compress string p ( string between stars could be compressed into one string)
            int m,n;
            int i , j , start, sp , pp,flag;
             
            m = 0;
            n = 0;
            while(s[m]!= NULL) m ++;
            while(p[n]!= NULL) n ++;
            
            //consider edge cases
            if ( m == 0 ){
                    for ( j = 0 ; j < n ; j ++)
                        if (p[j]!= '*') return false;
                    return true;
            }
            
            if ( n == 0) return false;
            
            //compress string p
            vector<int> position;
            vector<int> count;
            
         
            j = 0;
            //compress the string p
            while(p[j] != NULL){
                start = j;
                while(p[j]!='*' && p[j]!=NULL){
                    j ++;
                }               
                position.push_back(start);
                count.push_back(j-start);
                if ( count.back()== 0) j ++;
            }
     
            vector<int> oneline(position.size()+1, 0);
            vector<vector<int> > dp( m+1 , oneline );
           //initialize
           
           dp[0][0] = 1;
           j = 0;
           while(p[j] == '*'){
                dp[0][j+1] = 1;
                j ++;
            }
            for ( i = 1 ; i <= m; i ++)//the last NULL is taken into comparation
                for ( j = 1; j <= position.size(); j ++){              
                    dp[i][j] = 0;
                    if (p[position[j-1]] == '*'){
                        dp[i][j] = dp[i-1][j] || dp[i-1][j-1] || dp[i][j-1];
                        continue;
                    }
                    // now compare the string s[i-count[j]] to s[i] and p[position] to p[count+position]
                    if (count[j-1] == 0) continue;
                    sp = i-count[j-1];
                    pp = position[j-1];
                    if ( sp < 0 ) continue;                  
                    if (dp[sp][j-1] == 0) 
                           continue;
                                        
                    flag = 1;
                    while(sp <= i-1){
                        if ( p[pp]!='?' && p[pp] !=s[sp] ){
                                        flag = 0;
                                        break;
                                    }
                        sp ++;
                        pp ++;
                    }
                    dp[i][j] = flag;
                }
            
            return dp[m][position.size()];
        }
    };