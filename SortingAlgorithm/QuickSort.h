#ifndef QUICKSORT_H
#define QUICKSORT_H
#include"../utils/common.hpp"
/*��������*/
class QuickSort{
private:
    void Swap(vector<int>&nums,int left,int right){
        int temp=nums[left];
        nums[left]=nums[right];
        nums[right]=temp;
    }

    int partition(vector<int>&nums,int left,int right){
        int i=left,j=right;
        //��nums[left]��Ϊ��׼��
        while(i<j){
            while(i<j&&nums[left]<nums[j])j--;//���ҵ����ұȻ�׼��С��
            while(i<j&&nums[left]>nums[i])i++;//�������ұȻ�׼�����
            Swap(nums,i,j);//����������
        }
        //��j=iʱ
        Swap(nums,i,left);//������׼�����غϵĵط�����
        return i;//���ػ�׼��������
    }
public:
    void quickSort(vector<int>&nums,int left,int right){
        //�����鳤��Ϊ1ʱֹͣ
        if(left>=right)return;
        //�ڱ�����
        int pivot=partition(nums,left,right);
        //�ݹ�����������(˫������)
        quickSort(nums,left,pivot-1);
        quickSort(nums,pivot+1,right);
    }

};
/*����������λ�����Ż���*/
class QuickMidian{
private:
    /*Ԫ�ؽ���*/
    static void Swap(vector<int>&nums,int left,int right){
        int temp=nums[left];
        nums[left]=nums[right];
        nums[right]=temp; 
    }
    /*ѡȡ����Ԫ�ص���λ��*/
    static int medianThree(vector<int>&nums,int left,int mid,int right){
        //ʹ���������
        //0 ^ 0 = 1 ^ 1 = 0, 1 ^ 0 = 0 ^ 1 = 1;
        if((nums[left]<nums[mid])^(nums[left]<nums[right]))return left;//���leftָ���Ԫ��Ϊ��λ�����ͷ��ش��±�
        else if((nums[mid]<nums[left])^(nums[mid]<nums[right]))return mid;//ͬ��
        else return right;//�������
    }
    /*�ڱ�����*/
    static int partition(vector<int>&nums,int left,int right){
        //ѡȡ�������е���λ����Ϊ��׼Ԫ�ص�ǰһ��Ԫ��
        int med=medianThree(nums,left,left+(right-left)/2,right);
        //����λ�����������������
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
    /*��������*/
    static void quickSort(vector<int>&nums,int left,int right){
        if(left>=right)return;
        //���ҳ���׼Ԫ��
        int pivot=partition(nums,left,right);
        //�ݹ�����������
        quickSort(nums,left,pivot-1);
        quickSort(nums,pivot+1,right);
    }
};
/*��������β�ݹ��Ż���*/
class QuickSortTailCall{
private:
    /*Ԫ�ؽ���*/
    static void Swap(vector<int>&nums,int left,int right){
        int temp=nums[left];
        nums[left]=nums[right];
        nums[right]=temp;
    }
    /*��������*/
    static int partition(vector<int>&nums,int left,int right){
        //��nums[left]Ϊ��׼Ԫ��
        int i=left,j=right;
        while(i<j){
            while(i<j&&nums[left]<=nums[j])j--;//�ұȻ�׼С��
            while(i<j&&nums[left]>=nums[i])i++;//�ұȻ�׼���
            Swap(nums,i,j);
        }
        Swap(nums,left,i);//������׼Ԫ��
        return i;
    }
public:
    /*��������β�ݹ��Ż�*/
    void quickSort(vector<int>&nums,int left,int right){
        while(left<right){
            //�ڱ�����
            int pivot=partition(nums,left,right);
            if(pivot-left<right-pivot){//�ݹ�����������С���Ǹ�
                quickSort(nums,left,pivot-1);
                left=pivot+1;//���غ�Ϳ�ʼ������һ������
            }else{
                quickSort(nums,pivot+1,right);
                right=pivot-1;
            }
        }
    }
};

#endif