import pack.calculator;
public class adder {
    public static void main(String[] args) {
        calculator calc = new calculator();
        int sum = calc.add(5, 3);
        System.out.println("Sum: " + sum);
    }
}