public class Join 
{
	public static void main(String[] args) throws InterruptedException 
	{
		ThreadJoinTest t1=new ThreadJoinTest("����");
		ThreadJoinTest m=new TheradJoinTest("����");
	}
}

class ThreadJoinTest extends Thread
{
	public ThreadJoinTest(String name){
		super(name);
	}
	@Override
	public void run(){
		for(int i=100;i<1000;i++){
			System.out.println(this.getName()+":"+i);
		}
	}
}
