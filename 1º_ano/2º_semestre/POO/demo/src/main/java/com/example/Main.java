package com.example;

public class Main {
    public static void main(String[] args) {
        A i = new B();
        String  a = i.getName();
        System.out.println(a);
    }
}



class A{
    protected String getName(){
        return "a";
    }    
}

class B extends A{
    protected String getName(){
        return "b";
    }
}