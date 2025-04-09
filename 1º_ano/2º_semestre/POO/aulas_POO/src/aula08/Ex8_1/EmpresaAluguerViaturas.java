package aula08.Ex8_1;
import java.util.HashMap;
import aula06.Ex6_1.Pessoa;



public class EmpresaAluguerViaturas {
    protected String nomeEmpresa;
    protected String codigoPostal;
    protected String emailEmpresa;
    protected HashMap<Veiculos, Pessoa> conjuntoVeiculos;


    public EmpresaAluguerViaturas(String nomeEmpresa, String codigoPostal, String emailEmpresa){

        this.nomeEmpresa= nomeEmpresa;
        this.codigoPostal = codigoPostal;
        this.emailEmpresa = emailEmpresa;
        this.conjuntoVeiculos = new HashMap<>();
    }
    
    public void adicionarCarros(Veiculos carro){
        conjuntoVeiculos.put(carro, null);
    }

    public void arrendarCarro(Veiculos carro, Pessoa pessoa){
        if(conjuntoVeiculos.get(carro).getName()!= null )
            conjuntoVeiculos.put(carro, pessoa);
        else System.out.println("O carro já se encontra alugado..."); 
    }
    @Override
    public String toString(){
        String string = "";
        int i = 1;
        for(Veiculos carros : conjuntoVeiculos.keySet()){
            string += "O "+i +"º carro: " + carros  +"\n";
            i++;
        }
        return string;
     }
}
