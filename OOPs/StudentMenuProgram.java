import java.util.ArrayList;
import java.util.Scanner;

// Student class to store student details
class Student {
    String name;
    int rollNo;
    char grade;

    // Constructor
    Student(String name, int rollNo, char grade) {
        this.name = name;
        this.rollNo = rollNo;
        this.grade = grade;
    }
}

public class StudentMenuProgram {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Student> students = new ArrayList<>();

        int choice;

        do {
            System.out.println("\n----- STUDENT MENU -----");
            System.out.println("1. Add Student");
            System.out.println("2. Display Students");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter number of students: ");
                    int n = sc.nextInt();

                    for (int i = 0; i < n; i++) {
                        sc.nextLine(); // clear buffer

                        System.out.print("Enter Name: ");
                        String name = sc.nextLine();

                        System.out.print("Enter Roll Number: ");
                        int rollNo = sc.nextInt();

                        System.out.print("Enter Grade: ");
                        char grade = sc.next().charAt(0);

                        students.add(new Student(name, rollNo, grade));
                    }
                    break;

                case 2:
                    System.out.println("\n----- STUDENT DETAILS -----");
                    System.out.printf("%-15s %-10s %-5s\n", "Name", "Roll No", "Grade");
                    System.out.println("--------------------------------");

                    for (Student s : students) {
                        System.out.printf("%-15s %-10d %-5c\n",
                                s.name, s.rollNo, s.grade);
                    }
                    break;

                case 3:
                    System.out.println("Exiting program...");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }
        } while (choice != 3);

        sc.close();
    }
}
