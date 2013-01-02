#include <iostream>
#include <string>
using namespace std;  
  
     string add (string a , string b ) {
       
	    string result = "";
		char char_tmp;
		int flag, pa , pb , tmp , m , n;
		m = a.length();
		n = b.length();
		flag = 0 ;
		pa = 0;
		pb = 0;
		while ( (pa < m ) || ( pb < n ) ){
		     tmp = flag;
		     if ( pa < m ) tmp += a[pa] - '0';
			 if ( pb < n ) tmp += b[pb] -'0';
			 char_tmp = (tmp % 10 ) + '0';
			 result = result + char_tmp;
			 flag=  tmp/10 ;
			 pa ++;
			 pb ++;
		}
        if ( flag > 0 ) result = result + "1";	
        cout << result << ":" << a << ":" << b <<endl;	
		return result;
	}
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // revert the string for convenient
		int n , m , i  ;
		char j;
		char tmp;
		n = num1.length();
		
		for ( i = 0; i < n/2 ; i ++ ){
           tmp = num1[i];
		   num1[i] = num1[n-i-1];
		   num1[n-i-1] = tmp;
		}

        m = num2.length();
		
		for ( i = 0; i < m/2 ; i ++ ){
			tmp = num2[i];
			num2[i] = num2[m - i -1];
			num2[m-i-1] = tmp;
		}
 	cout << num1 << endl << num2 << endl;
		string result = "0"; 
		
		for (  i = 0 ; i < n ; i ++){
		    for ( j = '0' ; j < num2[i] ; j++)
			    result = add( result, num1 );
				
			num1 = "0" + num1  ;
			cout << result << " " << num1<<endl;
		}
		
		n = result.length();
		for ( i = 0 ; i < n/2 ; i ++ ){
		      tmp = result[i];
			  result[i] = result[n - i -1 ];
			  result[n-i-1] = tmp;
		}
		
		return result;
    }

int main () {
   //  cout<< add ("12","10" ) << endl;
     cout <<multiply("9","99")<<endl;
     system("pause");
}
