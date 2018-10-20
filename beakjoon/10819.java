package algorithm;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
	
	private static boolean[] visit;
	private static int[] arr;
	private static int ans = 0;
	public static void main(String[] argv) {
	
		int n = input();
		process(0, n);
		System.out.println(ans);
	}	
	public static void process(int s, int e) {
		for(int i = s; i<e; ++i) {
			for(int j = i+1 ; j<e; ++j) {
				swap(i, j);
				int cal = cal(e);
				ans = cal > ans ? cal : ans; 
				process(i+1, e);
				swap(i, j);
			}
		}
	}
	public static int cal(int n) {
		
		int sum = 0;
		for(int i = 0; i<n-1; ++i) {
			sum += Math.abs(arr[i] - arr[i+1]);
		}
		return sum;
	}
	public static void swap(int idx1, int idx2) {
		int temp = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = temp;
	}
	public static void print(int n) {
		for(int i = 0; i<n; ++i)
			System.out.print(arr[i] + " ");
		System.out.println();
	}
	
	public static int input() {
		Scanner input = new Scanner(System.in);
		
		int n = input.nextInt();
		arr = new int[n];
		visit = new boolean[n];
		
		for(int i = 0; i<n; arr[i++] = input.nextInt());
		return n;
	}
	
}

