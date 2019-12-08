class Foo {
public:
	pthread_mutex_t t1;
	pthread_mutex_t t2;
	Foo() {
		pthread_mutex_init(&t1, NULL);
		pthread_mutex_init(&t2, NULL);
		pthread_mutex_lock(&t1);
		pthread_mutex_lock(&t2);
	}

	void first(function<void()> printFirst) {

		// printFirst() outputs "first". Do not change or remove this line.
		printFirst();
		pthread_mutex_unlock(&t1);
	}

	void second(function<void()> printSecond) {

		pthread_mutex_lock(&t1);
		// printSecond() outputs "second". Do not change or remove this line.
		printSecond();
		pthread_mutex_unlock(&t2);
	}

	void third(function<void()> printThird) {

		pthread_mutex_lock(&t2);
		// printThird() outputs "third". Do not change or remove this line.
		printThird();
	}
};