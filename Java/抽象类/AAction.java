public abstract class AAction {
	public static final int EAT = 1;
	public static final int SLEEP = 5;
	public static final int WORK = 10;
	public void command(int code) {
		switch (code) {
			case EAT: {
				this.eat();
				break;
			}
			case SLEEP: {
				this.sleep();
				break;
			}
			case WORK: {
				this.work();
				break;
			}
			case EAT + SLEEP + WORK: {
				this.eat();
				this.sleep();
				this.work();
				break;
			}
		}
	}
	public abstract void eat();
	public abstract void sleep();
	public abstract void work();
}
class Person extends AAction {
	@Override
	public void eat() {
		System.out.println("����ʱ�򰲾������³Է���");
	}
	@Override
	public void sleep() {
		System.out.println("���������£�������˯�ţ������������Ρ�");
	}
	@Override
	public void work() {
		System.out.println("�����Ǹ߼����ද�����Ҫ���뷨�Ĺ�����");
	}
}
class Pig extends AAction {
	@Override
	public void eat() {
		System.out.println("��ʳ���е������ʣ����");
	}
	@Override
	public void sleep() {
		System.out.println("���ؾ�˯��");
	}
	@Override
	public void work() {}
}
class Robot extends AAction {
	@Override
	public void eat() {
		System.out.println("��������Ҫ��ͨ��Դ��硣");
	}
	@Override
	public void sleep() {}
	@Override
	public void work() {
		System.out.println("�����˰��չ̶�����·���й�����");
	}
}
class JavaDemo {
	public static void main(String [] args) {
		AAction robot = new Robot();
		AAction person = new Person();
		AAction pig = new Pig();
		System.out.println("----------------��������Ϊ-----------");
		robot.command(AAction.SLEEP);
		robot.command(AAction.WORK);
		System.out.println("----------------�������Ϊ-----------");
		person.command(AAction.SLEEP + AAction.EAT + AAction.WORK);
		System.out.println("-----------------�����Ϊ------------");
		pig.command(AAction.EAT);
		pig.command(AAction.SLEEP);
	}
}