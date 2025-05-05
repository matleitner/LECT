package aula09.Ex9_2;

public class PlaneTester {
    public static void main(String[] args){
        
    PlaneManager frota = new PlaneManager();
    Plane p1 = new Plane("Rayner","Fixe" , 1999, 122222, 700);
    Plane p2 = new MilitaryPlane("Marty", "Guerra", 2976, 20, 12123, 7000);
    Plane p3 = new ComercialPlane("Olá", "Epá", 1992, 10,1221, 1231);

    frota.addPlane(p1);
    frota.addPlane(p2);
    frota.addPlane(p3);
    frota.printAllPlanes();

    frota.removePlane("1");
    frota.printAllPlanes();
    System.out.println("333333333333333333");
    System.out.println(frota.searchPlane("1"));
    System.out.println("\\\\\\\\");
    System.out.println(frota.getCommercialPlanes());


    System.out.println("///////////");
    System.out.println(frota.getMilitaryPlanes());
    System.out.println("OOOOOOOOOOOOOOOOOO");
    System.out.println(frota.getFastestPlane());

    }
}