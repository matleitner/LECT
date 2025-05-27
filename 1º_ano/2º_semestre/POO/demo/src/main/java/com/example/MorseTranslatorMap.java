package com.example;
import java.util.LinkedHashMap;
import java.util.Map;
public class MorseTranslatorMap {
    private Map<Character, String> translatorChar;

    public MorseTranslatorMap(){
        translatorChar = new LinkedHashMap<>();
        translatorChar.put('A',".-");
        translatorChar.put('B',"-...");
        translatorChar.put('C',"-.-.");
        translatorChar.put('D',"-..");
        translatorChar.put('E',".");
        translatorChar.put('F',"..-.");
        translatorChar.put('G',"--.");
        translatorChar.put('H',"....");
        translatorChar.put('I',"..");
        translatorChar.put('J',".---");
        translatorChar.put('K',"-.-");
        translatorChar.put('L',".-..");
        translatorChar.put('M',"--");
        translatorChar.put('N',"-.");
        translatorChar.put('O',"---");
        translatorChar.put('P',".--.");
        translatorChar.put('Q',"--.-");
        translatorChar.put('S',"...");
        translatorChar.put('T',"-");
        translatorChar.put('U',"..-");
        translatorChar.put('R',".-.");
        translatorChar.put('V',"...-");
        translatorChar.put('W',".--");
        translatorChar.put('X',"-..-");
        translatorChar.put('Y',"-.--");
        translatorChar.put('Z',"--..");

        translatorChar.put('0',"-----");
        translatorChar.put('1',".----");
        translatorChar.put('2',"..---");
        translatorChar.put('3',"...--");
        translatorChar.put('4',"....-");
        translatorChar.put('5',".....");
        translatorChar.put('6',"-....");
        translatorChar.put('7',"--...");
        translatorChar.put('8',"---..");
        translatorChar.put('9',"----.");

        translatorChar.put(' ', "/");


    } 
    public String EncodeMorse(String line){
        line = line.toUpperCase();
        StringBuilder translated = new StringBuilder();
        for(Character c : line.toCharArray()){
            translated.append( translatorChar.get(c));
            translated.append(" ");



        }

        return translated.toString().trim();

    } 
    public String DecodeMorse(String line){
        StringBuilder translated = new StringBuilder();
        String[] arrayDeMorse = line.split(" ");

        for(String c : arrayDeMorse){
            translatorChar.entrySet().stream().filter(entry -> entry.getValue().equals(c)).findFirst().ifPresent(entry -> translated.append(entry.getKey()));      
        }

        return translated.toString().toLowerCase();
    }
    public static void main(String[] args) {
        
    }
}
