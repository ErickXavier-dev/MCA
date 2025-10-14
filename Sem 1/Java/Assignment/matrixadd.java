class matrixadd {
  public static void main(String args[]) {
    int arr[][] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arr1[][] = {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}};

    System.out.println("The sum of the two matrices is: ");

    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        System.out.print(arr[i][j] + arr1[i][j] + " ");
      }
      System.out.println();
    }
  }
}