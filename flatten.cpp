class Solution {
public:
       TreeNode * buildtree( TreeNode* root){
           if (root == NULL) return NULL;

           TreeNode* tail, *right ;



           right = root->right;

	   if ((root->left) != NULL){
	        tail = buildtree(root->left);
	       	root->right = root->left;
		root ->left = NULL;
	   }else {
	        tail = root;
	   }

	   //buildtree(right);
	   if (right == NULL){// NO RIGHT SUB TREE
	       tail->right = NULL;
	       return tail;
	   }else{
               tail->right = right;
	       return buildtree(right);
	   }
	   
       }

       void flatten( TreeNode * root){
           TreeNode * curent;
           buildtree(root);
       }
};
