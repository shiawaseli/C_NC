public class JavaDemo {
	/*
	static {
		// ��̬������������������ִ��
		System.out.println("***********����̬�顿�����ʼ��***********");
	}
	*/
	public static void main(String [] args) {
		Book b1 = new Book();
		Book b2 = new Book("JAVA");
		Book b3 = new Book("Orcale", 363);
		Book b4 = new Book("C++Primer", 564);
		System.out.println(b1.getInfo());
		System.out.println(b2.getInfo());
		System.out.println(b3.getInfo());
		System.out.println(b4.getInfo());
		System.out.println("ͼ���ܲ���: " + Book.getCount());
		System.out.println();
		
		Address address = new Address("�л����񹲺͹�", "ɽ��", "��˳�", "������", "234423");
		System.out.println(address.getInfo());
		System.out.println();
		
		Dept dept = new Dept(4234, "��Ŀ", "�Ϻ�");
		System.out.println(dept.getInfo());
		System.out.println();
		
		Employee emp = new Employee(2012, "��ķ", "��Ŀ", 2564.2, 0.3);
		System.out.println(emp.getInfo());
		System.out.println("���ʵ������: " + emp.salaryIncValue());
		System.out.println(emp.getInfo());
		System.out.println("�ϵ���Ĺ���: " + emp.salaryIncResult());
		System.out.println(emp.getInfo());
		System.out.println();
		
		Person p1 = new Person("�ܿ�", 34);
		Person p2 = new Person("��˹", 36);
		Person p3 = new Person("���ɵ�", 24);
		Person.setCountry("ú��");
		System.out.println(p1.getInfo());
		System.out.println(p2.getInfo());
		System.out.println(p3.getInfo());
		System.out.println();
		
		Dog dog = new Dog("С��", "��ɫ", 3);
		System.out.println(dog.getInfo());
		dog.setAge(5);
		dog.setName("���");
		System.out.println(dog.getInfo());
		System.out.println();
		
		Account ac = new Account("С��", 25642.5);
		System.out.println(ac.getInfo());
		System.out.println();

		User userA = new User();
		User userB = new User("Сǿ");
		User userC = new User("��ǿ", "���");
		System.out.println(userA.getInfo());
		System.out.println(userB.getInfo());
		System.out.println(userC.getInfo());
		System.out.println(User.getCount());
		System.out.println();
	}
}