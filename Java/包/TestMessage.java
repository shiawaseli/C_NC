package cn.lb.test;
// Ϊ���ܹ�һ�ε������࣬����ʹ��ͨ���'*'
// import cn.lb.util.*
// ע�⣺ ��ʹʹ����'*'�����е��룬Ҳ�������е��඼�ᱻ���أ�
// �������������Ҫ������Ӧ���࣬����ֱ�ӵ���û�����ܲ��

// ����ĳ����Ҫ��ͬʱ������������ͬ��Message��
import cn.lb.demo.*; // Ҳ����������ֱ�ӵ���ָ���࣬��������
import cn.lb.util.*; // ��������������
import cn.lb.sub.NetMessage; // ֱ������Ҫ���Ե�����
public class TestMessage {
	public static void main(String [] args) {
		// ʵ���������
		// cn.lb.util �е��� cn.lb.util.Message �� cn.lb.demo �е��� cn.lb.demo.Message ��ƥ��
		// Message msg = new Message(); // ���ò���ȷ
		cn.lb.util.Message msg = new cn.lb.util.Message(); // ��ȷָ��ʹ�õİ�
		System.out.println(msg.getContent());
		
		// ����protected����Ȩ��
		new NetMessage().print();
		// System.out.println(new Message().info); // ���뱨���޹�ϵ���಻��ֱ�ӷ���protected��Ա
	}
}