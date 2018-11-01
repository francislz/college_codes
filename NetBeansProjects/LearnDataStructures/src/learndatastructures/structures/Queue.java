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
public class Queue {
    private Node first;
    private Node last;
    private int size;

    public Queue() {
        this.first = null;
        this.last = null;
        this.size = 0;
    }    
    
   public void push(int value){
       Node newNode = new Node(value);
       if((first == null) && (size == 0)){
           first = newNode;
           last = newNode;
       }
       else{
           last.setNext(newNode);
           last = newNode;
       }
       size++;
   }
   
   public int pop(){
       if(size == 0){
           System.out.println("Queue empty, can't remove");
       }
       else{
           Node temp = first;
           first = temp.getNext();
           size--;
           return temp.getData();
       }
       return -1;
   }
   
   public void debug(){
       Node temp = first;
       while(temp != null){
           System.out.printf("%d ",temp.getData());
           temp = temp.getNext();
       }
       System.out.println();
   }
}
