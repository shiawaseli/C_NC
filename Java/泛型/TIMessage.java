interface TIMessage<T> { // ���ͽӿ�
	public String echo(T t);
}
// ʵ�ַ�ʽ1 ��������Ϊ����
class TMessageImpl<S> implements TIMessage<S> {
	public String echo(S t) {
		return "��ECHO�� " + t;
	}
}
// ʵ�ַ�ʽ2 �����ඨ�常�ӿڵ�ʱ��ֱ�Ӷ�������巺������
class MessageImplString implements TIMessage<String> {
	public String echo(String t) {
		return "��ECHO�� " + t;
	}
}
class JavaDemo {
	public static void main(String [] args) {
		TIMessage<String> msg1 = new TMessageImpl<String>();
		System.out.println(msg1.echo("www.baidu.com"));
		
		TIMessage<String> msg2 = new MessageImplString();
		System.out.println(msg2.echo("www.hao123.com"));
	}
}