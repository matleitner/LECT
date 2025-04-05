package aula06.Ex6_1;

public class Contacto {
    private int numTelefone;
    private String email;
    private int id;
    private static int counterId = 1;

    Contacto(int numTelefone, String email){
        this.email = email;
        this.numTelefone = numTelefone;
        this.id = counterId++;
    }

    public int getNumeroTelefone(){return numTelefone;}
    public String getEmail(){return email;}
    public void setEmail(String email){this.email = email;}
    public void setNumeroTelefone(int numTelefone){this.numTelefone = numTelefone;}
    public void setId(int id){this.id= id;}
    public int getId(){return id;}
    public String toString(){

        if(email == null){
            return "O id é: "+id+ ";\n O nº de telefone é: " + numTelefone; 
        }
        else if (numTelefone == 0){return "O id é:"+ id +";\n O email é: " + email;}

        else if (numTelefone == 0 && email.isEmpty() ){return "O id é:"+ id +";\n Este utilizador não possui um contacto!";}
        return "O id é:"+ id +";\n O nº de telefone é: " + numTelefone + " e o email é: " + email + ".";
    }
}