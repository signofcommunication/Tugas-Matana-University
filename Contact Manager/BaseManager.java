import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public abstract class BaseManager {
    protected final ExecutorService executor = Executors.newFixedThreadPool(2);

    public Future<?> submitTask(Runnable task) {
        return executor.submit(task);
    }

    public void shutdown() {
        executor.shutdown();
        logAction("Executor telah dimatikan.");
    }

    public abstract void logAction(String action);
}
