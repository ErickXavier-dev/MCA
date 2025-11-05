#include<stdio.h>

void linear(int arr[], int size, int val) {
  for(int i=0; i<size; i++){
    if(arr[i] == val){
      printf("Value was found!");
      return;
    }
  }
  printf("Value was not found.");
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
  linear(arr,size, val);
}