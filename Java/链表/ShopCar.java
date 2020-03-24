// ����ʵ����LinkList.java��
interface IGoods { // ������Ʒ��׼
	public String getName();
	public double getPrice();
}
interface IShopCar { // ���幺�ﳵ��׼
	public void add(IGoods goods); // �����Ʒ��Ϣ
	public void delete(IGoods goods); // ɾ����Ʒ
	public Object [] getAll(); // ��ù��ﳵ�е�ȫ����Ʒ��Ϣ
}
class ShopCarImpl implements IShopCar { // ���ﳵ
	private ILink<IGoods> allGoodses = new LinkImpl<IGoods>();
	public void add(IGoods goods) {
		this.allGoodses.add(goods);
	}
	public void delete(IGoods goods) {
		this.allGoodses.remove(goods);
	}
	public Object [] getAll() {
		return this.allGoodses.toArray();
	}
}
class Cashier { // ����̨
	private IShopCar shopcar;
	public Cashier(IShopCar shopcar) {
		this.shopcar = shopcar;
	}
	public double allPrice() { // �����ܼ�
		double all = 0.0;
		Object [] result = this.shopcar.getAll();
		for (Object obj : result) {
			IGoods goods = (IGoods)obj;
			all += goods.getPrice();
		}
		return all;
	}
	public int allCount() { // ��Ʒ����
		return this.shopcar.getAll().length;
	}
}
class Book implements IGoods {
	private String name;
	private double price;
	public Book(String name, double price) {
		this.name = name;
		this.price = price;
	}
	public String getName() {
		return this.name;
	}
	public double getPrice() {
		return this.price;
	}
	public boolean equals(Object obj) {
		if (obj == null || !(obj instanceof Book)) {
			return false;
		}
		if (this == obj) {
			return true;
		}
		Book book = (Book)obj;
		return book.name.equals(this.name) && book.price == this.price;
	}
	public String toString() {
		return "��ͼ����Ϣ�� ���ƣ� " + this.name + "���۸� " + this.price;
	}
}
class Bag implements IGoods {
	private String name;
	private double price;
	public Bag(String name, double price) {
		this.name = name;
		this.price = price;
	}
	public String getName() {
		return this.name;
	}
	public double getPrice() {
		return this.price;
	}
	public boolean equals(Object obj) {
		if (obj == null || !(obj instanceof Bag)) {
			return false;
		}
		if (this == obj) {
			return true;
		}
		Bag bag = (Bag)obj;
		return bag.name.equals(this.name) && bag.price == this.price;
	}
	public String toString() {
		return "��������Ϣ�� ���ƣ� " + this.name + "���۸� " + this.price;
	}
}
class JavaDemo {
	public static void main(String [] args) {
		IShopCar car = new ShopCarImpl();
		car.add(new Book("Java����", 79.9));
		car.add(new Book("Oracle����", 89.9));
		car.add(new Book("Сǿ�Ʊ���", 899.9));
		Cashier cas = new Cashier(car);
		System.out.println("�ܼ۸� " + cas.allPrice() + ", ���������� " + cas.allCount());
	}
}