void MoveTo(int *array, int i, int j) {
  int temp = array[j];
  for (int k = j; k > i; --k) {
    array[k] = array[k - 1];
  }
  array[i] = temp;
}

void InplaceMerge(int *array, int left, int middle, int right) {
  int i = left;
  for (int j = middle; j < right; ++j) {
    for (; i < j && array[i] <= array[j]; ++i);
    MoveTo(array, i, j);
  }
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
