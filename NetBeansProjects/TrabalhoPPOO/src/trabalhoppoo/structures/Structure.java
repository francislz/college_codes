package trabalhoppoo.structures;

import trabalhoppoo.exceptions.EmptyStructureException;
import trabalhoppoo.exceptions.FullStructureException;

public abstract class Structure {
    private int size;

    public Structure(int size) {
        this.size = size;
    }
    
    public abstract String push(int value) throws FullStructureException;
    public abstract String pop() throws EmptyStructureException;
    public abstract Node returnFirst();
    
    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }
    
    public void incrementSize(){
        this.size++;
    }
    
    public void decrementSize(){
        this.size--;
    }
}
