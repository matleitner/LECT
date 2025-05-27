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
        //System.out.println("############1#############");
        cm.printAllContacts();
        //System.out.println("#############2############");
        // --------------------------

        c1 = cm.getContact(1);
        //System.out.println("##############3###########");

        System.out.println(c1);
        c2 = cm.getContact(2);
        //System.out.println("###############4##########");

        System.out.println(c2);
        System.out.println(cm.getContact(5));           // -- não existe!
        System.out.println(cm.calculateContactCost(5)); // -- não existe!
        // --------------------------

        cm.call(1,12.5);
        cm.sendEmail(1);
        //System.out.println("################5#########");
        
        cm.printAllContacts();
        // --------------------------

        //System.out.println("#################6########");
        cm.readFile("contatos.txt");
        Contact c4 = new Contact("João Silva", 912345678, "joao@ua.pt", "2000-10-12");
        Contact c5 = new Contact("João Silva", 912345678, "joao@ua.pt", "2000-10-12");
        
        cm.addContact(c5);
        cm.addContact(c4);
        
        cm.printAllContacts();
        // --------------------------
        //System.out.println("##################7#######");
        c1 = cm.getContact(1);
        //System.out.println("#########################");
        System.out.println(c1);
        //System.out.println("#########################");
        c2 = cm.getContact(2);
        //System.out.println("#########################");
        System.out.println(c2);
        //System.out.println("###################8######");
        System.out.println(cm.getContact(9));
        //System.out.println("####################9#####");
        System.out.println(cm.calculateContactCost(1));
        // --------------------------

        //cm.writeFile("out.txt");
    }
}
