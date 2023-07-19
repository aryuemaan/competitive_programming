import java.util.*;

public class HelloClass {

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            // System.out.print();
            String input = scanner.nextLine();

            int rank = findRank(input);
            System.out.println(rank);
        }
    }

    public static int findRank(String input) {
        int len = input.length();
        int rank = 1;
        int factor = 1;
        for (int i = len - 1; i >= 0; i--) {
            char currChar = input.charAt(i);
            int smallerChars = 0;
            for (int j = i + 1; j < len; j++) {
                if (input.charAt(j) < currChar) {
                    smallerChars++;
                }
            }
            rank += smallerChars * factor;
            factor *= len - i;
        }
        return rank;
    }
}
