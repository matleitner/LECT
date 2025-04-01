package aula06.Ex6_1;
import aula05.Ex5_1.DateYMD;
import java.time.LocalDate;

public class Aluno extends Pessoa {
    private int numMec;
    private static int numMecTotalCounter = 100;
    private DateYMD dataInscricao;
   
    public Aluno(String name, int cc, DateYMD dataNasc,Contacto contacto){
        super(name, cc, dataNasc, contacto);

        this.dataInscricao = new DateYMD (LocalDate.now().getDayOfMonth(),LocalDate.now().getMonthValue(), LocalDate.now().getYear());

        this.numMec = numMecTotalCounter++;
    }
    public Aluno(String name, int cc, DateYMD dataNasc, DateYMD dataIncricao, Contacto contacto){
        super(name,cc ,dataNasc, contacto);
        this.dataInscricao = dataIncricao;
        this.numMec = numMecTotalCounter++;
    }
    public int getNumMec(){return numMec;}
    public void setNumMec(int numMec){ this.numMec =  numMec;}
    
    
    @Override
    public String toString(){return "Esta pessoa é o/a " + name + "\nNasceu a " + dataNasc + "\nCC: " + cc+"\nO num Mecanograf de " + name + " é: "+ numMec + "\nEle increveu se neste instituição no dia: " + dataInscricao+ "\n";} 

    @Override
    public int hashCode(){
        return (int) Math.pow(numMec*(22443)/(cc*2),2);}

    
    }
    

