import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;



public class Part1 {
    String v1,v2,v3,v4;
    public void lerTeclado(){
        Scanner sc = new Scanner(System.in);
        v1= sc.nextLine();
        v2= sc.nextLine();
        v3= sc.nextLine();
        v4= sc.nextLine();
        
        
        
        
        sc.close();
    }

    public void imprimir(){
        System.out.println(v1);
        System.out.println(v2);
        System.out.println(v3);
        System.out.println(v4);
        
    }
    public void lerFcheiro(){
        
    try {File file = new File("input.txt");
        Scanner sc = new Scanner(file);
        if (sc.hasNextLine()) v1 = sc.nextLine();
        if (sc.hasNextLine()) v2 = sc.nextLine();
        if (sc.hasNextLine()) v3 = sc.nextLine();
        if (sc.hasNextLine()) v4 = sc.nextLine();
    
            sc.close();
        }
    catch (FileNotFoundException e)
    {System.out.println("Erro file not find ");
        e.printStackTrace();}
    }
    public static void main(String[] args){
        Part1 p = new Part1();
        // p.lerTeclado();
        p.lerFcheiro();
        p.imprimir();
    


    }
}
