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
    bool flag;
    void travel ( TreeNode * root , int current_sum , int sum){
	    if (root == NULL ) return ;
	    if ( flag ) return;
	    if ( ((root->right) == NULL) && ( (root->left) == NULL )){
		    if ( sum == (current_sum+root->val) ) flag = true;
		    return;
	    }
	    travel( root->right, current_sum + root->val, sum);
    	    travel( root->left, current_sum + root->val, sum);
    }
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	flag = false;
	travel( root , 0 , sum);
	return flag;
	
        
    }
};

