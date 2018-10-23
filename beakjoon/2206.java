import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Node{
	public int y;
	public int x;
	public int step;
	public int chance;
	
	Node(int y, int x, int step, int chance){
		this.step = step;
		this.x = x;
		this.y = y;
		this.chance = chance;
	}
}

public class Main {
	

	private static int[] dx = {0, 1, 0, -1};
	private static int[] dy = {-1, 0, 1, 0};
	private static int N, M;
	private static int[][] map;
	private static int[][][] visit;
	
	
	public static void main(String[] args) throws IOException{

		input();
		process();
		
	}
	
	public static void process() {
		
		int ans = -1;
		boolean end = false;
		Queue<Node> q = new LinkedList<Node>();
		q.offer(new Node(0, 0, 1, 1));
		map[0][0] = 1;
		
		while(!end && !q.isEmpty() ) {
			
			int size = q.size();
			
			for(int i = 0; !end && i<size; ++i) {
				Node node = q.poll();
				if(node.x == M-1 && node.y == N-1) {
					ans = node.step;
					end = true;
				}
				
				for(int j= 0; !end && j<4; ++j) {
					int _x = node.x + dx[j];
					int _y = node.y + dy[j];
					if(inside(_y, _x)) {
						if(map[_y][_x] == 0 && visit[_y][_x][node.chance] == 0) {
							visit[_y][_x][node.chance] = 1;
							q.offer(new Node(_y, _x, node.step + 1, node.chance));
						}
						else if(map[_y][_x] == 1 && visit[_y][_x][node.chance] == 0 && node.chance == 1) {
							visit[_y][_x][0] = 1;
							q.offer(new Node(_y, _x, node.step + 1, 0));		
						}
					}
				}
			}
		}
		System.out.println(ans);
		
	}
	
	public static boolean inside(int y, int x) {
		return ((x >= 0 && x < M) && (y >=0 && y < N));
	}
	
	public static void input() {
		Scanner input = new Scanner(System.in);
		
		N = input.nextInt();
		M = input.nextInt();
		
		map = new int[N][M];
		visit = new int[N][M][2];
		
		input.nextLine();
		
		for(int i = 0; i<N; ++i) {
			String str = input.nextLine();
			for(int j = 0; j<M; ++j) {
				map[i][j] = str.charAt(j)-'0';
			}
		}
		
		//mapPrint();
	}
	public static void mapPrint() {
		for(int i = 0; i<N * M; ++i) {
			if(i%M == 0)
				System.out.println();
			System.out.print(map[i/M][i%M]);
		}
	}
}
