#include<stdio.h>
void main(){
  int arr[] = {5, 4, 10, 1, 6, 2}, size = 6;
  for(int i=1; i<size; i++){
    int temp = arr[i];
    for(int j= i-1; j>=0; j--){
      if(temp<arr[j]){
        arr[j+1] = arr[j];
        arr[j] = temp;
      } else {
        arr[j+1] = temp;
        break;
      }
    }
  }

  for(int i = 0; i<size; i++){
    printf("%d ", arr[i]);
  }
}