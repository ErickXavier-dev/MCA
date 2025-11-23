class throwexc{
  public static void main(String args[]) {
    try {
      validate(15);
    } catch (Exception e) {
      System.out.println(e.getMessage());
    }
  }

  public static void validate(int age) throws Exception {
    if (age < 18) {
      throw new Exception("Age is not valid to vote.");
    } else {
      System.out.println("Age is valid to vote.");
    }
  }
}