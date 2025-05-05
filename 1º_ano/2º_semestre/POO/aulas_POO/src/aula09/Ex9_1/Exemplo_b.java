package aula09.Ex9_1;
import java.util.HashSet;
import java.util.Set;
import java.util.Iterator;
import aula06.Ex6_1.Contacto;
import aula06.Ex6_1.Pessoa;
import aula05.Ex5_1.DateYMD;

// b) Com base neste exemplo, crie uma nova coleção (c3) que use um HashSet, em vez de
// ArrayList, e que contenha elementos do tipo Pessoa (Exercício 6.1).
// Set<Pessoa> c3 = new HashSet<>();
// ...
// Insira 5 elementos distintos e use um iterador para listar todos os elementos no écran.
// Verifique a ordem da listagem relativamente à ordem de inserção.
// Teste a inserção de elementos repetidos (que não podem existir num Set).


public class Exemplo_b {
    public static void main(String[] args) {
        
    
    Set<Pessoa> c3 = new HashSet<>();
    Pessoa p1 = new Pessoa("Martim", 0, new DateYMD(12, 12, 2023), new Contacto(925832555));
    Pessoa p2 = new Pessoa("Pobre", 0, new DateYMD(12, 12, 2023), new Contacto(925832555));
    Pessoa p3 = new Pessoa("Leitner", 0, new DateYMD(12, 12, 2023), new Contacto(925832555));
    
    c3.add(p1);
    c3.add(p2);
    c3.add(p3);
    c3.add(p3);
    System.out.println(c3);
    
    Iterator<Pessoa> it = c3.iterator();
    while(it.hasNext()){
        System.out.println(it.next());
    }
    
    
    }
}
