package aula09.Ex9_2;
import java.util.ArrayList;
import java.util.Iterator;
public class PlaneManager {
    private ArrayList<Plane> frota;
    public PlaneManager(){
        this.frota = new ArrayList<>();
    } 

    public void addPlane(Plane plane){
        frota.add(plane);
    }

    public void removePlane(String id){
        Iterator<Plane> it = frota.iterator();
        while(it.hasNext()){
            if(it.next().getId()== Integer.parseInt(id)){
                it.remove();
            }
        }
    
    }

    public Plane searchPlane(String id){
        Iterator<Plane> it = frota.iterator();
        while(it.hasNext()){
            Plane p1 = it.next();
            if(p1.getId()== Integer.parseInt(id)){
                return p1;
            }
        }
        return null;
    }
    public ArrayList<Plane> getCommercialPlanes(){
        ArrayList<Plane> CommercialPlanes = new ArrayList<>();
        
        for(Plane p : frota){
            if(p.getPlaneType().equals("Comercial")){
                CommercialPlanes.add(p);
            }
        }   
        return CommercialPlanes;
    }


    public ArrayList<Plane> getMilitaryPlanes(){
        ArrayList<Plane> MilitaryPlanes = new ArrayList<>();
        
        for(Plane p : frota){
            if(p.getPlaneType().equals("Militar")){
                MilitaryPlanes.add(p);
            }
        }
        return MilitaryPlanes;
    
    }
    public void printAllPlanes(){
        for(Plane p : frota) {
            System.out.println(p);
        }
    }
    public Plane getFastestPlane(){
        Plane fastestPlane = frota.get(0);
        
        for(Plane p : frota){
            if (fastestPlane.getVelocidadeMaxima()<p.getVelocidadeMaxima())
                fastestPlane = p;
        }
        return fastestPlane;
    }
}
