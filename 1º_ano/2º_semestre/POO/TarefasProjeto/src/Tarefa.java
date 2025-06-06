import java.time.LocalDate;

public class Tarefa {
    private int id;
    private static int counter = 0;
    private String tituloDaTarefa;
    private String descricao;
    private LocalDate dataLimite;
    private int prioridade; //de 1 a 5 
    private String estado; //pendente, em progresso, concluida

    public Tarefa( String tituloDaTarefa, String descricao, LocalDate data, int prioridade,String estado) {
        this.id = ++counter;
        this.tituloDaTarefa = tituloDaTarefa;
        this.descricao = descricao;
        this.dataLimite = data;
        this.prioridade = prioridade;
        this.estado = estado;
    }
    public int getId() {
        return id;
    }
    public String getTituloDaTarefa() {
        return tituloDaTarefa;
    }
    public void setTituloDaTarefa(String tituloDaTarefa) {
        this.tituloDaTarefa = tituloDaTarefa;
    }
    public String getDescricao() {
        return descricao;
    }
    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }
    public void setDataLimite(LocalDate dataLimite) {
        this.dataLimite = dataLimite;
    
    }
    
    public LocalDate getDataLimite() {
       return dataLimite;
    }
    public void setEstado(String estado) {
       this.estado = estado;
    } 

    public int getPrioridade() {
        return prioridade;
    }
    public void setPrioridade(int prioridade) {
        this.prioridade = prioridade;
    }
    public String getEstado() {
        return estado;
    }
    
    @Override
    public String toString() {
        return "Tarefa [id=" + id + ", tituloDaTarefa=" + tituloDaTarefa + ", descricao=" + descricao + ", dataLimite="
                + dataLimite + ", prioridade=" + prioridade + ", estado=" + estado + "]";
    }
    


}
