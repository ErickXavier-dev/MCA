import java.util.*;
class table {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    int a;
    System.out.print("Enter a number to print its table:");
    a = sc.nextInt();
    for (int i = 1; i <= 10; i++){
      System.out.println(a +" * " + i + " = " + a*i);
    }
  }
}