class TMessage <T> { // ֻ��Number��Number�����ܹ�ʹ��
	private T content;
	public void setContent(T content) {
		this.content = content;
	}
	public T getContent() {
		return this.content;
	}
}
class TMessageExtendsNumber <T extends Number> { // ֻ��Number��Number�����ܹ�ʹ��
	private T content;
	public void setContent(T content) {
		this.content = content;
	}
	public T getContent() {
		return this.content;
	}
}
class JavaDemo {
	public static void main(String [] args) {
		TMessage<String> msg1 = new TMessage<String>();
		msg1.setContent("www.baidu.com");
		fun(msg1);
		
		TMessage<Integer> msg2 = new TMessage<Integer>();
		msg2.setContent(1024);
		fun(msg2);
		
		TMessageExtendsNumber<Double> msg3 = new TMessageExtendsNumber<Double>();
		msg3.setContent(3.14);
		fun(msg3);
		
		// �������Ͳ��ܽ���String�͵�TypeΪ����
		// TMessageExtendsNumber<String> msg4 = new TMessageExtendsNumber<String>();
		// msg4.setContent("www.hao123.com");
		// fun(msg4); // �����������ܽ���String�͵�TypeΪ����
	}

	public static void fun(TMessage<?> temp) {
		System.out.println(temp.getContent());
	}
	public static void fun(TMessageExtendsNumber<?extends Number> temp) {
		System.out.println(temp.getContent());
	}
	
	/*
	 * �������෶Χ��С��ͨ���
	 * 1��?extends �ࣺ ���÷��͵�����
	 *	����"?extends Number": ��ʾ�÷�������ֻ��������Number��Number������
	 * 2��?super �ࣺ ���÷��͵�����
	 *	����"?super String": ��ʾֻ��ʹ��String���丸��
	 */
	
	
	/* 
	 * ����1 ���ô���ʱ�������⣬ͬʱֻ����һ��TMessage��Ϊ�����ĺ���
	 * ���ڲ�����Typeֻ����һ��׼ȷ���壬���ֵڶ�������ʱ����������
	 * 20: ����: ���Ƴ�ͻ: fun(TMessage<Integer>)��fun(TMessage<String>)������ͬ�ɷ�
	 * 
	 * public static void fun(TMessage<String> temp) {
	 * 	System.out.println(temp.getContent());
	 * }
	 * public static void fun(TMessage<Integer> temp) {
	 *	System.out.println(temp.getContent());
	 * }
	 */
	 
	 /*
	 * ����2 һ�������÷������ڷ����о���������ݽ����޸ģ���������
	 * 
	 * public static void fun(TMessage temp) {
	 *  temp.setContent(242); // ���Խ����޸�
	 *	System.out.println(temp.getContent());
	 * }
	 */
	 
	 /*
	 * ����3 ʹ��ͳ���'?'ʹ�������Խ������е����ͣ����Ҳ������޸�ֻ�ܻ�ȡ����
	 * �������ʹ���˸�С��Χ��ͨ��� ?extends Number
	 *
	 * public static void fun(TMessage<?extends Number> temp) {
	 * 	//temp.setContent("sdfs"); // ���ܽ����޸�
	 * 	System.out.println(temp.getContent());
	 * }
	 */
}