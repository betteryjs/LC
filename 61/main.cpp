#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class BuildList {

private:


    vector<int> nums;

private:


    bool InsertNextNode(ListNode *p, const int &e) {

        if (p == nullptr) {
            return false;
        }
        ListNode *s = new ListNode(e);
        s->next = p->next;
        p->next = s;
        return true;
    }

    ListNode *head = new ListNode(-1);


public:

    BuildList(const vector<int> &nums) : nums(nums) {
        ListNode *cur = this->head;

        ListTailInsert(cur, nums);


    }

    ListNode *ListTailInsert(ListNode *head, const vector<int> &nums) {
        ListNode *pos1 = head;
        for (const int &num: nums) {
            InsertNextNode(pos1, num);
            pos1 = pos1->next;
        }
        return head;
    }


    void PrintLinkList(ListNode *head) {
        ListNode *cur = head->next;
        while (cur) {
            cout << cur->val << " ";
            cur = cur->next;


        }
        cout << endl;

    }


    ListNode *getHead() {

        return this->head;

    }


};


class Solution {

private:

    ListNode *findKNode(ListNode *head, int k) {
        ListNode *fast = head;
        while (k--) {
            fast = fast->next;
        }
        ListNode *slow = head;
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;


    }


public:
    ListNode *rotateRight(ListNode *head, int k) {


    }

};


int main() {
//    vector<int> nums{1, 2, 3, 4, 5};
//
//    BuildList buildlist(nums);
//    ListNode *head = buildlist.getHead();
//    buildlist.PrintLinkList(head);
//    Solution2 *solution = new Solution2;
//    ListNode *NewHead = solution->rotateRight(head,2);
//
//    buildlist.PrintLinkList(NewHead);

    return 0;
}
