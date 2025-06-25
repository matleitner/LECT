import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;
import java.io.File;
import java.io.IOException;
import java.io.FileWriter;
import java.util.List;
import java.util.ArrayList;


public class ConcertManager {
    private Map<Integer, Concert> concertsMap;
    private StandardConcertProfitCalculator calculadora;
    
    public ConcertManager(){
        this.concertsMap = new TreeMap<>();
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
        // System.out.println(concertsMap); // para checkar o id da key com o do id da classe

        for(Map.Entry<Integer, Concert> entry :concertsMap.entrySet()){
            System.out.println(entry.getValue());
        }
    }
   public void sortConcertsByProfit() {
    Map<Integer, List<Concert>> meses_bandas = new TreeMap<>();

    for (int i = 1; i <= 12; i++) {
        meses_bandas.put(i, new ArrayList<>());
    }

    for (Concert concert : concertsMap.values()) {
        int mes = concert.getDataHora().getMonthValue();
        meses_bandas.get(mes).add(concert);
    }

    for (List<Concert> lista : meses_bandas.values()) {
        lista.sort(new SortByCost());
    }

    
    System.out.println("Concertos ordenados por lucro, agrupados por mês:");
    for (Map.Entry<Integer, List<Concert>> entry : meses_bandas.entrySet()) {
        int mes = entry.getKey();
        List<Concert> lista = entry.getValue();

        if (!lista.isEmpty()) {
            System.out.println("Mês: " + mes);
            for (Concert c : lista) {
                double lucro = calculateConcertProfit(c.getId());
                System.out.printf("  ID: %d | Lucro: %.2f | Local: %s | Data: %s\n",
                        c.getId(), lucro, c.getLocalDoConcerto(), c.getDataHora());
            }
        }
    }
}


    public void readFile(String fich){
        try(Scanner sc = new Scanner(new File(fich))){
            
            sc.nextLine();
            while(sc.hasNextLine()){
                int maximCounter = Concert.getCounter();
                String[] linha = sc.nextLine().split(";"); 
                //ID; Duracao; Local do Concerto; Data e Hora
                int id = Integer.parseInt(linha[0]);
                double duracao = Double.parseDouble(linha[1]);
                String localDoConcerto = linha[2].trim();
                String dataHora = linha[3].trim();
                Concert c = new Concert(localDoConcerto, dataHora, duracao);
                c.setId(id);
                if(maximCounter > id){
                    Concert.updateCounter(id);
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
            FileWriter fw = new FileWriter(fich);
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
