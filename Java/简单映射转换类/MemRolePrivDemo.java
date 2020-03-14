class Member {
	private String mid;
	private String name;
	private Role [] roles;
	public Member(String mid, String name) {
		this.mid = mid;
		this.name = name;
	}
	public String getInfo() {
		return "���û���Ϣ�� mid = " + this.mid +
		", name = " + this.name;
	}
	public Role [] getRoles() {
		return this.roles;
	}
	public void setRoles(Role [] roles) {
		this.roles = roles;
	}
}
class Role {
	private long rid;
	private String title;
	private Member [] members;
	private Privilege [] privileges;
	public Role(long rid, String title) {
		this.rid = rid;
		this.title = title;
	}
	public String getInfo() {
		return "����ɫ��Ϣ�� rid = " + this.rid +
		", title = " + this.title;
	}
	public Member [] getMembers() {
		return this.members;
	}
	public Privilege [] getPrivileges() {
		return this.privileges;
	}
	public void setMembers(Member [] members) {
		this.members = members;
	}
	public void setPrivileges(Privilege [] privileges) {
		this.privileges = privileges;
	}
}
class Privilege {
	private long pid;
	private String title;
	private Role role;
	public Privilege(long pid, String title) {
		this.pid = pid;
		this.title = title;
	}
	public String getInfo() {
		return "��Ȩ����Ϣ�� pid = " + this.pid +
		", title = " + this.title;
	}
	public Role getRole() {
		return this.role;
	}
	public void setRole(Role role) {
		this.role = role;
	}
}

public class MemRolePrivDemo {
	public static void main(String [] args) {
		// ��һ���� ���ݽṹ���ö�������
		Member memA = new Member("lb-a", "����");
		Member memB = new Member("lb-b", "����");
		Role roleA = new Role(1L, "ϵͳ����");
		Role roleB = new Role(2L, "���ݹ���");
		Role roleC = new Role(3L, "���¹���");
		Privilege priA = new Privilege(1000L, "ϵͳ��ʼ��");
		Privilege priB = new Privilege(1001L, "ϵͳ��ԭ");
		Privilege priC = new Privilege(1002L, "ϵͳ�����޸�");
		Privilege priD = new Privilege(1003L, "����Ա������");
		Privilege priE = new Privilege(1004L, "���ݲ�������");
		Privilege priF = new Privilege(1005L, "���ݹ�������");
		Privilege priG = new Privilege(1006L, "����Ա��");
		Privilege priH = new Privilege(1007L, "�༭Ա��");
		Privilege priI = new Privilege(1006L, "���Ա��");
		Privilege priJ = new Privilege(1007L, "Ա����ְ");
		// ���ӽ�ɫ��Ȩ�޵Ķ�Ӧ��ϵ
		roleA.setPrivileges(new Privilege[] {priA, priB, priC});
		roleB.setPrivileges(new Privilege[] {priD, priE, priF});
		roleC.setPrivileges(new Privilege[] {priG, priH, priI, priJ});
		// ����Ȩ�����ɫ��Ӧ
		priA.setRole(roleA);
		priB.setRole(roleA);
		priC.setRole(roleA);
		priD.setRole(roleB);
		priE.setRole(roleB);
		priF.setRole(roleB);
		priG.setRole(roleC);
		priH.setRole(roleC);
		priI.setRole(roleC);
		priJ.setRole(roleC);
		// �����û����ɫ�Ķ�Ӧ��ϵ
		memA.setRoles(new Role[] {roleA, roleB});
		memB.setRoles(new Role[] {roleA, roleB, roleC});
		roleA.setMembers(new Member[] {memA, memB});
		roleB.setMembers(new Member[] {memA, memB});
		roleC.setMembers(new Member[] {memB});
		// �ڶ����� ����Ҫ���ȡ����
		System.out.println("---------------ͨ���û�������Ϣ------------");
		System.out.println(memB.getInfo());
		for (int i = 0; i < memB.getRoles().length; i++) {
			System.out.println("\t|- " + memB.getRoles()[i].getInfo());
			for (int j = 0; j < memB.getRoles()[i].getPrivileges().length; j++) {
				System.out.println("\t\t|- " + memB.getRoles()[i].getPrivileges()[j].getInfo());
			}
		}
		System.out.println("---------------ͨ����ɫ������Ϣ------------");
		System.out.println(roleB.getInfo());
		System.out.println("\t|- ����˽�ɫ�µ�����Ȩ����Ϣ");
		for (int i = 0; i < roleB.getPrivileges().length; i++ ) {
			System.out.println("\t\t|- " + roleB.getPrivileges()[i].getInfo());
		}
		System.out.println("\t|- ����˽�ɫ�µ������û���Ϣ");
		for (int i = 0; i < roleB.getMembers().length; i++ ) {
			System.out.println("\t\t|- " + roleB.getMembers()[i].getInfo());
		}
		System.out.println("---------------ͨ��Ȩ�޲�����Ϣ------------");
		System.out.println(priA.getInfo());
		for (int i = 0; i < priA.getRole().getMembers().length; i++) {
			System.out.println("\t|- " + priA.getRole().getMembers()[i].getInfo());
		}
	}
}