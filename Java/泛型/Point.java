class Point { // û��ʹ�÷���ʱ��Object������ת������ClassCastException����
	private Object x;
	private Object y;
	public Point() {}
	public Point(Object x, Object y) {
		this.x = x;
		this.y = y;
	}
	public Object getX() {
		return this.x;
	}
	public Object getY() {
		return this.y;
	}
	public void setX(Object x) {
		this.x = x;
	}
	public void setY(Object y) {
		this.y = y;
	}
}

class JavaDemo {
	public static void main(String [] args) {
		Point point = new Point();
		// ��һ���� ��������������ݵ�����
		point.setX(10); // �Զ�װ��
		point.setY(20); // �Զ�װ��
		// point.setY("��γ20��"); // ��ʱ������Integerת�������
		// �ڶ����� �������ȡ����
		int x = (Integer)point.getX();
		int y = (Integer)point.getY();
		System.out.println("x����: " + x + ", y����: " + y);
	}
}