import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
	
	private static int[] arr;
	public static void main(String[] argv) {
		
		input();
		process();
	}	
	public static void process() {
		
		int index = -1;
		ArrayList<Integer> list = new ArrayList<>();
		
		list.add(arr[arr.length-1]);
		for(int i = arr.length-2; i>=0; --i) {
		
			list.add(arr[i]);
			if(arr[i] < arr[i+1]) {
				index = i;
				break;
			}
		}
		
		if(list.size() == arr.length && index == -1) {
			System.out.println(-1);
			return ;
		}
		
		int val = arr[index];
		Collections.sort(list);
		
		for(int i = 0; i<list.size(); ++i) {
			if(list.get(i) == val) {
				val = list.get(i+1);
				list.remove(i+1);
				break;
			}
		}	
		
		for(int i = 0; i<index; System.out.print(arr[i++]+ " "));
		System.out.print(val+" ");
		for(int i = 0; i<list.size(); System.out.print(list.get(i++)+" "));
		
	}
	public static void input() {
		
		Scanner input = new Scanner(System.in);
		
		int n = input.nextInt();
		
		arr = new int[n];
		for(int i = 0 ; i< n; arr[i++] = input.nextInt());
		
	}
	
}

