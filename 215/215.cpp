//
// Created by yjs on 2022/2/22.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;












class QuickSort {
public:
public:

    static void pprint(const string str, const vector<int> num) {
        cout << str << " [ ";
        for_each(num.begin(), num.end() - 1, [](const int a) { cout << a << " ,"; });
        cout << *(num.end() - 1) << " ]";
        cout << endl;
    }

    void maxHeapify(vector<int> &arr, int i, int heapSize) {
        while (2*i+1<=heapSize){
            int leftChild=(2*i)+1,rightChild=(2*i)+2,target=leftChild;
            if(rightChild <=heapSize && arr[rightChild]> arr[leftChild]){
                target=rightChild;
            }


            if(arr[target] > arr[i]){
                swap(arr[target],arr[i]);

            }else{
                break;
            }
            i=target;



        }


    }

    void maxHeapify2(vector<int>& a, int i, int heapSize) {
        int l = i * 2 + 1, r = i * 2 + 2, largest = i;
        if (l <= heapSize && a[l] > a[largest]) {
            largest = l;
        }
        if (r <= heapSize && a[r] > a[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(a[i], a[largest]);
            maxHeapify2(a, largest, heapSize);
        }
    }









    void build_heap(vector<int> &arr, int size) {
        for (int i =  size/2; i >= 0; i--) {
            maxHeapify2(arr, i, size);
        }
    }

    void heap_sort(vector<int> & arr) {
        int len=arr.size()-1;
        build_heap(arr, len);
        for (int i = len ; i >=1; i--) {
            swap(arr[i], arr[0]);
            len--;
            maxHeapify2(arr, 0, len);
        }
    }







    void comparator(vector<int> &arr) {
        sort(arr.begin(), arr.end());

    }

    vector<int> generateRandomArray(int maxSize, int maxValue) {

        uniform_real_distribution<> u(0,1);
        uniform_int_distribution<unsigned > u2(0,maxValue + 1);
        default_random_engine e;
        vector<int> arr(maxSize*u(e));
        for (int i = 0; i < arr.size(); i++) {
            arr[i]=u2(e);
        }
        return arr;


    }


    void run() {
        int testTime = 500000;
        int maxSize = 100; // 随机数组的长度0～100
        int maxValue = 100;// 值：-100～100
        bool succeed = true;
        for (int i = 0; i < testTime; i++) {
            vector<int> arr = generateRandomArray(maxSize, maxValue);

            vector<int> arr1(arr);
            vector<int> arr2(arr);
            this->heap_sort(arr1);
            comparator(arr2);
            if (arr1!=arr2) {
                // 打印arr1
                // 打印arr2
                succeed = false;
                for (int j = 0; j < arr.size(); j++) {
                    cout << arr[j] <<  " ";
                }
                cout << endl;
                break;
            }
        }
        cout << (succeed? "Nice!" : "Fucking fucked!")<<endl;
        vector<int> arr = generateRandomArray(maxSize, maxValue);
        pprint("arr before ",arr);
        this->heap_sort(arr);
        pprint("arr after",arr);
    }




};
class CheckSort{
private:
    function<void(vector<int>&)> functionSort;
public:
    CheckSort(const function<void(vector<int>&)> & function ) :functionSort(function){};
    static void pprint(const string str, const vector<int> num) {
        cout << str << " [ ";
        for_each(num.begin(), num.end() - 1, [](const int a) { cout << a << " ,"; });
        cout << *(num.end() - 1) << " ]";
        cout << endl;
    }
    friend QuickSort;




public:

    void comparator(vector<int> &arr) {
        sort(arr.begin(), arr.end());
    }

    vector<int> generateRandomArray(int maxSize, int maxValue) {

        uniform_real_distribution<> u(0,1);
        uniform_int_distribution<unsigned > u2(0,maxValue + 1);
        default_random_engine e;
        vector<int> arr(maxSize*u(e));
        for (int i = 0; i < arr.size(); i++) {
            arr[i]=u2(e);
        }
        return arr;


    }


    void run() {
        int testTime = 500000;
        int maxSize = 100; // 随机数组的长度0～100
        int maxValue = 100;// 值：-100～100
        bool succeed = true;
        for (int i = 0; i < testTime; i++) {
            vector<int> arr = generateRandomArray(maxSize, maxValue);

            vector<int> arr1(arr);
            vector<int> arr2(arr);
            this->functionSort(arr1);
            comparator(arr2);
            if (arr1!=arr2) {
                // 打印arr1
                // 打印arr2
                succeed = false;
                for (int j = 0; j < arr.size(); j++) {
                    cout << arr[j] <<  " ";
                }
                cout << endl;
                break;
            }
        }
        cout << (succeed? "Nice!" : "Fucking fucked!")<<endl;
        vector<int> arr = generateRandomArray(maxSize, maxValue);
        pprint("arr before ",arr);
        this->functionSort(arr);
        pprint("arr after",arr);
    }

};


int main() {
    vector<int> nums4{2, 3, 56, 89, 26, 65, 19, 16, 23};

    QuickSort quickSort;


//    QuickSort::pprint("in", nums4);
//    // 2*O(n/2)+O(n)  ==> O(n*log(n))
//    quickSort.quickSort1(nums4);
//    QuickSort::pprint("out", nums4);
    quickSort.run();
//    quickSort
    return 0;
}