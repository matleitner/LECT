package com.teste;

public class Figura {
    String tipo;
    public Figura (String tipo){
        this.tipo = tipo;
    }

    @Override
    public String toString(){
      return "Isto é uma figurai e é um " + tipo; 
    }
  
}


