class Outer {
	private String msg = "www.baidu.com";
	public void fun(/*final*/ long time) {
		// 1.8��ǰҪ���ڲ����ܹ�ֱ�ӷ��ʾֲ���������������Ҫʹ��final
		// ֮����ȡ�����������ƣ���Ҫ��Ϊ��֧��1.8����չ�ĺ���ʽ���
		/*final*/ String info = "�Һܺ�";
		class Inner { // �ڲ���
			// 1.8�Ժ��ڲ����ܹ�ֱ�ӷ��ʾֲ�����
			public void print() {
				System.out.println(Outer.this.msg);
				System.out.println(time);
				System.out.println(info);
			}
		}
		new Inner().print(); // ������ֱ��ʵ�����ڲ���
	}
}
class JavaDemo {
	public static void main(String [] args) {
		new Outer().fun(3423456L);
	}
}