import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
class ThreadPoolTest 
{
	//public static volatile int j=0;  //同一时刻只允许一个线程修改其值
	//public static volatile boolean exit=false;
	public static void main(String[] args) 
	{
		ExecutorService threadPool=Executors.newFixedThreadPool(10);
		for(int i=0;i<20;i++){
			threadPool.execute(new MyThread(i)); //提交任务
		}
	}

	public static class MyThread extends Thread
	{
		private int num;
		public MyThread(int num){
			this.num=num;
		}
		public void run(){
			try{
				System.out.println("Thread "+this.num+" is running");
				Thread.sleep(3000);
				System.out.println("Thread "+this.num+" is dead");
			}catch(InterruptedException e){
				e.printStackTrace();
			}
		}
	}
}
