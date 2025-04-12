package aula06.Ex6_1;
import java.util.Objects;

import aula05.Ex5_1.DateYMD;
import aula07.Ex7_3.Obra;


// Isto faz parte do exercicio 6.2





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
            return "\nEsta pessoa é o/a " + name + " nasceu a " + dataNasc + " cc: " + cc + " Contactos: " + contacto ;

        }
        
        @Override
        public boolean equals(Object obj){
        if(this!= obj)
            return false;
        if(obj ==null)
            return false;
        if(getClass() != obj.getClass()) 
            return false;
        Pessoa other = (Pessoa) obj;
        
        return name.equals(other.name)&&
dataNasc.equals(other.dataNasc) && cc == other.cc && contacto == other.contacto; 

 
}

        @Override
        public int hashCode() {
            
            
            return Objects.hash(name, cc,dataNasc, contacto); 
        }
    }
    

