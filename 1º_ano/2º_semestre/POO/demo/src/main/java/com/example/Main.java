package com.example;
import java.util.Map;
import java.util.TreeMap;
import java.util.HashMap;
import java.util.LinkedHashMap;

public class Main {
    public static void main(String[] args) {
        // A i = new B();
        // String  a = i.getName();
        // System.out.println(a);
        Map<String, Integer> mapa = new LinkedHashMap<>(); 
        mapa.put("Paris", 2);

        mapa.put("Paris", 20);
        System.out.println(mapa);

    }
}



class A{
    protected String getName(){
        return "a";
    }    
}

class B extends A{
    protected String getName(){
        return "b";
    }
}