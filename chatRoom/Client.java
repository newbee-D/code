import java.io.*;
import java.net.*;
import java.util.Scanner;
/*
*�ͻ���
*author��djs
*/
public class Client 
{
	private static final int PORT=1997;
	private static final String IP="127.0.0.1";
	public static void main(String[] args) 
	{
		try{
			//�������󲢷���
			Socket socket=new Socket(IP,PORT);
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
		public ClientThread(Socket socket){
			this.socket=socket;
		}
		@Override
		public void run(){
			new GetClientMsg(socket).start(); //�����߳�
			new SendToClient(socket).start();
		}
	}
	//�������߳�(��ȡ�������Ϣ)
	public static class GetClientMsg extends Thread
	{
		private Socket socket;
		private BufferedReader in=null;
		public GetClientMsg(Socket socket){
			this.socket=socket;
		}
		@Override
		public void run(){
			try{
				in=new BufferedReader(new InputStreamReader(socket.getInputStream()));
				while(true){
					System.out.println("Server say: "+in.readLine());
				}
			}catch(Exception e){
				System.out.println("��ȡ��Ϣʧ�� "+e.getMessage());
			}finally{
				try{
					socket.close();
					in.close();
				}catch(Exception e){
					e.printStackTrace();
				}
			}
		}

	}
	//�������߳�(�����˷�����Ϣ)
	public static class SendToClient extends Thread
	{
		private Socket socket;
		private PrintWriter out=null;
		public SendToClient(Socket socket){
			this.socket=socket;
		}
		@Override
		public void run(){
			try{
				out=new PrintWriter(socket.getOutputStream(),true);
				Scanner sc=new Scanner(System.in);
				while(true){
					out.println(sc.nextLine());
				}
			}catch(Exception e){
				System.out.println("������Ϣʧ�� "+e.getMessage());
			}finally{
				try{
					socket.close();
					out.close();
				}catch(Exception e){
					e.printStackTrace();
				}
			}
		}
	}
}
