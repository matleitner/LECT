package aula06.Ex6_1;
import aula05.Ex5_1.DateYMD;

public class Professor extends Pessoa {
    private String categoria;
    private String departamento;



    public Professor(String name, int cc, DateYMD dataNasc, String categoria, String departamento, Contacto contacto ){
        super(name, cc, dataNasc, contacto);
        this.categoria = categoria;
        this.departamento = departamento;
        }
        
        
        public void setDepartamento(String departamento){this.departamento = departamento;}
        public String getDepartamento(){return departamento;}

        public void setCategoria(String categoria){this.categoria = categoria;}
        public String geCategoria(){return categoria;}
        
        @Override
        public String toString(){return "O professor: "+ name + "\ncc:" + cc +"\nNasceu a " + dataNasc + "\nÉ " +categoria +"\nNo departamento de: " + departamento + "\n";}

        


}
