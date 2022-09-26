#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// @solution-sync:begin
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // select sort k
        heap_sort(nums,nums.size());
        return nums[nums.size()-k];




    }




    void maxHeapify(vector<int> &arr, int i, int heapSize) {
        int leftChild=2*i, rightChild=2*i+1, target;
        if(leftChild< heapSize  && arr[leftChild]>arr[i] )  target=leftChild;
        if(rightChild< heapSize  && arr[rightChild]>arr[i] )  target=rightChild;
        if(target!=i){
            swap(arr[i], arr[target]);
            maxHeapify(arr, target,heapSize);

        }



    }






// create heap
    void build_heap(vector<int> &arr, int size) {
        // father node is i
        // left child node is 2*i+1
        // right child node is 2*i+2
        for (int i =  size/2; i >= 0; i--) {
            maxHeapify(arr, i, size);
        }
    }

    void heap_sort(vector<int> &arr, int size) {
        build_heap(arr, size);
        for (int j = size - 1; j > 0; j--) {
            swap(arr[j], arr[0]);
            maxHeapify(arr, 0, j);
        }
    }


};
// @solution-sync:end







int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    auto solution = Solution();
    auto result = solution.findKthLargest(nums, k);
    cout << result << endl;

    return 0;
}
