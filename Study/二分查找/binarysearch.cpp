//
// Created by yjs on 2022/4/20.
//
#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> nums, int target) {
    int left = 0;
    int right = nums.size() - 1; // 注意

    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1; // 注意
        else if (nums[mid] > target)
            right = mid - 1; // 注意
    }
    return -1;
}


//int lower_bound(vector<int> nums, int target) {
//    if (nums.size() == 0) return -1;
//    int left = 0;
//    int right = nums.size(); // 注意
//
//    while (left < right) { // 注意
//        int mid = left + (right - left) / 2;
//        if (nums[mid] == target) {
//            right = mid;
//        } else if (nums[mid] < target) {
//            left = mid + 1;
//        } else if (nums[mid] > target) {
//            right = mid; // 注意
//        }
//    }
//    return left;
//}


int lower_bound(vector<int> nums, int target) {
    int left = 0, right = nums.size() - 1;
    // 搜索区间为 [left, right]
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            // 搜索区间变为 [mid+1, right]
            left = mid + 1;
        } else if (nums[mid] > target) {
            // 搜索区间变为 [left, mid-1]
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 收缩右侧边界
            right = mid - 1;
        }
    }
    // 检查出界情况
    if (left >= nums.size() || nums[left] != target) {
        return -1;
    }
    return left;
}

int upper_bound(vector<int> nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 这里改成收缩左侧边界即可
            left = mid + 1;
        }
    }
    // 这里改为检查 right 越界的情况，见下图
    if (right < 0 || nums[right] != target) {
        return -1;
    }
    return right;
}