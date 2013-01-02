/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
    Given a binary tree, determine if it is height-balanced.

     For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

*/
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	if (root == NULL) return true;
	// determine the left & right tree are ballanced
	//
        bool result = isBalanced( root-> left) && isBalanced(root->right);

	int left_depth, right_depth;

	// get the depth of left and right sub-tree
	if (root->left != NULL) 
		left_depth = root -> left -> val;
	   else 
		left_depth = 0;

	if (root -> right != NULL )
            		right_depth = root -> right -> val;
        	else 
			right_depth = 0;
	// determine the depth of root 
	root -> val = right_depth + 1;

	if (left_depth > right_depth)
		root -> val = left_depth + 1;

	result = ( result && (right_depth - left_depth > -2) && (right_depth - left_depth <  2 ));
	return result;
    }
};

