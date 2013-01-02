class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( n < 3 ) return 0;
        int next[n];//  next larger one
        int max[n];// the max value from i+1 .. n-1
        int i , j , sum , head , tail, min;
        max[n-1] = n;
        max[n-2] = n-1;
        for (i = n - 3 ; i >= 0 ; i --){
            max[i] = max[i+1];
            if ( A[max[i]] < A[i+1]) max[i] = i + 1;
        }
            
            

        // start to calculate next
        next[n-1] = n;
        for ( i = n - 2 ; i >=0; i --){
            j = i + 1;
            while( j< n && A[j]<A[i] ){
                j = next[j];
            }
            next[i] = j;
        }
        head = 0;
        tail = 0;
        sum = 0;
        while ( head < n-1 ) {
            if (next[head] < n ) tail = next[head];
                        else     tail = max[head];
            
            min = A[head];
            if (A[head]>A[tail]) min = A[tail];
            for ( i = head + 1 ; i < tail ; i ++)
                sum = sum + min - A[i];
            
            head = tail;
                
        }
        
        return sum;
        
    }
};