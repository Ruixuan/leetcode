class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
         int i, start, end ;
      
        for ( i = 0 ; i < intervals.size(); i++ ){
		if (newInterval.start <= intervals[i].end){
			if (newInterval.end < intervals[i].start){//insert it , creat a new interval
				intervals.insert( intervals.begin()+i, newInterval );
				return intervals;
			}else{// have to merg intervals
				if (newInterval.start < intervals[i].start)
					 intervals[i].start = newInterval.start;
			        int k = i + 1;
			        while ( k < intervals.size() ){
					if (intervals[k].start > newInterval.end ) break;
					k++;

		:	}	
				 

				 

				if ( intervals[k-1].end > newInterval.end ){
					intervals[i].end = intervals[k-1].end;
				} else{
					intervals[i].end = newInterval.end;
				}	
				 intervals.erase( intervals.begin() + i + 1 , intervals.begin() + k );
	 			return intervals;

			}
		}
	}
        intervals.push_back(newInterval);
        return intervals;	
    }
};

