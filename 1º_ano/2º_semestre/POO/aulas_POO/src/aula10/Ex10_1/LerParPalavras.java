package aula10.Ex10_1;
import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;
public class LerParPalavras{
    
    public Scanner abrirFicheiro(String filename){
        Scanner fileReader = null;
        try{
            File ficheiro = new File(filename);
            fileReader = new Scanner(ficheiro);
        }
        catch(FileNotFoundException e){
            System.out.println("Erro!!!");
            e.printStackTrace();
        }
        return fileReader;
    }
    public static void main(String[] args){
        LerParPalavras lerFile = new LerParPalavras();
        Scanner file = lerFile.abrirFicheiro("major.txt");
        file.useDelimiter("[\\t\\n\\.,:'‘’;?!\\-*\\{}=+&/\\(\\)\\[\\]”“\"']+");
        while(file.hasNext()){
            String word = file.next();
            // if(word.length()>3) System.out.println(word);
            System.out.println(word);
        
        }
        file.close();
    }
}