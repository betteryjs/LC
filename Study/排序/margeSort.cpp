//
// Created by yjs on 2022/4/25.
//

#include <bits/stdc++.h>


using namespace std;


class MargeSort {

public:

    void margeSort(vector<int> &nums, int left, int right) {
        //递归的终止情况
        if (left >= right) {
            return;
        }

        //第一步：分成子问题
        int mid = left + (right - left) / 2;


        //第二步：递归处理子问题
        margeSort(nums, left, mid);
        margeSort(nums, mid + 1, right);

        //第三步：合并子问题
        int k = 0, i = left, j = mid + 1;
        vector<int> tmp(right - left + 1, 0);
        while (i <= mid && j <= right) {

            if (nums[i] <= nums[j]) tmp[k++] = nums[i++];
            else tmp[k++] = nums[j++];
        }
        while (i <= mid) tmp[k++] = nums[i++];
        while (j <= right) tmp[k++] = nums[j++];

        for (k = 0, i = left; i <= right; k++, i++) nums[i] = tmp[k];


    }


};


int main() {


    MargeSort margesort;
    vector<int> nums{1, 25, 65, 99, 11, 12};

    margesort.margeSort(nums, 0, nums.size() - 1);

    for_each(nums.begin(), nums.end(), [](auto c) { cout << c << " "; });
    cout << endl;

    return 0;
}