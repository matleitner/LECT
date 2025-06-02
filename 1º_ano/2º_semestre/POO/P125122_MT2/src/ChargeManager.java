import java.util.Scanner;
import java.io.File;
import java.io.IOException;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Set;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedHashSet;
import java.util.List;

import java.io.PrintWriter;

public class ChargeManager {
    private Set<Charge> setDeCharges;
    private StandardChargeCostCalculator calculadora;
    public ChargeManager(){
        this.setDeCharges = new LinkedHashSet<>();
    }
    public void addCharge(Charge t){
        setDeCharges.add(t);
        
        
    }

    public void removeCharges(int id){
        setDeCharges.removeIf(n -> n.getId() == id);
    }
    public Charge getCharge(int id){
        return setDeCharges.stream().filter(n -> n.getId() == id).findFirst().orElse(null);
    }

    public double calculateChargeCost(int id){
        Charge c = getCharge(id);
        calculadora = new StandardChargeCostCalculator();
        if (c == null) return -1;

        return  calculadora.calculateChargeCost(c);

    }
    public void printAllCharges(){
        setDeCharges.forEach(System.out::println);
    }
    public void sortChargesByCost(){
        List<Charge> listaCharges = new ArrayList<>(setDeCharges);
        listaCharges.sort(Comparator.comparingDouble(Charge::getUnidade).reversed());
        for(Charge c : listaCharges){
            System.out.println(c);
        }
    }

    public void readFile(String fich){
        try(Scanner leitorFicheiro = new Scanner(new File(fich))){
            leitorFicheiro.nextLine();
            while(leitorFicheiro.hasNextLine()){
                String[] line = leitorFicheiro.nextLine().split(";");
                //ID; Energia Consumida; Local de Carga; Data e Hora
                int id = Integer.parseInt(line[0]);
                double energiaConsumida = Double.parseDouble(line[1]);
                String local = line[2];
                String dataString = line[3].trim()+ ":00";
                
                Charge c = new Charge(local,dataString, energiaConsumida);
                c.setId(id);
                addCharge(c);

            }
        }catch(IOException e){
            System.out.println("Ficheiro não encontrado");
            e.printStackTrace();
        }
    }

    public void writeFile(String fich){
        try(PrintWriter out = new PrintWriter(new File(fich))){
            for(Charge c : setDeCharges){
                out.printf("%d;%.2f;%s;%s;%.2f\n",c.getId(),c.getUnidade(), c.getLocal(), c.getData(), calculateChargeCost(c.getId()));
                
            }
        
        }catch(IOException e){
            e.printStackTrace();
        }

    }

    
    
}
