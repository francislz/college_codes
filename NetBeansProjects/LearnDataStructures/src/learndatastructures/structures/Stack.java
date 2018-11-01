/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package learndatastructures.structures;

/**
 *
 * @author franciscone
 */
public class Stack {
    private Node top;
    private int size;

    public Stack() {
        this.top = null;
        this.size = 0;
    }    
    
   public void push(int value){
       Node newNode = new Node(value);
       if((top == null) && (size == 0)){
           top = newNode;
       }
       else{
           newNode.setNext(top);
           top = newNode;
       }
       size++;
   }
   
   public int pop(){
       if(size == 0){
           System.out.println("Stack empty, can't remove");
       }
       else{
           Node temp = top;
           top = temp.getNext();
           size--;
           return temp.getData();
       }
       return -1;
   }
   
   public void debug(){
       Node temp = top;
       while(temp != null){
           System.out.printf("%d ",temp.getData());
           temp = temp.getNext();
       }
       System.out.println();
   }
}
