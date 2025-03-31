package aula06.Ex6_1;
import aula02.Extra.DateYMD;

    public class Pessoa{
        protected String name;
        protected int cc;
        protected DateYMD dataNasc;

        public Pessoa(String name, int cc, DateYMD d){
            this.name= name;
            this.cc = cc;
            this.dataNasc = d;
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
        @Override
        public String toString(){
            return "Esta pessoa é o/a " + name + " nasceu a " + dataNasc + " cc: " + cc;
        }
    }
    

