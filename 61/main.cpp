#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// 转换成树组
class Solution2 {


private:
    vector<int> nums;

public:



    ListNode *rotateRight(ListNode *head, int k) {
        ListNode * cur=head->next;
        while (cur!= nullptr){
            nums.push_back(cur->val);
            cur=cur->next;

        }

        if((int) nums.size()< k){
            reverse(0,(int) nums.size()-1);

        }else{
            reverse(0,(int) nums.size()-k-1);
            reverse((int) nums.size()-k,nums.size()-1);
            reverse(0,(int) nums.size()-1);
        }



        cur=head->next;

        for (auto c:nums) {
            cur->val=c;
            cur=cur->next;
//            cout<< c<< " ";


        }
        cout <<endl;
        return head;




    }


    void  reverse(const int  & left,const int & right){

        for (int i = left,j=right; i < j; ++i,--j) {
            swap(nums[i],nums[j]);

        }



    }





};





class Solution {

public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(head== nullptr || k==0) return head;

        int n = 0;        //链表的长度
        ListNode* tail;   //尾节点
        for(ListNode* p = head; p ; p = p->next){
            tail = p;
            n++;
        }

        k %= n;

        ListNode* cur = head;
        for(int i = 0; i < n - k - 1; i++)   cur = cur->next;  //找到链表的第n-k个节点
        // [0 n-k-2] n-k-1










        int listLength = getLength(head);



    }

    int getLength(ListNode *head) {
        int res = 0;
        ListNode *cur = head;
        while (cur != nullptr) {
            res++;
            cur = cur->next;
        }
        return res;

    }

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

int main() {
    vector<int> nums{1, 2, 3, 4, 5};

    BuildList buildlist(nums);
    ListNode *head = buildlist.getHead();
    buildlist.PrintLinkList(head);
    Solution2 *solution = new Solution2;
    ListNode *NewHead = solution->rotateRight(head,2);

    buildlist.PrintLinkList(NewHead);

    return 0;
}
