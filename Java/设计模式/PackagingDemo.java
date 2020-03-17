class Int {
	private int data; // ��װ��һ��������������
	public Int(int data) {
		this.data = data;
	}
	public int intValue() {
		return this.data;
	}
}
/*
 * Java �Դ��а�װ�࣬ʹ�������������ܹ�ת��ΪObject
 * Object��ֱ������: Boolean,Character,Void
 * Object��һ����������: Number---> Integer,Short,Byte,Long,Float,Double
 * Number�Դ��ķ����� intValue,shortValue,byteValue,longValue,floatValue,doubleValue
 */
class JavaDemo {
	public static void main(String [] args) {
		Object obj = new Int(10); // װ��: �������������ͱ����ڰ�װ��֮��
		int num = ((Int)obj).intValue(); // װ��: �Ӱ�װ������л�ȡ������������
		System.out.println(num * 2);
		
		Integer obj1 = new Integer(5);
		int num1 = obj1.intValue();
		System.out.println(num1 * 2);
		
		// 1.5�Ժ�֧���Զ���װ
		Integer obj2 = 10; // �Զ�װ�䣬��ʱ���ٹ��Ĺ��췽����
		int num2 = obj2; // �Զ�����
		obj2++; // ��װ��������ֱ�Ӳ�����ѧ����
		System.out.println(num2 * obj2); // ֱ�Ӳ�����ѧ����
		
		Object obj3 = 19.2; // double�Զ�װ��ΪDouble������ת��ΪObject
		double num3 = (Double)obj3; // ����ת��Ϊ��װ�࣬���Զ�����
		System.out.println(num3 * 2);
		
		Integer xx = 17;
		Integer yy = 17;
		System.out.println(xx == yy); // true
		
		Integer xx1 = 190;
		Integer yy1 = 190;
		System.out.println(xx1 == yy1); // false
		// ��װ�೬��һ���ֽ�ʱ��Ҫʹ��equals()�����бȽ�
		
		Integer xx2 = 17;
		Integer yy2 = new Integer(17);
		System.out.println(xx2 == yy2); // false��ԭ����String��ͬ
	}
}