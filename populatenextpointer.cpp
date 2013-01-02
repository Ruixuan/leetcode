/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	if (root ==NULL ) return;
	TreeLinkNode * next_head , *next_tail , * pt;
	root -> next = NULL;
        next_tail = NULL;
	next_head = NULL;
	pt = root;

	while ( pt != NULL || next_head != NULL ){

             if ( pt == NULL) {
                     if ( next_tail == NULL ) return;
		     next_tail->next = NULL;
		     pt = next_head;
		      
		     next_head = NULL;
		     next_tail = NULL;
	     }
	     
	     if ( pt ->left != NULL ){
		     if (next_head == NULL) {
		     		next_head = pt->left;
				next_tail = pt->left;
		     }else{
			     next_tail-> next = pt->left;
			     next_tail = next_tail->next;
		     }
	     }

	     if ( pt ->right != NULL ){
		     if (next_head == NULL) {
		     		next_head = pt->right;
				next_tail = pt->right;
		     }else{
			     next_tail-> next = pt->right;
			     next_tail = next_tail->next;
		     }
	     }

	     pt = pt -> next;	 
	}

	return;
          
        
    }
};

