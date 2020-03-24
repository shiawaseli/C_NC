// ����ʵ����LinkList.java��
interface Pet { // ��������׼
	public String getName(); // �������
	public String getColor(); // �����ɫ
}
class PetShop { // �����̵�
	private ILink<Pet> allPets = new LinkImpl<Pet>(); // ������������Ϣ
	public void add(Pet pet) { // ׷�Ӷ�����Ʒ�ϼ�
		this.allPets.add(pet); // �����б������
	}
	public void delete(Pet pet) {
		this.allPets.remove(pet);
	}
	public ILink<Pet> search(String keyword) {
		ILink<Pet> searchResult = new LinkImpl<Pet>();
		Object [] result = this.allPets.toArray(); // ��ȡȫ������
		if (result != null) {
			for (Object obj : result) {
				Pet pet = (Pet)obj;
				if (pet.getName().contains(keyword) 
					|| pet.getColor().contains(keyword)) {
					searchResult.add(pet); // �����ѯ���
				}
			}
		}
		return searchResult;
	}
}
class Cat implements Pet { // ʵ�ֳ����׼
	private String name;
	private String color;
	public Cat(String name, String color) {
		this.name = name;
		this.color = color;
	}
	public String getName() {
		return this.name;
	}
	public String getColor() {
		return this.color;
	}
	public boolean equals(Object obj) {
		if (obj == null || !(obj instanceof Cat)) {
			return false;
		}
		if (this == obj) {
			return true;
		}
		Cat cat = (Cat)obj;
		return cat.name.equals(this.name) && cat.color.equals(this.color);
	}
	public String toString() {
		return "������è�� ���֣� " + this.name + "����ɫ�� " + this.color;
	}
}
class Dog implements Pet { // ʵ�ֳ����׼
	private String name;
	private String color;
	public Dog(String name, String color) {
		this.name = name;
		this.color = color;
	}
	public String getName() {
		return this.name;
	}
	public String getColor() {
		return this.color;
	}
	public boolean equals(Object obj) {
		if (obj == null || !(obj instanceof Dog)) {
			return false;
		}
		if (this == obj) {
			return true;
		}
		Dog dog = (Dog)obj;
		return dog.name.equals(this.name) && dog.color.equals(this.color);
	}
	public String toString() {
		return "�����ﹷ�� ���֣� " + this.name + "����ɫ�� " + this.color;
	}
}
class JavaDemo {
	public static void main(String [] args) {
		PetShop shop = new PetShop(); // ����
		shop.add(new Dog("�ư߹�", "��ɫ"));
		shop.add(new Dog("�ƹ�", "��ɫ"));
		shop.add(new Cat("��è", "��ɫ"));
		shop.add(new Cat("�ߵ�è", "��ɫ"));
		shop.add(new Cat("Сǿè", "��ɫ"));
		shop.add(new Dog("����", "��ɫ"));
		shop.add(new Dog("С�ڹ�", "��ɫ"));
		Object [] result = shop.search("��").toArray();
		if (result != null) {
			for (Object obj : result) {
				System.out.println(obj);
			}
		}
	}
}