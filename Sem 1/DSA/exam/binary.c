#include <stdio.h>
int binary(int arr[], int size, int val){ 
  int low = 0, high = size-1, mid;
  while(low<=high){
    mid = (low+high)/2;
    if(arr[mid] == val){
      return mid;
    }
    if(arr[mid]>val){
      high = mid-1;
    } else if(arr[mid]<val){
      low = mid+1;
    }
  }
  return -1;
}

int main() {
  int size,val;
  printf("Enter the size for the array: ");
  scanf("%d",&size);
  int arr[size];

  for(int i=0; i<size; i++){
    printf("Enter the value for %dth position: ", i);
    scanf("%d", &arr[i]);
  }

  printf("Enter the value to be found: ");
  scanf("%d", &val);
  int pos = binary(arr,size, val);
  if (pos!= -1){
    printf("Value found at position %d: ", pos+1);
  } else {
    printf("Value was not found.");
  }
}