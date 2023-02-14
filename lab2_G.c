#include <stdio.h>

int find_max_deduction(int arr[], int n, int k) {
  int low = 0, high = n - 1;
  
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] <= k && (mid == n - 1 || arr[mid + 1] > k)) {
      return arr[mid];
    } else if (arr[mid] > k) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  
  return -1;
}

int main(void) {
  int arr[] = {-10, -20, 30, 40, 50, 60};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 34;
  
  int result = find_max_deduction(arr, n, k);
  printf("Maximum Deduction: %d\n", result);
  
  return 0;
}


