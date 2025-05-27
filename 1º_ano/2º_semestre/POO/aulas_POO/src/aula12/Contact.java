package aula12;
import java.time.LocalDate;
import java.util.Objects;

public class Contact {
    private int id;
    private String nome;
    private int numeroTelefone;
    private String email;
    private LocalDate dataDeNascimento;
    private double unitEmail;
    private double unitCall;
    public Contact(String nome, int numeroTelefone, String email, String dataDeNascimento){
        this.nome = nome.trim();
        this.email = email.trim();
        this.numeroTelefone = numeroTelefone;
        this.dataDeNascimento = LocalDate.parse(dataDeNascimento);
        this.id = -1;

    }
    @Override
    public boolean equals(Object o) {
        
        if (this == o) return true; 
        if (o == null || getClass() != o.getClass()) return false; 
        Contact contact = (Contact) o;
        return nome.equals(contact.nome) &&
           email.equals(contact.email) &&numeroTelefone==contact.numeroTelefone && 
           dataDeNascimento.equals(contact.dataDeNascimento);
    }
    @Override
    public int hashCode() {
        
        return Objects.hash(nome,email,dataDeNascimento,numeroTelefone);
    }
    public void setDataDeNascimento(LocalDate dataDeNascimento) {
        this.dataDeNascimento = dataDeNascimento;
    }
    public void setEmail(String email) {
        this.email = email;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public void setNumeroTelefone(int numeroTelefone) {
        this.numeroTelefone = numeroTelefone;
    }

    public LocalDate getDataDeNascimento() {
        return dataDeNascimento;
    }
    public String getEmail() {
        return email;
    }
    public int getId() {
        return id;
    }
    public String getNome() {
        return nome;
    }
    public int getNumeroTelefone() {
        return numeroTelefone;
    }
    public void call(int id, double unit){
        this.unitCall +=unit;

    }
    public double getUnitEmail() {
        return unitEmail;
    }

    public double getUnitCall() {
        return unitCall;
    }
    @Override
    public String toString() {
        
        return String.format("Nome: %s, Telefone: %d, Email: %s, Data nascimento: %s", nome, numeroTelefone,email,dataDeNascimento);
    }

    public void sendEmail(int id){

    }
    public void addUnitCall() {
        this.unitCall += 1;
    }
    public void addUnitEmail() {
        this.unitEmail += 1;
    }
    public void setId(int id) {
        this.id = id;
    }

}

