/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    void qsort ( int head , int tail , vector<Interval> &intervals){
		int i , j , k;
		Interval x;
		if ( head >= tail ) return;
		//swap first and the middle element
		x = intervals[(head + tail)/2];
		intervals[(head + tail)/2] = intervals[head];
		intervals[head] = x;
		i = head;
		j = tail;
		while ( i < j){
		    //find a smaller from right side
			while ( (i<j) && ( intervals[j].start > x.start )) j --;
			if ( i < j ){
			     intervals[i] = intervals[j];
				 i ++;
			}
			//find a bigger one from the left side 
			while ( (i < j) && (intervals[i].start < x.start) ) i ++;
			if ( i < j ){
			     intervals[j] = intervals[i];
				 j --;
			}
		}
		//
		intervals[i] = x;
		qsort( head, i -1, intervals);
		qsort ( i+1 ,tail  , intervals);
	}
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i , j , n ;
        Interval tmp,current;
		vector<Interval> result;
		 n = intervals.size();
		 if ( n == 0 ) return result;
		 
		 qsort ( 0 , n-1 , intervals);
		 /*
		// first sort the array by the start index
		for ( i = 0 ; i < n ; i ++)
		    for ( j = n-1 ; j > i ; j --)
			  if ( intervals[j].start < intervals[j-1].start){
				tmp = intervals[j];
				intervals[j] = intervals[j-1];
				intervals[j-1] = tmp;
			  }*/
		// Start to merge
		current = intervals[0];
	    for ( i = 1; i < n; i ++){
		    if ( current.end < intervals[i].start){
			     result.push_back( current );
				 current = intervals[i];
				 continue;
			}else{//merge two intervals
				if ( intervals[i].end > current.end ) 
					current.end = intervals[i].end;
				
			}
		}
		
		result.push_back( current );
		
		return result;
		 	
        
    }
};
