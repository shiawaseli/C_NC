class StringUtil {
	private String content; // ��Ҫ������ַ���
	public StringUtil(String content) {
		this.content = content;
	}
	public String getContent() {
		return this.content;
	}
	public String getInfo() { // Ĭ�ϵ���Ϣ����
		return this.getContent();
	}
}
public class StringCount extends StringUtil {
	private int lCount;
	private int oCount;
	public StringCount(String content) {
		super(content);
		this.countChar();
	}
	public void countChar() {
		char [] data = super.getContent().toCharArray();
		for (int i = 0; i < data.length; i++) {
			if (data[i] == 'l' || data[i] == 'L') {
				++lCount;
			}
			else if (data[i] == 'o' || data[i] == 'O') {
				++oCount;
			}
		}
	}
	public int getLCount() {
		return this.lCount;
	}
	public int getOCount() {
		return this.oCount;
	}
	public String getInfo() {
		return "lCount = " + this.lCount +
		", oCount = " + this.oCount;
	}
}
class JavaDemo {
	public static void main(String [] args) {
		String str = "hello world";
		StringCount scnt = new StringCount(str);
		System.out.println("�ַ���Ϊ" + scnt.getContent());
		System.out.println("l�ĸ���Ϊ" + scnt.getLCount());
		System.out.println("o�ĸ���Ϊ" + scnt.getOCount());
	}
}