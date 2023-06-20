#ifndef RADIXSORT_H
#define RADIXSORT_H
#include"../utils/common.hpp"
//获取元素的第k位，其中exp=10^(k-1)
int digit(int num,int exp){
    return (num/exp)%10;
}

/*计数排序（根据nums对第k位进行排序*/
void countingSortDigit(vector<int>&nums,int exp){
    //十进制位长度位0~9需要大小位10的桶
    vector<int>counting(10,0);
    int n=nums.size();
    //统计0~9出现的次数
    for(int num:nums){
        int d=digit(num,exp);
        counting[d]++;
    }
    //转化映射关系
    for(int i=0;i<10;i++){
        counting[i+1]+=counting[i];
    }
    //倒序遍历，放入结果集res中
    vector<int>res(n,0);
    for(int i=n-1;i>=0;i--){
        //先取当前位元素
        int d=digit(nums[i],exp);
        //取d在数组中的索引
        int num=counting[d]-1;
        //将结果放入res中
        res[num]=nums[i];
        counting[d]--;
    }
    //覆盖原数组
    for(int i=0;i<n;i++){
        nums[i]=res[i];
    }
}

/*基数排序 */
void radixSort(vector<int>&nums){
    //获取数组中最大元素
    int m=*max_element(nums.begin(),nums.end());
    //从低位到高位的顺序遍历
    for(int exp=1;exp<=m;exp*=10){
        /*
        k=1 -> exp=1
        k=2 -> exp=10
        即exp=10^(k-1)
        */
        countingSortDigit(nums,exp);
    }
}

#endif