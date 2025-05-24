package aula12;


public class ContactsTester {
    public static void main(String[] args) {
        ContactManager cm = new ContactManager();

        // --------------------------
        Contact c1 = new Contact("Maria Joaquina", 911234567, "joaquina@ua.pt", "1985-01-01");      
        Contact c2 = new Contact("João Miguel", 911234568, "joao@ua.pt", "1988-01-01");
        Contact c3 = new Contact("Maria Santos", 918765432, "maria@ua.pt", "1998-03-20");
        
        cm.addContact(c1);
        cm.addContact(c2);
        cm.addContact(c3);
        System.out.println("#########################");
        cm.printAllContacts();
        System.out.println("#########################");
        // --------------------------

        c1 = cm.getContact(1);
        System.out.println("#########################");

        System.out.println(c1);
        c2 = cm.getContact(2);
        System.out.println("#########################");

        System.out.println(c2);
        System.out.println(cm.getContact(5));           // -- não existe!
        System.out.println(cm.calculateContactCost(5)); // -- não existe!
        // --------------------------

        c1.call(3.5);
        c2.email();
        System.out.println("#########################");
        
        cm.printAllContacts();
        // --------------------------

        cm.readFile("contatos.txt");
        System.out.println("#########################");
        
        
        cm.printAllContacts();
        // --------------------------

        c1 = cm.getContact(1);
        System.out.println(c1);
        c2 = cm.getContact(2);
        System.out.println(c2);
        System.out.println(cm.getContact(5));
        System.out.println(cm.calculateContactCost(1));
        // --------------------------

        //cm.writeFile("out.txt");
    }
}
