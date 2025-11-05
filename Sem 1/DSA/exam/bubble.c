#include <stdio.h>
void bubble(int arr[], int size){
  int temp;
  for(int i = 0; i<size; i++) {
    for(int j = 0; j<size-i-1; j++) {
      if(arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

void main() {
  int arr[] = {9, 7, 6, 13, 17, 4, 10, 11}, size = 8;
	bubble(arr, size);
	
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
}