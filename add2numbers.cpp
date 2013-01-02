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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       ListNode * pt1, * pt2, *pt;
       ListNode * result, * tmp, *pre;
       int len1, len2 , flag, valuea , valueb;

       result = (ListNode *) malloc(sizeof (ListNode) );
       result->next = NULL;
       pt = result;
       pt1 = l1;
       pt2 = l2;
       flag = 0;
       tmp = result;
       while (pt1 != NULL || pt2 != NULL){
              pt = tmp;
              valueb = 0;
              valuea = 0;

	      if (NULL!= pt1){
		       valuea = pt1->val;
		       pt1 = pt1->next;
	      }

	      if (NULL != pt2 ) {
		       valueb = pt2->val;
		       pt2= pt2->next;
	      }
	      
	      pt->val = valueb + valuea + flag;

	      if ((pt->val)>9){
		      pt->val -= 10;
		      flag=1; 
	      }else {
		      flag =0;
	      }

              tmp = (ListNode *) malloc(sizeof(ListNode));
	      pt ->next = tmp;
	      tmp ->next = NULL;
       //       pt = tmp;
       }

       if (flag ==1 ) {
               pt = pt -> next;
               pt -> val = flag;
	       pt -> next = NULL;

       }else {
	       
	       pt->next = NULL;
       }                   
    return result;       

    }
};


