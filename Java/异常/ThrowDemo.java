class MyMath {
	// ��ʾ�������ִ�е�ʱ����ܲ����쳣����������쳣��Ҫ�ڵ��ô����д���
	// ������ʱ���� ����: δ������쳣����Exception; ���������в���������Ա��׳�
	public static int div(int x, int y) throws Exception {
		return x / y;
	}
}
class JavaDemo {
	public static void main(String [] args) {
		try {
			// throw�����׳��쳣
			// 1���Լ��׵��쳣Ҳ��Ҫtry������Ȼ����뱨��
			// ����: δ������쳣����Exception; ���������в���������Ա��׳�
            //            throw new Exception("�Լ�������Ķ���");
			throw new Exception("�Լ�������Ķ���");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	// ������Ҳ�����������쳣����ʱ�Ͳ���Ҫ������������������쳣��
	// ��ʾ���쳣����JVM������д���ʵ��ʹ����һ�㲻����ôʹ��
	// public static void main(String [] args) throws Exception {
	// 	System.out.println(MyMath.div(10, 0));
	// }
	
	// public static void main(String [] args) {
	// 	try {
	// 		// ��ʱ����û�д���Ҳ��Ҫʹ��try
	// 		// throws ǿ����Ҫʹ��try������ܴ��ڵ��쳣
	// 		System.out.println(MyMath.div(10, 0));
	// 	} catch (Exception e) {
	// 		e.printStackTrace();
	// 	}
	// }
}