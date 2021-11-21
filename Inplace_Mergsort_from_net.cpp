
void Merge(int* nums, int left, int mid, int right) {
  int it2 = mid + 1;
  if (nums[mid] <= nums[it2]) {
    return;
  }
  while (left <= mid && it2 <= right) {
    while (nums[left] <= nums[it2]) { // идем пока не найдем элемент больший элемент слева чем справа
      left++;
      if (left > mid) {
        return;
      }
    }
    int temp_value = nums[it2];      // ниже просто делаем сдвиг всех элементов вправо на 1 от миньшего до большего и ставим меньший элемент на место большего
    int index = it2;
    while (index != left) {
      nums[index] = nums[index - 1];
        index--;
      }
    nums[left] = temp_value;
    left++;
    mid++;
    it2++;
  }
}

void InPlaceMergeSort (int* nums, int left, int right) {
  if (right > left) {
    int mid = left + (right - left) / 2;
    InPlaceMergeSort(nums, left, mid);
    InPlaceMergeSort(nums, mid + 1, right);
    Merge(nums, left, mid, right);
  }
}
