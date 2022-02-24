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




    void adjustHeap(vector<int> &arr, int i, int n) {
        int parent = i;
        int child = 2 * i + 1; // left child
        while (child < n) {
            // find  the max node in [left child node, right child node]
            // default left child node is the max
            // if  left child is less than right child ,so right child is the max.
            if (child + 1 < n && arr[child] < arr[child + 1]) {
                child++;
            }
            // if parents is less than the max child node.
            if (arr[parent] < arr[child]) {
                swap(arr[parent], arr[child]);
                parent = child;
            }
            child = child * 2 + 1;
        }
    }






// create heap
    void build_heap(vector<int> &arr, int size) {
        // father node is i
        // left child node is 2*i+1
        // right child node is 2*i+2
        for (int i =  (size/2) - 1; i >= 0; i--) {
            adjustHeap(arr, i, size);
        }
    }

    void heap_sort(vector<int> &arr, int size) {
        build_heap(arr, size);
        for (int j = size - 1; j > 0; j--) {
            swap(arr[j], arr[0]);
            adjustHeap(arr, 0, j);
        }
    }


};
// @solution-sync:end


class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // select sort k
        priority_queue<int,vector<int>,less<int>> priorityQueue;

        for (int & num:nums) {

                priorityQueue.push(num);


        }
        int index=0;
        while (!priorityQueue.empty()){
            index++;
            if(index==k){
                return priorityQueue.top();
            }
            priorityQueue.pop();
        }








    }
};




class Solution3 {
public:
    int findKthLargest(vector<int>& nums, int k) {

        int l = 0, r = nums.size() - 1, target = nums.size() - k;
        while (l < r) {
            int mid = randomPartition(nums, l, r);
            if (mid == target) {
                return nums[mid];
            }if (mid < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return nums[l];

    }

    int randomPartition(vector<int>& arr, int left, int right) {
        int i = rand() % (right - left + 1) + left; // [left ,right]
        swap(arr[i], arr[left]);
        return quick_sort_parition(arr, left, right);
    }

    int quick_sort_parition(vector<int> &arr, int  low, int  hig) {


        vector<int>::value_type pivot =arr[low];
        while (low != hig) {
            while (low < hig && arr[hig] >= pivot  ) {
                hig--;
            }
            arr[low]=arr[hig];
            while (low<hig && arr[low] <= pivot ) {
                low++;
            }
            arr[hig]=arr[low];
        }
        arr[low] = pivot;
        return low;
    }
};

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    auto solution = Solution3();
    auto result = solution.findKthLargest(nums, k);
    cout << result << endl;

    return 0;
}
