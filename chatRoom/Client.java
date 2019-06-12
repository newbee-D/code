import java.io.*;
import java.net.*;
import java.util.Scanner;

public class Client 
{
	
	public static void main(String[] args) 
	{
		try{
			//创建请求并发送
			Socket socket=new Socket("127.0.0.1",1997);
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
		private static PrintWriter out=null;
		private static BufferedReader in=null;
		public ClientThread(Socket socket){
			this.socket=socket;
		}
		@Override
		public void run(){
			try{
				//获取服务端消息
				in=new BufferedReader(new InputStreamReader(socket.getInputStream()));
				//发送消息
				out=new PrintWriter(socket.getOutputStream(),true);//自动刷新，及时推送消息到服务端
				while(true){
					Scanner sca=new Scanner(System.in);
					out.println(sca.nextLine());
					System.out.println("Server say: "+in.readLine());
				}
			}catch(Exception e){
				System.out.println("读取或发送消息失败 "+e.getMessage());
			}finally{
				try{
					//关闭流
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
