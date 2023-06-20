#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H
#include"../utils/common.hpp"
/*将数字出现的次数映射到索引来进行排序*/
void countingSortNative(vector<int>&nums){
    //创建一个数组用来计数，使此数组的下标映射为nums的元素
    //需要知道nums的最大元素值
    int m=INT_MIN;
    for(int num:nums){
        m=max(m,num);
    }
    //开始统计次数
    vector<int>counting(m+1,0);//将映射数组初始化为0
    for(int num:nums){
        counting[num]++;
    }
    //统计完成之后开始按照conuting排序
    for(int i=0,j=0;i<counting.size();i++){//遍历整个数组
        for(;counting[i]>0;counting[i]--,j++){//将相同的元素依次排序
            nums[j]=i;
        }
    }
    /*此排序适用于非负整数排序，且数组中存在大量的重复元素*/
}

/*可用于对象的计数排序，稳定排序*/
void countingSort(vector<int>&nums){
    //确定counting数组的大小
    int m=INT_MIN;
    for(int num:nums){
        m=max(num,m);
    }
    //统计次数
    vector<int>counting(m+1,0);
    for(int num:nums){
        counting[num]++;
    }
    //求coounting数组的前缀和，将“出现次数”转化为“尾索引”
    //即counting[num]-1是num在res中最后一次出现的索引
    for(int i=0;i<counting.size();i++){
        counting[i+1]+=counting[i];
    }
    //倒倒序遍历nums，使映射数组中的值放入结果数组
    int n=nums.size();
    vector<int>res(n);
    for(int i=n-1;i>=0;i--){
        int num=nums[i];
        res[counting[num]-1]=num;//将映射值填入结果数组中 
        //res[counting[nums[i]]-1]=nums[i];
        counting[num]--;//映射关系减一
    }
    //使用res数组覆盖nums数组
    nums=res;
}




#endif