class SynchornizedTest
{
	public static void main(String[] args) 
	{
		Data data=new Data();
		new Thread(new Runnable(){
			public void run(){
				data.add();
			}
		}).start();
		new Thread(new Runnable(){
			public void run(){
				data.dec();
			}
		}).start();
	}

	static class Data
	{
		private int i=0;
		public  void add(){
			i++;
			System.out.println("�߳�"+Thread.currentThread().getName()+"ִ��,j��Ϊ"+i);
		}
		public  void dec(){
			i--;
			System.out.println("�߳�"+Thread.currentThread().getName()+"ִ��,j��Ϊ"+i);
		}
		public int getData(){
			return i;
		}
	}
}
