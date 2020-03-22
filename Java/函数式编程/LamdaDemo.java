/*
 * Lambda���ʽ�����¼��ָ�ʽ��
 * 	����û�в����� ()->{};
 * 	�����в����� (����, ����)->{};
 * 	�������ֻ��һ����䷵�أ� (����, ����)->���;
 */
 
// Ҫʹ��Lambda���ʽ��һ����Ҫ��ʵ��Ҫ��
// SAM��Single Abstract Method������ֻ��һ�����󷽷�����
@FunctionalInterface // ����ʽ�ӿ�
interface IMessage1 {
	public void send(String str);
}
@FunctionalInterface // ����ʽ�ӿ�
interface IMessage2 {
	public void send();
}
@FunctionalInterface // ����ʽ�ӿ�
interface IMath {
	public int add(int x, int y);
}
class JavaDemo {
	public static void main(String [] args) {
		// �����ڲ���ʵ��
		IMessage1 msg1 = new IMessage1(){
			public void send(String str) {
				System.out.println("������Ϣ�� " + str);
			}
		};
		msg1.send("www.hao123.com");
		
		// Lambda���ʽʵ��
		IMessage1 msg2 = (str)->{
			System.out.println("������Ϣ�� " + str);
		};
		msg2.send("www.baidu.com");
		
		IMessage2 msg3 = ()->{
			System.out.println("������Ϣ�� mail.qq.com");
		};
		msg3.send();
		
		IMath math1 = (x, y)-> x + y;
		IMath math2 = (x, y)->{
			return x + y;
		};
		System.out.println(math1.add(10, 20));
		System.out.println(math2.add(10, 20));
	}
}