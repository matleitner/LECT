package aula06.Ex6_3;
import java.util.ArrayList;
import java.util.List;
import java.util.Collections;



public class Conjunto {
    private ArrayList<Integer> inteiros;
    Conjunto(){
        this.inteiros = new ArrayList<>();
    }
    
    Conjunto(ArrayList<Integer> inteiros){
        this.inteiros = inteiros;
    }
    
    ArrayList<Integer> getConjunto(){ return inteiros;} 
    
    void setConjunto(ArrayList<Integer> inteiros){ this.inteiros =  inteiros;} 
    
    
    @Override
    public String toString(){
        
        return inteiros.toString(); 
    }
    
    void insert(int n){
        if(!inteiros.contains(n))
        inteiros.add(n);}

    
    boolean contains(int n){
    
        // for(int a : inteiros){
        //     if(a==n) return true;
        // }
        // return false;


        return inteiros.contains(n);
        }


    void remove(int n)
    {
        ArrayList<Integer> ola = new ArrayList<Integer>();
        for(int num : inteiros) {if(num != n){ola.add(num);
            }
        }
        this.setConjunto(ola);
    }
    void empty(){this.setConjunto(new ArrayList<Integer>());}
    int size(){int counter = 0;
    for(int num : inteiros)counter++;
    return counter;
    }

    Conjunto unir(Conjunto conj){
        Conjunto unir = new Conjunto(new ArrayList<>());
        for(int num : inteiros )if(!conj.contains(num)){unir.insert(num);}
        
        return unir;
    }


    Conjunto subtract(Conjunto dif){
        Conjunto diferenca = new Conjunto(new ArrayList<Integer>());
        for(int num : this.getConjunto()){
            
            if(!dif.contains(num))

             diferenca.insert(num);
        }     
        for(int num1 : dif.getConjunto()){
            
            if(!this.contains(num1))

             diferenca.insert(num1);
        }       
        return diferenca;
    }


    Conjunto intersect( Conjunto interseta){
        Conjunto intersetado = new Conjunto(new ArrayList<>());
        for(int num : this.getConjunto()){
            
            if(interseta.contains(num))
                intersetado.insert(num);
            }
        return  intersetado;
    }
    public static void main(String[] args){
                    Conjunto c1 = new Conjunto();
            c1.insert(4); c1.insert(7); c1.insert(6); c1.insert(5);
            Conjunto c2 = new Conjunto();
            int[] test = { 7, 3, 2, 5, 4, 6, 7};
            for (int el : test) c2.insert(el);
            c2.remove(3); c2.remove(5); c2.remove(6);
            System.out.println(c1);
            System.out.println(c2);
            System.out.println("Número de elementos em c1: " + c1.size());
            System.out.println("Número de elementos em c2: " + c2.size());

            System.out.println("c1 contém 6?: " + ((c1.contains(6) ? "sim" : "não")));
            System.out.println("c2 contém 6?: " + ((c2.contains(6) ? "sim" : "não")));
            System.out.println("União:" + c1.unir(c2));
            System.out.println("Interseção:" + c1.intersect(c2));
            System.out.println("Diferença:" + c1.subtract(c2));
            c1.empty();
            System.out.println("c1:" + c1);
            
 
        }

}
