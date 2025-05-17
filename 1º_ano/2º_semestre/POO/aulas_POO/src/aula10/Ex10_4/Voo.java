package aula10.Ex10_4;


import java.io.File;
import java.util.Scanner;
import java.io.IOException;
import java.util.Arrays;
import java.util.TreeMap;
import java.util.ArrayList;
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


   
    public static void main(String[] args){
        System.out.printf("%-30s%-30s%-30s%-30s%-30s%-30s\n\n","Hora","Voo","Companhia","Origem","Atraso","Obs");
//        load().forEach(System.out::println);
         printFlights();

    }
}
