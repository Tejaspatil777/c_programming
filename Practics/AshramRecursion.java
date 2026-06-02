import java.util.Scanner;

public class AshramRecursion {

    static Scanner sc = new Scanner(System.in);

    static void ashram(int count) {
        int age;
        char choice;

        System.out.print("Enter your age: ");
        age = sc.nextInt();

        if (age >= 1 && age <= 25)
            System.out.println("You are learning - BRAHMACHARYA ASHRAM");
        else if (age >= 26 && age <= 50)
            System.out.println("You are learning - GRIHAST AASHRAM");
        else if (age >= 51 && age <= 75)
            System.out.println("You are learning - VANAPRASTHA AASHRAM");
        else if (age >= 76 && age <= 100)
            System.out.println("You are learning - SANYAS AASHRAM");
        else 
             if(age< 0 )
            System.out.println("Out of KALYUG");

        while (true) {
            System.out.print("Do you want to continue? (Y/N): ");
            choice = sc.next().charAt(0);

            if (choice == 'Y' || choice == 'y') {
                ashram(count + 1);   // recursion
                return;
            }
            else if (choice == 'N' || choice == 'n') {
                System.out.println("Thank you very much");
                System.out.println("Program executed " + count + " times");
                return;
            }
            else {
                System.out.println("Incorrect Input");
            }
        }
    }

    public static void main(String[] args) {
        ashram(1);
        sc.close();
    }
}