package com.example;
import java.util.Map;
import java.util.TreeMap;
import java.util.HashMap;
import java.util.LinkedHashMap;
import com.teste.Figura;


public class Main {
    public static void main(String[] args) {
        // A i = new B();
        // String  a = i.getName();
        // System.out.println(a);
        System.out.println("Main.java:");
        Map<String, Integer> mapa = new LinkedHashMap<>(); 
        mapa.put("Paris", 2);
        MorseTranslatorMap a = new MorseTranslatorMap();
        String alal = a.EncodeMorse("Gosto de comer batatas");
        Figura figura = new Figura("Quadrado");

        System.out.println(figura);

        System.out.println(alal);

        System.out.println(a.DecodeMorse(alal));
        

        mapa.put("Paris", 20);
        System.out.println(mapa);
        
    }
}



