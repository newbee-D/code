public class ThreadTest 
{
	//线程创建

	//继承Thread类
	public static class MyThread extends Thread
	{
		public void run(){
			System.out.println("MyThread run");
		}
	}

	//实现Runnable接口
	public static class MyThreadImp implements Runnable
	{
		public void run(){
			System.out.println("MyThreadImp run");
		}
	}

	public static void main(String[] args) 
	{
		//启动线程的唯一方法就是通过Thread类的start()方法，start()方法是一个native方法
		//他将启动一个新的线程，并执行run()方法
		MyThread my=new MyThread();
		my.start();

		//其实Thread类就实现了Runable接口，算是接口的一个实例
		//所以要启动线程必须将MyThreadImp的实例传入Thread
		MyThreadImp imp=new MyThreadImp();
		Thread th=new Thread(imp);
		th.start();
		
		
	}
}
