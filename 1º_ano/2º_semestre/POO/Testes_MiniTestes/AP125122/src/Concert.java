import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Objects;

public class Concert {
    private int id;
    private static int counter = 0;
    private double duracao; //unidade minuto
    private String localDoConcerto; //formato "Cidade, país"
    private LocalDateTime dataHora;
   
    
   
   
    public Concert(String localDoConcerto, String dataHora, double duracao) {
        
        this.id = ++counter;
        this.localDoConcerto = localDoConcerto;
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm");
        LocalDateTime date = LocalDateTime.parse(dataHora, formatter);
        this.dataHora = date;
        this.duracao = duracao;
    }
    public int getId() {
        return id;
    }
    public void setId(int id){
        this.id = id;
    }
    public double getDuracao() {
        return duracao;
    }
    public void setDuracao(double duracao) {
        this.duracao = duracao;
    }
    public String getLocalDoConcerto() {
        return localDoConcerto;
    }
    public void setLocalDoConcerto(String localDoConcerto) {
        this.localDoConcerto = localDoConcerto;
    }
    public LocalDateTime getDataHora() {
        return dataHora;
    }
    public void setDataHora(LocalDateTime dataHora) {
        this.dataHora = dataHora;
    }
    @Override
    public String toString() {
        return "Concerto id:" + id + ", duração:" + duracao + ", local do concerto:" + localDoConcerto + ", data e hora:"
        + dataHora + "\n";
    }
    
    public static void updateCounter(int count){
        Concert.counter = count;
    }
    public static int getCounter(){
        return counter;
    }
    @Override
    public int hashCode() {
        return Objects.hashCode(id);
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null) return false;
        if(this == obj)  return true;
        if (getClass() != obj.getClass()) return false;
        Concert objeto = (Concert) obj;
        return  objeto.getId() == this.getId();
    }
}
