package aula06.Ex6_1;
import aula05.Ex5_1.DateYMD;


// Isto faz parte do exercicio 6.2

class Contacto {
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
    public class Pessoa{
        protected String name;
        protected int cc;
        protected DateYMD dataNasc;
        protected Contacto contacto;

        public Pessoa(String name, int cc, DateYMD d, Contacto contacto){
            this.name= name;
            this.cc = cc;
            this.dataNasc = d;
            this.contacto = contacto;
        }
        public String getName(){
            return name;
        }
        public int getCC(){
            return cc;

        }

        public DateYMD getDate(){
            return dataNasc;
        }
        public void setName(String name){
            this.name = name;
        } 
        public void setDataNasc(DateYMD date){
            this.dataNasc = date;
        } 

        public void setCC(int cc){
            this.cc = cc;
        } 
        public void setContato(Contacto contacto){
            this.contacto = contacto;
        }
        public Contacto getContacto(){return contacto;}

        @Override
        public String toString(){
            return "Esta pessoa é o/a " + name + " nasceu a " + dataNasc + " cc: " + cc + "\nContactos: " + contacto ;
        }
    }
    

