#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include"../utils/common.hpp"
/*ð������ O(n^2)*/
void bubbleSort(vector<int>&nums){
    //��ѭ�����������Ԫ������Ϊn-1, n-2, ..., 1
    for(int i=nums.size();i>0;i--){
        //��ѭ��
        for(int j=0;j<i;i++){//Ҫ�Ƚ�ǰһ��Ԫ�����һ��Ԫ�أ���jȡ��i-1����
            if(nums[j]>nums[j+1]){
                //��ǰһ��Ԫ�رȺ�һ��Ԫ�ش�ʱ���ͽ���λ��
                swap(nums[j],nums[j+1]);
            }
        }
    }
}
/*ð����������Ӧ����������ȫ�����ΪO(n)*/
/*��ĳһ��ѭ����û�н��й���������ô˵�������е�Ԫ���Ѿ�����*/
void bubbleSortWithFlag(vector<int>&nums){
    //ʹ��һ����־Ϊ�����ÿһ��ѭ�����Ƿ���й�����
    for(int i=nums.size();i>0;i--){
        bool flag=false;//���λ����ʼĬ��û�н�����
        for(int j=0;j<i;j++){
            if(nums[j]>nums[j+1]){
                swap(nums[j],nums[j+1]);
                flag=true;//�����й�����������Ϊtrue
            }
        }
        //������ѭ���������жϱ����Ƿ���й�����
        if(flag==false){//������û�н��й�������˵���Ѿ�����ֱ������
            break;
        }
    }
}

#endif