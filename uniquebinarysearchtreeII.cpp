
class Solution {
public:
    TreeNode* copy( TreeNode* root, int offset){
        if ( root == NULL )  return NULL;
        TreeNode* newroot= new TreeNode(root->val + offset);
        newroot->left = copy( root->left, offset);
        newroot->right = copy( root->right, offset);
        return newroot;
       
      
    }
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode *> result;
        vector< TreeNode* > oneline;
        vector< vector<TreeNode*> > list( n + 1 , oneline);
        list[0].push_back(NULL);
        int i , j , k , l ;
        for (i = 1 ; i <=n ; i ++ )
            for ( j = 1; j <=i ; j ++)
                for ( k = 0; k < list[j-1].size(); k ++)
                    for ( l = 0 ; l < list[i-j].size(); l ++){
                        TreeNode* root = new TreeNode(j);// the root is j
                        root->left = copy(list[j-1][k], 0);
                        root->right = copy(list[i-j][l], j );
                        list[i].push_back(root);
                    }
                
        return list[n];
    }
};