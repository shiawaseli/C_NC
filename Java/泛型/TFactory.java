interface TIMessage {
	public void send(String str);
}
class MessageImpl implements TIMessage {
	public void send(String str) {
		System.out.println("��Ϣ����: " + str);
	}
}
class TFactory { // ע������û�ж���Ϊ�����ֻ࣬����һ�����ͷ���
	public static <T> T getInstance(String className, Class<T> t) {
		if ("messageImpl".equalsIgnoreCase(className)) {
			// ������ǿת�ᱨ��
			return (T)new MessageImpl();
		}
		return null;
	}
}
class JavaDemo {
	public static void main(String [] args) {
		Integer num [] = fun(1, 3, 4);
		for (int temp : num) {
			System.out.print(temp + ", ");
		}
		System.out.println();
		// System.out.println(TIMessage.class);
		
		TIMessage msg = TFactory.getInstance("messageImpl", TIMessage.class);
		msg.send("������");
	}
	// ���ͷ���Ҳ��������ͨ���ж���
	// ����ʹ��<T>ָ��T��һ��ռλ��
	public static <T> T[] fun(T ... args) {
		return args;
	}
}