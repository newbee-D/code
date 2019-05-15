public class  FactoryPatterns
{
	public static void main(String[] args) 
	{
		CarFactory car=new CarFactory();
		Car car1=car.getCar("Bmw");
		car1.carName();
		System.out.println(car1);
		car1=car.getCar("Changan");
		car1.carName();
		System.out.println(car1);
	}
}

interface Car
{
	public void carName();
}

class Bmw implements Car
{
	@Override
	public void carName(){
		System.out.println("Bmw");
	}
}

class Changan implements Car
{
	@Override
	public void carName(){
		System.out.println("Changan");
	}
}

//����
class CarFactory
{
	public Car getCar(String name){
		if(name==null){
			return null;
		}
		if(name.equals("Bmw")){
			return new Bmw();
		}
		if(name.equals("Changan")){
			return new Changan();
		}
		return null;
	}
}
