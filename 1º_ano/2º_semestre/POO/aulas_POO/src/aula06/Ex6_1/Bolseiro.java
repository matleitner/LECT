package aula06.Ex6_1;
import aula05.Ex5_1.DateYMD;
public class Bolseiro extends Aluno {
    private int bolsa;
    private Professor orientador;
    
    
    
    public Bolseiro(String name, int cc, DateYMD dataNasc, Professor orientador, int bolsa,Contacto contacto){
        super(name, cc, dataNasc, contacto);
        this.bolsa = bolsa;
        this.orientador = orientador;
    }

    public Bolseiro(String name, int cc, DateYMD dataNasc, DateYMD dataInscricao, Professor Orientador, int bolsa, Contacto contacto){
        super(name, cc, dataNasc, dataInscricao, contacto);
        this.bolsa = bolsa;
        this.orientador = Orientador;
    }

    public void setBolsa(int bolsa){this.bolsa = bolsa;}
    
    public void setOrientador(Professor orientador){this.orientador = orientador;}
    
    public Professor getOrientador(){return orientador;}

    public int getBolsa(){return bolsa;}




}
