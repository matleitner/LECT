package aula12;

import java.util.LinkedHashSet;
import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import java.io.FileWriter;
import java.util.Set;


public class ContactManager {
    private Set<Contact> contactList;
    private int counter = 1;
    public ContactManager(){
        this.contactList = new LinkedHashSet<>();
    }
    public Set<Contact> getContactList() {
        return contactList;
    }
    
    public void addContact(Contact c){
        int i = contactList.size();
        
        contactList.add(c);
        //"debug" System.out.println(c.getNome() + "##" + c.getId());
        if(i != contactList.size()) c.setId(counter++);
        // "debug" System.out.println(c.getId());
 
    }

    public void sendEmail(int id){
        Contact c = contactList.stream().filter(n -> n.getId() == id).findFirst().orElse(null);
        c.addUnitEmail();
            
    
    }
    public void call(int id, double unit){
        Contact c = contactList.stream().filter(n -> n.getId() == id).findFirst().orElse(null);        
        c.addUnitCall();
    }


    public void removeContact(int i){
        contactList.removeIf(n -> n.getId()==i);
    
    }
    public Contact getContact(int i){
        return contactList.stream().filter(n -> n.getId() == i).findFirst().orElse(null);
    }
    public void  printAllContacts(){
        contactList.forEach(System.out::println);
    }
    public double calculateContactCost(int i){
        Contact c = contactList.stream().filter(n -> n.getId() == i).findFirst().orElse(null);
        if(c == null)return -1;
        StandardCostCalculator s = new StandardCostCalculator();
        

        return s.calculateCost(c.getUnitCall(), IContactCostCalculator.ContactType.CELLNUMBER);

    }


    public void readFile(String fname){
        try(Scanner sc = new Scanner(new File(fname)))
        {while(sc.hasNextLine()){
            
            // nome telefone email data
            String[] linha  = sc.nextLine().split("\t");
            Contact c = new Contact(linha[0], Integer.parseInt(linha[1]), linha[2], linha[3]);
            
            this.addContact(c);
        }
        sc.close();
    }catch(IOException e){
        e.printStackTrace();

    }   

    }

    public void writeFile(String fname){

        try(FileWriter file = new FileWriter(new File(fname), true)){
            
            
            
            for(Contact c : contactList){
                file.write( (c.getNome()+ ","+ c.getNumeroTelefone()+","+ c.getEmail() + "," + c.getDataDeNascimento() + "\n"));
            }   




        }catch(IOException e){
            e.printStackTrace();

        }
}
}
