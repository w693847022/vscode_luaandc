//模仿libuv 的高效双向循环链表队列
typedef void* Queue_t[2];
class Queue_w{
    public:
    inline Queue_t* Next(){ return &(*(&queue))[2];}
    inline Queue_t* Prev(){return (Queue_t*)queue[1];}
    inline Queue_t* NextPrev(){return (Queue_t*)((Queue_t*)queue[2])[1];}
    inline Queue_t* PrevNext(){return (Queue_t*)((Queue_t*)queue[1])[2];}
    Queue_t* queue;//[1] prev [2] next
};

