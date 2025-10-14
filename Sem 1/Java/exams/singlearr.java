class singlearr {
  public static void main(String args[]) {
    int arr[] = new int[3];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    System.out.println("Single dimentional array: ");
    for(int i = 0; i<3; i++) {
      System.out.println(arr[i]);
    }

    System.out.println("Single dimentional array1: ");
    for(int i:arr){
      System.out.println(i);
    }
  }
}