import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
class ThreadPoolTest 
{
	public static volatile int j=0;  //ͬһʱ��ֻ����һ���߳��޸���ֵ
	public static volatile boolean exit=false;
	public static void main(String[] args) 
	{

		ExecutorService threadPool=Executors.newFixedThreadPool(10);
		while(!exit){
			new Thread(new Runnable(){
				@Override
				public void run(){
					j=j+1;
					System.out.println("�߳�"+Thread.currentThread().getName()+"����ִ��"+j);
					
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
