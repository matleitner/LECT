package aula10.Ex10_4;


import java.io.File;
import java.util.Scanner;
import java.io.IOException;
import java.util.Arrays;
import java.util.TreeMap;
import java.util.ArrayList;
public class Voo {
    // String[] infoVoos = new String[6];
    public static ArrayList<Object> load(){
        ArrayList<String> voosTodos = new ArrayList<>();
        try(Scanner sc = new Scanner(new File("voos.txt")))
        
        {   sc.nextLine();
            while(sc.hasNextLine()){
            ArrayList<String> voos = new ArrayList<>();
            String[] infoVoos = sc.nextLine().replace(" ", "").split("\t");
            Arrays.stream(infoVoos).forEach(n->voos.add(n));
       
            TreeMap<String, String> comp = companhia();
            
            comp.forEach((sigla,companhia) -> {
                if(sigla.equals(infoVoos[1].substring(0, 2))){

                voos.add(companhia);

            }
        });

            //  HORA VOO ORGIEM ATRASO (OPCIONAL) 
            
        }

        }catch(IOException e){
            e.printStackTrace();
        }

        return voos;
    }
    public static String sumHour(String hora1, String hora2){
        //formato Hora:Min
        String[] hora_minuto1 = hora1.split(":");
        String[] hora_minuto2= hora2.split(":");
        int extraHour = (Integer.parseInt(hora_minuto1[1])+Integer.parseInt(hora_minuto2[0]))/60;
        int horaFinal = (Integer.parseInt(hora_minuto1[0]) + Integer.parseInt(hora_minuto2[0])+extraHour)%24;
        int minutoFinal = (Integer.parseInt(hora_minuto1[1])+Integer.parseInt(hora_minuto2[0]))%60; 
        return horaFinal + ":" + minutoFinal;
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
    public static void main(String[] args){
        System.out.println("Hora\tVoo\tCompanhia\tOrigem\tAtraso\tObs");
        
        System.out.println(load().toString());

    }
}
