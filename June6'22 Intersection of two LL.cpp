class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a= headA, *b= headB;
        while(a!= b){
          // last tak jana hai ....agar null mile tab hi dusre head par point karana h
            a= a ? a->next : headB;
            b= b ? b->next : headA;
        }
        return a;
    }
};
