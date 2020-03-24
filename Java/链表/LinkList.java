interface ILink<E> { // ���÷��ͱ��ⰲȫ����
	public void add(E e); // ��������
	public int size(); // ��ȡ���ݵĸ���
	public boolean isEmpty(); // �ж��Ƿ�ռ���
	public Object [] toArray(); // ������Ԫ�����������ʽ����
	public E get(int index); // ����������ȡ����
	public void set(int index, E data); // �޸���������
	public boolean contains(E data); // �ж������Ƿ����
	public void remove(E e); // ����ɾ��
	public void clear(); // ��ռ���
}
class LinkImpl<E> implements ILink<E> {
	private class Node { // ����ڵ�����ݹ�ϵ
		private E data; // ���������
		private Node next; // ������һ������
		public Node(E data) { // �����ݵ�����²�������
			this.data = data;
		}
		// ��һ�ε��ã� this = LinkImpl.root;
		// �ڶ��ε��ã� this = LinkImpl.root.next;
		// �����ε��ã� this = LinkImpl.root.next.next;
		public void addNode(Node newNode) { // �����µ�Node�ڵ�
			if (this.next == null) { // ��ǰ�ڵ����һ���ڵ�Ϊnull
				this.next = newNode; // ���浱ǰ�ڵ�
			} else {
				this.next.addNode(newNode);
			}
		}
		// ��һ�ε��ã� this = LinkImpl.root;
		// �ڶ��ε��ã� this = LinkImpl.root.next;
		// �����ε��ã� this = LinkImpl.root.next.next;
		public void toArrayNode() {
			LinkImpl.this.returnData[LinkImpl.this.foot++] = this.data;
			if (this.next != null) { // ������һ������
				this.next.toArrayNode();
			}
		}
		public E getNode(int index) {
			if (LinkImpl.this.foot++ == index) { // ������ͬ
				return this.data; // ���ص�ǰ����
			} else {
				return this.next.getNode(index);
			}
		}
		public void setNode(int index, E data) {
			if (LinkImpl.this.foot++ == index) { // ������ͬ
				this.data = data; // �޸�����
			} else {
				this.next.setNode(index, data);
			}
		}
		public boolean containsNode(E data) {
			// dataһ����Ϊnull
			if (data.equals(this.data)) { // ����Ƚ�
				return true;
			} else {
				if (this.next == null) { // û�к����ڵ���
					return false; // �Ҳ���
				} else {
					return this.next.containsNode(data); // �������ж�
				}
			}
		}
		public void removeNode(Node previous, E data) {
			if (data.equals(this.data)) {
				previous.next = this.next; // �ճ���ǰ�ڵ�
				LinkImpl.this.count--;
			} else {
				if (this.next != null) { // �к����ڵ�
					this.next.removeNode(this, data); // ������ɾ��
				}
			}
		}
		// �ⲿ�����ֱ�ӷ����ڲ����е�˽�г�Ա�����Բ���Ҫsetter��getter����
	}
	/* ----------------------����ΪLinkImpl���ж���ĳ�Ա--------------------------*/
	private Node root; // ���������
	private int count; // �������ݸ���
	private int foot; // �������ǲ�������Ľű�
	private Object [] returnData; // ���ص����ݱ���
	/* ----------------------����ΪLinkImpl���ж���ķ���--------------------------*/
	public void add(E e) {
		if (e == null) { // ���������Ϊnull
			return; // ��������ֱ�ӽ���
		}
		// ���ݱ����ǲ����й������Եģ�ֻ��Node���У���ôҪ��ʵ�ֹ�������ͱ��뽫���ݰ�װ��Node��֮��
		Node newNode = new Node(e); // ����һ���µĽڵ�
		if (this.root == null) { // ����û�и��ڵ�
			this.root = newNode;
		} else { // ���ڵ��Ѵ���
			this.root.addNode(newNode); // ���½ڵ㱣���ں��ʵ�λ��
		}
		this.count++;
	}
	public int size() {
		return this.count;
	}
	public boolean isEmpty() {
		// return this.root == null;
		return this.count == 0;
	}
	public Object [] toArray() {
		if (this.isEmpty()) { // �ռ���
			return null; // ����û������
		}
		this.foot = 0; // �ű�����
		this.returnData = new Object[this.count]; // �������еĳ��ȿ�������
		this.root.toArrayNode(); // ����Node����еݹ����ݻ�ȡ
		return this.returnData;
	}
	public E get(int index) {
		if (index >= this.count) { // ����Ӧ����ָ���ķ�Χ֮��
			return null;
		}
		this.foot = 0; // �����������±�
		// �������ݵĻ�ȡӦ����Node�����
		return this.root.getNode(index);
	}
	public void set(int index, E data) {
		if (index >= this.count) { // ����Ӧ����ָ���ķ�Χ֮��
			return; // ��������
		}
		this.foot = 0; // �����������±�
		// �޸��������ݵĲ���Ӧ����Node�����
		this.root.setNode(index, data); // �޸�����
	}
	public boolean contains(E data) {
		if (data == null) {
			return false; // û������
		}
		// ����Node���ж�
		return this.root.containsNode(data);
	}
	public void remove(E data) {
		if (this.root.data.equals(data)) { // ���ڵ�ΪҪɾ���ڵ�
			this.root = this.root.next;
			this.count--;
		} else { // ��ʱ����Node�ฺ��ɾ���͵ݼ�this.count
			this.root.removeNode(this.root, data);
		}
	}
	public void clear() {
		this.root = null; // ���������нڵ㶼û��
		this.count = 0; // ��������
	}
}
/*
// ����Demo
class JavaDemo {
	public static void main(String [] args) {
		ILink<String> all = new LinkImpl<String>();
		System.out.println("������֮ǰ�� ���ݸ����� " 
			+ all.size() + "���Ƿ�Ϊ�ռ��ϣ� " + all.isEmpty());
		all.add("Hello");
		all.add("World");
		all.add("Baidu");
		all.add("LB");
		System.out.println("������֮ǰ�� ���ݸ����� " 
			+ all.size() + "���Ƿ�Ϊ�ռ��ϣ� " + all.isEmpty());
		all.remove("World"); // ɾ������Ԫ��
		Object [] result = all.toArray();
		if (result != null) {
			for (Object obj : result) {
				System.out.println((String)obj);
			}
		}
		all.remove("Hello"); // ɾ����Ԫ��
		all.set(1, "����"); // �޸�����
		System.out.println("---------------���ݻ�ȡ�ķָ���--------------");
		System.out.println(all.get(0));
		System.out.println(all.get(1));
		System.out.println(all.get(2));
		System.out.println(all.get(3));
		System.out.println("---------------�����жϵķָ���--------------");
		System.out.println(all.contains("��"));
		System.out.println(all.contains("Baidu"));
		System.out.println("�����֮ǰ�� ���ݸ����� " 
			+ all.size() + "���Ƿ�Ϊ�ռ��ϣ� " + all.isEmpty());
		all.clear();
		System.out.println("�����֮�� ���ݸ����� " 
			+ all.size() + "���Ƿ�Ϊ�ռ��ϣ� " + all.isEmpty());
	}
}
*/