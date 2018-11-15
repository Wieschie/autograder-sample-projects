package p05;

import java.text.DecimalFormat;

public class Complex implements Cloneable, Comparable<Complex> {
    private double a, b;
    private static DecimalFormat df = new DecimalFormat("#.####");

    public Complex() {
        a = 0;
        b = 0;
    }

    public Complex(double a) {
        this.a = a;
        b = 0;
    }

    public Complex(double a, double b) {
        this.a = a;
        this.b = b;
    }

    public double getRealPart() { return a; }

    public double getImaginaryPart() { return b; }

    public double abs() { return Math.sqrt(Math.pow(a, 2) + Math.pow(b, 2)); }

    public Complex add(Complex rhs) { return new Complex(a + rhs.a, b + rhs.b); }

    public Complex subtract(Complex rhs) {
        return new Complex(a - rhs.a, b - rhs.b);
    }

    public Complex multiply(Complex rhs) {
        return new Complex(a * rhs.a - b * rhs.b, b * rhs.a + a * rhs.b);
    }

    public Complex divide(Complex rhs) {
        return new Complex((a * rhs.a + b * rhs.b) / (Math.pow(rhs.a, 2) + Math.pow(rhs.b, 2)),
                (b * rhs.a - a * rhs.b) / (Math.pow(rhs.a, 2) + Math.pow(rhs.b, 2)));
    }

    @Override
    public int compareTo(Complex rhs) {
        return Double.compare(this.abs(), rhs.abs());
    }

    @Override
    public String toString() {
        if (b != 0)
            return String.format("(%s + %si)", df.format(a), df.format(b));
        return df.format(a);
    }
}
