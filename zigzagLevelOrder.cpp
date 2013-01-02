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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
   // Start typing your C/C++ solution below
        // DO NOT write int main() function
	
       vector<int> depth;
       vector<int> empty;
       vector<TreeNode*> nodes;
       vector<vector<int> > result;
       int i;

       if (root == NULL) return result;



       depth.push_back(0);
       nodes.push_back(root);

       i = 0;

       while(i<depth.size()){
              
		if ( result.size() <= depth[i])			
			result.push_back(empty);

	       result[depth[i]].push_back(nodes[i]->val);
              
	       if (NULL != (nodes[i]->left)){

		              depth.push_back(depth[i]+1);
			      nodes.push_back(nodes[i]->left);

	       }

	       if (NULL != (nodes[i]->right)){

		              depth.push_back(depth[i]+1);
			      nodes.push_back(nodes[i]->right);

	       }
	      



	       i++;

       }
       int tmp,j;
       for (i=1; i < result.size(); i+=2){
	       for (j=0; j< result[i].size()/2; j++){
		       tmp = result[i][j];
		       result[i][j] = result[i][result[i].size() - j -1];
		       result[i][result[i].size() - j -1] = tmp;
	       }
		       
       }

       return result;
         
        
    }
};


