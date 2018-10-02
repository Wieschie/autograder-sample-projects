package p05;

import java.util.InputMismatchException;
import java.util.Scanner;

public class EX13_17 {

    public static void main(String[] args) {
        Complex c1, c2;
        try (Scanner input = new Scanner(System.in)) {
            System.out.print("Enter the first complex number: ");
            c1 = new Complex(input.nextDouble(), input.nextDouble());
            System.out.print("Enter the second complex number: ");
            c2 = new Complex(input.nextDouble(), input.nextDouble());
        }
        catch (InputMismatchException ex) {
            System.out.println("Please enter whitespace delimited decimal values for a and b");
            throw ex;
        }

        System.out.printf("%s + %s = %s%n", c1, c2, c1.add(c2));
        System.out.printf("%s - %s = %s%n", c1, c2, c1.subtract(c2));
        System.out.printf("%s * %s = %s%n", c1, c2, c1.multiply(c2));
        System.out.printf("%s / %s = %s%n", c1, c2, c1.divide(c2));
        System.out.printf("|%s| = %f%n", c1, c1.abs());
    }
}