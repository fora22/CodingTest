class foraQueue
{
private:
    int queueSize;
    int queueUsed;
public:
    int* queueArray;
    foraQueue();
    foraQueue(int size);
    ~foraQueue();
    int &operator[] (int index);
    void pushQueue(int data);
    int outputQueue();
    int length();
    int peek();
};
