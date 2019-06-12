import java.io.*;
import java.net.*;
import java.util.Scanner;

public class Client 
{
	
	public static void main(String[] args) 
	{
		try{
			//�������󲢷���
			Socket socket=new Socket("127.0.0.1",1997);
			System.out.println("Successful to connect to Server");
			new ClientThread(socket).start(); //�����ͻ����̲߳�����
		}catch(Exception e){
			System.out.println("������δ����"+e.getMessage());
		}
		
	}

	//�ͻ����߳�
	public static class ClientThread extends Thread
	{
		private static Socket socket;
		private static PrintWriter out=null;
		private static BufferedReader in=null;
		public ClientThread(Socket socket){
			this.socket=socket;
		}
		@Override
		public void run(){
			try{
				//��ȡ�������Ϣ
				in=new BufferedReader(new InputStreamReader(socket.getInputStream()));
				//������Ϣ
				out=new PrintWriter(socket.getOutputStream(),true);//�Զ�ˢ�£���ʱ������Ϣ�������
				while(true){
					Scanner sca=new Scanner(System.in);
					out.println(sca.nextLine());
					System.out.println("Server say: "+in.readLine());
				}
			}catch(Exception e){
				System.out.println("��ȡ������Ϣʧ�� "+e.getMessage());
			}finally{
				try{
					//�ر���
					socket.close();
					in.close();
					out.close();
				}catch(Exception e){
					System.out.println(e.getMessage());
				}
			}
		}
	}
}
