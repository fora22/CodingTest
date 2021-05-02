import java.util.*;

class CodingTest11_6{
    public static void main(String[] args){
        int[] food_times = {3,1,2,5,2};
        int k = 10;
        k = k+1;
        while_1 : while(true){
            for(int l = 0; l < food_times.length; l++){
                food_times[l] -= 1;
                k -= 1;
                if(food_times[l] == 0){
                    for(int cpt = 0; cpt < food_times.length-1; cpt++){
                        food_times[cpt] = food_times[cpt+1];
                    }
                    food_times = Arrays.copyOf(food_times, food_times.length-1);
                    l -= 1;
                }
                if(k == 0){
                    System.out.println(l);
                    break while_1;
                }
            }
        }
    }
}