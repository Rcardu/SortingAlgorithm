/*
 * @Author: Ricardo
 * @Date: 2024-04-16 16:17:01
 * @Last Modified by:   ICEY
 * @Last Modified time: 2024-04-16 16:17:01
 */
#include "SortClass.h"
namespace ICEY {

void SortAlorithm::bubbleSort(std::vector<int>& nums) {
  for (size_t idx = nums.size(); idx > 0; idx--) {
    for (size_t jdx = 0; jdx + 1 < idx; jdx++) {
      if (nums[jdx] > nums[jdx + 1]) {
        std::swap(nums[jdx], nums[jdx + 1]);
      }
    }
  }
}
/*[1.1 0.7 5.4 3.2 7.7 8.9]*/
void SortAlorithm::bucketSort(std::vector<float>& nums) {
  int k = nums.size() / 2;
  std::vector<std::vector<float>> bucket(k);
  for (float num : nums) {
    int i = k * num;
    bucket[i].push_back(num);
  }
  for (std::vector<float>& buckets : bucket) {
    std::sort(buckets.begin(), buckets.end());
  }
  int i = 0;
  for (std::vector<float>& buckets : bucket) {
    for (float num : buckets) {
      nums[i++] = num;
    }
  }
}
void SortAlorithm::countingSortNative(std::vector<int>& nums) {
  int m = INT_MIN;
  for (int num : nums) {
    m = std::max(m, num);
  }
  std::vector<int> counting(m + 1, 0);
  for (int num : nums) {
    counting[num]++;
  }
  for (int i = 0, j = 0; i < counting.size(); i++) {
    for (; counting[i] > 0; counting[i]--, j++) {
      nums[j] = i;
    }
  }
}
void SortAlorithm::countingSort(std::vector<int>& nums) {
  int m = INT_MIN;
  for (int num : nums) {
    m = std::max(num, m);
  }
  std::vector<int> counting(m + 1, 0);
  for (int num : nums) {
    counting[num]++;
  }
  for (int i = 0; i < counting.size(); i++) {
    counting[i + 1] += counting[i];
  }
  int n = nums.size();
  std::vector<int> res(n);
  for (int i = n - 1; i >= 0; i--) {
    int num = nums[i];
    res[counting[num] - 1] = num;
    counting[num]--;
  }
  nums = res;
}
void SortAlorithm::insertSort(std::vector<int>& nums) {
  for (int i = 1; i < nums.size(); i++) {
    int base = nums[i];
    int j = i - 1;
    while (j >= 0 && nums[j] > base) {
      nums[j + 1] = nums[j];
      j--;
    }
    nums[j + 1] = base;
  }
}
void SortAlorithm::mergr(std::vector<int>& nums, int left, int mid, int right) {
  std::vector<int> temp(nums.begin() + left, nums.begin() + right + 1);
  int leftStart = left - left, leftEnd = mid - left;
  int rightStart = mid - left + 1, rightEnd = right - left;
  int i = leftStart, j = rightStart;
  for (int k = left; k <= right; k++) {
    if (i > leftEnd)
      nums[k] = temp[j++];
    else if (j > rightEnd || temp[i] <= temp[j])
      nums[k] = temp[i++];
    else
      nums[k] = temp[j++];
  }
}
void SortAlorithm::mergrSort(std::vector<int>& nums, int left, int right) {
  if (left >= right)
    return;
  int mid = left + (right - left) / 2;
  mergrSort(nums, left, mid);
  mergrSort(nums, mid + 1, right);
  mergr(nums, left, mid, right);
}

void SortAlorithm::QuickSort::Swap(std::vector<int>& nums,
                                   int left,
                                   int right) {
  int temp = nums[left];
  nums[left] = nums[right];
  nums[right] = temp;
}

int SortAlorithm::QuickSort::partition(std::vector<int>& nums,
                                       int left,
                                       int right) {
  int i = left, j = right;
  while (i < j) {
    while (i < j && nums[left] <= nums[j])
      j--;
    while (i < j && nums[left] > nums[i])
      i++;
    Swap(nums, i, j);
  }
  Swap(nums, i, left);
  return i;
}
void SortAlorithm::QuickSort::quickSort(std::vector<int>& nums,
                                        int left,
                                        int right) {
  if (left >= right)
    return;
  int pivot = partition(nums, left, right);
  quickSort(nums, left, pivot - 1);
  quickSort(nums, pivot + 1, right);
}

void SortAlorithm::QuickMidian::Swap(std::vector<int>& nums,
                                     int left,
                                     int right) {
  int temp = nums[left];
  nums[left] = nums[right];
  nums[right] = temp;
}
int SortAlorithm::QuickMidian::medianThree(std::vector<int>& nums,
                                           int left,
                                           int mid,
                                           int right) {
  if ((nums[left] < nums[mid]) ^ (nums[left] < nums[right]))
    return left;
  else if ((nums[mid] < nums[left]) ^ (nums[mid] < nums[right]))
    return mid;  // ͬ��
  else
    return right;
}
int SortAlorithm::QuickMidian::partition(std::vector<int>& nums,
                                         int left,
                                         int right) {
  int med = medianThree(nums, left, left + (right - left) / 2, right);
  Swap(nums, left, med);
  int i = left, j = right;
  while (i < j) {
    while (i < j && nums[left] <= nums[j])
      j--;
    while (i < j && nums[left] >= nums[i])
      i++;
    Swap(nums, i, j);
  }
  Swap(nums, i, left);
  return i;
}
void SortAlorithm::QuickMidian::quickSort(std::vector<int>& nums,
                                          int left,
                                          int right) {
  if (left >= right)
    return;
  int pivot = partition(nums, left, right);
  quickSort(nums, left, pivot - 1);
  quickSort(nums, pivot + 1, right);
}
void SortAlorithm::QuickSortTailCall::Swap(std::vector<int>& nums,
                                           int left,
                                           int right) {
  int temp = nums[left];
  nums[left] = nums[right];
  nums[right] = temp;
}
int SortAlorithm::QuickSortTailCall::partition(std::vector<int>& nums,
                                               int left,
                                               int right) {
  int i = left, j = right;
  while (i < j) {
    while (i < j && nums[left] <= nums[j])
      j--;
    while (i < j && nums[left] >= nums[i])
      i++;
    Swap(nums, i, j);
  }
  Swap(nums, left, i);
  return i;
}

void SortAlorithm::QuickSortTailCall::quickSort(std::vector<int>& nums,
                                                int left,
                                                int right) {
  while (left < right) {
    int pivot = partition(nums, left, right);
    if (pivot - left < right - pivot) {
      quickSort(nums, left, pivot - 1);
      left = pivot + 1;
    } else {
      quickSort(nums, pivot + 1, right);
      right = pivot - 1;
    }
  }
}
int SortAlorithm::digit(int num, int exp) {
  return (num / exp) % 10;
}

void SortAlorithm::countingSortDigit(std::vector<int>& nums, int exp) {
  std::vector<int> counting(10, 0);
  int n = nums.size();
  for (int num : nums) {
    int d = digit(num, exp);
    counting[d]++;
  }
  for (int i = 0; i < nums.size() - 1; i++) {
    counting[i + 1] += counting[i];
  }
  std::vector<int> res(n, 0);
  for (int i = n - 1; i >= 0; i--) {
    int d = digit(nums[i], exp);
    int num = counting[d] - 1;
    res[num] = nums[i];
    counting[d]--;
  }
  for (int i = 0; i < n; i++) {
    nums[i] = res[i];
  }
}

void SortAlorithm::radixSort(std::vector<int>& nums) {
  int m = *max_element(nums.begin(), nums.end());
  for (int exp = 1; exp <= m; exp *= 10) {
    countingSortDigit(nums, exp);
  }
}
}  // namespace ICEY
