import java.util.function.*;
/*
 *		Java�ڽ��м����Ƚϵ��͵ĺ���ʽ�ӿ����£�
 *	1�������ͺ���ʽ�ӿڣ� �������ݲ����ؽṹ
 *		��String�����ṩ��һ�����ղ���ͬʱ�з��ز�������ķ���
 *			|- String.startsWith;
 * 		@FunctionalInterface
 * 		public interface Function<T, R> {
 * 			public R apply(T t);
 * 		}

 *	2�������ͺ���ʽ�ӿڣ� ֻ�ܽ������ݵĴ����������û���κεķ���
 *		�ڽ���ϵͳ���������ʱ��ʹ����һ�����ղ�����û�з���ֵ�ķ���
 *			|- System.out.println;
 * 		@FunctionalInterface
 * 		public interface Consumer<T> {
 * 			public void apply(T t);
 * 		}
 *
 * 	3�������ͺ���ʽ�ӿڣ� ���������ݣ�ֻ�з��صĲ���
 *		��String�����ṩ��һ��û�н��ղ����������з���ֵ�ķ���
 *			|- String.toLowerCase;
 *		@FunctionalInterface
 * 		public interface Supplier<T> {
 * 			public T get();
 * 		}
 *
 *	4�������ͺ���ʽ�ӿڣ� ���������жϴ���
 *		��String�����ṩ��һ��ֻ�����жϵķ���
 *			|- String.equalsIgnoreCase;
 *		@FunctionalInterface
 * 		public interface Predicate<T> {
 * 			public boolean test(T t);
 * 		}
*/
class JavaDemo {
	public static void main(String [] args) {
		Function<String, Boolean> fun = "**Function"::startsWith;
		System.out.println(fun.apply("**"));
		
		Consumer<String> con = System.out::println;
		con.accept("www.baidu.com");
		
		Supplier<String> sup = "WWW.HAO123.COM"::toLowerCase;
		System.out.println(sup.get());
		
		Predicate<String> pre = "lb"::equalsIgnoreCase;
		System.out.println(pre.test("LB"));
	}
}