interface IChannel { // ����ӿ�
	public void send(); // ������Ϣ
	abstract class AbstractMessage { // �ڲ�������
		public abstract String getContent(); // ��ȡ��Ϣ����
	}
}
class ChannelImpl implements IChannel {
	public void send() {
		AbstractMessage msg = new MessageImpl();
		System.out.println("������Ϣ�� " + msg.getContent());
	}
	class MessageImpl extends AbstractMessage {
		public String getContent() {
			return "www.baidu.com";
		}
	}
}
class JavaDemo {
	public static void main(String [] args) {
		IChannel channel = new ChannelImpl();
		channel.send();
	}
}