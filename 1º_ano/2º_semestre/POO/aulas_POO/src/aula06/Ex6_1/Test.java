package aula06.Ex6_1;
import aula05.Ex5_1.DateYMD;
public class Test {
    public static void main(String[] args){
        Aluno al = new Aluno ("Andreia Melo", 9855678,
    new DateYMD(18, 7, 1990), new DateYMD(1, 9, 2018), new Contacto(0, null));
    Professor p1 = new Professor("Jorge Almeida", 3467225, new DateYMD(13, 3, 1967),
    "Associado", "Informática", new Contacto(0, null));
    Bolseiro bls = new Bolseiro ("Igor Santos", 8976543, new DateYMD(11, 5, 1985), p1,
    900, new Contacto(0, null));
    Aluno al2 = new Aluno ("Martim Leitner", 198440432, new DateYMD(04,10,2025), new Contacto(0, null));
    bls.setBolsa(1050);
    System.out.println("Aluno: " + al.getName());
    System.out.println(al);

    System.out.println("Bolseiro: " + bls.getName() + ", NMec: "
    + bls.getNumMec() + ", Bolsa: " + bls.getBolsa() + ", Orientador: " +
    bls.getOrientador());
    System.out.println(bls);

    System.out.println(al2);
 }

    
}
