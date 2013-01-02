class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       int len = S.length();
       int n = L.size();
       vector<int> result;
       if ( n <= 0 ) return result;
       int m = L[0].length();
       int i, j , k , head ,tail, sum , flag;
       vector<int> word(len,-1);
       
       for ( i = 0; i < m ; i ++){
           vector<int> occupied(n,0);
           sum = 0;
           head = i;
           tail = head;
           while ( tail < len){
                if (tail + m > len ) break;
                if ( head + n*m > len) break;
                // try to match a string start at S[tail]
                flag = 1;
                for (j = 0; j < n ; j ++)
                    if (occupied[j] == 0){
                        flag = 0;
                        for ( k = 0; k < m; k ++)
                            if (S[k+tail]!= L[j][k]){
                                flag = 1;
                                break;
                            }
                            
                        if (flag == 0){//successful match
                            word[tail] = j;
                            occupied[j] = 1;
                            sum ++;
                            break;
                        }
                    }
                //check if match sucess or not 
                if (flag == 0){
                    // find a match in the tail, 
                    // tail points to next
                    tail = tail + m;
                    if (sum == n){//match all the concatation
                        result.push_back(head);                      
                        occupied[word[head]] = 0;//release the first word
                        head = head + m ;
                        sum --;
                    }                   
                }else {
                    //CAN NOT MATCH 
                     //release the first 
                     if (sum > 0 ) sum --;
                     if (word[head] >= 0) occupied[word[head]] = 0;//release the first word
                     head = head + m ;
                     if ( head > tail ) tail = head;
                }
                
           }
           
       }
       
    return result;   
    }
};

