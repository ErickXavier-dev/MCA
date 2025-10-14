class mms {
  public static void main(String args[]) {
    int arr[] = {12, 73, 28, 34, 45, 18, 45, 62, 55, 6};
    int min = arr[0], max = 0, sum = 0;

    for(int i = 0; i < 10; i++) {
      if(arr[i] > max) {
        max = arr[i];
      }
      if(arr[i] < min) {
        min = arr[i];
      }
      sum = sum + arr[i];
    }

    System.out.println("The Min from the array is: " + min);
    System.out.println("The Max from the array is: " + max);
    System.out.println("The Sum from the array is: " + sum);
  }
}