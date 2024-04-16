/*
 * @Author: Ricardo
 * @Date: 2024-04-16 16:17:14
 * @Last Modified by:   ICEY
 * @Last Modified time: 2024-04-16 16:17:14
 */
#include "SortClass.h"
int main() {
  std::vector<int> nums = {1, 0, 1, 2, 0, 4, 0, 2, 2, 4};
  ICEY::SortAlorithm sil;

  // 冒泡排序
  auto num1 = nums;
  sil.bubbleSort(num1);
  std::cout << "Result is:" << std::endl;
  ICEY::print(num1);

  // 桶排序
  std::vector<float> numf{0.1, 0.25, 0.28, 0.33, 0.95, 0.56, 0.77};
  auto num2 = numf;
  sil.bucketSort(num2);
  ICEY::print(num2);

  // 计数排序
  auto num3 = nums;
  sil.countingSortNative(num3);
  ICEY::print(num3);

  // 插入排序
  auto num4 = nums;
  sil.insertSort(num4);
  ICEY::print(num4);

  // 归并排序
  auto num5 = nums;
  sil.mergrSort(num5, 0, num5.size() - 1);
  ICEY::print(num5);

  // 快速排序
  ICEY::SortAlorithm::QuickSort sqs;
  auto num6 = nums;
  sqs.quickSort(num6, 0, num6.size() - 1);
  ICEY::print(num6);

  // 基数排序
  std::vector numr{53, 3, 542, 748, 14, 214, 154, 63, 616};
  sil.radixSort(numr);
  ICEY::print(numr);

  return 0;
}
