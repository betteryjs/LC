#include <iostream>


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head== nullptr){

            return nullptr;
        }
        ListNode *slow = head, *fast = head;
        while (fast != nullptr) {
            if (slow->val!=fast->val){
                slow=slow->next;
                slow->val=fast->val;


            }
            fast=fast->next;


        }
        // 断开与后面重复元素的连接
        slow->next= nullptr;
        return head;


    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
