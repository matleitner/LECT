package aula06.Ex6_3;
import java.util.ArrayList;
public class Conjunto {
    private ArrayList<Integer> inteiros;

    Conjunto(ArrayList<Integer> inteiros){
        this.inteiros = new ArrayList<>();
    }
    void insert(int n){
        if(!inteiros.contains(n))
        inteiros.add(n);}

    boolean contains(int n){
        for(int a : inteiros){
            if(a==n) return true;
        }
        return false;
    }
    void remove(int n){for(int num : inteiros) {if(num == n){inteiros.remove(num);}}}
    void empty(){for(int num : inteiros) {inteiros.remove(num);}}
    @Override
    public String toString(){
        for (int num: inteiros) System.out.print(num + " ");
        return ""; 
    }
    int size(){int counter = 0;
    for(int num : inteiros)counter++;
    return counter;
    }

    Conjunto unir(Conjunto conj){
        for(int num : inteiros )if(!conj.contains(num)){conj.add(num);}
        return inteiros; 
    }
}
