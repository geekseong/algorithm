import java.util.Arrays;
import java.util.Scanner;

public class Main {

    private final static int BEER_NUM = 20;

    private static boolean searchOk;
    private static int  arrSize;
    private static int[][] storeCord, graph;
    private static boolean[] visit;

    public static void main(String[] args){

        Scanner input = new Scanner(System.in);
        int T = input.nextInt();

        while(T-- > 0) {

            init();

            int storeNum = input.nextInt();
            arrSize = storeNum + 2;
            storeCord = new int[2][arrSize];
            visit = new boolean[arrSize];

            //출발점좌표, 편의점의 좌표, 페스티벌 장소의 좌표가 저장되어 있음.
            //0 => x좌표, 1 => y 좌표
            for (int i = 0; i < arrSize; ++i) {
                storeCord[0][i] = input.nextInt();
                storeCord[1][i] = input.nextInt();
            }

            //(페스티벌을 포함함) 각 편의점 사이의 거리를 저장하는 좌표
            graph = new int[arrSize][arrSize];
            for (int i = 0; i < arrSize; Arrays.fill(graph[i++], 0)) ;

            //모든 좌표간의 거리들을 계산
            for (int i = 0; i < arrSize; ++i) {

                int px = storeCord[0][i];
                int py = storeCord[1][i];

                for (int j = 0; j < arrSize; ++j) {

                    if (i != j) {
                        int tx = storeCord[0][j];
                        int ty = storeCord[1][j];

                        graph[i][j] = graph[j][i] = Math.abs(px - tx) + Math.abs(py - ty);
                    }
                }
            }

            searchPath(0);
            if(searchOk)
                System.out.println("happy");
            else
                System.out.println("sad");
        }
    }
    public static void init(){
        searchOk = false;
        storeCord = graph = null;
        visit = null;

    }

    public static void searchPath(int index){

        if(searchOk || index == arrSize -1){
            searchOk = true;
            return ;
        }

        visit[index] = true;

        for(int i = 0; i < arrSize; ++i){
            if(i != index && canVisit(index, i)){
                int spendBeer = (graph[index][i] + 49) / 50;
                searchPath(i);
            }
        }
    }
    public static boolean canVisit(int from, int to){

        //to 를 방문하지 않았고, from -> to 로 남은 맥주로 갈 수 있으면
        return !visit[to] && (graph[from][to] <= 50 * BEER_NUM);
    }
}

