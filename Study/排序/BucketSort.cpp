//
// Created by yjs on 2022/2/23.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;


class BucketSort{

public:

    void bucketSort(vector<int> & arr) {

        vector<int>::value_type maxx = *max_element(arr.begin(), arr.end());
        vector<int>::value_type minx = *min_element(arr.begin(), arr.end());
        const int bucket_size=maxx / 10 - minx / 10 + 1;;

        vector<vector<int>> bucket(bucket_size);
        // 初始化空桶
        for (int i = 0; i < bucket_size; ++i) {
            vector<int> x{0};
            bucket.push_back(x);
        }
        for (int i = 0; i < arr.size(); ++i) {
            bucket[arr[i] / 10].push_back(arr[i]);
        }
        int index = 0;
        for (int i = 0; i < bucket_size; ++i) {
            // sort of bucket
            insertSort(bucket[i]);

            for (auto it = bucket[i].begin(); it != bucket[i].end(); ++it) {
                arr[index++] = *it;

            }
        }
    }


    static void insertSort(vector<int> &arr) {
        int len = arr.size();
        for (int i = 1; i < len; ++i) {
            for (int j = i-1; j >=0 ; j--) {
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }
            }
        }
    }


};


// buckets sort
class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        int max_count=0;
        for (const int & num:nums) {
            max_count=max(max_count,++counts[num]);

        }
        // create buckets
        vector<vector<int>> buckets(max_count+1);

        for (const auto & p : counts) {

            buckets[p.second].push_back(p.first);
        }
        vector<int> ans;
        for (int i = max_count; i >=0 && ans.size()<k ; --i) {
            for(const int  & num:buckets[i]){
                ans.push_back(num);
                if(ans.size()==k){
                    break;
                }
            }
        }
        return ans;
    }



};




int main() {

    return 0;
}