class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ( x < 0 ) return false;
	if  ( x % 10 == 0 && x > 0 ) return false;
	int tmp, len;
	tmp = x;
	len = 0;
	while ( tmp > 0 ){
		tmp /=10;
		len++;
	}

	unsigned reverse , i;
	tmp = x;
	reverse = 0 ;	
	while ( reverse < tmp){
		reverse = (reverse * 10) + (tmp % 10 );
		if ( (len % 2 ) == 1 )
			if ( reverse == tmp ) return true;// odd digits in x
		tmp = tmp / 10;
		if ( ( len % 2 ) == 0)
			if ( reverse == tmp ) return true;// even digits in x		
	}

	return reverse==tmp;

    }
};

