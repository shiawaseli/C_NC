class Array { // ����Ĳ�����
	private int [] data; // ��������
	private int foot;
	public Array(int len) {
		if (len > 0) {
			this.data = new int[len]; // ��������
		} else {
			this.data = new int[1]; // ����һ���ռ�
		}
	}
	// ʵ��������������䣬�������������С��ʵ�ʴ�С: ���д�С+�����С
	public void increment(int num) {
		int [] newData = new int[this.data.length + num];
		System.arraycopy(this.data, 0, newData, 0, this.data.length);
		this.data = newData; // �ı���������
	}
	public boolean add(int num) { // ��������
		if (this.foot < this.data.length) { // ��λ��
			this.data[this.foot++] = num;
			return true;
		}
		return false;
	}
	public int[] getData() {
		return this.data;
	}
}
class SortArray extends Array { // ������������
	public SortArray(int len) {
		super(len);
	}
	public int [] getData() { // ���������
		java.util.Arrays.sort(super.getData()); // ����
		return super.getData();
	}
}
class ReverseArray extends Array { // ���巴ת����
	public ReverseArray(int len) {
		super(len);
	}
	public int [] getData() { // ��÷�ת���
		int center = super.getData().length / 2;
		int temp, head = 0, tail = super.getData().length - 1;
		for (int i = 0; i < center; i++) {
			temp = super.getData()[head];
			super.getData()[head] = super.getData()[tail];
			super.getData()[tail] = temp;
			++head;
			--tail;
		}
		return super.getData();
	}
}
class JavaDemo {
	public static void main(String [] args) {
		Array arr1 = new SortArray(5);
		System.out.println(arr1.add(16));
		System.out.println(arr1.add(82));
		System.out.println(arr1.add(23));
		System.out.println(arr1.add(74));
		System.out.println(arr1.add(55));
		System.out.println(arr1.add(62));
		arr1.increment(3);
		System.out.println(arr1.add(62));
		System.out.println(arr1.add(47));
		System.out.println(arr1.add(89));
		int [] data1 = arr1.getData();
		for (int i : data1) {
			System.out.print(i + ", ");
		}
		System.out.println();
		
		Array arr2 = new ReverseArray(5);
		System.out.println(arr2.add(1));
		System.out.println(arr2.add(2));
		System.out.println(arr2.add(3));
		System.out.println(arr2.add(4));
		System.out.println(arr2.add(5));
		int [] data2 = arr2.getData();
		for (int i : data2) {
			System.out.print(i + ", ");
		}
		System.out.println();
	}
}