interface IMessage {
	public String getMessage();
}
// ʹ��ö�ٶ���Color
// ö�����п��Զ��幹�췽�������ǲ�����public����Ȩ��
// ���ǿ���ͨ����д����ķ������public����
// ʹ��ö��ʵ��ԶԶ�ȶ���ģʽҪ�����
enum EColor implements IMessage { // ö����
	// ���ᳫʹ�ú���
	// û���޲ι��죬��Ҫ��ʽ���ù��캯��
	RED("��ɫ"), GREEN("��ɫ"), BLUE("��ɫ"), 
	��ɫ("��ɫ"), ��ɫ("��ɫ"), ��ɫ("��ɫ"); // ʵ��������
	private String title; // ö�ٱ���Ҫд������
	private EColor(String title) {
		this.title = title;
	}
	public String toString() {
		return this.title;
	}
	@Override
	public String getMessage() {
		return this.title;
	}
}

enum EColor1 {
	RED("��ɫ") {
		public String getMessage() {
			return this.toString();
		}
	}, GREEN("��ɫ") {
		public String getMessage() {
			return this.toString();
		}
	}, BLUE("��ɫ") {
		public String getMessage() {
			return this.toString();
		}
	};
	private String title;
	private EColor1(String title) {
		this.title = title;
	}
	public String toString() {
		return this.title;
	}
	// ö�ٿ���ֱ�Ӷ�����󷽷�����ֱ����ÿ��ʵ��ʱ��д
	public abstract String getMessage();
}

/* -------------------------------------------------------------------------------- */

enum Sex {
	MALE("��"), FEMALE("Ů");
	private String title;
	private Sex(String title) {
		this.title = title;
	}
	public String toString() {
		return this.title;
	}
}

class Person {
	private String name;
	private int age;
	private Sex sex;
	public Person(String name, int age, Sex sex) {
		this.name = name;
		this.age = age;
		this.sex = sex;
	}
	public String toString() {
		return "name = " + this.name + 
		", age = " + this.age + 
		", sex = " + this.sex;
	}
}

/* -------------------------------------------------------------------------------- */

class JavaDemo {
	public static void main(String [] args) {
		// ����ģʽʵ�ֵ�Color
		// ��ָ�������ڵ�Ŀ��ʱ������null
		// Color c = Color.getInstance("pink");
		// Color c = Color.getInstance("Blue");
		// System.out.println(c);
		
		// ��ָ�������ڵ�Ŀ��ʱ��ֱ�ӱ�������: �Ҳ�������
		// EColor ec = EColor.��;
		EColor ec = EColor.��ɫ; // ��ȡʵ��������
		System.out.println(ec);
		// ʹ��ö�ٿ��Ժܼ򵥵�ʵ�ֱ���
		for (EColor temp : EColor.values()) {
			System.out.println(temp);
		}
		// switchҲ֧��ʹ��ö��
		switch (ec) {
			case RED:
			case ��ɫ:
				System.out.println("��ɫ");
				break;
			case GREEN:
			case ��ɫ:
				System.out.println("��ɫ");
				break;
			case BLUE:
			case ��ɫ:
				System.out.println("��ɫ");
				break;
		}
		
		// enum�������ʵ���Ǽ̳���Enum�࣬���м̳���ordinal��name����
		for (EColor temp : EColor.values()) {
			System.out.println(temp.ordinal() + " - " + temp.name() + " - " + temp);
		}
		
		IMessage msg = EColor.RED;
		System.out.println(msg.getMessage());
		
		System.out.println(EColor1.RED.getMessage());
		
		System.out.println("-----------------------ʵ��Ӧ��----------------------");
		System.out.println(new Person("����", 20, Sex.MALE));
	}
}