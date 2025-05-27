package com.example;

import java.util.Scanner;

public class TranslateMain {

    public static void main(String[] args) {
        MorseTranslatorMap map = new MorseTranslatorMap();
        Scanner sc = new Scanner(System.in);
        String toTranslate = sc.nextLine();
        String morse = map.EncodeMorse(toTranslate);
        String traduzido = map.DecodeMorse(morse);
        System.out.println(morse);        
        System.out.println(traduzido);

        sc.close();

    }
    
}
