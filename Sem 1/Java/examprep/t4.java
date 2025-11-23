class counter{
  private int cnt = 0;
  public  void adder(){
    cnt++;
  }
  public  int get(){
    return cnt;
  }
}

class display{
  public static void main(String args[]) {
    counter a = new counter();

    Thread t1 = new Thread(() -> {
      for (int i = 0; i<10; i++){
        a.adder();
      }
    });

    Thread t2 = new Thread(() -> {
      for (int i = 0; i<10; i++){
        a.adder();
      }
    });

    t1.start();
    t2.start();

    try{
      t1.join();
      t2.join();
    } catch(InterruptedException e){
      System.out.println(e);
    }

    System.out.println("Value of counter: "+a.get());
  }
}