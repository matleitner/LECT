public class ContactsTester {
    public static void main(String[] args) {
        ContactManager cm = new ContactManager();

        // --------------------------
        Contact c1 = new Contact("Maria Joaquina", 911234567, "joaquina@ua.pt", "1985-01-01");      
        Contact c2 = new Contact("João Miguel", 911234568, "joao@ua.pt", "1988-01-01");
        cm.addContact(c1);
        cm.addContact(c2);
        cm.printAllContacts();
        // --------------------------

        c1 = cm.getContact(1);
        System.out.println(c1);
        c2 = cm.getContact(2);
        System.out.println(c2);
        System.out.println(cm.getContact(5));           // -- não existe!
        System.out.println(cm.calculateContactCost(5)); // -- não existe!
        // --------------------------

        c1.call(3.5);
        c2.email();
        cm.printAllContacts();
        // --------------------------

        cm.readFile("contatos.txt");
        cm.printAllContacts();
        // --------------------------

        c1 = cm.getContact(1);
        System.out.println(c1);
        c2 = cm.getContact(2);
        System.out.println(c2);
        System.out.println(cm.getContact(5));
        System.out.println(cm.calculateContactCost(5));
        // --------------------------

        cm.writeFile("out.txt");
    }
}
