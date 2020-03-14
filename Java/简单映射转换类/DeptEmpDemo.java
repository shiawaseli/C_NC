class Dept {
	private long deptno;
	private String dname;
	private String loc;
	private Emp emps []; // �����Ա��Ϣ
	public Dept() {}
	public Dept(long deptno, String dname, String loc) {
		this.deptno = deptno;
		this.dname = dname;
		this.loc = loc;
	}
	public String getInfo() {
		return "��������Ϣ�� ���ű��: " + this.deptno + 
		", ��������: " + this.dname +
		", ����λ��: " + this.loc;
	}
	public void setEmps(Emp [] emps) {
		this.emps = emps;
	}
	public Emp [] getEmps() {
		return this.emps;
	}
}	
class Emp {
	private long empno;
	private String ename;
	private String job;
	private double salary;
	private double comm;
	private Dept dept; // ��������
	private Emp mgr; // �����쵼
	public Emp(long empno, String ename, String job, double salary, double comm) {
		this.empno = empno;
		this.ename = ename;
		this.job = job;
		this.salary = salary;
		this.comm = comm;
	}
	public String getInfo() {
		return "����Ա��Ϣ�� ��Ա���: " + this.empno + 
		",��Ա����: " + this.ename + 
		",��Աְλ�� " + this.job +
		",��������: " + this.salary + 
		",Ӷ��: " + this.comm;
	}
	public Dept getDept() {
		return this.dept;
	}
	public Emp getMgr() {
		return this.mgr;
	}
	public void setDept(Dept dept) {
		this.dept = dept;
	}
	public void setMgr(Emp mgr) {
		this.mgr = mgr;
	}
}
public class DeptEmpDemo {

	public static void main(String [] args) {
		// ��һ���� ���ݹ�ϵ������Ķ���
		// ���������ʵ�������󣬴�ʱ��û���κεĹ�������
		Dept dept = new Dept(10, "����", "�Ϻ�");
		Emp empA = new Emp(7369L, "SMITH", "CLERK", 800.00, 0.0);
		Emp empB = new Emp(7566L, "FIRD", "MANAGER", 2450.00, 0.0);
		Emp empC = new Emp(7839L, "KING", "PRESIDENT", 5000.00, 0.0);
		// ��ҪΪ������й���������
		empA.setDept(dept); // ���ù�Ա�벿�ŵĹ���
		empB.setDept(dept); // ���ù�Ա�벿�ŵĹ���
		empC.setDept(dept); // ���ù�Ա�벿�ŵĹ���
		empA.setMgr(empB); // ���ù�Ա���쵼�Ĺ���
		empB.setMgr(empC); // ���ù�Ա���쵼�Ĺ���
		dept.setEmps(new Emp[] {empA, empB, empC}); // �������Ա
		// �ڶ����� ���ݹ�ϵ��ȡ����
		System.out.println(dept.getInfo());
		for (int i = 0; i < dept.getEmps().length; i++) {
			System.out.println("\t|- " + dept.getEmps()[i].getInfo());
			if (dept.getEmps()[i].getMgr() != null)
				System.out.println("\t\t|- " + dept.getEmps()[i].getMgr().getInfo());
		}
		System.out.println("--------------------------------------------");
		System.out.println(empB.getDept().getInfo()); // ���ݹ�Ա��ȡ������Ϣ
		System.out.println(empB.getMgr().getInfo()); // ���ݹ�Ա��ȡ�쵼��Ϣ

	}
}