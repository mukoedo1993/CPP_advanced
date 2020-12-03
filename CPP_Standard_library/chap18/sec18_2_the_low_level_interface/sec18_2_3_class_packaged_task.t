async() gives you a handle to deal with the outcome of a task that you try to start immediately in 
the background. Sometimes, however, you need to process the outcome of a background task that you don't
necessarily start immediately. For example, another instance, such as a thread pool, might control when and how many background tasks
run simultaneously. In this case, instead of
double 
