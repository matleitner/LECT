package aula10.Ex10_4;



import java.io.File;
import java.util.Scanner;
import java.io.IOException;
import java.util.Arrays;
import java.util.TreeMap;
import java.util.stream.Collectors;
import java.io.FileWriter;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Comparator;

public class Voo {
    
    public static ArrayList<ArrayList<String>> load(){
        TreeMap<String, String> comp = companhia();
        ArrayList<ArrayList<String>> voosTodos= new ArrayList<>(); 

        try(Scanner sc = new Scanner(new File("voos.txt")))
        {  sc.nextLine();
            while(sc.hasNextLine()){
                ArrayList<String> voos = new ArrayList<>();
                String[] infoVoos = sc.nextLine().trim().replace(",", "|").split("\t");
                Arrays.stream(infoVoos).forEach(n->voos.add(n));
                String sigla = infoVoos[1].substring(0,2);
                String companhia = comp.getOrDefault(sigla, "Desconhecido");
               
                voos.add(companhia);
                if(voos.size()==5){
                    voos.add( sumHour(voos.get(0), voos.get(3)));
   
                }


                voosTodos.add(voos);
                }         
                
            }
                
            //  HORA VOO ORGIEM ATRASO (OPCIONAL) 
            
        
    
        catch(IOException e){
            e.printStackTrace();
        }
        
        return voosTodos;
    }


    public static String sumHour(String hora1, String hora2){
        //formato Hora:Min
        String[] hora_minuto1 = hora1.split(":");
        String[] hora_minuto2= hora2.split(":");
        int extraHour = (Integer.parseInt(hora_minuto1[1])+Integer.parseInt(hora_minuto2[1]))/60;
        int horaFinal = (Integer.parseInt(hora_minuto1[0]) + Integer.parseInt(hora_minuto2[0])+extraHour)%24;
        int minutoFinal = (Integer.parseInt(hora_minuto1[1])+Integer.parseInt(hora_minuto2[1]))%60; 
        return String.format("%02d",horaFinal) + ":" +String.format("%02d", minutoFinal);
    }




    public static TreeMap<String,String> companhia(){
        TreeMap<String, String> comp = new TreeMap<>(); 
        try(Scanner companhia = new Scanner(new File("companhias.txt"))){
            companhia.nextLine();
            while(companhia.hasNextLine()){
                String[] splitDaLinha =companhia.nextLine().split("\t");  
                comp.put(splitDaLinha[0], splitDaLinha[1]);

            }
        
        }catch(IOException e){
            e.printStackTrace();
        }
    
        return comp;
    }



    public static void printFlights(){
        ArrayList<ArrayList<String>> voosTodos = load();
        for(ArrayList<String> voo: voosTodos){
            if(voo.size()==6)
            System.out.printf("%-30s%-30s%-30s%-30s%-30s%-30s\n", voo.get(0), voo.get(1), voo.get(4),voo.get(2),voo.get(3), voo.get(5));
            else
            System.out.printf("%-30s%-30s%-30s%-30s\n", voo.get(0), voo.get(1), voo.get(3),voo.get(2));
        
        }    


    
    
    }




    public static void saveTable(){

        try(FileWriter file = new FileWriter(new File("table.txt"), true)){
            file.write(String.format("%-30s%-30s%-30s%-30s%-30s%-30s\n\n","Hora","Voo","Companhia","Origem","Atraso","Obs"));
            ArrayList<ArrayList<String>> voosTodos = load();
            for(ArrayList<String> voo: voosTodos){
            if(voo.size()==6)
            file.write(String.format("%-30s%-30s%-30s%-30s%-30s%-30s\n", voo.get(0), voo.get(1), voo.get(4),voo.get(2),voo.get(3), voo.get(5)));
            else
            file.write(String.format("%-30s%-30s%-30s%-30s\n", voo.get(0), voo.get(1), voo.get(3),voo.get(2)));
        
        }    



        }catch(IOException e){
            System.out.println(e.getMessage());
        }

    }
    public static TreeMap<String, String> mediaAtradosPorEmpresa(ArrayList<ArrayList<String>> voos){
        TreeMap<String,ArrayList<String>> companhiasAtrasosMedia = new TreeMap<>();
        int totalSoma = 0;
        TreeMap<String,String> mediaCompanhiasAtrasadas = new TreeMap<>();
        for(ArrayList<String> voo : voos){
            if(voo.size()==6){
            String companhia = voo.get(4);
            String horaAtraso = voo.get(3);
            companhiasAtrasosMedia
        .computeIfAbsent(companhia, k -> new ArrayList<>())
        .add(horaAtraso);
            
    
            
        }

    }   
    
    for (String companhia : companhiasAtrasosMedia.keySet()) {
        ArrayList<String> atrasos = companhiasAtrasosMedia.get(companhia);
            
            for(int i = 0; i<atrasos.size();i++){
                
                totalSoma += Integer.parseInt(atrasos.get(i).split(":")[1]) + Integer.parseInt(atrasos.get(i).split(":")[0])*60;
            }
            mediaCompanhiasAtrasadas.put(companhia, String.format("%02d:%02d",(totalSoma /atrasos.size())/60,(totalSoma /atrasos.size())%60));
            totalSoma = 0;
        }
        //System.out.println(companhiasAtrasosMedia.toString());
        return mediaCompanhiasAtrasadas;



    }
    public static void countFlights(ArrayList<ArrayList<String>> voos){
        Map<String,Integer> flightsCount = new HashMap<>();
        
        
        
        for(ArrayList<String> voo : voos){
            flightsCount.putIfAbsent(voo.get(2),0);
            flightsCount.put(voo.get(2), flightsCount.get(voo.get(2))+1);
        }
        
        
        
    
        
        
        
        LinkedHashMap<String, Integer> sortedByValue = flightsCount.entrySet()
            .stream()
            .sorted(
                Comparator.comparing(Map.Entry<String,Integer>::getValue, Comparator.reverseOrder()).thenComparing(Map.Entry::getKey)
            ).collect(Collectors.toMap(
                Map.Entry::getKey,
                Map.Entry::getValue,
                (e1, e2) -> e1,
                LinkedHashMap::new 
            ));
            
        try(FileWriter fw = new FileWriter(new File("cidades.txt"))){
        
        for(Map.Entry<String,Integer> entry: sortedByValue.entrySet()){
        fw.write(entry.getKey()+ " -> " + entry.getValue()+"\n");
        };
    
    
        }catch(IOException e){
            System.out.println(e.getMessage());
        }

    }

   
    public static void main(String[] args){
        
        //load().forEach(System.out::println);
        printFlights();
        //saveTable();
        //mediaAtradosPorEmpresa(load()).forEach((key,val)-> System.out.println(key+" -> "+val));
        //countFlights(load());
        
    
    }
}
