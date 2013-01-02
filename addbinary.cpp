class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       int pta, ptb, flag, avalue, bvalue, sum,i;
       string c;
       pta = a.length();
       ptb = b.length();
       c = a;
       if (pta<ptb)
	       c = b;
       flag = 0 ;

       for (i = c.length() -1 ; i >= 0; i -- )
       {
	       pta --;
	       ptb --;
	       avalue = 0;
	       bvalue = 0;

	       if (pta >=0)
	 		avalue = ('1' == a[pta]);
	       if (ptb >= 0)	       
			bvalue = ('1' == b[ptb]);

	       sum = avalue + bvalue + flag;
	       if (sum % 2 == 1){
		       c[i] = '1';
	       }else{
		       c[i] = '0';
	       }
	       flag = (sum >= 2);

       }
     if (flag) c= "1" + c;
     return c;
    }
};

