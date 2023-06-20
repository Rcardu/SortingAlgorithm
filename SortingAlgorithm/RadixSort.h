#ifndef RADIXSORT_H
#define RADIXSORT_H
#include"../utils/common.hpp"
//��ȡԪ�صĵ�kλ������exp=10^(k-1)
int digit(int num,int exp){
    return (num/exp)%10;
}

/*�������򣨸���nums�Ե�kλ��������*/
void countingSortDigit(vector<int>&nums,int exp){
    //ʮ����λ����λ0~9��Ҫ��Сλ10��Ͱ
    vector<int>counting(10,0);
    int n=nums.size();
    //ͳ��0~9���ֵĴ���
    for(int num:nums){
        int d=digit(num,exp);
        counting[d]++;
    }
    //ת��ӳ���ϵ
    for(int i=0;i<10;i++){
        counting[i+1]+=counting[i];
    }
    //�����������������res��
    vector<int>res(n,0);
    for(int i=n-1;i>=0;i--){
        //��ȡ��ǰλԪ��
        int d=digit(nums[i],exp);
        //ȡd�������е�����
        int num=counting[d]-1;
        //���������res��
        res[num]=nums[i];
        counting[d]--;
    }
    //����ԭ����
    for(int i=0;i<n;i++){
        nums[i]=res[i];
    }
}

/*�������� */
void radixSort(vector<int>&nums){
    //��ȡ���������Ԫ��
    int m=*max_element(nums.begin(),nums.end());
    //�ӵ�λ����λ��˳�����
    for(int exp=1;exp<=m;exp*=10){
        /*
        k=1 -> exp=1
        k=2 -> exp=10
        ��exp=10^(k-1)
        */
        countingSortDigit(nums,exp);
    }
}

#endif