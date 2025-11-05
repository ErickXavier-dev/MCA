#include <stdio.h>
void insertion(int arr[], int size){
  for(int i=1; i<size; i++){
    int key = arr[i];
    for(int j=i-1; j>0; j--) {
      if(arr[j]>key){
        arr[j+1] = arr[j];
        arr[j] = key
      } else {
        arr[j+1] = key;
        break;
      }
    }
  }
}

void main() {
	int arr[] = {9, 7, 6, 13, 17, 4, 10, 11}, size = 8;
	insertion(arr, size);
	
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
}
