import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;


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
        Scanner sc = new Scanner(System.in);
        
        int linhas = Integer.parseInt(sc.nextLine());
        
        for (int i = 0; i < linhas; i++) {
            String linha = sc.nextLine();
        
            switch (i) {
                case 0:
                    v1 = Integer.parseInt(linha);
                    break;
                case 1:
                    String[] numeros = linha.split("\\s+");
                    for (String num : numeros) {
                            v2.add(Integer.parseInt(num));
                    }
                    break;
                case 2:
                    v3 = linha;
                    break;
                default:
                    v4.add(linha);
                    break;
            }
        }
        
        sc.close();
    }
        
    

    public static void lerFicheiro() {
        try {
            Scanner sc = new Scanner(new File("inputs.txt"));
            int linhas = Integer.parseInt(sc.nextLine());
    
            for (int i = 0; i < linhas; i++) {
                String linha = sc.nextLine();
    
                switch (i) {
                    case 0:
                        v1 = Integer.parseInt(linha);
                        break;
                    case 1:
                        String[] numeros = linha.split("\\s+");
                        for (String num : numeros) {
                            v2.add(Integer.parseInt(num));
                        }
                        break;
                    case 2:
                        v3 = linha;
                        break;
                    default:
                        v4.add(linha);
                        break;
                }
            }
    
            sc.close();
        } catch (FileNotFoundException e) {
            System.out.println("Ficheiro 'inputs.txt' não encontrado.");
        }
    }
    
    

    public static void imprimir() {
        System.out.println(4);  
        System.out.println(v1);

        for ( int i = 0; i < v2.size(); i++) {
            System.out.print(v2.get(i) + " ");
            if (i<v2.size()-1){
                System.out.print(" ");
            }
        }
        System.out.println();
        System.out.println(v3);
        for (String s : v4) {
            System.out.println(s);
        }
    }

    public static void main(String[] args) {
        // -----------------------------------------------------------------
        // !!! Não imprimir texto a pedir determinado input, ler direto !!!
        // -----------------------------------------------------------------

        // pode editar livremente este código
        //lerTeclado();
        lerFicheiro();
        imprimir();
    }
}
