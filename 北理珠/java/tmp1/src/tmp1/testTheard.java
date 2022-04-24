package tmp1;

class RunnableDemo implements Runnable {
    private Thread t;
    private String threadName;

    RunnableDemo(String name) {
        threadName = name;
        System.out.println("Creating " + threadName);
    }

    public void run() {
        System.out.println("Runing " + threadName);
        try {
            for (int i = 4; i > 0; i--) {
                System.out.println("Thread: " + threadName + ", " + i);
                Thread.sleep(50);
            }
        } catch (InterruptedException e) {
            System.out.println("Thread: "+threadName+" interrupted.");
        }
        System.out.println("Thread "+threadName+" existing.");
    }

    public void start(){
        System.out.println("Starting "+threadName);
        if (t == null) {
            t = new Thread(this,threadName);
            t.start();
        }
    }
}

public class testTheard {
    public static void main(String[] args) {
        Long l = 0xf029L;
        System.out.println(l);
    }
}
