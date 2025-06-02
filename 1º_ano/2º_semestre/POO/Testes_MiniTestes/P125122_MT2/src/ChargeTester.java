
public class ChargeTester {
    public static void main(String[] args) {
        ChargeManager cm = new ChargeManager();

        // ----------------------------------------------------------
        Charge t1 = new Charge("Aveiro, Portugal", "2025-05-27 11:00:00", 5.0);
        Charge t2 = new Charge("Dublin, Ireland", "2025-05-28 05:00:00", 15.0);
        cm.addCharge(t1);
        cm.addCharge(t2);
        // ----------------------------------------------------------

        cm.printAllCharges();

        // ----------------------------------------------------------
        System.out.println(cm.getCharge(1));
        System.out.println(cm.calculateChargeCost(1));
        System.out.println(cm.getCharge(2));
        System.out.println(cm.calculateChargeCost(2));
        System.out.println(cm.getCharge(30));              // não existe!
        System.out.println(cm.calculateChargeCost(30));    // não existe!
        // ----------------------------------------------------------

        System.out.println("---------------");
        cm.sortChargesByCost();
        System.out.println("---------------");

        // ----------------------------------------------------------
        cm.readFile("charges.txt");
        cm.printAllCharges();

        // ----------------------------------------------------------
        System.out.println(cm.getCharge(1));
        System.out.println(cm.calculateChargeCost(1));
        System.out.println(cm.getCharge(2));
        System.out.println(cm.calculateChargeCost(2));
        System.out.println(cm.getCharge(30));
        System.out.println(cm.calculateChargeCost(30));
        // ----------------------------------------------------------

        cm.writeFile("result.txt");

        // ----------------------------------------------------------

        System.out.println("---------------");
        cm.sortChargesByCost();
        System.out.println("---------------");

        // ----------------------------------------------------------

    }
}
