/*
	����ģʽ��
		�ڶ���ģʽ�У�����������ж��ʵ�������Ҷ���������Լ������������Լ���ʵ������������ṩ�Լ���ʵ����
		
	ע�⣺
		1. ͨ��ʵ����������������
		2. ����˽�й�����ֹ�ⲿ���졣
		3. �ṩgetInstantce()������ȡʵ����
		
	��Ҫ�����
		Ϊ�˷�ֹ�������⣻��һ������ı��˶����״̬����ʱ�����ִ�����һ������
		��֮ǰ����Զ���״̬�ĸı䵼���˶������һ���������˴���Ĵ���
		
	��ʱʹ�ã�
		�����пɸı��״̬ʱ������ȷ��˵������ʵ��Ӧ���и�״̬��ı䣩��
		
	�ؼ����룺
		���캯����˽�еġ�
		
	Ӧ��ʵ����
		1���Դ��齫Ϊ����ÿ�̿��ֶ��������ӣ����������������ֻ��2����
		���Գ���֮����ǣ����ӵĵĸ��������޵ģ�ÿ������ͬ��״̬��

*/
class Color {
	private static final Color RED = new Color("��ɫ");
	private static final Color GREEN = new Color("��ɫ");
	private static final Color BLUE = new Color("��ɫ");
	private String title;
	private Color(String title) { // ���췽��˽�л�
		this.title = title;
	}
	public static Color getInstance(String color) {
		switch (color.toLowerCase()) {
			case "red": return RED;
			case "green": return GREEN;
			case "blue": return BLUE;
			default: return null;
		}
	}
	public String toString() {
		return this.title;
	}
}
class JavaDemo {
	public static void main(String [] args) {
		// ��ָ�������ڵ�Ŀ��ʱ������null
		// Color c = Color.getInstance("pink");
		Color c = Color.getInstance("Blue");
		System.out.println(c);
	}
}