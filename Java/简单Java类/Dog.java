public class Dog {
	private String name;
	private String color;
	private int age;
	public Dog() {}
	public Dog(String name, String color, int age) {
		this.name = name;
		this.color = color;
		this.age = age;
	}
	public String getInfo() {
		return "��������: " + this.name +
		"\n������ɫ: " + this.color +
		"\n��������: " + this.age;
	}
	public String getName() {
		return this.name;
	}
	public String getColor() {
		return this.color;
	}
	public int getAge() {
		return this.age;
	}
	public void setName(String name) {
		this.name = name;
	}
	public void setColor(String color) {
		this.color = color;
	}
	public void setAge(int age) {
		this.age = age;
	}
}