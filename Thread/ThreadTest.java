public class ThreadTest 
{
	//�̴߳���

	//�̳�Thread��
	public static class MyThread extends Thread
	{
		public void run(){
			System.out.println("MyThread run");
		}
	}

	//ʵ��Runnable�ӿ�
	public static class MyThreadImp implements Runnable
	{
		public void run(){
			System.out.println("MyThreadImp run");
		}
	}

	public static void main(String[] args) 
	{
		//�����̵߳�Ψһ��������ͨ��Thread���start()������start()������һ��native����
		//��������һ���µ��̣߳���ִ��run()����
		MyThread my=new MyThread();
		my.start();

		//��ʵThread���ʵ����Runable�ӿڣ����ǽӿڵ�һ��ʵ��
		//����Ҫ�����̱߳��뽫MyThreadImp��ʵ������Thread
		MyThreadImp imp=new MyThreadImp();
		Thread th=new Thread(imp);
		th.start();
		
		
	}
}
