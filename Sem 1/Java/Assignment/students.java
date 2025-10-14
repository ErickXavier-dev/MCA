class student {
  int rollno, marks;
  String name;

  void acceptDetails(int r, String n, int m) {
    rollno = r;
    name = n;
    marks = m;
  }

  void displayDetails() {
    System.out.println("Roll Number: " + rollno);
    System.out.println("Name: " + name);
    System.out.println("Marks: " + marks);
  }

  void checkPass(int mark) {
    if (mark >= 40) {
      System.out.println(name + " has passed.");
    } else {
      System.out.println(name + " has failed.");
    }
  }
}

class students {
  public static void main(String args[]) {
    student s1 = new student();
    student s2 = new student();
    student s3 = new student();

    s1.acceptDetails(1, "Alice", 85);
    s2.acceptDetails(2, "Bob", 90);
    s3.acceptDetails(3, "Thomas", 35);

    System.out.println("Details of Student 1:");
    s1.displayDetails();
    s1.checkPass(s1.marks);

    System.out.println("\nDetails of Student 2:");
    s2.displayDetails();
    s2.checkPass(s2.marks);

    System.out.println("\nDetails of Student 3:");
    s3.displayDetails();
    s3.checkPass(s3.marks);
  }
}