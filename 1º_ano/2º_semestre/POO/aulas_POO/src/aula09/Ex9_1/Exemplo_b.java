package aula09.Ex9_1;
import java.util.HashSet;
import java.util.Set;

import aula06.Ex6_1.Contacto;
import aula06.Ex6_1.Pessoa;
import aula05.*;
import aula05.Ex5_1.DateYMD;

public class Exemplo_b {
    public static void main(String[] args) {
        
    
    Set<Pessoa> c3 = new HashSet<>();
    Pessoa p1 = new Pessoa("Martim", 0, new DateYMD(12, 12, 2023), new Contacto(925832555));
    Pessoa p2 = new Pessoa("Pobre", 0, new DateYMD(12, 12, 2023), new Contacto(925832555));
    Pessoa p3 = new Pessoa("Leitner", 0, new DateYMD(12, 12, 2023), new Contacto(925832555));
    
    c3.add(p1);
    c3.add(p2);
    c3.add(p3);
    System.out.println(c3);
    
    
    
    
    
    }
}
