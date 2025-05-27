
import java.time.LocalDate;
import java.util.Objects;


public class Rooms{    
    private int numberOfTheRoom;
    private String typeOfRoom; 
    private int priceForNight;
    private boolean status;
    private LocalDate dateAvailable;
    
    
    public Rooms(int numberOfTheRoom, String typeOfRoom, int priceForNight, boolean status){
        this.numberOfTheRoom = numberOfTheRoom;
        this.typeOfRoom = typeOfRoom;
        this.priceForNight = priceForNight;
        this.status = status; 
    }

    public void setNumberOfTheRoom(int numberOfTheRoom) {
        this.numberOfTheRoom = numberOfTheRoom;
    }
    public void setPriceForNight(int priceForNight) {
        this.priceForNight = priceForNight;
    }
    public void setStatus(boolean status) {
        this.status = status;
    }
    public void setTypeOfRoom(String typeOfRoom) {
        this.typeOfRoom = typeOfRoom;
    }

    public int getNumberOfTheRoom() {
        return numberOfTheRoom;
    }
    public int getPriceForNight() {
        return priceForNight;
    }
    public String getTypeOfRoom() {
        return typeOfRoom;
    }
    
    public boolean getStatus(){
        return status; 
    }



    @Override
    public String toString() {
        
        return "Quarto tipo:"+ typeOfRoom+", nº"+ numberOfTheRoom+ ", preço: " + priceForNight +" "+ (status ? "dísponivel" : "não dísponivel")  ;
    }
    @Override
    public boolean equals(Object o) {
        if (this == o) return true; 
        if (o == null || getClass() != o.getClass()) return false; 
        Rooms room = (Rooms) o;
        return typeOfRoom.equals(room.getTypeOfRoom()) &&
           numberOfTheRoom == room.getNumberOfTheRoom() &&priceForNight==room.getPriceForNight() && 
           status== room.getStatus();

    }
    @Override
    public int hashCode() {
        
        return Objects.hash(typeOfRoom, priceForNight, numberOfTheRoom, status);
    }


}

