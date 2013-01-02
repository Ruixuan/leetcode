 #include <iostream>
 #include <vector>
 using namespace std;
 
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       vector<int> factorial( n+1 , 1 );
       vector<int> used( 259 , 0 );
       int i  ;
       string result;
       result = "";
       factorial[0] = 1;
       for ( i = 1 ; i < n+1 ; i ++ ) {
		factorial[i] = i * factorial[i-1];
		cout << factorial[i] << endl;
       } 
 	int tmp,j;
	char a; 
       for ( i = n-1 ; i >= 0 ; i--){
             //  cout << factorial[i] << endl;
	           tmp = (k - 1 ) / factorial[i] + 1; 
	           k = k - (tmp -1 ) * factorial[i];

	           for ( a = '1' ; a <='9'; a ++){
			if ( ! used[a] ) tmp --;
			if (tmp == 0 ) break;
		}
		
		result = result + a;
		used[a] = 1;

        }

       return result;

    }
    
    int main (){
       cout<< getPermutation( 3 , 5) << endl;
       system( "pause"); 
    }
