import java.util.*;
class multiarr{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int rw, sw;
    System.out.print("Enter the row size for 2D-Array: ");
    rw = sc.nextInt();
    System.out.print("Enter the column size for 2D-Array: ");
    sw = sc.nextInt();

    int arr[][] = new int[rw][sw];

    System.out.println("Enter values to the array: ");
    for(int i = 0; i<rw; i++) {
      for(int j = 0; j<sw; j++){
        arr[i][j] = sc.nextInt();
      }
    }

    System.out.println("Values inside 2D Array: ");
    for(int i = 0; i<rw; i++) {
      for(int j = 0; j<sw; j++){
        System.out.print(arr[i][j]+" ");
      }
      System.out.println();
    }
  }
}