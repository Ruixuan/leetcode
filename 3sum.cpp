class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
     int len = num.size();
     int i,j,k, head, tail;
     vector <int> oneresult(3,0), lastresult ;
      vector<vector<int> > result; 
    int sum2,tmp;
    
    //sort it 
   for (i=0; i<len; i++) 
   for ( j = len-1 ; j > i ; j--)
            if ( num[j-1] > num[j] ){
			tmp = num[j-1];
			num[j-1] = num[j];
			num[j] = tmp;
		    }
			
  // result.push_back(num);
    for ( i = 0; i< len-2 ; i++){
    if ( num[i] > 0) break;
    if (i-1>=0 ){
        if (num[i] == num[i-1]) continue;
    }
    oneresult[0] = num[i];
	for ( j = i+1; j< len-1 ; j++){
        if (j>i+1){
          if (num[j-1]==num[j]) continue;
        }
	     sum2 = num[i] + num[j];
	     if ( sum2>0 ) break;
	     oneresult[1] = num[j];
	   
	     //start to find the third num using binary search
	     head = j+1;
	     tail = len-1;
	     while (head <= tail){
	        k = (head + tail ) / 2 ;
		if ((-num[k]) == sum2){//we find it!
                                oneresult[2] = num[k];
                                   if (result.size() != 0){
               lastresult = result.back();
              //  if ((lastresult[0] == oneresult[0]) && (lastresult[1] == oneresult[1]) && (lastresult[2] == oneresult[2])) break;
        
	          }
		                result.push_back(oneresult);
		                break;
		}else{
		if  ((-num[k]) > sum2) {
			                  head = k + 1;
		                        }else{
					  tail = k - 1;
					}
		      }//end else
         }//end while 
		   
	}

    }
    
    return result;
    }
};


