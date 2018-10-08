import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	
	private static boolean[] eratos = new boolean[4000001];
	private static ArrayList<Integer> primeSet = new ArrayList<>();
	public static void main(String[] args) {
	
		
		int N = input();
		setPrimeSet();
		process(N);
	}
	public static void process(int n) {
		
		int ans = 0;
		int s = 0, e = 0;
		int subSum = primeSet.get(e);
		while( s <= e && e < primeSet.size()) {
			if(subSum == n) {
				++ans;
				subSum += primeSet.get(++e);
			}
			else if (subSum > n) {
				subSum -= primeSet.get(s++);
			}
			else if(subSum < n){
				if(e + 1 < primeSet.size())
					subSum += primeSet.get(++e);
				else
					break;
			}
		}
		
		System.out.println(ans);
	}

	
	public static int input() {
		Scanner input = new Scanner(System.in);
		return  input.nextInt();
	}
	
	public static void setPrimeSet() {
		
		
		primeSet.add(2);
		
		long start = System.currentTimeMillis();
		for(int i = 3; i<=4000000; i+=2 ) {
			if(eratos[i] == false) {
				//System.out.println(i);
				primeSet.add(i);
				for(int j = 1; i*j <= 4000000; ++j ) {
					eratos[i*j] = true;
				}
			}
		}	
		
	}

}

