package week4;

import java.util.Scanner;

public class Test {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);


        System.out.print("Enter the lower limit of the interval: ");
        int lowerLimit = scanner.nextInt();

        System.out.print("Enter the upper limit of the interval: ");
        int upperLimit = scanner.nextInt();


        System.out.println("Prime numbers between " + lowerLimit + " and " + upperLimit + ":");
        displayPrimeNumbers(lowerLimit, upperLimit);
    }


    static boolean isPrime(int number) {
        if (number <= 1) {
            return false;
        }

        for (int i = 2; i <= Math.sqrt(number); i++) {
            if (number % i == 0) {
                return false;
            }
        }

        return true;
    }


    static void displayPrimeNumbers(int lowerLimit, int upperLimit) {
        for (int i = lowerLimit; i <= upperLimit; i++) {
            if (isPrime(i)) {
                System.out.print(i + " ");
            }
        }
    }
}
