class Solution {
	public:
	    ListNode *deleteDuplicates(ListNode *head) {
		            // Start typing your C/C++ solution below
			    //         // DO NOT write int main() function
			    //                 
                        int pre;
			ListNode * pt, * result,*result_tail;
			result = NULL;
			result_tail = NULL;
			if ( head == NULL ) return head;
			pre = head -> val + 1;
			pt = head;
			int flag ;
			while ( pt != NULL ) {
				flag = 0;
				if ( pt->val == pre ) flag = 1;
				if ( pt->next != NULL )
				    if ( pt->next->val == pt->val ) 
					    flag = 1;

			        if ( !flag ) {
				// this node is OK
					if ( result == NULL) {
						result = pt;
						result_tail = pt;
					}else{
						result_tail->next = pt;
						result_tail = result_tail->next;
					}
				}

				pre = pt->val;
				pt = pt->next;
			}

			if (result_tail != NULL)
				result_tail-> next = NULL;	
			return result;

		}
 };
