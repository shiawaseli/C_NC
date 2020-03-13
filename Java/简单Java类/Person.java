public class Person {
	private int age;
	private String name;
	private static String country = "�л����";
	public Person() {
		//System.out.println("********һ��Person�౻������*******");
	}
	public Person(String name) {
		this();
		this.setName(name);
	}
	public Person(String name, int age) {
		this(name);
		if (age >= 0) {
			this.setAge(age);
		}
	}
	public void tell() {
		System.out.println("����: " + this.name + 
		"\n����: " + this.age + 
		"\n����: " + this.country);
	}
	public String getInfo() {
		return "����: " + this.name + 
		"\n����: " + this.age + 
		"\n����: " + this.country;
	}
	public int getAge() {
		return this.age;
	}
	public String getName() {
		return this.name;
	}
	public static String getCountry() {
		return Person.country;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public void setName(String name) {
		this.name = name;
	}
	public static void setCountry(String country) {
		Person.country = country;
	}
}