#include "foraQueue.h"

foraQueue::foraQueue() : queueSize(1), queueUsed(0)
{
    this->queueArray = new int[this->queueSize];
}

foraQueue::foraQueue(int size) : queueSize(size), queueUsed(0)
{
    this->queueArray = new int[this->queueSize];
}

foraQueue::~foraQueue()
{
    delete[] queueArray;
}

int& foraQueue::operator[] (int index)
{
    //REVIEW - operator를 사용하면 array[5] 형식으로 배열 인덱스로 데이터를 접근할 수 있다.
    return this->queueArray[index];
}

void foraQueue::pushQueue(int data)
{
    if (this->queueUsed < this->queueSize) {
        //REVIEW - 지금 사용하는공간이 크기보다 작으면 초기화 시킴
        this->queueArray[this->queueUsed] = data;
    }
    else {
        //REVIEW - 클 경우 1칸을 더 늘려서 초기화 시킴
        int* temp = new int[this->queueSize];
        for (int i = 0; i < this->queueUsed; i++) {
            temp[i] = this->queueArray[i];
        }

        delete[] this->queueArray;
        this->queueSize += 1;
        this->queueArray = new int[queueSize];

        for (int i = 0; i < this->queueUsed; i++) {
            this-> queueArray[i] = temp[i];
        }
        delete[] temp;
        this->queueArray[this->queueUsed] = data;
    }

    this->queueUsed++;
}

int foraQueue::outputQueue()
{
    if (this->queueUsed == 0) {
        return -1;
    }

    int output = this->queueArray[0];
    this->queueUsed--;
    int* temp = new int[this->queueUsed];

    for (int i = 0; i < this->queueUsed; i++) {
        temp[i] = this->queueArray[i + 1];
    }

    delete[] this->queueArray;

    this->queueArray = new int[this->queueUsed];
    for(int i = 0; i < this->queueUsed; i++) {
        this->queueArray[i] =  temp[i];
    }
    delete[] temp;

    return output;
}

int foraQueue::length()
{
    return this->queueSize;
}

int foraQueue::peek()
{
    return this->queueArray[queueUsed];
}