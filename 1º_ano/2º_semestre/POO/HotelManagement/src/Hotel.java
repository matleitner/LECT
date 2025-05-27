import java.util.ArrayList;

public class Hotel {
    private ArrayList<Rooms> roomList; 


    public Hotel(){
        roomList = new ArrayList<>();
    }
    public void addRoom(Rooms room){
        roomList.add(room);
    }
    
    
    
}
