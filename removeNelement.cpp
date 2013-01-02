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
		           ListNode *removeNthFromEnd(ListNode *head, int n) {
		        	 ListNode * pt, *pre_n;
				 int i;
				 if ( n == 0 ) return  head;
				 pre_n = head;
				 pt = head;
				 
				 for ( i = 0  ; i < n ; i ++ )
					 pt = pt->next;
				 if ( pt  == NULL ) return pre_n->next;

				 while ( pt != NULL){
					 if ( pt -> next == NULL ) break;
					 pt = pt->next;
					 pre_n = pre_n -> next;
				 }
				 pre_n->next = pre_n->next->next;

				 return head;

				 
			 	
			}
	       };
