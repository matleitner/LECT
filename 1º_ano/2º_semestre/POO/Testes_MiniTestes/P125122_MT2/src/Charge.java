import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Objects;

public class Charge {
    private int id;
    private static int counter = 1;
    private double unidade; //kW/h
    private String local;    // CIDADE, PAIS
    private LocalDateTime data; //data e hora
    public Charge(String local, String data, double unidade){
        this.local = local;
        DateTimeFormatter formatter  =  DateTimeFormatter.ofPattern("yyy-MM-dd HH:mm:ss");
        LocalDateTime date = LocalDateTime.parse(data, formatter);
        this.data = date;
        this.unidade = unidade;
        this.id = counter++;
        }
    public void setLocal(String local){
        this.local = local;
    }
    public void setData(LocalDateTime data){
        this.data = data;
    }
    public void setUnidade(double unidade){
        this.unidade= unidade;
    }
    public void setId(int id){
        this.id = id;
    }
    public String getLocal(){
        return local;
    }
    public LocalDateTime getData(){
        return data;
    }
    public double getUnidade(){
        return unidade;
    }
    public int getId(){
        return id;
    }

    @Override
    public String toString(){
        return "id:" + id +" Local: " + local +", energia consumida " + unidade + ", data e hora: " + data;
    }

    @Override
    public boolean equals(Object o) {
        
        if (this == o) return true; 
        if (o == null || getClass() != o.getClass()) return false; 
        Charge c = (Charge) o;
        //comparar ids como sao unicos é o que basta para substituir
        return c.getId() == id;
    }
    @Override
    public int hashCode() {
        
        return Objects.hash(id);
    }
    
    
}
