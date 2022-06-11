// 2 pointer approach
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
// hashmap approach
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> mp;
        while(headA){
            mp[headA]++;
            headA= headA->next;
        }
        while(headB){
            if(mp[headB]>0) return headB;
            headB= headB->next;
        }
        return nullptr;
    }
};
// using stacks also we can do and we can use a brute force approach with tc O(n^2). 
