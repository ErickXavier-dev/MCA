abstract class bank {
  abstract void interest();
}

class sbi extends bank{
  void interest(){
    System.out.println("SBI Interest is 7%");
  }
}

class boi extends bank {
  void interest() {
    System.out.println("BOI Interest is 8%");
  }
}

class imoney{
  public static void main(String args[]){
    bank b;
    b = new sbi();
    b.interest();
    b = new boi();
    b.interest();
  }
}