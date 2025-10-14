class person {
  String name;
  person(String nme) {
    name = nme;
  }

  void getName() {
    System.out.println("Name of the person is " + name);
  }
}

class employeep extends person {
  int empid;
  employeep(int id, String nme) {
    super(nme);
    empid = id;
  }

  void getId() {
    System.out.println("Employee ID is: " + empid);
  }

  public static void main(String args[]) {
    employeep e = new employeep(123, "Gowri Parvathy Sailesh");
    e.getId();
    e.getName();
  }
}