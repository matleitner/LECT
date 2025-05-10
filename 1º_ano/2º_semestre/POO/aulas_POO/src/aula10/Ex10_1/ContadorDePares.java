package aula10.Ex10_1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Map;
import java.util.HashMap;
import java.util.Scanner;

public class ContadorDePares {

    public static void main(String[] args) {
        String nomeArquivo = "major.txt";
        
        Map<String, Map<String, Integer>> pares = contarParesArquivo(nomeArquivo);
        
        if (pares != null) {
            exibirResultados(pares);
        }
    }

    public static Map<String, Map<String, Integer>> contarParesArquivo(String nomeArquivo) {
        Map<String, Map<String, Integer>> pares = new HashMap<>();
        
        String separadores = "[\\t\\n.,:'‘’;?!-*{}=+&/()\\[\\]”“\"']";
        
        try (Scanner scanner = new Scanner(new File(nomeArquivo))) {
            String palavraAnterior = null;
            while (scanner.hasNext()) {
                String palavra = scanner.next();
                
                palavra = palavra.replaceAll(separadores, "").toLowerCase();

                if (palavra.length() >= 3) {
                    if (palavraAnterior != null) {
                        pares.putIfAbsent(palavraAnterior, new HashMap<>());
                        Map<String, Integer> paresDaPalavraAnterior = pares.get(palavraAnterior);
                        paresDaPalavraAnterior.put(palavra, paresDaPalavraAnterior.getOrDefault(palavra, 0) + 1);
                    }

                    palavraAnterior = palavra;
                }
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            return null;
        }

        return pares;
    }

    public static void exibirResultados(Map<String, Map<String, Integer>> pares) {
        for (Map.Entry<String, Map<String, Integer>> entry1 : pares.entrySet()) {
            String palavra1 = entry1.getKey();
            for (Map.Entry<String, Integer> entry2 : entry1.getValue().entrySet()) {
                String palavra2 = entry2.getKey();
                int contagem = entry2.getValue();
                System.out.printf("%s={%s=%d}%n", palavra1, palavra2, contagem);
            }
        }
    }
}
