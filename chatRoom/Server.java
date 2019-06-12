import java.io.*;
import java.util.Scanner;
import java.net.*;
/*
*������
*author:djs
*/
class Server
{
	private static volatile int port=1997; //ͬ��port��������֤���̰߳�ȫ

	public static void main(String[] args) 
	{
		System.out.println("���������������ȴ��ͷ�������");
		try{
			ServerSocket ss=new ServerSocket(port,5); //�����˿�����ͬʱ������5���ͻ���
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
		private Socket socket;
		private PrintWriter out=null;
		private BufferedReader in=null;
		public ServerThread(Socket socket){
			this.socket=socket;
			System.out.println("Client "+socket.getInetAddress().getHostAddress()+" ���������");
		}

		@Override
		public void run(){
			try{
				
				//��ͻ��˷�����Ϣ
				
				out=new PrintWriter(socket.getOutputStream(),true);
				//��ȡ�ͻ��˷��͵�����
				in=new BufferedReader(new InputStreamReader(socket.getInputStream()));
				while(true){
					System.out.println(socket.getInetAddress().getHostAddress()+"say��"+in.readLine());
					Scanner sca=new Scanner(System.in);
					out.println(sca.nextLine());
					
				}
			}catch(Exception e){
				System.out.println("��ȡ������Ϣ����"+e.getMessage());
			}finally{
				try{
					if(socket!=null){
						socket.close();
						in.close();
						out.close();
					}
				}catch(Exception e){
					System.out.println(e.getMessage());
				}
			}
		}
	}
}
