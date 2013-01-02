/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    

    void travel ( TreeNode * root , int current_sum , int sum, vector<vector<int> > &result , vector<int> &oneresult ){

	    if (root == NULL ) return ;

	    oneresult.push_back(root->val);
          
	    if ( ((root->right) == NULL) && ( (root->left) == NULL ))
		    if ( sum == (current_sum + root->val) ){

			 
			  //  result[0].push_back( root->val);
			    result.push_back( oneresult);

		    }
		    
		    
	    

	    travel( root->right, current_sum + root->val, sum, result , oneresult);
    	    travel( root->left, current_sum + root->val , sum, result, oneresult);

	    oneresult.pop_back();
    }

 vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	
	vector<int> oneresult;
	vector<vector<int> > result;
      
	travel( root , 0 , sum, result, oneresult);
	return result;
	
        
    }
};


