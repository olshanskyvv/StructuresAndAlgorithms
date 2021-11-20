void Partition(int *array, int &i, int &j) {
  int pivot = array[i];
  for (int id = i; id < j; ++id) {
    while (id < j && array[id] > pivot) {
      --j;
      swap(array[id], array[j]);
    }
    if (array[id] < pivot) {
      swap(array[id], array[i]);
      ++i;
    }
  }
}

void QuickSort(int *array, int left, int right) {
  if (right - left <= 1) {
    return;
  }
  int i = left;
  int j = right;
  Partition(array, i, j);
  QuickSort(array, left, i);
  QuickSort(array, j, right);
}
