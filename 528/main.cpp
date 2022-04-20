#include <iostream>
#include <bits/stdc++.h>


using namespace std;


class Solution {
private:
    vector<int> preSum;

public:
    Solution(vector<int>& w) {
        int n=w.size();
        preSum.resize(n+1);

        preSum[0]=0;
        for (int i = 1; i <=n; ++i) {
            preSum[i]=preSum[i-1]+w[i-1];
            
        }



    }

    int pickIndex() {

        int n=preSum.size();
        uniform_int_distribution<int> dis(1,preSum[n-1]);

        int target=dis.a();
        return lower_bound(preSum.begin(),preSum.end(), target) - preSum.begin();


    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
