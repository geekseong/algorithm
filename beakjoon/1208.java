import java.util.Scanner;

public class Main {

	
	private static int N, S;
	private static int[] list;
	private static long [] dp = new long[8000001];
	private final static int MAX_VAL = 4000000, MIN_VAL = -4000000;
	
	
	public static void main(String[] argv) {
	
		input();
		process();
		System.out.println(dp[convertToCurr(S)]);
	}
	
	public static void process() {
		
		
		// minus -> , plus <-
		
		for(int i = 0; i<N; ++i) {
			int el = list[i];
			
			if(el <= 0) {
				for(int j = MIN_VAL + Math.abs(el); j <= MAX_VAL; ++j) {
					int idx = convertToCurr(j);
					
					dp[idx + el] += dp[idx];
					if(el == j) ++dp[idx];
					
				}
			}
			else if(el > 0) {
				for(int j = MAX_VAL - el; j>=MIN_VAL; --j) {
					int idx = convertToCurr(j);
					
					dp[idx + el] += dp[idx];
					if(el == j) ++dp[idx];
				}
			}
		}
		
//		for(int i = -1000000; i<=1000000; i+=100000) {
//			int cIdx = convertToCurr(i);
//			System.out.print("["+i+"]"+dp[cIdx] +" ");
//		}
	}
	public static int convertToCurr(int v) {
		return MAX_VAL + v;
	}
	public static void input() {
		Scanner input = new Scanner(System.in);
		N = input.nextInt();
		S = input.nextInt();
		
		list = new int[N + 1];
		for(int i = 0; i<N; list[i++] = input.nextInt());
	}
}
