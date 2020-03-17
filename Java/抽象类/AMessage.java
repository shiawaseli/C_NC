abstract class AMessage { // ���������
	private String type;
	public AMessage(String type) { // û���ṩ�޲ι���
		this.type = type;
	}
	public abstract String getConnectInfo(); // ���󷽷�
	public String getType() {
		return "type: " + this.type;
	}
	public void setType(String type) {
		this.type = type;
	}
	// static�������ܳ������Ӱ�죬����ֱ��ʹ����������
	public static AMessage getInstance() {
		return new DatabaseAMessage();
	}
}
class DatabaseAMessage extends AMessage { // ��ļ̳й�ϵ
	public DatabaseAMessage() {
		super("������Ϣ"); // ������ʽ���ø���Ĺ��췽��
	}
	@Override // Annotationע��
	public String getConnectInfo() { // ������д
		return "Oracle���ݿ�������Ϣ";
	}
}
class JavaDemo {
	public static void main(String [] args) {
		AMessage msg = AMessage.getInstance();
		System.out.println(msg.getConnectInfo());
		System.out.println(msg.getType());
		msg.setType("�ͻ���Ϣ");
		System.out.println(msg.getConnectInfo());
		System.out.println(msg.getType());
	}
}