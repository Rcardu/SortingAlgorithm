#ifndef QUICKSORT_H
#define QUICKSORT_H
#include"../utils/common.hpp"
/*快速排序*/
class QuickSort{
private:
    void Swap(vector<int>&nums,int left,int right){
        int temp=nums[left];
        nums[left]=nums[right];
        nums[right]=temp;
    }

    int partition(vector<int>&nums,int left,int right){
        int i=left,j=right;
        //以nums[left]作为基准数
        while(i<j){
            while(i<j&&nums[left]<nums[j])j--;//从右到左找比基准数小的
            while(i<j&&nums[left]>nums[i])i++;//从左到右找比基准数大的
            Swap(nums,i,j);//交换这两个
        }
        //当j=i时
        Swap(nums,i,left);//交换基准数与重合的地方的数
        return i;//返回基准数的索引
    }
public:
    void quickSort(vector<int>&nums,int left,int right){
        //子数组长度为1时停止
        if(left>=right)return;
        //哨兵划分
        int pivot=partition(nums,left,right);
        //递归左右子数组(双闭区间)
        quickSort(nums,left,pivot-1);
        quickSort(nums,pivot+1,right);
    }

};
/*快速排序（中位基数优化）*/
class QuickMidian{
private:
    /*元素交换*/
    static void Swap(vector<int>&nums,int left,int right){
        int temp=nums[left];
        nums[left]=nums[right];
        nums[right]=temp; 
    }
    /*选取三个元素的中位数*/
    static int medianThree(vector<int>&nums,int left,int mid,int right){
        //使用异或运算
        //0 ^ 0 = 1 ^ 1 = 0, 1 ^ 0 = 0 ^ 1 = 1;
        if((nums[left]<nums[mid])^(nums[left]<nums[right]))return left;//如果left指向的元素为中位数，就返回此下标
        else if((nums[mid]<nums[left])^(nums[mid]<nums[right]))return mid;//同上
        else return right;//其他情况
    }
    /*哨兵划分*/
    static int partition(vector<int>&nums,int left,int right){
        //选取三个数中的中位数作为基准元素的前一个元素
        int med=medianThree(nums,left,left+(right-left)/2,right);
        //将中位数交换至数组最左端
        Swap(nums,left,med);
        int i=left,j=right;
        while(i<j){
            while(i<j&&nums[left]<=nums[j])j--;
            while(i<j&&nums[left]>=nums[i])i++;
            Swap(nums,i,j);
        }
        Swap(nums,i,left);
        return i;
    }
public:
    /*快速排序*/
    static void quickSort(vector<int>&nums,int left,int right){
        if(left>=right)return;
        //先找出基准元素
        int pivot=partition(nums,left,right);
        //递归左右子数组
        quickSort(nums,left,pivot-1);
        quickSort(nums,pivot+1,right);
    }
};
/*快速排序（尾递归优化）*/
class QuickSortTailCall{
private:
    /*元素交换*/
    static void Swap(vector<int>&nums,int left,int right){
        int temp=nums[left];
        nums[left]=nums[right];
        nums[right]=temp;
    }
    /*划分区间*/
    static int partition(vector<int>&nums,int left,int right){
        //以nums[left]为基准元素
        int i=left,j=right;
        while(i<j){
            while(i<j&&nums[left]<=nums[j])j--;//找比基准小的
            while(i<j&&nums[left]>=nums[i])i++;//找比基准大的
            Swap(nums,i,j);
        }
        Swap(nums,left,i);//交换基准元素
        return i;
    }
public:
    /*快速排序，尾递归优化*/
    void quickSort(vector<int>&nums,int left,int right){
        while(left<right){
            //哨兵划分
            int pivot=partition(nums,left,right);
            if(pivot-left<right-pivot){//递归子数组区间小的那个
                quickSort(nums,left,pivot-1);
                left=pivot+1;//返回后就开始操作另一个区间
            }else{
                quickSort(nums,pivot+1,right);
                right=pivot-1;
            }
        }
    }
};

#endif