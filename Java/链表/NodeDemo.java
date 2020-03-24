class Node<E> {
	private E data;
	private Node<E> next;
	public Node(E data) {
		this.data = data;
	}
	public E getData() {
		return this.data;
	}
	public Node<E> getNext() {
		return this.next;
	}
	public void setData(E data) {
		this.data = data;
	}
	public void setNext(Node<E> next) {
		this.next = next;
	}
}

class JavaDemo {
	public static void main(String [] args) {
		Node<String> n1 = new Node<String>("��ͷ");
		Node<String> n2 = new Node<String>("����һ");
		Node<String> n3 = new Node<String>("�����");
		Node<String> n4 = new Node<String>("������");
		Node<String> n5 = new Node<String>("������");
		
		n1.setNext(n2);
		n2.setNext(n3);
		n3.setNext(n4);
		n4.setNext(n5);
		
		print(n1);
	}
	
	public static void print(Node<?> node) {
		if (node != null) { // ����нڵ�
			System.out.print(node.getData() + "->");
			print(node.getNext());
		} else {
			System.out.println("null");
		}
	}
}