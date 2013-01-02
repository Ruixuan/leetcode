class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int time[3];
	int i;
	for (i = 0 ; i < 3 ; i++ ) time[i] = 0;
	for ( i = 0; i < n ; i ++)
		time[A[i]] ++;
	int j ;
	i = 0;
	for (j = 0 ;  j < 3 ; j ++)
		while ( time[j]>0){
			A[i] = j;
			i ++;
			time[j] --;
		}
	return;

    }
};

