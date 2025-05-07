import java.util.*;

@FunctionalInterface
interface MyNum {
    int getNum(int n);
    
}
public class teste {
    public static void main(String[] args){
        // String s1 = "123";
        // System.out.println(s1.matches("\\d{0,4}"));
        // Person p = new Person("Martim", 0);
        // System.out.println(p.name);

        // int ola = 1;
        // switch(ola){
        //     case 12: case 1: System.out.println("oi"); break;
        //     default: System.out.println("Adeus"); break;
        // }
        // String s1 = "Aveiro";
        // String s2 = "Aveiro";
        // System.out.println(s1.equals(s2) ? "Iguais" : " Diferentes"); System.out.println
        // (s1.equalsIgnoreCase(s2) ? "Iguais" : " Diferentes ");
        // System.out.println(s1.compareTo(s2));
        MyNum n1 = (x) -> x+1;
        System.out.println(n1.getNum(10));
    }
}