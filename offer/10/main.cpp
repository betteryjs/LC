//
// Created by yjs on 2022/1/6.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    // time O(n) space O(1)
public:
    int mod = 1e9+7;
    int fib(int n) {
        if(n<2){
            
        }
        int a=0,b=1,sum;
        for (int i = 0; i < n; ++i) {
            sum=(a+b) % mod;
            a=b;
            b=sum;
        }
        return b;
    }
};


class Solution2 {
    static int cache[110];
public:
//    const static int count = 110;
    int mod = 1e9+7;

    int fib(int n){
        if(n<=1){
            return n;
        }
        if(cache[n]!=0){

            return cache[n];

        }

        cache[n]= fib(n-1)+ fib(n-2);
        cache[n]%=mod;
        return cache[n];


    }

};

class Solution3 {



public:
    const int MOD = 1000000007;

    vector<vector<long>> pow(vector<vector<long>> &a,int n){

        vector<vector<long>> ret{{1, 0}, {0, 1}};

        while (n>0){
            if(n&1){  // n 为基数
                ret= multiply(ret,a);
            }
            n>>=1;  // n/=2
            a= multiply(a,a);
        }
        return  ret;


    }


    vector<vector<long>> multiply(vector<vector<long>>& a, vector<vector<long>>& b) {
        vector<vector<long>> c{{0,0},{0,0}};
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                c[i][j]=(a[i][0]*b[0][j]+a[i][1]*b[1][j])%MOD;
            }
        }
        return c;
    }


    int fib(int n){
        if (n<2){
            return n;
        }
        vector<vector<long>> q{{1,1},{1,0}};
        vector<vector<long>> res=pow(q,n-1);
        return res[0][0];
    }
};

int main(){

    Solution3 go;

    int res= go.fib(25);


    cout<< res<<endl;



    return 0;

}