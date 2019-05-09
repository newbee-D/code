import java.util.concurrent.Semaphore;
class SemaphoreTest 
{
	public static void main(String[] args) 
	{
		int N=8; //����������
		Semaphore sem=new Semaphore(5); //����������
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
				sem.acquire();  //��ȡ���
				System.out.println("����"+this.num+"�õ������");
				Thread.sleep(10000);
				System.out.println("����"+this.num+"�ͷ������");
				sem.release();
				
			}catch(InterruptedException e){
				e.printStackTrace();
			}
		}
			
	}
}
