#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#include"../utils/common.hpp"
/*��������O(n^2)�����鱾��������ʱ��ΪO(n)*/
void insertSort(vector<int>&nums){
    //�ӵڶ���Ԫ�ؿ�ʼ����
    for(int i=1;i<nums.size();i++){
        //��ȡ��׼Ԫ��
        int base=nums[i];
        //��ǰһ��Ԫ�ؿ�ʼ
        int j=i-1;
        while(j>=0&&nums[j]>base){//�����ǰԪ�رȻ�׼Ԫ�ش󣬾ͽ���Ԫ��������һλ
            nums[j+1]=nums[j];  
            j--;//ָ����һ��Ԫ��
        }//��jС��0ʱ����˵�������Ѿ����
        nums[j+1]=base;//����׼Ԫ�ز��뵽��ȷλ�ã�����ǰԪ�ص�ǰһ��λ�ã���Ϊ��ǰԪ�ص�ǰһ��Ԫ���Ѿ�����,���߲���Ҫ�ƶ���
    }
}



#endif