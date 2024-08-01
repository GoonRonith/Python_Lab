package week5;

import java.util.Scanner;

public class ReverseNumbers {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Declare an array to store the integers
        int[] numbers = new int[10];

        // Read ten integers from the user
        System.out.println("Enter ten integers:");

        for (int i = 0; i < 10; i++) {
            System.out.print("Enter integer #" + (i + 1) + ": ");
            numbers[i] = scanner.nextInt();
        }

        // Display the integers in reverse order
        System.out.println("\nIntegers in reverse order:");

        for (int i = 9; i >= 0; i--) {
            System.out.println(numbers[i]);
        }

        // Close the Scanner
        scanner.close();
    }
}

