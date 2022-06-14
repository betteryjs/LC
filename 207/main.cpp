#include <bits/stdc++.h>


using namespace std;





// 拓扑排序
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> indegrees(numCourses);
        vector<vector<int>> adjancecy(numCourses,vector<int>()); // 邻接链表
        queue<int> queue;
        for (const vector<int> & cp :prerequisites) {
            indegrees[cp[0]]++; // 入度+1
            adjancecy[cp[1]].push_back(cp[0]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if(indegrees[i]==0){
                queue.push(i);
            }
        }
        while (!queue.empty()){
            int pre=queue.front();
            queue.pop();
            numCourses--;
            for (const int cur : adjancecy[pre]) {
                if(--indegrees[cur]==0) queue.push(cur);


            }



        }
        return numCourses==0;




    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
