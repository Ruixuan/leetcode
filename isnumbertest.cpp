 #include<iostream>
 using namespace std;
 
 bool isNumber( char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        char * pt;
        int flag_start, flag_is_power, flag , number_flag , is_dot;
        //first check start
        is_dot = 0;
        pt = &s[0];
        number_flag = 0;
        flag_is_power = 0;
        // clean up white spaces
        while(*pt != NULL && *pt == ' ') pt ++;
        // check the chars
        if (*pt == '+' || *pt == '-'){
            pt ++;
            if (*pt == NULL) return false;
        }
        
        if (*pt == 'e') return false;
        
        is_dot = 0;
        
        while(*pt != NULL){
                    
            if ( *pt>='0' && *pt<='9'){
                number_flag = 1;
                pt ++;
                continue;
            }
            
            if (*pt == '.'){
                if (is_dot == 0){
                        is_dot = 1;
                        pt ++;
                        continue;
                    }
                }
            
            if ( *pt == ' ' ){// this should be the end 
                while( *pt != NULL){
                    if ( *pt != ' ') return false;
                    pt ++;
                }
                return number_flag;
            }
            
            if ( *pt == 'e'){
                if ( !number_flag)  return false;
                if ( flag_is_power) return false;
                number_flag = 0;//reset the number flag
                flag_is_power = 1;// set the power flag , make sure no more 'e's
                pt ++;
                if (*pt == '+' || *pt == '-'){
                        pt ++;
                        if (*pt == NULL) return false;
                    } 
                continue;    
            }
            // other chars are illegal
            return false;
            
        }
        
        return number_flag;
        
    }
    
 int main (){
     char a[] = "   0.1  ";
     cout<< isNumber(a) << endl;
     system("pause");
 }
