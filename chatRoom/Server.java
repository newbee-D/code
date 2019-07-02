import java.io.*;
import java.util.Scanner;
import java.net.*;
/*
*������
*author:djs
*/
class Server
{
	private static final int PORT=1997; 

	public static void main(String[] args) 
	{
		try{
			ServerSocket ss=new ServerSocket(PORT,5); //�����˿�����
			System.out.println("���������������ȴ��ͷ�������");
			while(true){
				Socket socket=ss.accept();//�����������ѡȡһ������
				ServerThread st=new ServerThread(socket); //����һ���̷߳���ѡȡ������
				st.start(); //�����߳�
			}
		}catch(Exception e){
			System.out.println("����ʧ��"+e.getMessage());
		}
		
	}

	//�������߳�
	public static class ServerThread extends Thread
	{
		public Socket socket;
		public ServerThread(Socket socket){
			this.socket=socket;
			System.out.println("Client "+socket.getInetAddress().getHostAddress()+" ���������");
		}

		@Override
		public void run(){
			new GetClientMsg(socket).start(); //�����߳�
			new SendToClient(socket).start();
		}
	}
	//�������߳�(��ȡ�ͻ�����Ϣ)
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
					System.out.println(socket.getInetAddress().getHostAddress()+" say: "+in.readLine());
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
	//�������߳�(��ͻ��˷�����Ϣ)
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
