// this is the solution of string matching(leetcode.com), I am using KMP algorithm
class Solution {
public:

    int creat_T( char* a, int la , int* T){
    int pos , i; 
    T[0] = -1;// if mismatch at T[0], have to restart matching, the match point go backwards
    if (la < 2) return 0;
    T[1] = 0;//if mismach at T[1], go to the T[0] for help 
    i = 0;
    pos =2; // we got T[0] and T[1] so start from T[2]
    
    while( pos < la ){
               if (a[pos-1] == a[i]){
                               i++;
                               T[pos] = i;
                               pos ++;
                            }else{// matching fails
                                  if (T[i] >= 0 ){
                                               //start matching from
                                               i = T[i];
                                           }else{//  
                                                 T[pos] = 0;
                                                 pos ++;
                                                 //i++;
                                                 }
                                  }
                
           }
    
         
}

int match(char* b, char* a){
         int la, lb, i , m ;
         
         la = 0;
         while(a[la] ) la++;
         lb = 0; 
         while (b[lb] ) lb ++;
         if (la ==0 && lb == 0) return 0;
         if (la == 0 ) return 0;
         if (lb == 0 ) return -1;
         int * T;
         T = (int *) malloc( la*sizeof(int));
         creat_T(a,la,T);
         //ok start matching
         i = 0; 
         m = 0;
         while(m < lb){
              if (a[i] == b[m]){
                          i++;
                          m++;
                       }else{ 
                               //m remains the same
                            //  cout<< i << "  " << T[i] <<endl;
                               i = T[i];
                               if (i == -1){
                                     m ++;
                                     i = 0;
                                  }
                                 
                             }
              if (i == la){
                    return m-i;
                 }
         }
         
          
       return -1;  
         
     }
     
    char *strStr(char *haystack, char *needle) {
      
        int a = match(haystack, needle);
        if (a==-1) return NULL;
        return haystack+a;
        
    }
};
