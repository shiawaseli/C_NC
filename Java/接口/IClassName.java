interface IClassName { // ����ӿ�
	public String getClassName(); // ����һ��Ҫ����
}
class Company implements IClassName {
	public String getClassName() {
		return "Company";
	}
}
class JavaDemo {
	public static void main(String [] args) {
		IClassName ica = new Company();
		System.out.println(ica.getClassName());
	}
}