package aula06.Ex6_1;
import java.util.Scanner;

import aula05.Ex5_1.DateYMD;

import java.util.ArrayList;



public class Testar6_2 {
    public static void main(String[] args){
        ArrayList<Pessoa> contactos = new ArrayList<Pessoa>();
        Scanner sc = new Scanner(System.in);
        
        System.out.println("1. Inserir contacto\n2. Alterar contacto\n3. Apagar contacto\n4. Procurar contacto\n5. Listar contactos\n0. Sair");
        int menuResposta = sc.nextInt();
        sc.nextLine();
        while(menuResposta != 0){
        switch(menuResposta){
            case 1:
                	Pessoa p = new Pessoa(null, 0, null, null);
                    System.out.println("Insira o nome da pessoa!");
                    p.setName(sc.nextLine());
                    System.out.println("Insira o cc de " + p.getName());
                    p.setCC(sc.nextInt());
                    System.out.println("Insira uma data: Dia/Mes/Ano");
                    String diaMesAno [] = sc.next().split("/");

                    
                    p.setDataNasc(new DateYMD(Integer.parseInt(diaMesAno[0]), Integer.parseInt(diaMesAno[1]), Integer.parseInt(diaMesAno[2])));
                    
                    System.out.println("Insira um contacto, numero telefone ou email:");
                    
                    int numeroTelefonePessoa;
                    String emailPessoa;
                    do{
                        System.out.println("Numerio telefone: ");
                        numeroTelefonePessoa = sc.nextInt();
                    sc.nextLine();} 
                        while( String.valueOf(numeroTelefonePessoa).length()!=9);
                        do{

                    System.out.println("Email:");        
                    emailPessoa = sc.nextLine(); 
                
                }
                    
                     while(!isValid(emailPessoa)); 


                    p.setContato(new Contacto(numeroTelefonePessoa, emailPessoa));

                    contactos.add(p);

                    System.out.println(p);
                    System.out.println();

                    
                    break;
            case 2:
                if(contactos.size() != 0){    
            System.out.println("Que contacto é que dejesa alterar?");
                for(Pessoa contact : contactos){
                    System.out.println(contact);
                }
                int numAlterar = sc.nextInt();
                sc.nextLine();


            
            }
                System.out.println("Não há contactos guardados");
            case 3:
                System.out.println("Qual o contacto que deseja apagar? (por numero ou nome ou id)");
                String nomeOuNumeroAEliminar = sc.nextLine();

                for(Pessoa contacto : contactos){
                    if (nomeOuNumeroAEliminar.equals( contacto.getName()) || nomeOuNumeroAEliminar.equals(String.valueOf(contacto.getContacto().getNumeroTelefone())) || nomeOuNumeroAEliminar.equals(String.valueOf(contacto.getContacto().getId())));
                    contactos.remove(contacto);
                }
            case 5:
            if(contactos.size()!=0)
                for(Pessoa contact : contactos){
                        System.out.println();
                        System.out.println(contact);
                        System.out.println(

                        );
                    }
            else System.out.println("Vazio");
            } 
        System.out.println("\nPretende ir ao menu?(sim/não)");
        String respostaAgain = sc.nextLine();

        if(respostaAgain!="sim" || respostaAgain != "s") menuResposta = 0;


        System.out.println("1. Inserir contacto\n2. Alterar contacto\n3. Apagar contacto\n4. Procurar contacto\n5. Listar contactos\n0. Sair");
        menuResposta = sc.nextInt();
        sc.nextLine();

        }
    }
    
    



    public static boolean isValid(String emailPessoa){
        if(emailPessoa.contains("@") && emailPessoa.split("@").length == 2
                    && emailPessoa.contains(".") && emailPessoa.split("\\.").length > 1
                    && !emailPessoa.contains(" ")) return true;

            return false;
    }

}
