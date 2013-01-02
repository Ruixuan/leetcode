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
    int max;
    int max_recursive(TreeNode *root){

       if (NULL == root) return 0;

       int result = root->val;

       int left, right;
       left = max_recursive(root->left);
       right = max_recursive( root->right);

       if ((left + root->val) > result ) result = (left + root->val);

       if ((right + root->val) > result ) result = (right + root->val);

       if (result > max ) max = result;
        if ((root->val + left + right) > max ) max = (root->val + left + right);
       return result;

    }
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	max = root->val;
        max_recursive(root);
	return max;
    }
};

