#include <stdio.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
} CQueue;

// 초기화
void initCQueue(CQueue *q) {
    q->front = 0;
    q->rear = 0;
}

// Queue가 비어 있는지 확인
int isEmpty(CQueue* q) {
    return q->front == q->rear;
}

// Queue가 가득 찼는지 확인
int isFull(CQueue* q) {
    return (q->rear + 1) % MAX == q->front;
}



// 삽입
void enqueue(CQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is Full!\n");
        return;
    }
    q->data[q->rear] = value;
    q->rear = (q->rear + 1) % MAX;
}

// 삭제
int dequeue(CQueue *q) {
   if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return -1;
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    return value;
}

// 맨 앞 원소 확인
int peek(CQueue *q) {

   if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return -1;
    }

    return q->data[q->front];

}



int main() {
    CQueue q;
    initCQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("%d\n", dequeue(&q)); // 10
    printf("%d\n", peek(&q));    // 20
    printf("%d\n", dequeue(&q)); // 20

    return 0;
}

