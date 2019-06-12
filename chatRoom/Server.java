import java.io.*;
import java.util.Scanner;
import java.net.*;
/*
*服务器
*author:djs
*/
class Server
{
	private static volatile int port=1997; //同步port变量，保证多线程安全

	public static void main(String[] args) 
	{
		System.out.println("服务器已启动，等待客服端连接");
		try{
			ServerSocket ss=new ServerSocket(port,5); //监听端口请求，同时最多服务5个客户端
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
		private Socket socket;
		private PrintWriter out=null;
		private BufferedReader in=null;
		public ServerThread(Socket socket){
			this.socket=socket;
			System.out.println("Client "+socket.getInetAddress().getHostAddress()+" 连入服务器");
		}

		@Override
		public void run(){
			try{
				
				//向客户端发送消息
				
				out=new PrintWriter(socket.getOutputStream(),true);
				//读取客户端发送的数据
				in=new BufferedReader(new InputStreamReader(socket.getInputStream()));
				while(true){
					System.out.println(socket.getInetAddress().getHostAddress()+"say："+in.readLine());
					Scanner sca=new Scanner(System.in);
					out.println(sca.nextLine());
					
				}
			}catch(Exception e){
				System.out.println("读取或发送消息错误："+e.getMessage());
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
