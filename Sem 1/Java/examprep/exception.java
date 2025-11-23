import java.util.*;
class vexce{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();

    System.out.println("Addition Result: " + (a + b));
    System.out.println("Subtraction Result: " + (a - b));
    System.out.println("Multiplication Result: " + (a * b));

    try {
      System.out.println("Division Result: " + (a / b));
    } catch (ArithmeticException e){
      System.out.println("Error: Division by zero is not allowed.");
    }
  }
}