class MyMath {
	// �쳣���������ô����д���һ��Ҫ�ڷ�����ʹ��throws
	public static int div(int x, int y) throws Exception {
		int temp;
		System.out.println("********* ��START�� �������㿪ʼ");
		// ע��ǰ�Ǳ�׼��try-catch�ṹ�����������������Ϣʱʹ�ô˽ṹ
		// ������·����ʱ����Ҫ������ӹرյ���ʾ��Ϣ
		try {
			temp = x / y;
		}/* catch (Exception e) { // ʵ���Ͽ���ʡ��catch��throw�Ĳ���
			throw e; // �������쳣
		} */finally {
			// ʹ��finallyʹÿ�ζ���Ȼ�����������ʾ
			// ��ʹ��finally�Ļ����������쳣ʱ���������������ʾ
			System.out.println("********* ��END�� �����������");
		}
		return temp;
	}
}
class JavaDemo {
	public static void main(String [] args) {
		try {
			System.out.println(MyMath.div(10, 0));
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}