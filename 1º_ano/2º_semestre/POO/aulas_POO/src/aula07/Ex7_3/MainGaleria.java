package aula07.Ex7_3;

import java.util.Scanner;

public class MainGaleria {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        Galeria galeria = new Galeria(100);
        int opcao = 0;
        do {
            System.out.println("\nMenu:");
            System.out.println("1. Adicionar uma obra");
            System.out.println("2. Listar obras");
            System.out.println("3. Vender uma obra");
            System.out.println("4. Calcular o lucro total");
            System.out.println("5. Sair");
            System.out.print("Opçao: ");
            opcao = sc.nextInt();
            switch (opcao) {
                case 1:
                    System.out.println("\n1. Adicionar uma obra do tipo");
                    System.out.println("1. Quadro");
                    System.out.println("2. Escultura");
                    System.out.println("3. Obra Digital (NFT)");
                    System.out.print("Tipo de produto: ");
                    int opcaoProduto = sc.nextInt();
                    sc.nextLine();
                    switch (opcaoProduto) {
                        case 1:
                            System.out.println("Tipo de produto: ");
                            int tipoDeProduto = sc.nextInt();
                            switch(tipoDeProduto){
                                case 1:

                                    break;


                                case 2:
                                    break;
                                
                                
                                case 3:
                                    break; 
                                
                                case 4:
                                    break;


                                
                            
                            
                            }

                            galeria.addObra();
                            break;
                        case 2:
                            // Adicionar uma Escultura
                            break;
                        case 3:
                            // Adicionar uma ObraDigital (i.e., NFT)
                            break;
                    }
                    break;
                case 2:
                    // Listar as obras
                    break;
                case 3:
                    // Vender uma obra
                    break;
                case 4:
                    // Apresentar o lucro total
                    break;
                case 5:
                    System.out.println("5. Sair");
                    sc.close();
                    break;
            }
        } while (opcao != 5);

        
    }
}