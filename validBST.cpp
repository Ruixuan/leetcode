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
    void in_order( TreeNode* root, vector<int> & list){
        
        if (root == NULL) return;
        in_order( root->left, list );
        list.push_back(root->val);
        in_order( root->right, list );
    }
    bool isValidBST(TreeNode *root) {
        vector<int> list;
        if ( root == NULL) return true;
        in_order(root, list);
        int i;
        
        for ( i = 0; i < list.size()-1; i ++)
            if (list[i]>=list[i+1]) return false;
        
        return true;
    }
};