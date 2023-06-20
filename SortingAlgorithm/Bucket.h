#ifndef BUCKET_H
#define BUCKET_H
#include"../utils/common.hpp"
void bucketSort(vector<float>&nums){
    //��ʼ��k=n/2��ͰԤ����ÿ��Ͱ�з���2��Ԫ��
    int k=nums.size()/2;
    vector<vector<float>>bucket(k);
    //������Ԫ��ӳ�䵽Ͱ��
    for(float num:nums){
        int i=k*num;//ӳ���ϵΪk*num
        bucket[i].push_back(num);
    }
    //��ÿ��Ͱ��������
    for(vector<float>&buckets:bucket){
        sort(buckets.begin(),buckets.end());
    }
    //����Ͱ������ۺ�
    int i=0;
    for(vector<float>&buckets:bucket){
        for(float num:buckets){
            nums[i++]=num;
        }
    }
}




#endif