//
// Created by yjs on 2022/5/13.
//

#include <bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 迭代
class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode * cur=dummyHead;
        while (cur->next!= nullptr){

            if(cur->next->val==val){

                cur->next=cur->next->next;

            }else{
                cur=cur->next;
            }

        }
        return dummyHead->next;






    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
