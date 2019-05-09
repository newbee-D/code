import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
class ThreadPoolTest 
{
	public static volatile int j=0;  //同一时刻只允许一个线程修改其值
	public static volatile boolean exit=false;
	public static void main(String[] args) 
	{

		ExecutorService threadPool=Executors.newFixedThreadPool(10);
		while(!exit){
			new Thread(new Runnable(){
				@Override
				public void run(){
					j=j+1;
					System.out.println("线程"+Thread.currentThread().getName()+"正在执行"+j);
					
					try{
						
						Thread.sleep(9000);
					}catch(InterruptedException e){
						e.printStackTrace();
					}finally{
					}
				}
			}).start();
		}
	}
}
