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
            sc.nextLine();
            switch (opcao) {
                case 1:
                    System.out.println("\n1. Adicionar uma obra do tipo");
                    System.out.println("1. Quadro");
                    System.out.println("2. Escultura");
                    System.out.println("3. Obra Digital (NFT)");
                    System.out.print("Tipo de produto: ");
                    int tipoProduto = sc.nextInt();
                    sc.nextLine();
                    switch (tipoProduto) {
                        case 1:
                        System.out.println("Nome do Quadro: ");
                        String nomeDoQuadro = sc.nextLine();
                        System.out.println("Autor do Quadro: "  );
                        String autorDoQuadro = sc.nextLine();
                        System.out.println("Preço do Quadro: ");
                        int precoDoQuadro = sc.nextInt();
                        sc.nextLine();
                        System.out.println("Tipo de tinta: ");
                        String tintaDoQuadro = sc.nextLine();
                        System.out.println("Obra emoldurada? (s/n)");
                        String emolduradaPergunta = sc.nextLine();
                        boolean emoldurada = false;
                        if(emolduradaPergunta.equals("s")) emoldurada = true;
                        
                        System.out.println("Tamanho da Tela: ");
                        String tamanhoDaTela = sc.nextLine();

                        Quadro obraQuadro = new Quadro(nomeDoQuadro, autorDoQuadro, precoDoQuadro, tintaDoQuadro, emoldurada, tamanhoDaTela);
                        galeria.addObra(obraQuadro);
                        

                            break;
                        case 2:
                            // Adicionar uma Escultura
                            System.out.println("Nome do Escultura: ");
                            String nomeDoEscultura = sc.nextLine();
                            System.out.println("Autor do Escultura: "  );
                            String autorDoEscultura = sc.nextLine();
                            System.out.println("Preço do Escultura: ");
                            int precoDoEscultura = sc.nextInt();
                            sc.nextLine();
                            System.out.println("Material: ");
                            String tipoDeMadeira = sc.nextLine();
                            
                            System.out.println("Quantos exemplares foram produzidos: ");
                            int exemplaresProduzidos = sc.nextInt();
                            sc.nextLine();
                            boolean exemplares = true;
                            if(exemplaresProduzidos!=1) emoldurada = false;

                            Escultura obraEscultura = new Escultura(nomeDoEscultura, autorDoEscultura, precoDoEscultura, tipoDeMadeira, exemplares, exemplaresProduzidos);
                            galeria.addObra(obraEscultura);
                                
                            break;
                        case 3:
                            // Adicionar uma ObraDigital (i.e., NFT)
                            System.out.println("Nome do NFT: ");
                            String nomeDoNFT = sc.nextLine();
                            System.out.println("Autor do NFT: "  );
                            String autorDoNFT = sc.nextLine();
                            System.out.println("Preço do NFT: ");
                            int precoDoNFT = sc.nextInt();
                            sc.nextLine();
                            System.out.println("Nome do blockchain: ");
                            String blockchain = sc.nextLine();
                            
                            System.out.println("Endereço do Contrato: ");
                            String enderecoDoCOntrato = sc.nextLine();

                            ObraDigital obraNFT = new ObraDigital(nomeDoNFT, autorDoNFT, precoDoNFT, blockchain, enderecoDoCOntrato);
                            galeria.addObra(obraNFT);
                                
                            break;
                        }
                     break;
                    

                case 2:
                // Listar as obras
                    System.out.println(galeria);
                    break;
                case 3:
                    System.out.println("Selecione a Obra que quer vender\n" + galeria);
                    int identificadorParaVender = sc.nextInt();
                    sc.nextLine();
                    System.out.println("Por quanto? ");
                    int dinheiroVender = sc.nextInt();
                    sc.nextLine();

                    // Vender uma obra
                        galeria.vender(identificadorParaVender, dinheiroVender);
                        break;

                case 4:
                    // Apresentar o lucro total
                    System.out.println(galeria.lucro());
                    break;
                case 5:
                    System.out.println("5. Sair");
                    sc.close();
                    break;
            }
        } while (opcao != 5);
           
    }
}