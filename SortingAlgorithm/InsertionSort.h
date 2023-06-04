#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#include"../utils/common.hpp"
/*插入排序O(n^2)当数组本来就有序时，为O(n)*/
void insertSort(vector<int>&nums){
    //从第二个元素开始排序
    for(int i=1;i<nums.size();i++){
        //获取基准元素
        int base=nums[i];
        //从前一个元素开始
        int j=i-1;
        while(j>=0&&nums[j]>base){//如果当前元素比基准元素大，就将此元素向右移一位
            nums[j+1]=nums[j];  
            j--;//指向下一个元素
        }//当j小于0时，就说明排序已经完成
        nums[j+1]=base;//将基准元素插入到正确位置（即当前元素的前一个位置，因为当前元素的前一个元素已经右移,或者不需要移动）
    }
}



#endif