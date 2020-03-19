// �����Զ����쳣��
// �̳� Exception ʱ����ǿ��Ҫ�����쳣
// �̳� RuntimeErrorException ʱ������Ҫ��ǿ�ƴ����쳣
class BombException extends RuntimeException {
	public BombException(String msg) {
		super(msg);
	}
}
class Food {
	public static void eat(int num) throws BombException {
		if (num > 10) {
			throw new BombException("��̫���ˣ����ӱ��ˡ�");
		} else {
			System.out.println("������ʼ�ԣ����³��֡�");
		}
	}
}
class JavaDemo {
	public static void main(String [] args) {
		// Exception in thread "main" BombException: ��̫���ˣ����ӱ��ˡ�
		//     at Food.eat(JavaDemo.java:12)
		//     at JavaDemo.main(JavaDemo.java:20)
		Food.eat(11);
		
		int x = 10;
		
		// �м�ᾭ������x�����Ĳ�������
		
		// ���ԣ�
		// ��Java�ж��Բ�����һ���������ִ�еĲ���
		// ֻ�Ǹ����飬��ʹ������������Ҳ���������
		assert x == 100 : "x�����ݲ���100";
		// ֻ��ʹ�����²�������ʱ���Żᱨ��
		// >java -ea JavaDemo
		// Exception in thread "main" java.lang.AssertionError: x�����ݲ���100
		// 		at JavaDemo.main(JavaDemo.java:6)
		
		System.out.println(x);
	}
}