public class Book {
	private String bid; // ͼ����
	private String title; // ����
	private double price; // �۸�
	private static int count = 0;
	
	/*
	static {
		// �����кܶ������Ҫ���ڳ�ʼ����̬��Ա
		System.out.println("����̬�顿 Book��̬��ִ��");
	}
	{
		System.out.println("������顿 Book�����ִ��");
	}
	*/
	public Book() {
		this("NOTITLE - " + (Book.count + 1), -1);
	}
	public Book(String title) {
		this(title, -1);
	}
	public Book(String title, double price) {
		//System.out.println("�����췽���� Book�๹�췽��ִ��");
		Book.count++;
		this.bid = "" + Book.count;
		this.title = title;
		this.price = price;
		//System.out.println("������" + Book.count + "��ͼ��: " + this.title);
	}
	public String getInfo() {
		return "ͼ����: " + this.bid +
		"\n����: " + this.title +
		"\n�۸�: " + this.price;
	}
	public String getBid() {
		return this.bid;
	}
	public String getTitle() {
		return this.title;
	}
	public double getPrice() {
		return this.price;
	}
	public static int getCount() {
		return Book.count;
	}
	public void setBid(String bid) {
		this.bid = bid;
	}
	public void setTitle(String title) {
		this.title = title;
	}
	public void setPrice(double price) {
		this.price = price;
	}
}