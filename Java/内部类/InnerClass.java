class Outer { // �ⲿ��
	private String msg = "www.baidu.com"; // ˽�г�Ա����
	public void fun1() { // ��ͨ����
		Inner1 in = new Inner1(); // ʵ�����ڲ������
		in.print(); // �����ڲ��෽��
		System.out.println(in.info); // �����ڲ����˽������
	}
	// �ڲ����ܹ�����ķ����ⲿ���е�˽������
	// �ڲ������ⲿ��֮���˽�в����ķ��ʲ�����Ҫgetter��setter�ȼ�ӷ���
	class Inner1 { // ��Outer����ڲ�������Inner1��
	private String info = "�����������ã����·�����";
		public void print() {
			System.out.println(Outer.this.msg); // Ouber���е�����
		}
	}
	
	// ˼��һ�� msg�������Ҫ���ⲿ������Ҫ�ṩ��getter����
	public String getMsg() {
		return this.msg;
	}
	public void fun2() { // ��ͨ����
		// ˼���壺 ��Ҫ����ǰ����Outer���ݵ�Inner2��֮��
		Inner2 in = new Inner2(this); // ʵ����inner2�����
		in.print(); // ����inner2�෽��
		System.out.println(in.getInfo()); // ����inner2���˽������
	}
	
	private class Inner3 { // ��Outer����ڲ�������Inner3��
	private String info = "��������һ�㣬���Ǵ��ڼ�����ɡ�";
		public void print() {
			System.out.println(Outer.this.msg); // Ouber���е�����
		}
	}
	
	private static final String MSG = "www.baidu.com";
	// �ڲ�static��
	static class Inner4 {
		public void print() {
			System.out.println(Outer.MSG);
		}
	}
}
class Inner2 { // ģ���ڲ���inner1ʵ����ͬ�Ĺ���
	private String info = "�������Ǻ���������ȥ���·��ɡ�";
	// ˼������ inner2��������ʵ������ʱ����ҪOuter�������
	private Outer out;
	// ˼���ģ� Ӧ��ͨ��Inner2��Ĺ��췽����ȡOuter�����
	public Inner2(Outer out) {
		this.out = out;
	}
	public void print() {
		// ˼������ �����Ҫ�����ⲿ���е�getter��������ôһ��Ҫ��Outer�����
		System.out.println(this.out.getMsg()); // Ouber���е�����
	}
	public String getInfo() {
		return this.info;
	}
}
class JavaDemo {
	public static void main(String [] args) {
		Outer out = new Outer();
		out.fun1();
		out.fun2();
		
		// ʵ�����ڲ���ķ�����
		// �ⲿ��.�ڲ��� �ڲ������ = new �ⲿ��().new �ڲ���();
		Outer.Inner1 in1 = new Outer().new Inner1();		
		// �ڲ���������֮����γ�һ��Outer$Inner1.class���ļ�������'$'���������оͱ�Ϊ��'.'
		// �ڲ����ȫ�ƾ���"�ⲿ��.�ڲ���"
		// ֻ����ʵ�������ⲿ��֮�����ʵ�����ڲ���
		in1.print();
		
		// Inner3��private����ģ���ʱ��Inner3�޷����ⲿ����ʹ��
		// ����: Outer.Inner3������Outer�з���private
        //         Outer.Inner3 in2 = new Outer().new Inner3();
		// Outer.Inner3 in2 = new Outer().new Inner3();
		// in2.print();
		
		// ʵ�����ڲ�static��ķ�����
		// �ⲿ��.�ڲ��� �ڲ������ = new �ⲿ��.�ڲ���();
		Outer.Inner4 in3 = new Outer.Inner4();
		in3.print();
	}
}