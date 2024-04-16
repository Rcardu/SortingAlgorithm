/*
 * @Author: Ricardo
 * @Date: 2024-04-13 21:48:05
 * @Last Modified by: ICEY
 * @Last Modified time: 2024-04-16 16:21:08
 */
#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

namespace ICEY {
class SortAlorithm {
 public:
  /*冒泡排序*/
  void bubbleSort(std::vector<int>& nums);

  /*桶排序*/
  void bucketSort(std::vector<float>& nums);
  /*计数排序*/
  void countingSortNative(std::vector<int>& nums);
  // 计数排序
  void countingSort(std::vector<int>& nums);
  // 插入排序
  void insertSort(std::vector<int>& nums);
  // 归并排序
  void mergr(std::vector<int>& nums, int left, int mid, int right);
  void mergrSort(std::vector<int>& nums, int left, int right);

 public:
  /*快速排序*/
  class QuickSort {
   private:
    void Swap(std::vector<int>& nums, int left, int right);
    int partition(std::vector<int>& nums, int left, int right);

   public:
    void quickSort(std::vector<int>& nums, int left, int right);
  };
  class QuickMidian {
   private:
    void Swap(std::vector<int>& nums, int left, int right);
    int medianThree(std::vector<int>& nums, int left, int mid, int right);
    int partition(std::vector<int>& nums, int left, int right);

   public:
    void quickSort(std::vector<int>& nums, int left, int right);
  };
  class QuickSortTailCall {
   private:
    void Swap(std::vector<int>& nums, int left, int right);
    int partition(std::vector<int>& nums, int left, int right);

   public:
    void quickSort(std::vector<int>& nums, int left, int right);
  };

 public:
  // 基数排序
  int digit(int num, int exp);
  void countingSortDigit(std::vector<int>& nums, int exp);
  void radixSort(std::vector<int>& nums);
};
template <class T>
void print(const T& val) {
  for (const auto& i : val) {
    std::cout << i << " ";
  }
  std::cout << "\n";
}
}  // namespace ICEY
