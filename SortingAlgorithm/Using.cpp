#include"../utils/common.hpp"
#include"QuickSort.h"
#include"MergeSort.h"
#include"CountiongSort.h"
#include"RadixSort.h"
int main(){

    /*vector<int>nums,a,b,c;
    nums={2,4,1,0,3,5};
    a=nums;
    b=nums;
    c=nums;
    QuickSort as;
    as.quickSort(a,0,a.size()-1);
    cout<<"快速排序后顺序为："<<endl;
    printVector(a);

    QuickMidian bs;
    bs.quickSort(b,0,b.size()-1);
    cout<<"快速排序后顺序为："<<endl;
    printVector(b);

    QuickSortTailCall cs;
    cs.quickSort(c,0,c.size()-1);
    cout<<"快速排序后顺序为："<<endl;
    printVector(c);*/
    /*vector<int>nums={7,3,2,6,0,1,5,4};
    mergrSort(nums,0,nums.size()-1);
    cout<<"排序后为： "<<endl;
    printVector(nums);*/

    vector<int>nums={1,0,1,2,0,4,0,2,2,4};
    radixSort(nums);
    cout<<"排序后的数组为:"<<endl;
    for(int num:nums)cout<<num<<" ";



    while(getchar()!='\n')
    continue;
    getchar();
    return 0;
}