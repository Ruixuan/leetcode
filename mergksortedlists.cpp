/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode * merge ( ListNode * a , ListNode * b ){
	  ListNode * head, * tail;
	  head = ( ListNode * ) malloc ( sizeof ( ListNode ) );
	  head -> next = NULL;
	  tail = head;
	  while ( (a!=NULL) || ( b!=NULL ) ) {
	  
	     if ( a == NULL ) {
		     tail->next = b;
			 break;
		 }
		 
		 if ( b == NULL ){
		    tail->next = a;
			break;
		 }
		 
		 if ((a->val) < (b->val)){
		     tail->next = a;
			 tail = tail-> next;
			 a = a -> next;
		 }else {
		     tail->next = b;
			 tail = tail-> next;
			 b = b -> next;
		 }
	  }
	  
      return head->next;	  
	}
	
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		ListNode * head = NULL;
		int i ;
		for ( i = 0 ; i < lists.size(); i++)
		   head = merge( head , lists[i]);
		
		return head;
        
    }
};