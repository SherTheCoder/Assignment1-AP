#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    //MAKE CHANGES IN THIS FUNCTION ONLY
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        for(int i = 1 ; i < lists.size() ; i ++){
            lists[0] = merge(lists[0], lists[i]);
        }
        return lists[0];
    }


    ListNode* merge(ListNode* left, ListNode* right){
        ListNode dummy = ListNode(0);
        ListNode* ptr = &dummy;
        while(left && right){
            if(left->val < right->val){
                ptr->next = left;
                left = left->next;
            }
            else{
                ptr->next = right;
                right = right->next;
            }
            ptr = ptr->next;
        }
        if(left) ptr->next = left;
        if(right) ptr->next = right;
        return dummy.next;
    }
};
