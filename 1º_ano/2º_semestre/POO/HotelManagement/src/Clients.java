import java.util.Objects;

public class Clients {
    private String name;
    private int cc;
    private int cellphoneNumber;
    private String email;
    
    
    public Clients(String name, int cc, int cellphoneNumber, String email){
        this.name = name;
        this.cc = cc;
        this.cellphoneNumber = cellphoneNumber;
        this.email = email;
    }
    @Override
    public boolean equals(Object o) {
         if (this == o) return true; 
        if (o == null || getClass() != o.getClass()) return false; 
        Clients client = (Clients) o;
        return name.equals(client.name) &&
           cc == client.getCc() &&cellphoneNumber ==client.getCellphoneNumber() && 
           email.equals(client.getEmail());

    }    
    
    @Override
    public int hashCode() {
        return Objects.hash(name,cc,email,cellphoneNumber);
    }
    
    
    
    
    
    
    
    public int getCc() {
        return cc;
    }
    public int getCellphoneNumber() {
        return cellphoneNumber;
    }
    public String getEmail() {
        return email;
    }
    public String getName() {
        return name;
    }

    public void setCc(int cc) {
        this.cc = cc;
    }
    public void setCellphoneNumber(int cellphoneNumber) {
        this.cellphoneNumber = cellphoneNumber;
    }
    public void setEmail(String email) {
        this.email = email;
    }
    public void setName(String name) {
        this.name = name;
    }




}