import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    private static boolean[] eratos = new boolean[10000];
    private static boolean[] visit = new boolean[10000];

    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);


        int T = input.nextInt();

        while(T-- > 0) {

            init();

            input.nextLine();
            String from = Integer.toString(input.nextInt());
            String to = Integer.toString(input.nextInt());

            int result = BFS(from , to);
            if(result == -1){
                System.out.println("Impossible");
            }
            else{
                System.out.println(result);
            }
        }
    }
    public static int BFS(String from, String to) {

        Queue<String> q = new LinkedList<>();

        boolean end = false;
        q.offer(from);
        visit[Integer.parseInt(from)] = true;


        int ans = 0;
        while(!end && !q.isEmpty()) {

            int qSize = q.size();

            for(int i = 0; !end && i<qSize; ++i) {

                String cur = q.poll();

                if(to.equals(cur)) {
                    end = true;
                }

                for(int index = 0; !end && index <4; ++index) {
                    StringBuilder el = new StringBuilder(cur);

                    for(int j = 0; !end && j<=9; ++j) {
                        el.setCharAt(index, (char)(j + '0'));
                        int val = Integer.parseInt(el.toString());

                        if(check(val)) {

                            visit[val] = true;
                            q.offer(el.toString());
                        }
                    }
                }
            }
            if(!end)
                ++ans;
        }

        return end ? ans : -1;
    }

    public static boolean check(int val) {
        return val >= 1000 && !visit[val] && eratos[val];
    }
    public static void init() {

        for(int i = 0; i<10000; eratos[i++] = true);
        for(int i = 0; i<10000; visit[i++] = false);

        eratos[0] = eratos[1] = false;

        for(int i = 2; i<10000; ++i) {
            if(eratos[i] == true) {
                for(int j = 2; i * j < 10000; ++j) {
                    eratos[i * j] = false;
                }
            }
        }

    }
}



