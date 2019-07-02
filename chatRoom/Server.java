import java.io.*;
import java.util.Scanner;
import java.net.*;
/*
*服务器
*author:djs
*/
class Server
{
	private static final int PORT=1997; 

	public static void main(String[] args) 
	{
		try{
			ServerSocket ss=new ServerSocket(PORT,5); //监听端口请求
			System.out.println("服务器已启动，等待客服端连接");
			while(true){
				Socket socket=ss.accept();//从请求队列中选取一个请求
				ServerThread st=new ServerThread(socket); //开启一个线程服务选取的请求
				st.start(); //启动线程
			}
		}catch(Exception e){
			System.out.println("连接失败"+e.getMessage());
		}
		
	}

	//服务器线程
	public static class ServerThread extends Thread
	{
		public Socket socket;
		public ServerThread(Socket socket){
			this.socket=socket;
			System.out.println("Client "+socket.getInetAddress().getHostAddress()+" 连入服务器");
		}

		@Override
		public void run(){
			new GetClientMsg(socket).start(); //开启线程
			new SendToClient(socket).start();
		}
	}
	//消费者线程(获取客户端消息)
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
				System.out.println("获取消息失败 "+e.getMessage());
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
	//生产者线程(向客户端发送消息)
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
				System.out.println("发送消息失败 "+e.getMessage());
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
