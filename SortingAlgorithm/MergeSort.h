#ifndef MERGESORT_H
#define MERGESORT_H
#include"../utils/common.hpp"

/*�ϲ������������������*/
/*������������[left,mid]*/
/*������������[mid+1,right]*/
void mergr(vector<int>&nums,int left,int mid,int right){
    /*��ʼ���������飬��СΪ��������������ܺͣ������������ұ�����+1��������Ϊ�������������������*/
    vector<int>temp(nums.begin()+left,nums.begin()+right+1);
    /*��ʼ�������������ʼ����ֹ���������Ǹ��������������������*/
    int leftStart=left-left,leftEnd=mid-left;//����������ʼӦΪ0����������Ϊ�м�������ȥ������
    int rightStart=mid-left+1,rightEnd=right-left;//���������������������������+1�������������ȥ����������ʼ
    //i��j�ֱ�ָ��nums�������ϲ������������Ԫ��
    int i=leftStart,j=rightStart;
    //ͨ������ԭ����nums���ϲ����������� 
    for(int k=left;k<=right;k++){
        //������������Ѿ��ϲ���գ�Ҳ�����������黹��ʣ���ֱ��������������
        if(i>leftEnd)nums[k]=temp[j++];
        //�����������ϲ���ϣ�����������ʣ��������Ԫ����С����temp[i]<temp[j]���ͺϲ���ߵ���
        else if(j>rightEnd||temp[i]<=temp[j])nums[k]=temp[i++];
        //������������δ�ϲ���ϲ���temp[j]<=temp[i](Ҳ���������������)
        else nums[k]=temp[j++];
    }
}

void mergrSort(vector<int>&nums,int left,int right){
    //������Ϊ1ʱ��ֹ
    if(left>=right)return;
    //��������
    int mid=left+(right-left)/2;
    //���ҵݹ黮��
    mergrSort(nums,left,mid);
    mergrSort(nums,mid+1,right);
    //����������
    mergr(nums,left,mid,right);
}



#endif