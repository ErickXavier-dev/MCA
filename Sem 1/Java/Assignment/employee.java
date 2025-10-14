class empd {
  int empid, salary;
  String empname;

  void getEmp(int id, String name, int sal) {
    empid = id;
    empname = name;
    salary = sal;
  }

  void printemp() {
    System.out.println("Employee ID: " + empid);
    System.out.println("Employee Name: " + empname);
    System.out.println("Employee Salary: " + salary);
  }
}

class employee {
  public static void main(String args[]) {
    empd e1 = new empd();

    e1.getEmp(101, "John", 50000);

    System.out.println("Details of Employee 1:");
    e1.printemp();
  }
}