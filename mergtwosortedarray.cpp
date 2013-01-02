class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //move A backward by n  steps
		int i,pa, pb, pc,flag;
		for ( i = m-1 ; i >= 0 ; i -- )
		   A[ i + n ] = A[i];
		 
		 
		pa = n;
		pb = 0;
		pc = 0;
		
		while ( pb < n ){
		
		   if ( pa >= m + n)// pa is reaching the end 
		      flag = 1;
			  else flag = ( B[pb] <= A[pa]);
		   if (  flag  ){//insert B 
		       A[pc] = B[pb];
			   pc ++ ;
			   pb ++ ;
		    } else{
			    A[pc] = A[pa];
				pa ++;
				pc ++;
			}	
		}
		
    }
};