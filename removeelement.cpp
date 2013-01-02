class Solution {
	public:
	    int removeElement(int A[], int n, int elem) {
		            // Start typing your C/C++ solution below
		            // DO NOT write int main() function
			   int indent = 0;
			   int i;
			   for ( i = 0; i < n ; i ++){
				   A[i-indent] = A[i];
				   if (A[i] == elem ) indent ++;
			   }

			   return n-indent;
			            
		        }
};
