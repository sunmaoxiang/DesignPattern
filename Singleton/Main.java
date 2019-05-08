/*
这份代码是对单例模式在多线程情况下的改进，synchronized可以防止多个线程同时进入到一个函数中，就是比如说像下面这种公用水壶倒水的问题。
*/

class Singleton {
	private static Singleton uniqueInstance;
	private Singleton() {}  // 把构造器声明为私有的，只有自Singleton类内才可以调用构造器
	public static Singleton getSingleton() {
		if(uniqueInstance == null) {
			uniqueInstance = new Singleton();
		}
		return uniqueInstance;
	}
	public void use() {
		System.out.println("Using");
	}
}

class Bottle {
	private boolean isfill;
	private static Bottle uniqeueBottle;
	private Bottle() { isfill = false; }
	public static synchronized Bottle getBottle() {
		if(uniqeueBottle == null) {
			uniqeueBottle = new Bottle();
		}
		return uniqeueBottle;
	}
	// 为了线程安全水满了溢出
	public synchronized void fill(){
        System.out.println("??????");
		if(!isfill) {
			System.out.println("填满了");
			if(isfill) System.out.println("溢出了");
			isfill = true;
		}
	}
};

// 创建多个线程
public class Main extends Thread{
	@Override
	public void run() { 
		Bottle.getBottle().fill();
	}
	public static void main(String[] args) { 
		Main[] threads = new Main[10];
		for(int i = 0 ; i < threads.length ; i++){
			threads[i] = new Main();
		}
		for (int j = 0; j < threads.length; j++) {
			threads[j].start();
		}
	}
}

