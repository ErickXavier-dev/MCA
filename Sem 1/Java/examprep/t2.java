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

    System.out.println("Priority of thread a: " + a.getPriority());
    System.out.println("Priority of thread b: " + b.getPriority());
    a.setPriority(7);
    System.out.println("New priority of thread a: " + a.getPriority());
    b.setPriority(Thread.MIN_PRIORITY);
    System.out.println("New priority of thread b: " + b.getPriority());

    a.start();
    b.start();

    try{
      a.join();
    } catch(InterruptedException e){
      System.out.println(e);
    }

    System.out.println("Main thread finished execution.");
  }
}