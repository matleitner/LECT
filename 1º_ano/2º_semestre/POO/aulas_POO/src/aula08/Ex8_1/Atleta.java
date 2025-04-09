package aula08.Ex8_1;
import aula06.Ex6_1.Pessoa;
import aula05.Ex5_1.DateYMD;
import aula06.Ex6_1.Contacto;
public class Atleta extends Pessoa implements IKmPercorridos{
        private int kmsPercorridos;
        private int kmRecentes;
    
        Atleta(String name, int cc, DateYMD dataNasc, Contacto contacto){
            super(name, cc, dataNasc, contacto);
        }

        public void trajeto(int quilometros){
            this.kmsPercorridos+= quilometros;
            kmRecentes = quilometros;
    
        }
        public int ultimoTrajeto(){
            return kmRecentes;
        }
    
        public int distanciaTotal(){
            return kmsPercorridos;
        }
    
}
