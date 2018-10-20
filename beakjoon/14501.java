package algorithm;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

class Job{
	
	private int t;
	private int p;
	
	Job(int t, int p){
		this.p = p;
		this.t = t;
	}
	
	public int getT() {
		return this.t;
	}
	public int getP() {
		return this.p;
	}
	
}
public class Main {
	
	private static int ans;
	private static Job[] job;
	public static void main(String[] argv) {
		int n = input();
		process(1, 0, n);
		System.out.println(ans);
	}	
	public static void process(int idx, int val, int retire) {
	
		if(idx > retire) {
			ans = val > ans ? val : ans;
			return; 
		}
		
		int nextT = idx + job[idx].getT() ;
		if( nextT-1 <= retire) {
			process(nextT, val + job[idx].getP(), retire);
		}
		
		process(idx + 1, val, retire);
		
	}
	public static int input() {
		Scanner input = new Scanner(System.in);
		
		int n = input.nextInt();
		job = new Job[n+1];
		
		for(int i = 1; i<=n; job[i++] = new Job(input.nextInt(), input.nextInt()));
		return n;
	}
}

