import java.util.Arrays;

public class FindAll{

    static int[] findall(int data[],int ind,int target,int sfi){
        if(ind == data.length){
            return new int[sfi];
        }
        if(data[ind] == target){
            int[] res = findall(data, ind+1, target, sfi+1);
            res[sfi] = ind;
            return res;
        }
        else{
            int[] res = findall(data, ind+1, target, sfi);
            return res;
        }
    }

    public static void main(String[] args) {
        int[] data = {1,34,2,4,2,3,2,3,4,9};
        System.out.println(Arrays.toString(findall(data,0,2,0)));
    }
}