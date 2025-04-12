package aula08.Ex8_2;

import java.util.ArrayList;
public class Ementa {
    private String nome;
    private String local;
    private ArrayList<PratoDia> listaPratos;
    public static int numeroDoPrato=1;

    Ementa(String nome, String local){
        this.nome = nome;
        this.local = local;
        listaPratos = new ArrayList<>();
    }
    public enum DiaSemana{
            SEGUNDA,
            TERCA,
            QUARTA,
            QUINTA,
            SEXTA,
            SABADO,
            DOMINGO
    }
    public enum VariedadeCarne{
        VACA,PERU,FRANGO,OUTRA
    }
    public enum TipoPeixe{
        CONGELADO,FRESCO
    }
    private class PratoDia{
        Prato prato;
        DiaSemana dia;
        PratoDia(Prato prato, DiaSemana dia){
            this.prato = prato;
            this.dia = dia;
        }
        @Override 
        public String toString(){return prato + ", " + dia;}
    } 



    
   public void addPrato(Prato prato, DiaSemana dia){
        listaPratos.add(new PratoDia(prato, dia));

   }

   public String toString(){
    String ementa = ""; 
    for (PratoDia prato : listaPratos)
        ementa += prato + ""+ "\n";
        return ementa;
   }
}
