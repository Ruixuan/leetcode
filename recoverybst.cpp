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
    void Travel_Inorder ( TreeNode * root , int &max , int &flag , TreeNode** nodes){
        if ( root  == NULL ) return ;
	 Travel_Inorder( root->left , max , flag , nodes );	
       // check this nodes
	if ( (flag == 0) && (root->val < max )){// the first wrong value has appeared
		flag ++;
	}
	if ( (flag ==1) && ( root->val >= max )){// the second wrong value 
		flag ++;
	}
	nodes[flag] = root;
	if ( (root->val)>max) max = root->val;
        //travel right	
	Travel_Inorder( root->right , max , flag , nodes );	
    
    }
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       int flag,max;
       TreeNode * nodes[5];
       flag = 0;
       max = -999999;
       Travel_Inorder( root , max , flag , nodes );
       int tmp;
       //swap the nodes
       tmp = nodes[0] -> val;
       nodes[0]->val = nodes[1]->val;
       nodes[1]->val = tmp;       
    }
};

