/*
Java Program using Constructors & Methods.
===========================================
Create a class Student with the instance variables name, rollNumber, and course to store data for each Student object. The class should have a parameterized constructor to initialize the instance variables with values passed during object creation. The class should also have a default constructor to create a Student object without providing initial values and setting default values for the instance variables. Define a method displayStudentDetails() which prints the details of a Student object to the console. The class should also contain an updateCourse(String course) method which modifies the course instance variable of a Student object. Write down a java program to perform the above operations using the Student object. The values for the parameterized constructor should accept from the user.
*/

import java.util.*;
class student {
  String name;
  int rollnum;
  String course;

  student() {
    name = "";
    rollnum = 0;
    course = "";
  }

  student(String n, int r, String c) {
    name = n;
    rollnum = r;
    course = c;
  }
}

class instud {
  public static void printStudentDetails(student s) {
    System.out.println("Name: "+ s.name);
    System.out.println("Roll Number: "+ s.rollnum);
    System.out.println("Course: "+s.course);
  }

  public static void updateCourse(student s, String cou) {
    s.course = cou;
  }

  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    student s = new student();
    int ch;

    System.out.print("Enter the Roll Number of the Student: ");
    s.rollnum = sc.nextInt();
    sc.nextLine();
    System.out.print("Enter the Name of the Student: ");
    s.name = sc.nextLine();
    System.out.print("Enter the Course of the Student:");
    s.course = sc.nextLine();

    while(true) {
      System.out.println("Options: ");
      System.out.println("1. Display the student.");
      System.out.println("2. Update Student Course.");
      System.out.println("3. Exit");
      System.out.println("Enter your Choice: ");
      ch = sc.nextInt();

      switch(ch) {
        case 1:
          System.out.println("------Student Details------");
          printStudentDetails(s);
          break;
        case 2:
          System.out.print("Enter new Course:");
          sc.nextLine();
          updateCourse(s, sc.nextLine());
          System.out.println("Course Updated Successfully");
          break;
        case 3:
          System.exit(0);
        default:
          System.out.println("Invalid Option.");
      }
    }
    
  }
}