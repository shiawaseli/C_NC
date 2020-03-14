class Item {
	private long iid;
	private String title;
	private Subitem [] subitems;
	public Item(long iid, String title) {
		this.iid = iid;
		this.title = title;
	}
	public String getInfo() {
		return "��������Ϣ�� iid = " + this.iid +
		",title = " + this.title;
	}
	public Subitem [] getSubitems() {
		return this.subitems;
	}
	public void setSubitems(Subitem [] subitems) {
		this.subitems = subitems;
	}
}
class Subitem {
	private long sid;
	private String title;
	private Item item;
	public Subitem(long sid, String title) {
		this.sid = sid;
		this.title = title;
	}
	public String getInfo() {
		return "���ӷ�����Ϣ�� sid = " + this.sid +
		",title = " + this.title;
	}
	public Item getItem() {
		return this.item;
	}
	public void setItem(Item item) {
		this.item = item;
	}
}
public class ItemDemo {
	public static void main(String [] args) {
		// ��һ���� ���ݽṹ���ö�������
		Item item = new Item(1L, "ͼ��");
		Subitem [] subitems = new Subitem [] {
			new Subitem(10L, "���ͼ��"),
			new Subitem(10L, "ͼ��ͼ����ͼ��")
		};
		item.setSubitems(subitems);
		// һ���������ж���ӷ���
		for (int i = 0; i < subitems.length; i++) {
			subitems[i].setItem(item);
		}
		// �ڶ����� ����Ҫ���ȡ����
		System.out.println(item.getInfo());
		for (int i = 0; i < item.getSubitems().length; i++) {
			System.out.println("\t|- " + item.getSubitems()[i].getInfo());
		}
	}
}