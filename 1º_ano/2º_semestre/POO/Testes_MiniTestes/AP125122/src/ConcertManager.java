import java.util.Map;
import java.util.Scanner;

import java.util.HashMap;
import java.io.File;
import java.io.IOException;
import java.io.FileWriter;


public class ConcertManager {
    private Map<Integer, Concert> concertsMap;
    private StandardConcertProfitCalculator calculadora;
    
    public ConcertManager(){
        this.concertsMap = new HashMap<>();
    }

    public void addConcert(Concert c){
        concertsMap.put(c.getId(), c);
    }
    public void removeConcert(int id){
        concertsMap.remove(id);
    }
    public Concert getConcert(int id){
        if(concertsMap.get(id) == null) return null;

        return concertsMap.get(id);
    }
    public double calculateConcertProfit(int id){
        calculadora = new StandardConcertProfitCalculator();
        return calculadora.calculateConcertProfit(concertsMap.get(id));
    }
    public void printAllConcerts(){
        for (Concert c : concertsMap.values()){
            System.out.println(c);
        }
    }
    public void sortConcertsByProfit(){ 
        // a ideia era criar um mapa com as keys sendo os meses e o value 
        //um arrayList ou um set com os respetivos concertos de cada mes 
        // ordenados pelo lucro 
        // mas não tive tempo para conseguir acabar o algoritmo.
        
        //--->
    //     Map<Integer, Set<Concert>> mapSorted = new HashMap<>(); 
    //     for(Concert c : concertsMap.values()){
    //         if(!mapSorted.containsKey(c.getDataHora().getMonthValue())){
    //             mapSorted.put(c.getDataHora().getMonthValue(), new TreeSet<>());
    //         }
    //         else
    //             mapSorted.values().add(c);
    // }
    }

    public void readFile(String fich){
        try(Scanner sc = new Scanner(new File(fich))){
            sc.nextLine();
            while(sc.hasNextLine()){
                String[] linha = sc.nextLine().split(";"); 
                //ID; Duracao; Local do Concerto; Data e Hora
                int id = Integer.parseInt(linha[0]);
                double duracao = Double.parseDouble(linha[1]);
                String localDoConcerto = linha[2].trim();
                String dataHora = linha[3].trim();
                Concert c = new Concert(localDoConcerto, dataHora, duracao);
                c.setId(id);
                if(concertsMap.containsKey(id)){
                    Concert.dontChangeCounter();
                }
                concertsMap.put(id, c);
                
            }
        }catch(IOException e){
            e.printStackTrace();
            System.out.println("Ficheiro não encontrado");
        }
    }

    public void writeFile(String fich){
        try{
            FileWriter fw = new FileWriter("filename.txt");
            for (Concert c : concertsMap.values()){
                fw.write(c.getId()+ ";");
                fw.write(c.getDuracao()+ ";");
                fw.write(c.getLocalDoConcerto()+";");
                fw.write(c.getDataHora() +";");
                fw.write(calculateConcertProfit(c.getId())+ "\n");
        }
            fw.close();




        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
    }



    }

}
