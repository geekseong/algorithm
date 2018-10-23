import java.util.HashSet;
import java.util.Scanner;


public class Main {

	private static int[] dx = {0, 1, 0, -1};
	private static int[] dy = {-1, 0, 1, 0};
	private static int[][] map = new int[5][5] ;
	private static HashSet<Integer> set = new HashSet<>();
	public static void main(String[] args) {
		
		input();
		process();
		System.out.println(set.size());
	}
	
	public static void process() {
		process(-1, -1, "", -1);
	}
	public static void process(int y, int x, String v, int left) {
		
		if(y == -1 && x == -1 && left == -1) {
			
			for(int i = 0; i<5 * 5; ++i) {
				int _y = i/5;
				int _x = i%5;
				process(_y, _x, "", 5);
			}
			return ;
		}
		
		if(left == 0) {
			String total = v + Integer.toString(map[y][x]);
			int fVal = Integer.parseInt(total);
			set.add(fVal);
			return ;
		}
		for(int i = 0; i<4; ++i) {
			int _y = y + dy[i];
			int _x = x + dx[i];
			
			if(inside(_y, _x)) {
				process(_y, _x, v+Integer.toString(map[y][x]), left - 1);
			}
		}
		
	}
	public static boolean inside(int y, int x) {
		return ( x >=0 && x < 5) && ( y >= 0 && y < 5);
	}
	public static void input() {
		Scanner input = new Scanner(System.in);
		for(int i = 0; i<5 * 5; map[i/5][i%5] = input.nextInt(), ++i);
	}
}

