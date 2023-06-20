#ifndef BUCKET_H
#define BUCKET_H
#include"../utils/common.hpp"
void bucketSort(vector<float>&nums){
    //初始化k=n/2个桶预期向每个桶中分配2个元素
    int k=nums.size()/2;
    vector<vector<float>>bucket(k);
    //将数组元素映射到桶中
    for(float num:nums){
        int i=k*num;//映射关系为k*num
        bucket[i].push_back(num);
    }
    //对每个桶进行排序
    for(vector<float>&buckets:bucket){
        sort(buckets.begin(),buckets.end());
    }
    //遍历桶将结果聚合
    int i=0;
    for(vector<float>&buckets:bucket){
        for(float num:buckets){
            nums[i++]=num;
        }
    }
}




#endif