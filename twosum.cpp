class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        int i, j , n;
        n = numbers.size();
        for ( i = 0 ; i < n-1 ; i ++)
            for ( j = i + 1 ; j < n ; j ++)
              if (numbers[i] + numbers[j] == target){
                result.push_back(i+1);
                result.push_back(j+1);
                return result;
              }
                
        
    }
};