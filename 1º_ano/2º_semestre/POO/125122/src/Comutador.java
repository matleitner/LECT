import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
public class Comutador {
    private String nome;
    private List<String> listaMACsource; 
    private LinkedList <Trama> filaTrama;
    
    Comutador(String nome){
        if(nome.length()<100){
            this.nome = nome; 
        }
        
        else{
            this.nome = nome.substring(0, 100);
        }
        this.listaMACsource = new ArrayList<String>();
        this.filaTrama = new LinkedList<>();
    }

    public void addTrama(Trama t){
        listaMACsource.add(t.getMACSource());
        filaTrama.add(t);
    }

    public void removeTrama(Trama t){
        filaTrama.remove(t);


    }

    public void enviaTrama(){
        Trama trama = filaTrama.getFirst();
        for(String source : listaMACsource)
        if(trama.getMACdestino().equals(source)){
            System.out.println("[OK]");
        }
        else {
            if(trama instanceof ARP)
            System.out.println("[DISCOVER]");
            else System.out.println("[NOK]");
        }
        System.out.println(trama);
        filaTrama.remove(trama);
    }

    public boolean hasTramas(){
        return filaTrama.isEmpty();
    }

    public int getCustoDaFila(){
        return 1; 
    }
    
    @Override
    public String toString() {
        System.out.println("Comutador" + nome + "está UP tramas_por_enviar= " + filaTrama.size() + " custo_da_fila = " + this.getCustoDaFila() );
        String result = "";
        for (Trama t: filaTrama){
            result += t + "\n";
        }
        return result;
    }
}
