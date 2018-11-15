package p05;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static java.time.Duration.ofMillis;
import org.junit.jupiter.api.*;
import static org.junit.jupiter.api.Assertions.*;

class ComplexTests {
    private List<Complex> cs, cs_valid;
    // epsilon for double comparisons
    private static double eps = .0001;

    // helper to test equality without relying on compareTo()
    private static void assertEqualsComplex(Complex lhs, Complex rhs) {
        assertAll("Complex equality",
                () -> assertEquals(lhs.getRealPart(), rhs.getRealPart(), eps),
                () -> assertEquals(lhs.getImaginaryPart(), rhs.getImaginaryPart(), eps)
        );
    }

    private static ArrayList<Complex> get_test_data() {
        return new ArrayList<Complex>(Arrays.asList(
                                      new Complex(3.5, 5.5),
                                      new Complex(-3.5, 1),
                                      new Complex(5),
                                      new Complex(),
                                      new Complex(0, 1)
                                      ));
    }

    @BeforeEach
    void setUp() {
        cs = get_test_data();
        cs_valid = get_test_data();
    }

    // check to see if any side effects occurred
    @AfterEach
    void tearDown() {
        cs_valid = get_test_data();
        for (int i = 0; i < cs.size(); i++) {
            assertEqualsComplex(cs.get(i), cs_valid.get(i));
        }
    }

    @Test
    @DisplayName("test1: points:5")
    void getRealPart() {
        assertTimeoutPreemptively(ofMillis(10), () -> assertAll("getRealPart",
                () -> assertEquals(3.5, cs.get(0).getRealPart(), eps),
                () -> assertEquals(-3.5, cs.get(1).getRealPart(), eps),
                () -> assertEquals(5, cs.get(2).getRealPart(), eps),
                () -> assertEquals(0, cs.get(3).getRealPart(), eps)
         ));
    }

    @Test
    void getImaginaryPart() {
        assertTimeoutPreemptively(ofMillis(10), () -> assertAll("getImaginaryPart",
            () -> assertEquals(5.5, cs.get(0).getImaginaryPart(), eps),
            () -> assertEquals(1, cs.get(1).getImaginaryPart(), eps),
            () -> assertEquals(0, cs.get(2).getImaginaryPart(), eps),
            () -> assertEquals(0, cs.get(3).getImaginaryPart(), eps)
        ));
    }

    @Test
    void abs() {
        assertEquals(6.5192, cs.get(0).abs(), eps);
        assertEquals(3.6401, cs.get(1).abs(), eps);
        assertEquals(5, cs.get(2).abs(), eps);
        assertEquals(0, cs.get(3).abs(), eps);
    }

    @Test
    void add() {
        assertEqualsComplex(cs_valid.get(3), cs.get(3).add(cs.get(3)));
        assertEqualsComplex(cs_valid.get(2), cs.get(3).add(cs.get(2)));
        assertEqualsComplex(new Complex(0, 6.5), cs.get(0).add(cs.get(1)));
    }

    @Test
    void subtract() {
        assertEqualsComplex(cs_valid.get(2), cs.get(2).subtract(cs.get(3)));
        assertEqualsComplex(cs_valid.get(3), cs.get(2).subtract(cs.get(2)));
        assertEqualsComplex(new Complex(7, 4.5), cs.get(0).subtract(cs.get(1)));
    }

    @Test
    void multiply() {
        assertEqualsComplex(cs_valid.get(3), cs.get(3).multiply(cs.get(3)));
        assertEqualsComplex(cs_valid.get(3), cs.get(2).multiply(cs.get(3)));
        assertEqualsComplex(new Complex(-17.75, -15.75), cs.get(0).multiply(cs.get(1)));
        assertEqualsComplex(new Complex(-1, 0), cs.get(4).multiply(cs.get(4)));
    }

    @Test
    void divide() {
        assertEqualsComplex(new Complex(Double.NaN, Double.NaN), cs.get(2).divide(cs.get(3)));
        assertEqualsComplex(new Complex(1, 0), cs.get(2).divide(cs.get(2)));
        assertEqualsComplex(new Complex(-.5094, -1.7169), cs.get(0).divide(cs.get(1)));
        assertEqualsComplex(new Complex(1, 0), cs.get(4).divide(cs.get(4)));
    }

    @Test
    void compareTo() {
        assertEquals(1, cs.get(0).compareTo(cs.get(1)));
        assertEquals(-1, cs.get(1).compareTo(cs.get(0)));
        assertEquals(0, cs.get(3).compareTo(cs.get(3)));
        assertEquals(0, cs.get(3).compareTo(new Complex()));
    }

    @Test
    void toStringTest() {
        assertEquals("(3.5 + 5.5i)", cs.get(0).toString());
        assertEquals("0", cs.get(3).toString());
        assertEquals("3.5556", new Complex(3.555551234).toString());
        assertEquals("(0 + 15.1234i)", new Complex(.00000001, 15.12344).toString());
    }
}
