import java.util.*;
class jagged{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int rw;
    System.out.print("Enter the row size for 2D-Array: ");
    rw = sc.nextInt();

    int arr[][] = new int[rw][];

    for(int i = 0; i<rw; i++) {
      System.out.print("Enter the size of row "+i+" : ");
      arr[i] = new int[sc.nextInt()];
    }

    System.out.println("Enter values to the array: ");
    for(int i = 0; i<rw; i++) {
      for(int j = 0; j<arr[i].length; j++){
        arr[i][j] = sc.nextInt();
      }
    }

    System.out.println("Values inside 2D Array: ");
    for(int i = 0; i<rw; i++) {
      for(int j = 0; j<arr[i].length; j++){
        System.out.print(arr[i][j]+" ");
      }
      System.out.println();
    }
  }
}