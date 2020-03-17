interface IGraphical { // �����ͼ��׼
	public void paint(); // ��ͼ
}
class Point { // ����������
	private double x;
	private double y;
	public Point(double x, double y) {
		this.x = x;
		this.y = y;
	}
	public double getX() {
		return this.x;
	}
	public double getY() {
		return this.y;
	}
	public String toString() {
		return "[" + this.x + "," + this.y + "]";
	}
}
class Triangle implements IGraphical { // ����������
	private Point [] x;
	private Point [] y;
	private Point [] z;
	public Triangle(Point [] x, Point [] y, Point [] z) {
		this.x = x;
		this.y = y;
		this.z = z;
	}
	@Override
	public void paint() {
		System.out.println("�����������Ρ� ��ʼ����: ");
		System.out.println("\t|-����һ���ߡ� ��ʼ����: " + this.x[0] + ", ��������: " + this.x[1]);
		System.out.println("\t|-���ڶ����ߡ� ��ʼ����: " + this.y[0] + ", ��������: " + this.y[1]);
		System.out.println("\t|-���������ߡ� ��ʼ����: " + this.z[0] + ", ��������: " + this.z[1]);
	}
}
class Circular implements IGraphical { // ����Բ��
	private Point center;
	private double radius;
	public Circular(Point center, double radius) {
		this.center = center;
		this.radius = radius;
	}
	@Override
	public void paint() {
		System.out.println("������Բ�Ρ� ��ʼ����: ��" + 
		this.center + "ΪԲ��, ��" + this.radius + "Ϊ�뾶����Բ��");
	}
}
class Factory { // ���幤����
	public static IGraphical getInstance(String className, double ... args) {
		if ("triangl".equalsIgnoreCase(className)) {
			return new Triangle(
				new Point[] {
					new Point(args[0], args[1]), 
					new Point(args[2], args[3])
				}, new Point[] {
					new Point(args[2], args[3]), 
					new Point(args[4], args[5])
				}, new Point[] {
					new Point(args[4], args[5]), 
					new Point(args[0], args[1])
				}
			);
		} else if ("circular".equalsIgnoreCase(className)) {
			return new Circular(new Point(args[0], args[1]), args[2]);
		} else {
			return null;
		}
	}
}
class JavaDemo {
	public static void main(String [] args) {
		IGraphical iga = Factory.getInstance("triangl", 1.1, 2.2, 3.3, 4.4, 5.5, 6.6);
		iga.paint();
		IGraphical iga2 = Factory.getInstance("circular", 2.5, 2.6, 10);
		iga2.paint();
	}
}