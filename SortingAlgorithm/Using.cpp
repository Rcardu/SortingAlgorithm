#include"../utils/common.hpp"
#include"QuickSort.h"
int main(){

    vector<int>nums,a,b,c;
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
    printVector(c);
    



    while(getchar()!='\n')
    continue;
    getchar();
    return 0;
}