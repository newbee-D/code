import java.util.concurrent.Semaphore;
class SemaphoreTest 
{
	public static void main(String[] args) 
	{
		int N=8; //消费者数量
		Semaphore sem=new Semaphore(5); //生产者数量
		for(int i=0;i<N;i++){
			new Worker(i,sem).start();
		}

	}
	static class Worker extends Thread
	{
		private int num;
		private Semaphore sem;
		public Worker(int num,Semaphore sem){
			this.num=num;
			this.sem=sem;
		}
		@Override
		public void run(){
			try{
				sem.acquire();  //获取许可
				System.out.println("工人"+this.num+"拿到了许可");
				Thread.sleep(10000);
				System.out.println("工人"+this.num+"释放了许可");
				sem.release();
				
			}catch(InterruptedException e){
				e.printStackTrace();
			}
		}
			
	}
}
