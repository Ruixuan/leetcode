class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.length();
        vector<int> stack;
        int i, tmp;
        for ( i = 0; i < n ; i ++){
            if ( s[i] == '(') {
                stack.push_back(0);
              }
            
            if (s[i] == '['){
               // if (stack.size() > 0)
                 //   if (stack.back() < 1) return false;
                stack.push_back(1);
            }
            
            if (s[i] == '{'){
                //if (stack.size() > 0)
                   // if (stack.back() < 2) return false;
                stack.push_back(2);
            }
            
            if ( s[i] == ')'){
                if (stack.size() == 0 ) return false;
                tmp = stack.back();
                if (tmp != 0) return false;
                stack.pop_back();
            }
                       
            if ( s[i] == ']'){
                if (stack.size() == 0 ) return false;
                tmp = stack.back();
                if (tmp != 1) return false;
                stack.pop_back();
            }
            
            if ( s[i] == '}'){
                if (stack.size() == 0 ) return false;
                tmp = stack.back();
                if (tmp != 2) return false;
                stack.pop_back();
            }
            
            
              
        }
        
        return (stack.size() == 0);
        
    }
};