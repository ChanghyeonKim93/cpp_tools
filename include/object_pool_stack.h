#ifndef _OBJECTPOOL_STACK_H_
#define _OBJECTPOOL_STACK_H_

#include <iostream>
#include <memory>
#include <stack>

// Attaboy!

template <typename T>
class ObjectPoolStack {
private:
	int max_num_obj_;
	int cur_num_obj_;
	std::stack<T*> objstack_;

public:
	// 생성자
	ObjectPoolStack(int max_num_object) : max_num_obj_(max_num_object), cur_num_obj_(0)
	{
		for(int i = 0; i < max_num_obj_; ++i){
			T* new_obj = new T();
			objstack_.push(new_obj);
		}
		printf("object size: %d / allocated # of objects: %d / total memory consumption: %d [Mbytes]\n",
			(int)sizeof(T), max_num_obj_, (int)(sizeof(T)*max_num_obj_) / (1024 * 1024));
	};

	// memory chunk의 앞부분을 가져온다.
	T* getObject() {
		T* cur_obj;
		if (cur_num_obj_ < max_num_obj_) {
			cur_obj = objstack_.top();
			objstack_.pop();
			++cur_num_obj_;
			return cur_obj;
		}
		else {
			printf("ERROR: no object pool is remaining.\n");
			return nullptr;
		}
	};

	void returnObject(T* obj){
		obj->~T(); // initialize the object.
		objstack_.push(obj);
	};

	// 소멸자
	~ObjectPoolStack() {
		if (!objstack_.empty()) {
			T* obj;
			while(!objstack_.empty())
			{
				obj = objstack_.top();
				objstack_.pop();
				delete obj;
			}
			printf("\n object pool is successfully returned.\n");
		}
		else {
			printf("\n Already empty.\n");
		}
	};

	void showRemainedMemory() {
		printf("remained mem: %d\n", max_num_obj_ - cur_num_obj_);
	};

};

#endif