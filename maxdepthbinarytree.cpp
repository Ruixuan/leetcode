class Solution {
public:    
    int max_depth( TreeNode * root  ){
	    if (root ==NULL) return 0;
		int l_depth, r_depth;
		r_depth = max_depth( root->right );
		l_depth = max_depth( root->left );
		if (r_depth > l_depth ) return r_depth+1;
		                        else return l_depth+1;
		
	   
	}
   int maxDepth(TreeNode *root)   {
	    return max_depth( root ); 
	}
};