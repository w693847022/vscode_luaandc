//模仿libuv 的高效双向循环链表队列
typedef void* Queue_t[2];
class Queue_w{
    public:
    inline Queue_w* GetNext(){return (Queue_w*)&((*(&queue))[2]);}//通过 引用再解引用使其变成左值
    inline Queue_w* GetPrev(){return (Queue_w*)&((*(&queue))[1]);}
    inline Queue_w* GetNextPrev(){return (Queue_w*)&((* ( &(*(Queue_w**)GetNext()) ) )[1]);}
    inline Queue_w* GetPrevNext(){return (Queue_w*)&((* ( &(*(Queue_w**)GetPrev()) ) )[2]);}
    void SetNext(Queue_w* q)
    {
        *(Queue_w**)&((*(&queue))[2]) =  q;
    }
    void SetPrve(Queue_w* q)
    {
        *(Queue_w**)&((*(&queue))[1]) = q;
    }
    void SetNextPrve(Queue_w * q)
    {
       *(Queue_w**)&(*(&(*(Queue_w**)GetNext()))[1]) =  q;
    }
    void SetPrveNext(Queue_w *q)
    {
        *(Queue_w**)&(*(&(*(Queue_w**)GetPrev()))[2]) = q;
    }
    
    Queue_t* queue;//[1] prev [2] next
};

