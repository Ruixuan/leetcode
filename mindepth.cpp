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
    void depthmin ( TreeNode * root , int &min , int depth) {
	
	    if ( depth > min) return;
	    if (root == NULL  ){ 
		   return;
		}
	    if ( (root->left == NULL) && ( root->right == NULL )){
		  if ( min > depth ) min = depth;
		  return;
		}
		
		depthmin( root->right , min , depth + 1 );
		depthmin( root->left , min , depth + 1 );
	}
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int min = 999999;
		if (root == NULL ) return 0;
        depthmin( root , min , 1 );
		return min;
    }
};