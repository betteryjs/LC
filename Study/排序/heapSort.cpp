//
// Created by yjs on 2022/2/23.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;


class HeapSort {
    // 堆排序时间复杂度O(N*log(N))
    // 堆排序额外空间复杂度O(1)
public:
    void heapSort(vector<int> &arr) {
        if (arr.empty() || arr.size() < 2) {
            return;
        }
        // O(N*logN)
//		for (int i = 0; i < arr.length; i++) { // O(N)
//			heapInsert(arr, i); // O(logN)
//		}
        // O(N)
        for (int i = arr.size() - 1; i >= 0; i--) {
            heapify(arr, i, arr.size());
        }
        int heapSize = arr.size();
        swap(arr[0], arr[--heapSize]);
        // O(N*logN)
        while (heapSize > 0) { // O(N)
            heapify(arr, 0, heapSize); // O(logN)
            swap(arr[0], arr[--heapSize]); // O(1)
        }
    }

    void heapInsert(vector<int> &arr, int index) {
        // 当前位置大于父位置的数
        while (arr[index] > arr[(index - 1) / 2]) {
            // 当前位置的值和父位置的值作交换
            swap(arr[index], arr[(index - 1) / 2]);
            // index 来到父位置
            index = (index - 1) / 2;
        }
    }

    // arr[index]位置的数，能否往下移动
    void heapify(vector<int> &arr, int index, int heapSize) {
        int left = index * 2 + 1; // 左孩子的下标
        while (left < heapSize) { // 下方还有孩子的时候
            // 两个孩子中，谁的值大，把下标给largest
            // 1）只有左孩子，left -> largest
            // 2) 同时有左孩子和右孩子，右孩子的值<= 左孩子的值，left -> largest
            // 3) 同时有左孩子和右孩子并且右孩子的值> 左孩子的值， right -> largest

            // left + 1 < heapSize right child exists and return the max of (left_child ,right_child )
            int largest = left + 1 < heapSize && arr[left + 1] > arr[left] ? left + 1 : left;
            // 父和较大的孩子之间，谁的值大，把下标给largest
            largest = arr[largest] > arr[index] ? largest : index;
            if (largest == index) {
                break;
            }
            swap(arr[largest], arr[index]);
            index = largest;
            left = index * 2 + 1;
        }
    }
};

int main() {

    return 0;
}