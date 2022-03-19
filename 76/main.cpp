#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

// @solution-sync:begin
// 滑动窗口

class Solution {




public:
    unordered_map <char, int> ch1, ch2;
    bool check() {
        for (const auto &p: ch2) {
            if (ch1[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {

        for (const auto &c: t) {
            ++ch2[c];
        }

        int left=0,right=-1;
        int min_left=-1,len=s.length();

        while (right<int(s.size())){
            if(ch2.find(s[++right])!=ch2.end()){
                // s[++right] 在 string t 中
                ++ch1[s[right]];

            }
            while (check() && left<=right){
                if((right-left+1)<=len){
                    len=right-left+1;
                    min_left=left;
                }
                if(ch2.find(s[left])!=ch2.end()){
                    --ch1[s[left]];
                }
                ++left;

            }
        }

        return min_left == -1 ? string() : s.substr(min_left, len);
    }
};
// @solution-sync:end

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    auto solution = Solution();
    auto result = solution.minWindow(s, t);
    cout << result << endl;

    return 0;
}
