class csb{
  int cnt;
  void added(){
    synchronized(this){
      cnt++;
    }
  }
  int get(){
    synchronized(this){
      return cnt;
    }
  }
}

class dsb{
  public static void main(String args[]) {
    csb c1 = new csb();

    Thread t1 = new Thread(() ->{
      for(int i = 0; i<10; i++){
        c1.added
      }
    })
  }
}