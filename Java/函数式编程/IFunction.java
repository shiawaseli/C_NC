@FunctionalInterface
interface IFunction1<P, R> {
	public R change(P p);
	// ����ȡ���������������ǲ��ᳫ��ô��
	// public R ת��(P p);
}
@FunctionalInterface
interface IFunction2<R> {
	public R upper();
}
@FunctionalInterface
interface IFunction3<P> {
	public int compare(P p1, P p2);
}
class Person {
	private String name;
	private int age;
	public Person(String name, int age) {
		this.name = name;
		this.age = age;
	}
	public String toString() {
		return "name = " + this.name +
		", age = " + this.age;
	}
}
@FunctionalInterface
interface IFunction4<R> {
	public R create(String s, int a);
}
class JavaDemo {
	public static void main(String [] args) {
		// MethodReferences ��������
		// �����������������ص��ǿ��Խ����ڴ��ָ����
		// �����ڴ�ͳ�Ŀ���֮��һֱ��ʹ�õ�ֻ�Ƕ������ò�����
		// ��JDK1.8֮��Ҳ�ṩ�з��������ã�����ͬ�ķ������ƿ�������ͬһ��������
		// �ṩ�������õĸ������������Ҳֻ���ֲ��˶������õ�֧�ֹ���

		// ���Ҫ���з��������ã���Java�����ṩ�����µ����֣�	
		// 1�����þ�̬���� �������ƣ���static�������ơ�
		//	��String�������ṩ��String.valueOf()������������������ھ�̬����
		//		|- �������壺 public static String valueOf(int i), �÷����в��������һ��з���ֵ
		IFunction1<Integer, String> fun1 = String::valueOf;
		String str1 = fun1.change(100);
		System.out.println(str1.length());
		
		// 2������ʵ���������еķ��� ��ʵ�������󣺣���ͨ������
		//	��String�������ṩ��һ��ת��д�ķ����� public String toUpperCase()
		//		|- ��������Ǳ�������ʵ���������ṩ������²ſ��Ե���
		IFunction2<String> fun2 = "www.baidu.com"::toUpperCase;
		System.out.println(fun2.upper());
		
		// 3�������ض����͵ķ��� ���ض��ࣺ����ͨ������
		// 	�ڽ��з������õ�ʱ��Ҳ���������ض����е�һЩ����������
		//	��String�������ṩ��һ���ַ�����С��ϵ�ıȽ�
		//		|- �ȽϷ����� public int compareTo(String anotherString);
		// 			����һ����ͨ���������Ҫ������ͨ����������������Ҫʵ��������
		//			�������˵�������ʵ��������ֻ�������������������Ϳ���ʹ���ض��������ô���
		IFunction3<String> fun3 = String::compareTo;
		System.out.println(fun3.compare("A", "a"));
		
		// 4�����ù��췽�� �������ƣ���new��
		// �ڷ����������������ɱ�����ľ��ǹ��췽��������
		IFunction4<Person> fun4 = Person::new;
		System.out.println(fun4.create("����", 20));
	}
}