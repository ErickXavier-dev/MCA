class catd {
  int age;
  String name;

  catd() {
    age = 0;
    name = "Unknown";
  }

  void displayDetails() {
    System.out.println("Cat Name: " + name);
    System.out.println("Cat Age: " + age);
  }
}

class cat {
  public static void main(String args[]) {
    catd c1 = new catd();
    
    System.out.println("Details of Cat 1:");
    c1.displayDetails();
  }
}