class Solution {
	public:
	    int firstMissingPositive(int A[], int n) {
		 
//		vector <int> flag(n+10,0);

		int i,k,tmp;


                for ( i = 0 ; i < n ; i++){
                     
		     while (A[i]!= i+1){
			   
			     if (A[i] <= 0) break;
			     if ( A[i] >n) break;
			     if (A[i] == A[A[i]-1]) break;
			     
			     tmp = A[i];
			     A[i] = A[tmp-1];
			     A[tmp-1] = tmp; 
		     }

		}
		for (i=0; i< n ; i++)
			if (A[i] != i+1 ) return i+1;

		return n+1;


	    }
};
