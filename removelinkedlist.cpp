 class Solution {
	 public:
	     ListNode *deleteDuplicates(ListNode *head) {
			ListNode * pt;
			pt = head;

			while ( pt != NULL ) {
				if ( pt->next == NULL ) break;
				if ( pt->val == pt->next->val ) pt->next = pt->next->next;
				else
					pt = pt->next;
			}

			return head;

			                      
 	}
 };
