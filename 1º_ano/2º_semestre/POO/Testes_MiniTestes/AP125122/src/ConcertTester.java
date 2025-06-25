public class ConcertTester {
    public static void main(String[] args) {
        ConcertManager cm = new ConcertManager();

        // ----------------------------------------------------------
        Concert c1 = new Concert("Madrid, Espanha", "2025-05-27 11:00", 25.0);
        Concert c2 = new Concert("Oslo, Suécia", "2025-05-28 05:00", 35.0);
        cm.addConcert(c1);
        cm.addConcert(c2);
        // ----------------------------------------------------------

        cm.printAllConcerts();

        // ----------------------------------------------------------
        System.out.println(cm.getConcert(1));
        System.out.println(cm.calculateConcertProfit(1));
        System.out.println(cm.getConcert(2));
        System.out.println(cm.calculateConcertProfit(2));
        System.out.println(cm.getConcert(30));              // não existe!
        System.out.println(cm.calculateConcertProfit(30));    // não existe!
        // ----------------------------------------------------------

        System.out.println("---------------");
        cm.sortConcertsByProfit();
        System.out.println("---------------");

        // ----------------------------------------------------------
        cm.readFile("classicpimba.txt");
        cm.printAllConcerts();

        System.out.println("---------------");
        System.out.println("---------------");


        Concert c3 = new Concert("Aveiro, Portugal", "2025-10-04 10:00", 69.0);
        cm.addConcert(c3);
        cm.printAllConcerts();
        System.out.println("---------------");
        System.out.println("---------------");
        // ----------------------------------------------------------
        System.out.println(cm.getConcert(1));
        System.out.println(cm.calculateConcertProfit(1));
        System.out.println(cm.getConcert(2));
        System.out.println(cm.calculateConcertProfit(2));
        System.out.println(cm.getConcert(30));
        System.out.println(cm.calculateConcertProfit(30));
        // // ----------------------------------------------------------

        cm.writeFile("result.txt");

        // // ----------------------------------------------------------

        System.out.println("---------------");
        cm.sortConcertsByProfit();
        System.out.println("---------------");

        // ----------------------------------------------------------

    }
}
