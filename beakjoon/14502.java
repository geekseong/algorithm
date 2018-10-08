package com.company;


import java.util.ArrayList;
import java.util.Scanner;

public class Main {


    private static int ans;
    private static int[] dx = {0, 1, 0, -1};
    private static int[] dy = {-1, 0, 1, 0};
    private static int col, row;
    private static int[][] map;
    private static ArrayList<Integer> virus;

    public static void main(String[] args){

        input();
        process();
    }
    public static void process(){

        buildWall(0, 3);
        System.out.println(ans);
    }

    public static void buildWall(int index, int leftWall){

        if(leftWall == 0){
            influence();
            return ;
        }

        for(int i = index; i<row * col ; ++i){

            int y = i / col;
            int x = i % col;
            if(map[y][x] == 0){
                map[y][x] = 1;
                buildWall(index + 1, leftWall - 1);
                map[y][x] = 0;
            }
        }
    }

    public static void influence(){

        // 바이러스 퍼트리기
        fillmap(2);

        // 안전한 면적 구하기
        getSafeArea();

        // 원래 상태로 복구
        fillmap(0);
        for(int i = 0; i<virus.size(); ++i){
            map[virus.get(i)/col][virus.get(i)%col] = 2;
        }

    }
    public static void getSafeArea(){

        int count = 0;
        for(int i = 0; i<row * col; ++i){
            if(map[i/col][i%col] == 0)
                ++count;
        }

        ans = count > ans ? count : ans;
    }
    public static void fillmap(int type){
        for(int i = 0; i<virus.size(); ++i){

            int index = virus.get(i);
            int y = index/col;
            int x = index%col;

            influence(y, x, type);
        }
    }
    private static void influence(int y, int x, int type){

        map[y][x] = type;

        for(int i = 0; i<4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];


            // type == 2이면 바이러스 퍼트리기
            if (type == 2 && inside(ny, nx) && map[ny][nx] == 0) {
                influence(ny, nx, type);
            }

            //type == 0 이면 map 원상복구
            if (type == 0 && inside(ny, nx) && map[ny][nx] == 2) {
                influence(ny, nx, type);
            }

        }

    }

    public static boolean inside(int y, int x){

        return (x >= 0 && x < col) && (y >=0 && y < row);
    }
    public static void input(){
        Scanner input = new Scanner(System.in);

        row = input.nextInt();
        col = input.nextInt();
        map = new int[row][col];
        virus = new ArrayList<>();

        for(int i = 0; i<row * col; ++i){

            int type = input.nextInt();
            map[i/col][i%col] = type;
            if( type == 2){
                virus.add(i);
            }
        }
    }

    public static void print(){
        for(int i = 0 ; i<row * col; ++i){

            if(i % col == 0)
                System.out.println();

            System.out.print(map[i/col][i%col]+" ");

        }
    }
}

