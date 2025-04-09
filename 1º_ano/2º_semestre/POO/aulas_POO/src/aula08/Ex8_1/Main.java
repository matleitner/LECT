package aula08.Ex8_1;
import aula06.Ex6_1.*;

public class Main {
    public static void main(String[] args){
        
        Pessoa atleta = new Atleta("Jorge", 123123123, null, new Contacto(932233213, null));
        EmpresaAluguerViaturas Cofidis = new EmpresaAluguerViaturas("Cofidis", "1234-321", "Cofidis@ua.pt");
        
        Motociclo mota1 = new Motociclo("12", null, "piças", 0, null);
        PesadoMercadorias camiao = new PesadoMercadorias("Mercedes", "Bue boa", "Topo de gama", 0, 0, 12000, 1230);
        Cofidis.adicionarCarros(mota1);
        mota1.setPreco(120000);
        Cofidis.adicionarCarros(camiao);
        camiao.setPreco(1000000);

        System.out.println(Cofidis);
        camiao.trajeto(123);
        mota1.trajeto(1000);
        

        if(camiao.getKms()<mota1.getKms())Cofidis.arrendarCarro(camiao, atleta);
    }
}
