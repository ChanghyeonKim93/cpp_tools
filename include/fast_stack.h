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
class FastStack {// node���� �����ϴ� stack���δٰ� ������.
public:
    int sz;
    int MAX_SIZE;
    T* mem; // ���� �Ҵ� ��, ������ �迭�̶�� ���� �ȴ�.

    /**
    *
    * @brief Constructor for FastStack data structure.
    * @details Constructor for FastStack data structure.
       Main difference from the standard 'stack' is that memories for stack are pre-allocated in our implementations.
    * @return none.
    */
    FastStack() {
        MAX_SIZE = 65536; // stack�� �׷��� ũ�� �ʾƵ� �Ǵ���.
        mem = (T*)malloc(sizeof(T)*MAX_SIZE); // 8 * max_size
        sz = 0; // ���� �ƹ��͵� �� ����.
                // cout << "FASTSTACK init" << endl;
    };

    /**
    *
    * @brief destruct the FastStack and free the pre-allocated memories
    * @details destruct the FastStack and free the pre-allocated memories
    * @return none.
    */
    ~FastStack() { free(mem); };// �����ߴ� stack ����. // malloc�� free };

    /**
    *
    * @brief Push a element onto the top of the stack.
    * @details Push a element onto the top of the stack.
    * @return none.
    */
    void Push(T& value_) { // ����带 �����鼭 stack size 1�� Ű��.
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
    // stack�� ����ϰ� ������ ���� �ʿ�� ������, size=0���� ���������Ѵ�.

    /**
    *
    * @brief clear the stack. (not free memories, but re-index to zero.)
    * @details clear the stack. (not free memories, but re-index to zero.)
    * @return none.
    */
    void clear() { sz = 0; };
};

#endif
