two_calcul.cpp
It shows the code of calculation in two methods: quick and dirty and accurate but slow, simultaneously.


std::launch is a scoped enumerator, it has two members: async, deferred.
If std::lanuch::async is given in a std::async, then the function passed to the std::async will start. And it will block the braces which include the future object.

We could apply get to an initialized std::future object. Then, the future will calculate the result before moving on.
We could also apply wait()(wait for func to be done(might start background task)), wait_for(t)(wait for time t to start) and wait_until(t)(until given time t to start). All these three functions will return a std::future_status object.

std::future_status is a scoped enumerator, it has three members: deferred, timeout, and ready.
deferred means that the operation has not yet started and wait for a wait() or get() to force it to start.
timeout means that the operation was started asynchronously but hasn't finished yet
ready means the operation has finished.

