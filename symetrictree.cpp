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
    void comparetree(TreeNode* root_left, TreeNode* root_right, bool &flag){
        if (!flag) return;
        if (root_left ==NULL){
            flag = (root_right == NULL);
            return;
        }
        if (root_right == NULL){
            flag = (root_left == NULL);
            return;
        }
        
        flag = ((root_left->val) == (root_right->val));
  
        comparetree(root_left->left, root_right->right, flag);
        comparetree(root_left->right, root_right->left, flag);                        
    }
    
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool flag = 1;
        if (root==NULL)  return 1;
        comparetree(root->left, root->right, flag);
        return flag;
        
    }
};