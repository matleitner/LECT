import java.util.ArrayList;
import java.util.List;
public class Hotel {
    private List<Rooms> roomList; 
    private List<Clients> clientList;


    public Hotel(){
        roomList = new ArrayList<>();
    }
    public void addRoom(Rooms room){
        roomList.add(room);
    }
    
    
    
}
