package p05;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static java.time.Duration.ofMillis;
import org.junit.jupiter.api.*;
import static org.junit.jupiter.api.Assertions.*;

class ComplexTests {
    private List<Complex> cs;
    private static List<Complex> cs_const;
    // epsilon for double comparisons
    private static double eps = .0001;

    // helper to test equality without relying on compareTo()
    private static void assertEqualsComplex(Complex lhs, Complex rhs) {
        assertAll("Complex equality",
                () -> assertEquals(lhs.getRealPart(), rhs.getRealPart(), eps),
                () -> assertEquals(lhs.getImaginaryPart(), rhs.getImaginaryPart(), eps)
        );
    }

    // create an unmodifiableList with the same elements to check for size effects after each test
    @BeforeAll
    static void init() {
        cs_const = Collections.unmodifiableList(Arrays.asList(
                new Complex(3.5, 5.5),
                new Complex(-3.5, 1),
                new Complex(5),
                new Complex(),
                new Complex(0, 1)
        ));
    }

    @BeforeEach
    void setUp() {
        cs = new ArrayList<>(Arrays.asList(
                new Complex(3.5, 5.5),
                new Complex(-3.5, 1),
                new Complex(5),
                new Complex(),
                new Complex(0, 1)
        ));
    }

    // check against const list to see if any side effects occurred
    @AfterEach
    void tearDown() {
        for (int i = 0; i < cs.size(); i++) {
            assertEqualsComplex(cs.get(i), cs_const.get(i));
        }
    }

    @Test
    @DisplayName("points:2.5")
    void getRealPart() {
        assertTimeoutPreemptively(ofMillis(10), () -> assertAll("getRealPart",
                () -> assertEquals(3.5, cs.get(0).getRealPart(), eps),
                () -> assertEquals(-3.5, cs.get(1).getRealPart(), eps),
                () -> assertEquals(5, cs.get(2).getRealPart(), eps),
                () -> assertEquals(0, cs.get(3).getRealPart(), eps)
         ));
    }

    @Test
    @DisplayName("points:2.5")
    void getImaginaryPart() {
        assertTimeoutPreemptively(ofMillis(10), () -> assertAll("getImaginaryPart",
            () -> assertEquals(5.5, cs.get(0).getImaginaryPart(), eps),
            () -> assertEquals(1, cs.get(1).getImaginaryPart(), eps),
            () -> assertEquals(0, cs.get(2).getImaginaryPart(), eps),
            () -> assertEquals(0, cs.get(3).getImaginaryPart(), eps)
        ));
    }

    @Test
    @DisplayName("points:5")
    void abs() {
        assertEquals(6.5192, cs.get(0).abs(), eps);
        assertEquals(3.6401, cs.get(1).abs(), eps);
        assertEquals(5, cs.get(2).abs(), eps);
        assertEquals(0, cs.get(3).abs(), eps);
    }

    @Test
    @DisplayName("points:5")
    void add() {
        assertEqualsComplex(cs_const.get(3), cs.get(3).add(cs.get(3)));
        assertEqualsComplex(cs_const.get(2), cs.get(3).add(cs.get(2)));
        assertEqualsComplex(new Complex(0, 6.5), cs.get(0).add(cs.get(1)));
    }

    @Test
    @DisplayName("points:5")
    void subtract() {
        assertEqualsComplex(cs_const.get(2), cs.get(2).subtract(cs.get(3)));
        assertEqualsComplex(cs_const.get(3), cs.get(2).subtract(cs.get(2)));
        assertEqualsComplex(new Complex(7, 4.5), cs.get(0).subtract(cs.get(1)));
    }

    @Test
    @DisplayName("points:10")
    void multiply() {
        assertEqualsComplex(cs_const.get(3), cs.get(3).multiply(cs.get(3)));
        assertEqualsComplex(cs_const.get(3), cs.get(2).multiply(cs.get(3)));
        assertEqualsComplex(new Complex(-17.75, -15.75), cs.get(0).multiply(cs.get(1)));
        assertEqualsComplex(new Complex(-1, 0), cs.get(4).multiply(cs.get(4)));
    }

    @Test
    @DisplayName("points:10")
    void divide() {
        assertEqualsComplex(new Complex(Double.NaN, Double.NaN), cs.get(2).divide(cs.get(3)));
        assertEqualsComplex(new Complex(1, 0), cs.get(2).divide(cs.get(2)));
        assertEqualsComplex(new Complex(-.5094, -1.7169), cs.get(0).divide(cs.get(1)));
        assertEqualsComplex(new Complex(1, 0), cs.get(4).divide(cs.get(4)));
    }

    @Test
    @DisplayName("points:5")
    void compareTo() {
        assertEquals(1, cs.get(0).compareTo(cs.get(1)));
        assertEquals(-1, cs.get(1).compareTo(cs.get(0)));
        assertEquals(0, cs.get(3).compareTo(cs.get(3)));
        assertEquals(0, cs.get(3).compareTo(new Complex()));
    }

    @Test
    @DisplayName("points:5")
    void toStringTest() {
        assertEquals("(3.5 + 5.5i)", cs.get(0).toString());
        assertEquals("0", cs.get(3).toString());
        assertEquals("3.5556", new Complex(3.555551234).toString());
        assertEquals("(0 + 15.1234i)", new Complex(.00000001, 15.12344).toString());
    }
}