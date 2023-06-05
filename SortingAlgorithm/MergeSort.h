#ifndef MERGESORT_H
#define MERGESORT_H
#include"../utils/common.hpp"

/*合并左子数组和右子数组*/
/*左子数组区间[left,mid]*/
/*右子数组区间[mid+1,right]*/
void mergr(vector<int>&nums,int left,int mid,int right){
    /*初始化辅助数组，大小为这两个子数组的总和，即右子数组右闭区间+1，从索引为左子数组的左区闭区间*/
    vector<int>temp(nums.begin()+left,nums.begin()+right+1);
    /*初始化左子数组的起始与终止索引，就是辅助数组的左子数组索引*/
    int leftStart=left-left,leftEnd=mid-left;//左子数组起始应为0，结束索引为中间索引减去左索引
    int rightStart=mid-left+1,rightEnd=right-left;//右子数组索引就是左子数组结束+1，到右子数组减去左子数组起始
    //i，j分别指向nums数组来合并左、右子数组的元素
    int i=leftStart,j=rightStart;
    //通过覆盖原数组nums来合并左右子数组 
    for(int k=left;k<=right;k++){
        //如果左子数组已经合并完闭，也就是右子数组还有剩余就直接填入右子数组
        if(i>leftEnd)nums[k]=temp[j++];
        //如果右子数组合并完毕，左子数组有剩余或者左边元素最小（即temp[i]<temp[j]）就合并左边的数
        else if(j>rightEnd||temp[i]<=temp[j])nums[k]=temp[i++];
        //如果两个数组均未合并完毕并且temp[j]<=temp[i](也就是右子数组更大)
        else nums[k]=temp[j++];
    }
}

void mergrSort(vector<int>&nums,int left,int right){
    //当区间为1时终止
    if(left>=right)return;
    //划分区间
    int mid=left+(right-left)/2;
    //左右递归划分
    mergrSort(nums,left,mid);
    mergrSort(nums,mid+1,right);
    //排序子数组
    mergr(nums,left,mid,right);
}



#endif