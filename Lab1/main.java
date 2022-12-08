/*  This is my Java program that uses an array of structs/objects that store student information 
Created by Delvis Burgos                      */

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    ArrayList<Student> students = new ArrayList<Student>();

    /* This is to enter the student(s) information */
    Scanner scan = new Scanner(System.in);
    System.out.println("Would you like to enter a student:(yes/no)");
    String option = scan.nextLine();
    while (option.equalsIgnoreCase("yes")) {
      System.out.println("Enter student's first name:");
      String fname = scan.nextLine();
      System.out.println("Enter student's last name:");
      String lname = (scan.nextLine());
      System.out.println("Enter student's age:");
      String age = scan.nextLine();
      System.out.println("Enter student's grade level:");
      String grade = scan.nextLine();
      System.out.println("Enter student's gpa");
      float gpa = scan.nextFloat();

      scan.nextLine();
      Student student = new Student(fname, lname, age, gpa, grade);
      students.add(student);
      System.out.println("Would you like to enter another student:(yes/no)");
      option = scan.nextLine();
    }
    /* This uses user input to decide to display the inputed information */
    if (option.equalsIgnoreCase("no")) {
      System.out.println("Do you want to dispay the inputed students? (yes/no");
      String display = scan.nextLine();
      if (display.equalsIgnoreCase("yes")) {
        for (Student entrie : students) {
          System.out.println(entrie.getFname() + " " + entrie.getLname() + " | " + entrie.getAge() + " | " + entrie.getGpa() + " | " + entrie.getGrade());
        }

      }
    } else {
      System.out.println("option not availabe");
      System.exit(0);
    }

    /*  This allows the user to search for a user that was inputed, uploading the results of the Student's information */
    System.out.println("Type student's first name to search: ");
    String firstName = scan.nextLine();
    for (Student entrie : students) {
      if (entrie.getFname().contains(firstName)) {
        System.out.println(entrie.getFname() + " " + entrie.getLname() + " | " + entrie.getAge() + " | " + entrie.getGpa() + " | " + entrie.getGrade());
      }
    }

    /*  This allows the user to search for a grade of a student that was inputed, uploading the results of the Student's information */
    System.out.println("Type student's grade level to search: ");
    String gradeLev = scan.nextLine();
    for (Student entrie : students) {
      if (entrie.getGrade().contains(gradeLev)) {
        System.out.println(entrie.getFname() + " " + entrie.getLname() + " | " + entrie.getAge() + " | " + entrie.getGpa() + " | " + entrie.getGrade());
      }
    }
  }
}

/* Using structures/objects within the Student class */
class Student {
  private String fname;
  private String lname;
  private String age;
  private float gpa;
  private String grade;

  public Student(String fname, String lname, String age, float gpa, String grade) {
    this.fname = fname;
    this.lname = lname;
    this.age = age;
    this.gpa = gpa;
    this.grade = grade;
  }

  public String getFname() {
    return fname;
  }

  public String getLname() {
    return lname;
  }

  public String getAge() {
    return age;
  }

  public float getGpa() {
    return gpa;
  }

  public String getGrade() {
    return grade;
  }
}
