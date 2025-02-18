package aula02;

import java.util.Scanner;

public class Ex2_2 {public static void main(String[] args) {
        // Cria o objeto Scanner para ler a entrada do usuário
        Scanner sc = new Scanner(System.in);
        
        // Lê uma linha de texto
        System.out.print("Digite seu nome: ");
        String nome = sc.nextLine();
        
        // Lê um número inteiro
        System.out.print("Digite sua idade: ");
        int idade = sc.nextInt();
        
        // Exibe as informações lidas
        System.out.println("Olá, " + nome + "! Você tem " + idade + " anos.");
        
        // Fecha o scanner para liberar os recursos
        sc.close();
    }
}
