#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include <exception>
#include <iostream>
#include <string>
#include <vector>
#include <functional>

namespace UnitTest {
	
	enum TestRoutine {
		EQUAL,
		NOT_EQUAL,
		GREATER_THAN,
		GREATER_EQUAL,
		LESS_THAN,
		LESS_EQUAL
	};
	
	class TestFailureException;
	
	template <typename T>
	inline void expectEQ(const T& a, const T& b) {
		a == b ? std::cout << "Test passed" << std::endl : throw TestFailureException();
	}

	class TestCaseBase {
		public:
			virtual void run() = 0;	
	};

	template <typename T>
	class TestCase : public TestCaseBase {
		
		struct func_call {
			std::function<void()> call;
		};

		TestRoutine test_routine;
		std::vector<T> val_queue;
		std::vector<func_call> func_queue;
		
		public:
			void setTestRoutine(TestRoutine r) { this->test_routine = r; }
			
			void addValue(const T v) { this->val_queue.push_back(v); }
			
			template<typename F, typename... Args>
			void addFunction(F func, Args... args) {
				func_call newfunc = { std::bind(func, args...) };
				this->func_queue.push_back(newfunc);
			}
		
			template<typename O, typename F, typename... Args>
			void addFunctionMember(const O instance, F func, Args... args) {
				func_call newfunc = { std::bind(func, instance, args...) };
				this->func_queue.push_back(newfunc);
			}
			
			void run() {}
	};
	
	class Test {
		
		bool fatal_failure = false;
		unsigned int tests = 0;
		unsigned int passed = 0;
		unsigned int failed = 0;
		
		std::vector<TestCaseBase *> tests_queue;
		
		public:
			void setFatalFailure(bool b) { this->fatal_failure = b; }
			void addTestCase(TestCaseBase& tc) { this->tests_queue.push_back(&tc); }
			
			void run();
			
			/*
			void addTestCase(TestRoutine r, const T& a, const T& b);
			
			template <typename F>
			void addTestCase(TestRoutine r, const T& a, F f, unsigned int argc, void *argv);
			
			template <typename F>
			void addTestCase(TestRoutine r, F f1, unsigned int argc1, void *argv1,
							 F f2, unsigned int argc2, void *argv2);
			*/
		
		private:
		
	};
	
	class TestFailureException : public std::exception {
		
	};
}

#endif