#ifndef _FASTSTACK_H_
#define _FASTSTACK_H_

#include <iostream>
#include <memory>
#include <exception>
using namespace std;


/**
*
* @brief fast implementation STACK container. (via pre-allocation)(Template)
* @details fast implementation (template) STACK container. (via pre-allocation)
* @author Changhyeon Kim
* @date 2020-09-14
*
*/
template <typename T>
class FastStack {// node만을 저장하는 stack으로다가 만들자.
public:
    int sz;
    int MAX_SIZE;
    T* mem; // 동적 할당 된, 포인터 배열이라고 보면 된다.

    /**
    *
    * @brief Constructor for FastStack data structure.
    * @details Constructor for FastStack data structure.
       Main difference from the standard 'stack' is that memories for stack are pre-allocated in our implementations.
    * @return none.
    */
    FastStack() {
        MAX_SIZE = 65536; // stack은 그렇게 크지 않아도 되더라.
        mem = (T*)malloc(sizeof(T)*MAX_SIZE); // 8 * max_size
        sz = 0; // 아직 아무것도 안 넣음.
                // cout << "FASTSTACK init" << endl;
    };

    /**
    *
    * @brief destruct the FastStack and free the pre-allocated memories
    * @details destruct the FastStack and free the pre-allocated memories
    * @return none.
    */
    ~FastStack() { free(mem); };// 생성했던 stack 해제. // malloc은 free };

    /**
    *
    * @brief Push a element onto the top of the stack.
    * @details Push a element onto the top of the stack.
    * @return none.
    */
    void Push(T& value_) { // 새노드를 넣으면서 stack size 1개 키움.
        if (!isFull()) {
            *(mem + sz) = value_;
            ++sz;
        }
        else throw std::runtime_error("[ERROR]: FastStack is full.\n");
    };

    /**
    *
    * @brief Pop a element from the top of the stack.
    * @details Pop a element from the top of the stack.
    * @return none.
    */
    void pop() {
        if (!empty()) --sz;
        else throw std::runtime_error("[ERROR]: FastStack is empty.\n");
    };

    /**
    *
    * @brief Return the element in the top of the stack.
    * @details Return the element in the top of the stack.
    * @return Element of the top <template T>.
    */
    T top() {
        if (!empty()) return *(mem + (sz - 1));
        else return -1;
    };

    /**
    *
    * @brief Return true when stack is empty.
    * @details Return true when stack is empty.
    * @return true: empty, false: not empty.
    */
    bool empty() {
        if (sz < 1) return true;
        else return false;
    };
    
    /**
    *
    * @brief Return true when stack is 'FULL' (not just existing!).
    * @details Return true when stack is 'FULL' (not just existing!).
    * @return true: FULL, false: not full.
    */
    bool isFull() { return (sz == MAX_SIZE); };
    // stack을 사용하고 내용을 지울 필요는 없지만, size=0으로 만들어줘야한다.

    /**
    *
    * @brief clear the stack. (not free memories, but re-index to zero.)
    * @details clear the stack. (not free memories, but re-index to zero.)
    * @return none.
    */
    void clear() { sz = 0; };
};

#endif
