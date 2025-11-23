interface flyable{
  void fly_obj();
}

class spacecraft implements flyable{
  public void fly_obj(){
    System.out.println("This is a Spacecraft");
  }
}

class airplane implements flyable{
  public void fly_obj(){
    System.out.println("This is a airplane");
  }
}

class helicopter implements flyable{
  public void fly_obj(){
    System.out.println("This is a Helicopter");
  }
}

class flyer{
  public static void main(String args[]){
    flyable sc = new spacecraft();
    flyable ap = new airplane();
    flyable hc = new helicopter();

    sc.fly_obj();
    ap.fly_obj();
    hc.fly_obj();
  }
}