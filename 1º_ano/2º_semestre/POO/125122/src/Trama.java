
public abstract class Trama {
    protected String enderecoMACsource;
    protected String enderecoMACdestino;


    Trama( String enderecoMACsource, String enderecoMACdestino){
        this.enderecoMACsource= enderecoMACsource;
        this.enderecoMACdestino= enderecoMACdestino;
    }
    public String getMACSource(){
        return enderecoMACsource;
    }
    public String getMACdestino(){
        return enderecoMACdestino;
    }
    
    
}
