// ������������ӿ����ƵĶ���Ҫ����ͬ
// Ϊ�����ֽӿ������ڽӿ���ǰ��I��ͷ
interface IMessage { // ������һ���ӿ�
	// �ӿ��еķ���Ĭ����public������default����˸�дʱֻ��ʹ��public
	// ����Ĭ�� public abstract
	// ����Ĭ�� public static final
	/*public static final */String INFO = "www.baidu.cn"; // ȫ�ֱ���
	/*public abstract */String getInfo(); // ���󷽷�
	
	// ͨ������һ�����ɵĳ����࣬�����ÿ�������½ӿڶ���Ҫ��ÿ����������ʵ�ֵ�����
	// 1.8�����˸ı䣬����ֱ���ڽӿ��ж���default��ͨ������static����
	// �������������л��ǲ����鶨����ͨ������static����
	// public default boolean connectMessage() {
	// 	System.out.println("������Ϣ�ķ���ͨ����");
	// 	return true;
	// }
	// ���Զ���static��������ͨ���ӿ���ֱ�ӵ���
	// public static IMessage getInstance() {
	// 	return new MessageImpl(); // ����������
	// }
}

// ʹ�ýӿڿ���ʵ�ֶ�̳�
interface IChannel {
	public abstract boolean connect(); // ������󷽷�
}

abstract class DatabaseAbstract { // ����һ��������
	// �ӿ��е�abstract�ܹ�ʡ�ԣ��������в�����ʡ��
	public abstract boolean getDatabaseConnection();
}

// ��ʱ�ӿ��޷�ֱ�Ӳ���ʵ�������󣬽ӿ�ֻ�б�����ʵ�ֺ����ʹ��
// ����һ��Ҫ��д�ӿ������еĳ��󷽷�
class MessageImpl extends DatabaseAbstract implements IMessage, IChannel { // ʵ���˽ӿ�
	@Override
	public String getInfo() {
		if (this.connect()) {
			if (this.getDatabaseConnection()) {
				return "���ݿ��еõ�һ����Ϣ�����ܵ���Ϣ���������ˣ������ң���";
			} else {
				return "���ݿ���Ϣ�޷����ʡ�";
			}
		}
		return "ͨ������ʧ�ܣ��޷������Ϣ";
	}
	@Override
	public boolean connect() {
		System.out.println("��Ϣ����ͨ���Ѿ��ɹ�������");
		return true;
	}
	@Override
	public boolean getDatabaseConnection() {
		return true;
	}
}

/* -------------------------�ӿڵĶ�̳�----------------------------- */
// extends����̳���ֻ�ܼ̳�һ�����࣬���ǽӿ��Ͽ��Լ̳ж��
interface IService extends IMessage, IChannel { // �ӿڶ�̳�
	public String service();
}
class MessageService implements IService {
	@Override
	public String getInfo() {
		return null;
	}
	@Override
	public boolean connect() {
		return true;
	}
	@Override
	public String service() {
		return "��ȡ��Ϣ����";
	}
}


/*
 * ��ʵ�ʿ����У��ӿڵ�ʹ��������������ʽ: 
 *	1�����б�׼����
 *	2����ʾһ�ֲ���������
 *	3����¶Զ�̷�����ͼ�����һ�㶼��RPC�ֲ�ʽ������ʹ��
*/

class JavaDemo {
	public static void main(String [] args) {
		IMessage msg = new MessageImpl();
		System.out.println(msg.getInfo());
		System.out.println(IMessage.INFO);
		
		IChannel chl = (IChannel)msg;
		System.out.println(chl.connect());
		
		// Object�������Խ��������������ͣ����������������͡�����󡢽ӿڶ�������
		Object obj = (Object)msg; // ����ת��
		IChannel chan = (IChannel)obj; // �Ϸ�
	}
}