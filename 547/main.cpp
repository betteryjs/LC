#include <vector>
#include <iostream>

using namespace std;

// @solution-sync:begin
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int count=0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if(!visited[i]){
                dfs(isConnected,i,visited);
                ++count;
            }

        }
        return count;
    }


    void dfs(vector<vector<int>>& isConnected, int i, vector<bool>& visited) {
        visited[i]= true;
        for (int j = 0; j < isConnected.size(); ++j) {
            if(isConnected[i][j]==1 && !visited[j]){
                dfs(isConnected,j,visited);
            }
        }




    }
};
// @solution-sync:end

int main() {
    vector<vector<int>> isConnected = {
            {1, 1, 0},
            {1, 1, 0},
            {0, 0, 1}
    };

    auto solution = Solution();
    auto result = solution.findCircleNum(isConnected);
    cout << result << endl;

    return 0;
}
