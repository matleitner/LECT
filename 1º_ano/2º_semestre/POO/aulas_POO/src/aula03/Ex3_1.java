package aula03;
import aula02.Extra;
import java.text.DecimalFormat;

public class Ex3_1 {
    public static void main(String[] args){
        System.out.print("Insira um número: ");
        DecimalFormat df = new DecimalFormat("#,###");
        int numeroInt = Extra.Verificador();
        int somador = 0;
        if (numeroInt != 1){ 
        for ( int i = 2; i<numeroInt ; i++) {
           if(Extra.isPrime(i))
               somador += i;
        }
    }
    somador += numeroInt;
    System.out.println("A soma de todos os números primos de 0 a "+ df.format(numeroInt) +" é: "+ df.format(somador));
}
}

