public class Parte2 {
    public static Trama[] geraTramas() {
        Trama[] out = new Trama[9];
        out[0] = new ARP("00:11:22:33:44:55", "ff:ff:ff:ff:ff:ff", ARP.Tipo.REQUEST, "2.2.2.2");
        out[1] = new ARP("aa:bb:cc:dd:ee:ff", "00:11:22:33:44:55", ARP.Tipo.REPLY, "aa:bb:cc:dd:ee:ff");
        out[2] = new IPv4("00:11:22:33:44:55", "aa:bb:cc:dd:ee:ff", "1.1.1.1","2.2.2.2", "Olá! :)");
        out[3] = new ARP("aa:bb:cc:dd:ee:ff", "ff:ff:ff:ff:ff:ff", ARP.Tipo.REQUEST, "1.1.1.1");
        out[4] = new ARP("00:11:22:33:44:55", "00:11:22:33:44:55", ARP.Tipo.REPLY, "00:11:22:33:44:55");
        out[5] = new ARP("00:11:22:33:44:55", "00:11:22:33:44:55", ARP.Tipo.REPLY, "00:11:22:33:44:55");
        out[6] = new IPv4("aa:bb:cc:dd:ee:ff", "00:11:22:33:44:55", "2.2.2.2","1.1.1.1", "Olá! :)");
        out[7] = new ARP("00:11:22:33:44:55", "ff:ff:ff:ff:ff:ff", ARP.Tipo.REQUEST, "3.3.3.3");
        out[8] = new IPv4("aa:bb:cc:dd:ee:ff", "01:00:00:00:00:00", "2.2.2.2","3.3.3.3", "EVIL SPAM; muahahahah!");
        return out;
    }

    public static void main(String[] args) {
        // --------------------------------------------------------
        // Run #1
        // --------------------------------------------------------
        Trama[] tramas = geraTramas();
        Trama p1 = tramas[0];
        Trama p2 = tramas[1];
        Trama p3 = tramas[2];
        Trama p4 = tramas[3];
        Trama p5 = tramas[4];
        Trama p6 = tramas[5];
        Trama p7 = tramas[6];
        Trama p8 = tramas[7];
        Trama p9 = tramas[8];

        Comutador c1 = new Comutador("Aveiro-UA");
        c1.addTrama(p1);
        c1.addTrama(p2);
        c1.addTrama(p3);
        c1.addTrama(p4);
        c1.addTrama(p5);
        c1.addTrama(p6);
        c1.addTrama(p7);
        c1.addTrama(p8);
        c1.addTrama(p9);

        System.out.println(c1);
        while(c1.hasTramas()) {
            c1.enviaTrama();
        }
        System.out.println(c1);

        // --------------------------------------------------------
        // Run #2
        // --------------------------------------------------------
        tramas = geraTramas();
        p1 = tramas[0];
        p2 = tramas[1];
        p3 = tramas[2];
        p4 = tramas[3];
        p5 = tramas[4];
        p6 = tramas[5];
        p7 = tramas[6];
        p8 = tramas[7];
        p9 = tramas[8];

        c1.addTrama(p1);
        c1.addTrama(p2);
        c1.removeTrama(p2);
        c1.addTrama(p3);
        c1.addTrama(p4);
        c1.addTrama(p5);
        c1.addTrama(p6);
        c1.addTrama(p7);
        c1.addTrama(p8);
        c1.addTrama(p9);

        System.out.println(c1);
        while(c1.hasTramas()) {
            c1.enviaTrama();
        }
        System.out.println(c1);
    }
}
