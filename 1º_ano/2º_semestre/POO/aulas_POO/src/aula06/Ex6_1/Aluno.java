package aula06.Ex6_1;
import aula02.Extra.DateYMD;
import java.time.LocalDate;

public class Aluno extends Pessoa {
    private int numMec;
    private static int numMecTotalCounter = 100;
    private DateYMD dataInscricao;
   
    public Aluno(String name, int cc, DateYMD dataNasc){
        super(name, cc, dataNasc);

        this.dataInscricao = new DateYMD (LocalDate.now().getDayOfMonth(),LocalDate.now().getMonthValue(), LocalDate.now().getYear());

        this.numMec = numMecTotalCounter++;
    }
    public Aluno(String name, int cc, DateYMD dataNasc, DateYMD dataIncricao){
        super(name,cc ,dataNasc );
        this.dataInscricao = dataIncricao;
        this.numMec = numMecTotalCounter++;
    }
    public int getNumMec(){return numMec;}
    public void setNumMec(int numMec){ this.numMec =  numMec;}
    
    @Override
    public String getName(){
        return name;
    }
    @Override
    public int getCC(){
        return cc;

    }
    @Override
    public DateYMD getDate(){
        return dataNasc;
    }
    @Override
    public void setName(String name){
        this.name = name;
    } 
    @Override
    public void setDataNasc(DateYMD date){
        this.dataNasc = date;
    } 
    @Override
    public void setCC(int cc){
        this.cc = cc;
    } 

    @Override
    public String toString(){return "Esta pessoa é o/a " + name + "\nNasceu a " + dataNasc + "\nCC: " + cc+"\nO num Mecanograf de " + name + " é: "+ numMec + "\nEle increveu se neste instituição no dia: " + dataInscricao;} 

    @Override
    public int hashCode(){
        return (int) Math.pow(numMec*(22443)/(cc*2),2);}

    public static void main(String[] args){
        
        DateYMD d = new DateYMD(04, 10, 2006);
        
        Aluno Beatriz = new Aluno("Beatriz", 122313121, new DateYMD(01, 8, 2005));
        Aluno Martim = new Aluno("Martim",122312233 , d);
        System.out.println(Martim);
        System.out.println();
        System.out.println(Beatriz);
    }
    }
    

