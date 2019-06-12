import java.io.*;
import java.net.*;
import java.util.Scanner;
/*
*客户端
*author：djs
*/
public class Client 
{
	private static final int PORT=1997;
	private static final String IP="127.0.0.1";
	public static void main(String[] args) 
	{
		try{
			//创建请求并发送
			Socket socket=new Socket(IP,PORT);
			System.out.println("Successful to connect to Server");
			new ClientThread(socket).start(); //创建客户端线程并启动
		}catch(Exception e){
			System.out.println("服务器未启动"+e.getMessage());
		}
		
	}

	//客户端线程
	public static class ClientThread extends Thread
	{
		private static Socket socket;
		public ClientThread(Socket socket){
			this.socket=socket;
		}
		@Override
		public void run(){
			new GetClientMsg(socket).start(); //开启线程
			new SendToClient(socket).start();
		}
	}
	//消费者线程(获取服务端消息)
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
	//生产者线程(向服务端发送消息)
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
