package Parte1;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Parte1 {
    // -----------------------------------------------------
    //          !!! Não alterar este código !!!
    // -----------------------------------------------------
    private static int v1;
    private static List<Integer> v2 = new ArrayList<>();
    private static String v3;
    private static List<String> v4 = new ArrayList<>();
    // -----------------------------------------------------

    // -----------------------------------------------------------
    // >> Pode acrescentar novos métodos aqui (não é obrigatório)
    // -----------------------------------------------------------

    // pex., public static void ler(SOURCE) {}

    // -----------------------------------------------------------

    public static void lerTeclado() {
        Scanner scan =  new Scanner(System.in);
        // TODO: implementar a leitura aqui
        // pex., ler(teclado); -ou- o que lhe for mais conveniente
        int linhas = scan.nextInt();
        
        if(linhas>1){
        v1 = scan.nextInt();
        scan.nextLine();
        }
        if(linhas >2){
        String[] nums = scan.nextLine().split(" ");
        for(String  num : nums){
            while(!num.isEmpty())
                v2.add(Integer.parseInt(num));
        }}

        if(linhas>3){

         v3 = scan.nextLine();
        }
        if(linhas> 4){
         String[] p = scan.nextLine().split(" ");
        for(String word : p){
            v4.add(word);
        }
        scan.close();
    }}
    
    public static void lerFicheiro() {
        // TODO: implementar a leitura aqui
        // pex., ler(ficheiro); -ou- o que lhe for mais conveniente
        
        try {
            File file = new File("inputs.txt");
            Scanner sc = new Scanner(file);
        
            if (sc.hasNextLine()) {
                v1 = sc.nextInt();
                sc.nextLine();
            }
            if (sc.hasNextLine()){ 
                String[] nums = sc.nextLine().split(" ");
                for(String a : nums) {
                    v2.add(Integer.parseInt(a));
                }
        }
            if (sc.hasNextLine()) v3 = sc.nextLine();

            if (sc.hasNextLine()) 
            {String[] words = sc.nextLine().split(" ");
            for (String w : words){
                    v4.add(w);
                }
            }
            
            sc.close();
            }
    catch (FileNotFoundException e)
        {
            System.out.println("Ficheiro não encontrado");
            e.printStackTrace();
        }
    }


    public static void imprimir() {
        // TODO: implementar a impressão aqui
        System.out.println(v1);
        for(int num: v2){
            System.out.print(num + " ");
        }

        System.out.println(v3);

        for(String palavra : v4){
            System.out.println(palavra + " ");
        }
    }

    public static void main(String[] args) {
        // -----------------------------------------------------------------
        // !!! Não imprimir texto a pedir determinado input, ler direto !!!
        // -----------------------------------------------------------------

        // pode editar livremente este código
        // lerTeclado();
        lerFicheiro();
        imprimir();
    }
}
