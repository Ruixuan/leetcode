class Solution {
public:
    int abs (int a){
       if (a > 0) return a;
    else 
	          return -a;
    }
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	int len = num.size();
	int i , j , k , tmp, closest;
	int head, tail;//for binary search

	//first sort


	for (i=0; i<len; i++)
		for ( j = len-1 ; j > i ; j --)
			if (num[j]<num[j-1]){
				tmp = num[j];
				num[j] = num[j-1];
				num[j-1] = tmp;
			}
	 closest = (num[0] + num[1] + num[2]);
	//then calculate a+b, then using target-a-b to locate the c
	for (i=0; i < len-2 ; i++ ){
		for (j=i+1; j< len-1 ; j++){
			 head = j + 1;
			 tail = len -1;
			 tmp = target - num[i] -num[j];
			 while( head <= tail){
				k = ( head + tail ) / 2 ;
				if (tail - head <= 2  ) break;
				if (num[k] == tmp ){
					//we find the best match!
					closest = target;
					return target;
				}
				// to locate the num
				if ( num[k] > tmp){
					tail = k-1;
				}else{
					head = k+1;
				}
				
			 }

                         // now we located 
			 if ( this->abs(num[i] + num[j] + num[k] - target) < this->abs(closest  - target)  ) closest =  (num[i] + num[j] + num[k] );
		  	 if ( this->abs(num[i] + num[j] + num[head] - target) < this->abs(closest - target)  ) closest =  (num[i] + num[j] + num[head] );
			 if ( this->abs(num[i] + num[j] + num[tail] - target) < this->abs(closest - target)  ) closest =  (num[i] + num[j] + num[tail] );
		   //	 return closest;
		}
	
	}
	return closest;
    }
};


