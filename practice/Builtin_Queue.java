import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Queue;

public class Builtin_Queue {
    public static void main(String[] args) {
        Queue<Integer> queue = new ArrayDeque<Integer>();
        queue.add(1);
        System.out.println(queue.remove());
    }
}