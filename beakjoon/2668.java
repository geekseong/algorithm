import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Scanner;

public class Main {

	private static int[] visit;
	private static int[] numList;
	private static ArrayList<Integer> ansSet;
	
	public static void main(String[] args){
		
		input();
		process();
	}
	public static void process() {
		
		int numbering = 0;
		
		for(int i = 1; i<numList.length; ++i) {
			if(i == numList[i]) {
				visit[i] = ++numbering;
				ansSet.add(i);
			}
		}
	
		for(int i = 1; i<numList.length; ++i) {
			if(visit[i] == 0) {
				 DFS(i, ++numbering); 
			}
		}
		
		Collections.sort(ansSet);
		
		System.out.println(ansSet.size());
		for(int i = 0; i<ansSet.size(); ++i) {
			System.out.println(ansSet.get(i));
		}
		
	}
	public static void DFS(int index, int numbering) {
	
		visit[index] = numbering;
		int next = numList[index];
		 
		//방문하지 않은 노드
		if(visit[next] == 0) { 
			visit[next] = numbering;
			DFS(next, numbering);
		}
		
		// 방문했지만 사이클인 경우
		// 사이클에 포함된 노드를 모두 찾아냄
		else if(visit[next] == numbering) {
			ansSet.add(index);
			int cNext = next;
			while(index != cNext ) {
				ansSet.add(cNext);
				cNext = numList[cNext];
			}
		}
	}

	public static void input() {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		
		numList = new int[n+1];
		visit = new int[n + 1];
		ansSet = new ArrayList<Integer>();
		for(int i = 1; i<=n; numList[i++] = input.nextInt()) ;
		
	}
	
}

