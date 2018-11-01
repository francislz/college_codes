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
public class Node {
    private int data;
    private Node next;
    private Node prev;

    public Node(int data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
    
    public Node(){}

    public int getData() {
        return data;
    }

    public void setData(int data) {
        this.data = data;
    }

    public Node getNext() {
        return next;
    }

    public void setNext(Node next) {
        this.next = next;
    }

    public Node getPrev() {
        return prev;
    }

    public void setPrev(Node prev) {
        this.prev = prev;
    }
    
    
}
