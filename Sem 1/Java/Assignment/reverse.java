class reverse {
  public static void main(String args[]) {
    int num = 123, rev = 0, temp;

    System.out.println("The number before reversal is: " + num);

    while(num != 0) {
      temp = num % 10;
      rev = (rev * 10) + temp;
      num = num / 10;
    }

    System.out.println("The number after reversal is: " + rev);
  }
}