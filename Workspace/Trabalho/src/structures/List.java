package structures;

public class List {
	private Node first;
	private Node last;
	private int size;
	
	public List() {
		this.first = null;
		this.last = null;
		this.size = 0;
	}
	
	public void insertEnd(int data) {
		insertPos(data, 0);
	}
	
	public void insertBegin(int data) {
		insertPos(data, size - 1);
	}
	
	public void insertPos(int data, int pos) {
		Node node = new Node(data);
		
		if(size == 0) {
			first = node;
			last = node;
		}
		else {
			if(pos == 0) {
				node.setNext(first.getNext());
				first = node;
			}
			else if(pos == (size - 1)) {
				last.setNext(node);
				last = node;
			}
			else {
				int i = 0;
				Node temp = first;
				Node prev = null;
				while(i < pos) {
					prev = temp;
					temp = temp.getNext();
					++i;
				}
				prev.setNext(node);
				node.setNext(temp);
			}
		}
		++size;
	}
	
	
}
