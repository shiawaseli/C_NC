interface IChannel1 { // ����ӿ�
	public void send(IMessage1 msg); // ������Ϣ
	interface IMessage1 { // �ڲ��ӿ�
		public String getContent(); // ��ȡ��Ϣ����
	}
}
class ChannelImpl implements IChannel1 {
	public void send(IMessage1 msg) {
		System.out.println("������Ϣ�� " + msg.getContent());
	}
	// �ڲ��ӿڲ�����һ��Ҫʵ��
	class MessageImpl implements IMessage1 {
		public String getContent() {
			return "www.baidu.com";
		}
	}
}
interface IChannel2 { // ����ӿ�
	public void send(); // ������Ϣ
	class ChannelImpl2 implements IChannel2 {
		public void send() {
			System.out.println("www.hao123.com");
		}
	}
	public static IChannel2 getInstance() {
		return new ChannelImpl2();
	}
}
/*------------------------------------�ڲ�static�ӿ�-------------------------------*/
interface IMessageWarp { // ��Ϣ��װ
	static interface IMessage2 {
		public String getContent();
	}
	static interface IChannel3 {
		public boolean connect(); // ��Ϣ�ķ���ͨ��
	}
	public static void send(IMessage2 msg, IChannel3 channel) { // ��Ϣ����
		if (channel.connect()) {
			System.out.println(msg.getContent());
		} else {
			System.out.println("��Ϣͨ���޷���������Ϣ����ʧ�ܣ�");
		}
	}
}
// ����ͨ��'.'ֱ�Ӽ̳нӿڵ��ڲ�static�ӿ�
class DefaultMessage implements IMessageWarp.IMessage2 {
	public String getContent() {
		return "mail.google.com";
	}
}
class NetChannel implements IMessageWarp.IChannel3 {
	public boolean connect() {
		return true;
	}
}
interface IMessage3 {
	public void send(String str);
	// ʹ��static�������һ�����ӿڵ����������
	public static IMessage3 getInstance() {
		return new IMessage3() {
			public void send(String str) {
				System.out.println(str);
			}
		};
	}
}
class JavaDemo {
	public static void main(String [] args) {
		IChannel1 channel1 = new ChannelImpl();
		channel1.send(((ChannelImpl)channel1).new MessageImpl());
		channel1.send(new ChannelImpl().new MessageImpl());
		
		IChannel2 channel2 = IChannel2.getInstance();
		channel2.send();
		
		//�ڲ�static�ӿ�
		IMessageWarp.send(new DefaultMessage(), new NetChannel());
	
		// �����ڲ���һ��ʹ���ڳ�����ͽӿڣ�����ֻʹ�ü��ε����������
		IChannel2 channel3 = new IChannel2() { // �����ڲ���
			public void send() {
				System.out.println("mail.qq.com");
			}
		};
		channel3.send();
		
		// ʹ��static�������һ�����ӿڵ����������
		IMessage3.getInstance().send("www.bilibili.com");
	}
}