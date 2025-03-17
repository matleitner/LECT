package aula03;
import java.util.Scanner;

public class AltoBaixo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Loop para jogar múltiplas vezes
        while (true) {
            System.out.println("Vamos jogar AltoBaixo! Eu pensei em um número de 1 a 100.");
            
            // Gera um número aleatório entre 1 e 100
            int numeroAleatorio = (int) (Math.random() * 100 + 1);
            int tentativas = 0;
            int palpite = 0;

            // Loop para o jogo em si
            while (palpite != numeroAleatorio) {
                System.out.print("Tente adivinhar o número (de 1 a 100): ");
                // Verifica se a entrada é um número inteiro válido
                while (!sc.hasNextInt()) {
                    System.out.println("Entrada inválida! Digite um número inteiro.");
                    sc.next(); // Descartar a entrada inválida
                }
                palpite = sc.nextInt(); // Lê a tentativa do usuário
                tentativas++; // Incrementa o contador de tentativas

                // Verifica o palpite do usuário
                if (palpite < numeroAleatorio) {
                    System.out.println("O número que eu pensei é maior do que isso...");
                } else if (palpite > numeroAleatorio) {
                    System.out.println("O número que eu pensei é menor do que isso...");
                } else {
                    System.out.println("Parabéns! Você acertou o número!");
                    System.out.println("Número de tentativas: " + tentativas);
                }
            }

            // Pergunta se o jogador deseja continuar
            System.out.println("Deseja jogar novamente? (Digite 'S' para sim ou qualquer outra tecla para sair)");
            String resposta = sc.next().toUpperCase(); // Lê a resposta e converte para maiúsculas

            if (!(resposta.equals("SIM") || resposta.equals("S"))) {
                System.out.println("Obrigado por jogar! Até a próxima!");
                break; // Sai do loop e termina o programa
            }
        }

        sc.close(); // Fecha o scanner
    }
}
