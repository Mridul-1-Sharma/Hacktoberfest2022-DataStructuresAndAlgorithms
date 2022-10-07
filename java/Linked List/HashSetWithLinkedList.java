import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class HashSetWithLinkedList {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter total input size: ");
        int n = sc.nextInt();

        List<Integer> hashSet = new LinkedList<>();

        for(int ii = 0; ii < n; ii++){
            int input = sc.nextInt();
            if(!hashSet.contains(input)) {
                hashSet.add(input);
            }
        }

        for(Object o: hashSet) {
            System.out.println(o);
        }

        sc.close();
    }
}