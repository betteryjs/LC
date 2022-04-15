#include <iostream>
#include <vector>

using namespace std;

class NumArray {
private:
    vector<int> nums;
public:
    NumArray(vector<int> &nums):nums(nums) {

    }

    int sumRange(int left, int right) {
        int sum=0;
        for (int i = left; i <= right; ++i) {
            sum+=nums[i];

        }
        return sum;

    }
};


class NumArray2 {
private:
    vector<int> preSum;
public:
    NumArray2(vector<int>& nums) {
        // preSum[0] = 0，便于计算累加和
        vector<int> preSum(nums.size()+1);
        for (int i = 1; i < preSum.size(); ++i) {
            preSum[i]=preSum[i-1]+nums[i-1];
        }



    }

    int sumRange(int left, int right) {
        return preSum[right+1]-preSum[left];

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
