#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include"../utils/common.hpp"
/*冒泡排序 O(n^2)*/
void bubbleSort(vector<int>&nums){
    //外循环，待排序的元素数量为n-1, n-2, ..., 1
    for(int i=nums.size();i>0;i--){
        //内循环
        for(int j=0;j<i;i++){//要比较前一个元素与后一个元素，即j取到i-1即可
            if(nums[j]>nums[j+1]){
                //当前一个元素比后一个元素大时，就交换位置
                swap(nums[j],nums[j+1]);
            }
        }
    }
}
/*冒泡排序（自适应）当数组完全有序可为O(n)*/
/*当某一轮循环中没有进行过交换，那么说明数组中的元素已经有序*/
void bubbleSortWithFlag(vector<int>&nums){
    //使用一个标志为来标记每一轮循环中是否进行过交换
    for(int i=nums.size();i>0;i--){
        bool flag=false;//标记位，初始默认没有交换过
        for(int j=0;j<i;j++){
            if(nums[j]>nums[j+1]){
                swap(nums[j],nums[j+1]);
                flag=true;//若进行过交换就设置为true
            }
        }
        //当本轮循环结束后判断本轮是否进行过交换
        if(flag==false){//当本轮没有进行过交换，说明已经有序，直接跳出
            break;
        }
    }
}

#endif