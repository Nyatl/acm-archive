
import java.math.BigDecimal;
import java.math.MathContext;
import java.math.RoundingMode;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h1 = sc.nextInt(), m1 = sc.nextInt();
        int h2 = sc.nextInt(), m2 = sc.nextInt();
        int h3 = sc.nextInt(), m3 = sc.nextInt();
        int n = sc.nextInt();

        MathContext mc = new MathContext(n + 500);

        BigDecimal time1 = new BigDecimal(h1 * 60 + m1);
        BigDecimal time2 = new BigDecimal(h2 * 60 + m2);
        BigDecimal time3 = new BigDecimal(h3 * 60 + m3);

        time1 = time1.divide(BigDecimal.valueOf(60), mc);
        time2 = time2.divide(BigDecimal.valueOf(60), mc);
        time3 = time3.divide(BigDecimal.valueOf(60), mc);

        time1 = BigDecimal.ONE.divide(time1, mc);
        time2 = BigDecimal.ONE.divide(time2, mc);
        time3 = BigDecimal.ONE.divide(time3, mc);

        BigDecimal ans = BigDecimal.ONE.divide(time1.add(time2).add(time3), n, RoundingMode.HALF_UP);
        
        System.out.println(ans.toString());

    }

}
