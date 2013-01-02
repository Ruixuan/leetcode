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
    
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int>  result;
	vector<TreeNode*> node_stack;
        vector<int> pc_stack;
	TreeNode * pt;
	int pc;
	node_stack.push_back(root);
	pc_stack.push_back(0);
	while(node_stack.size()>0){
		pc = pc_stack.back();
		pc_stack.pop_back();

		pt = node_stack.back();		
		node_stack.pop_back();

		if (pt == NULL ) continue;

		if (pc == 0){

			//push the root
			pc ++;
			pc_stack.push_back(pc);
			node_stack.push_back(pt);
			//push the left node 
			
			pc_stack.push_back(0);
			node_stack.push_back(pt->left);
			continue;

			}

		result.push_back( pt->val);
		pc ++;
		if (pc == 2){
			// insert the right node
			pc_stack.push_back(0);
			node_stack.push_back(pt->right);

		}
			
		

	}
	return result;

    }
};

