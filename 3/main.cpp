#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for_each(nums.begin(), nums.end(),[](int & a){cout << a<<" ";});
        cout<<endl;

       vector<int>::iterator res=unique(nums.begin(), nums.end());
//       return copy(res,res+1,ans);
        for (auto a = res; a!=nums.end() ; ++a) {
            cout<< (*a)<< " ";
        }



    }
};
int main() {
    Solution go;
    vector<int>num{3, 4, 2, 0, 0, 1};
    go.findRepeatNumber(num);
    return 0;
}
