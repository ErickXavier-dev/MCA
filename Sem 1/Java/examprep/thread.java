class threx extends Thread {
  public void run() {
    for (int i = 0; i<10; i++) {
      System.out.println("Thread loop count: "+i);
    }
  }
}

class thrun {
  public static void main(String args[]) {
    threx a = new threx();
    threx b = new threx();
    
    a.start();
    b.start();
  }
}