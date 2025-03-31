package aula06.Ex6_1;
import aula02.Extra.DateYMD;

public class Professor extends Pessoa {
    private String categoria;
    private String departamento;



    public Professor(String name, int cc, DateYMD dataNasc, String categoria, String departamento ){
        super(name, cc, dataNasc);
        this.categoria = categoria;
        this.departamento = departamento;
        }
        @Override
        public String getName(){return name;}

        @Override
        public int getCC(){return cc;}
        
        @Override
        public DateYMD getDate(){return dataNasc;}
        
        @Override
        public void setName(String name){this.name = name;} 
        
        @Override
        public void setDataNasc(DateYMD date){this.dataNasc = date;} 
        
        @Override
        public void setCC(int cc){this.cc = cc;} 
        
        public void setDepartamento(String departamento){this.departamento = departamento;}
        public String getDepartamento(){return departamento;}

        public void setCategoria(String categoria){this.categoria = categoria;}
        public String geCategoria(){return categoria;}
        
        @Override
        public String toString(){return "O professor: "+ name + "\ncc:" + cc +"\nNasceu a " + dataNasc + "\nÉ " +categoria +"\nNo departamento de: " + departamento;}

        


}
