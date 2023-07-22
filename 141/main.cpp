
#include <iostream>



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
    bool hasCycle(ListNode *head) {
        ListNode * fast=head,*slow=head;
        while (fast!= nullptr && fast->next!= nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){

                return true;

            }

        }
        return false;

    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
