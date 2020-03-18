class TPoint <T> {
	// ��ʱx,y�����Ͳ���ȷ��
	private T x;
	private T y;
	public TPoint() {}
	public TPoint(T x, T y) {
		this.x = x;
		this.y = y;
	}
	public T getX() {
		return this.x;
	}
	public T getY() {
		return this.y;
	}
	public void setX(T x) {
		this.x = x;
	}
	public void setY(T y) {
		this.y = y;
	}
}
// ʹ�÷��Ϳ��Խ���󲿷ֵ�������ǿ������ת���������ĳ������һ����������
// ���뷺�ͺ�Ͳ���Ҫ��ʹ��Object�����������ͣ���ΪObject����ת������
class JavaDemo {
	public static void main(String [] args) {
		// TPoint point = new TPoint(); // ������<Type>ʱ���Զ���ʹ��Object������ֱ��뾯��
		// Type����ֱ��ʹ�û����������ͣ���ʱ����ʹ�ð�װ����ΪType
		// 1.7��ʼ�����Ͷ���ʵ�������Լ�ΪTPoint<Integer> point = new TPoint<>();
		TPoint<Integer> point = new TPoint<Integer>();
		// ��һ���� ��������������ݵ�����
		point.setX(10); // �Զ�װ��
		point.setY(20); // �Զ�װ��
		// point.setY("��γ20��"); // ��ʱ��ֱ�ӱ��뱨��
		// �ڶ����� �������ȡ����
		// ָ����Type�󣬿��Բ���ת��
		int x = point.getX();
		int y = point.getY();
		System.out.println("x����: " + x + ", y����: " + y);
	}
}