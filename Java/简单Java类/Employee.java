public class Employee {
	private long empno;
	private String ename;
	private String dept;
	private double salary;
	private double rate;
	public Employee() {
		this(1000, "������", null, 0.0, 0.0);
	}
	public Employee(long empno) {
		this(empno, "��Ա��", "δ��", 0.0, 0.0);
	}
	public Employee(long empno, String ename) {
		this(empno, ename, "δ��", 0.0, 0.0);
	}
	public Employee(long empno, String ename, String dept) {
		this(empno, ename, dept, 0.0, 0.0);
	}
	public Employee(long empno, String ename, String dept, double salary) {
		this(empno, ename, dept, 2500.0, 0.0);
	}
	public Employee(long empno, String ename, String dept, double salary, double rate) {
		this.empno = empno;
		this.ename = ename;
		this.dept = dept;
		this.salary = salary;
		this.rate = rate;
	}
	public String getInfo() {
		return "��Ա���: " + this.empno + 
		"\n��Ա����: " + this.ename + 
		"\n���ڲ���: " + this.dept +
		"\n��������: " + this.salary + 
		"\n����������: " + this.rate;
	}
	public double salaryIncValue() { // �õ�нˮ�������
		return this.salary * this.rate;
	}
	public double salaryIncResult() {
		this.salary = this.salary * (1 + this.rate);
		return this.salary;
	}
	public long getEmpno() {
		return this.empno;
	}
	public String getEname() {
		return this.ename;
	}
	public String getDept() {
		return this.dept;
	}
	public double getSalary() {
		return this.salary;
	}
	public double getRate() {
		return this.rate;
	}
	public void setEmpno(long empno) {
		this.empno = empno;
	}
	public void setEname(String ename) {
		this.ename = ename;
	}
	public void getDept(String dept) {
		this.dept = dept;
	}
	public void getSalary(double salary) {
		this.salary = salary;
	}
	public void getRate(double rate) {
		this.rate = rate;
	}
}