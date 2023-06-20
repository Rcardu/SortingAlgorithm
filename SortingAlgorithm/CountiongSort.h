#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H
#include"../utils/common.hpp"
/*�����ֳ��ֵĴ���ӳ�䵽��������������*/
void countingSortNative(vector<int>&nums){
    //����һ����������������ʹ��������±�ӳ��Ϊnums��Ԫ��
    //��Ҫ֪��nums�����Ԫ��ֵ
    int m=INT_MIN;
    for(int num:nums){
        m=max(m,num);
    }
    //��ʼͳ�ƴ���
    vector<int>counting(m+1,0);//��ӳ�������ʼ��Ϊ0
    for(int num:nums){
        counting[num]++;
    }
    //ͳ�����֮��ʼ����conuting����
    for(int i=0,j=0;i<counting.size();i++){//������������
        for(;counting[i]>0;counting[i]--,j++){//����ͬ��Ԫ����������
            nums[j]=i;
        }
    }
    /*�����������ڷǸ����������������д��ڴ������ظ�Ԫ��*/
}

/*�����ڶ���ļ��������ȶ�����*/
void countingSort(vector<int>&nums){
    //ȷ��counting����Ĵ�С
    int m=INT_MIN;
    for(int num:nums){
        m=max(num,m);
    }
    //ͳ�ƴ���
    vector<int>counting(m+1,0);
    for(int num:nums){
        counting[num]++;
    }
    //��coounting�����ǰ׺�ͣ��������ִ�����ת��Ϊ��β������
    //��counting[num]-1��num��res�����һ�γ��ֵ�����
    for(int i=0;i<counting.size();i++){
        counting[i+1]+=counting[i];
    }
    //���������nums��ʹӳ�������е�ֵ����������
    int n=nums.size();
    vector<int>res(n);
    for(int i=n-1;i>=0;i--){
        int num=nums[i];
        res[counting[num]-1]=num;//��ӳ��ֵ������������ 
        //res[counting[nums[i]]-1]=nums[i];
        counting[num]--;//ӳ���ϵ��һ
    }
    //ʹ��res���鸲��nums����
    nums=res;
}




#endif