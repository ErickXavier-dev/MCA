class pdetail {
  int age;
  String name;

  pdetail(int a, String n) {
    age = a;
    name = n;
  }
}

class person {
  public static void main(String args[]) {
    pdetail p1 = new pdetail(21, "Alice");
    pdetail p2 = new pdetail(22, "Bob");

    System.out.println("Person 1: Name = " + p1.name + ", Age = " + p1.age);
    System.out.println("Person 2: Name = " + p2.name + ", Age = " + p2.age);
  }
}