// ͬʱcatch�����֪���쳣���������쳣�ľ���
// ��ʱ��ȫ����ͨ���жϱ����쳣��������catch����쳣
class JavaDemo {
	public static void main(String [] args) {
		// 1����ʱ���벻����ִ�л�����쳣
		// ��1�� *******************����ʼִ��********************
		// Exception in thread "main" java.lang.ArithmeticException: / by zero
		//		at JavaDemo.main(JavaDemo.java:5)
		// System.out.println("��1�� *******************����ʼִ��********************");
		// System.out.println("��2�� *******************��ѧ���㣺 " + (10 / 0));
		// System.out.println("��3�� *******************����ִ�н���********************");
		
		System.out.println("��1�� *******************����ʼִ��********************");
		try {
			// ��ʱ�����������쳣��
			// 1����δ����״̬�� ����ִ�е�ʱ��û�������ʼ������
			// >java JavaDemo (�س�)
			// ��1�� *******************����ʼִ��********************
			// ��finally�� �����Ƿ������쳣������ִ��
			// Exception in thread "main" java.lang.ArrayIndexOutOfBoundsException: 0
			//		at JavaDemo.main(JavaDemo.java:15)
			// 2����δ����״̬�� ��������ݲ�������
			// >java JavaDemo a b (�س�)
			// ��1�� *******************����ʼִ��********************
			// ��finally�� �����Ƿ������쳣������ִ��
			// Exception in thread "main" java.lang.NumberFormatException: For input string: "a"
			// 		at java.lang.NumberFormatException.forInputString(Unknown Source)
			// 		at java.lang.Integer.parseInt(Unknown Source)
			// 		at java.lang.Integer.parseInt(Unknown Source)
			// 		at JavaDemo.main(JavaDemo.java:15)
			// 3�����Ѵ���״̬�� ����ı�����Ϊ0
			// >java JavaDemo 10 0 (�س�)
			// ��1�� *******************����ʼִ��********************
			// ��catch�����쳣�� java.lang.ArithmeticException: / by zero
			// ��finally�� �����Ƿ������쳣������ִ��
			// ��3�� *******************����ִ�н���********************
			
			int x = Integer.parseInt(args[0]);
			int y = Integer.parseInt(args[1]);
			System.out.println("��2�� *******************��ѧ���㣺 " + (x / y));
		} /*catch (ArrayIndexOutOfBoundsException e) { // �����һ���쳣
			System.out.println("��catch�����쳣�� " + e);
		} catch (NumberFormatException e) { // ����ڶ����쳣
			System.out.println("��catch�����쳣�� " + e);
		} */catch (ArithmeticException e) {
			// e.printStackTrace(); // ���������쳣��Ϣ�������ļ������к�
			System.out.println("��catch�����쳣�� " + e); // �����쳣
		} finally { // finally
			// ��ʹ�쳣û����������finally���ǻ�ִ��
			System.out.println("��finally�� �����Ƿ�����쳣������ִ��");
		}
		System.out.println("��3�� *******************����ִ�н���********************");
	}
}