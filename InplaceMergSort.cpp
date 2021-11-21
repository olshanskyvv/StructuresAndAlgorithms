void Reverse(int *arr, int left, int right) {
  for (int i = 0; left + i < right - i - 1; ++i) {
    swap(arr[left + i], arr[right - i - 1]);
  }
}

void ArraySwap(int *arr, int left, int &middle, int right) {
  Reverse(arr, left, right);
  middle = right + left - middle;
  Reverse(arr, left, middle);
  Reverse(arr, middle, right);
}

int LowerBound(const int *arr, int left, int right, int value) {
  if (right - left <= 1) {
    if (arr[left] >= value) {
      return left;
    }
    return right;
  }
  int middle = (right - left) / 2 + left;
  if (arr[middle] >= value) {
    return LowerBound(arr, left - 1, middle, value);
  }
  return LowerBound(arr, middle, right, value);
}

void InplaceMerge(int *array, int left, int middle, int right) {
  if (right - middle < 1 || middle - left < 1) {
    return;
  }
  if (right - middle == 1 && middle - left == 1) {
    if (array[left] > array[middle]) {
      swap(array[left], array[middle]);
    }
    return;
  }
  int x_id = (middle - left) / 2 + left;
  int x = array[x_id];
  int lb_id = LowerBound(array, middle, right, x);
  ArraySwap(array, x_id, middle, lb_id);
  InplaceMerge(array, left, x_id, middle);
  InplaceMerge(array, middle + 1, lb_id, right);
}

void InplaceMergeSort(int *array, int left, int right) {
  if (right - left <= 1) {
    return;
  }
  int middle = (right - left) / 2 + left;
  InplaceMergeSort(array, left, middle);
  InplaceMergeSort(array, middle, right);
  InplaceMerge(array, left, middle, right);
}
