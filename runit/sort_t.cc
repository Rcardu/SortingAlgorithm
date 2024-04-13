#include "SortClass.h"
int main() {
  /*vector<int>nums,a,b,c;
  nums={2,4,1,0,3,5};
  a=nums;
  b=nums;
  c=nums;
  QuickSort as;
  as.quickSort(a,0,a.size()-1);
  cout<<"���������˳��Ϊ��"<<endl;
  printVector(a);

  QuickMidian bs;
  bs.quickSort(b,0,b.size()-1);
  cout<<"���������˳��Ϊ��"<<endl;
  printVector(b);

  QuickSortTailCall cs;
  cs.quickSort(c,0,c.size()-1);
  cout<<"���������˳��Ϊ��"<<endl;
  printVector(c);*/
  /*vector<int>nums={7,3,2,6,0,1,5,4};
  mergrSort(nums,0,nums.size()-1);
  cout<<"�����Ϊ�� "<<endl;
  printVector(nums);*/

  std::vector<int> nums = {1, 0, 1, 2, 0, 4, 0, 2, 2, 4};
  ICEY::SortAlorithm sil;
  sil.bubbleSort(nums);
  std::cout << "Result is:" << std::endl;
  for (int num : nums)
    std::cout << num << " ";

  while (getchar() != '\n')
    ;
  return 0;
}
