#include <vector>
#include <iostream>

using namespace std;

// @solution-sync:begin
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // binary search













    }
};
// @solution-sync:end

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    auto solution = Solution();
    auto result = solution.findMedianSortedArrays(nums1, nums2);
    cout << result << endl;

    return 0;
}
