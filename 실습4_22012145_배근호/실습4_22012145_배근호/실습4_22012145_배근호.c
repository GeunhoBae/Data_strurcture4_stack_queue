#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)
//����: int stack[10], top = -1 && �Լ�: void push(int item), int pop()
//����: int queue[10], front = -1, rear = -1 && �Լ�: void add_q(int item), int delete_q()
//����: int c_queue[10], c_front = 0, c_rear =  0 && �Լ�: void add_cq(int item), int delete_cq()

int* stack; int top = -1;
int* queue; int front = -1, rear = -1;
int c_queue[10]; int c_front = 0, c_rear = 0; //����ť�� �����迭
int max_stack_size = 10, max_queue_size = 10, max_c_queue_size = 10;

//����
void push(int item) {
    int stack_size = max_stack_size;
    if (stack_size - 1 == top) {
        stack_size *= 2;
        stack = (int*)realloc(stack, sizeof(int) * stack_size);
    }
    stack[++top] = item;
}

int pop() {
    return stack[top--];
}

// ť
void add_q(int item) {
    int queue_size = max_queue_size;
    if (queue_size - 1 == front) {
        queue_size *= 2;
        queue = (int*)realloc(queue, sizeof(int) * queue_size);
    }
    queue[++rear] = item;
}

int delete_q() {
    return queue[++front];
}

//���� ť
int c_queue_size = 10;
void add_cq(int item) {
    c_rear = (c_rear + 1) % c_queue_size;
    c_queue[c_rear] = item;
}

int delete_cq() {
    c_front = (c_front + 1) % c_queue_size;
    return c_queue[c_front];
}

// main
void main() {
    stack = (int*)malloc(sizeof(int) * max_stack_size);
    queue = (int*)malloc(sizeof(int) * max_queue_size);
    int choice = 0, item = 0;

    //4.1 ����
    printf("4.1 ����\n");
    while (1) {
        printf("���� - 1.push 2.pop(����: -1) : ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("push item : ");
            scanf("%d", &item);
            push(item);
        }
        else if (choice == 2) {
            printf("pop item : ");
            printf("%d\n", stack[top]);
            pop();
        }
        else break;
        printf("index : item\n");
        for (int i = 0; i <= top; i++) {
            printf("%d : %d\n", i, stack[i]);
        }
    }
    //4.2 ť
    printf("4.2 ť\n");
    while (1) {
        printf("ť - 1.addQ 2.deleteQ(����: -1) : ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("addQ item: ");
            scanf("%d", &item);
            add_q(item);
        }
        else if (choice == 2) {
            printf("deleteQ item: ");
            printf("%d\n", queue[front + 1]);
            delete_q();
        }
        else break;
        printf("index : item\n");
        for (int i = front + 1; i <= rear; i++) {
            printf("%d : %d\n", i, queue[i]);
        }
    }
    //4.3 ����ť
    printf("4.3 ����ť\n");
    while (1) {
        printf("����ť - 1.addCQ 2.deleteCQ(����: -1): ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("addCQ item: ");
            scanf("%d", &item);
            add_cq(item);
        }
        else if (choice == 2) {
            printf("deleteCQ item: ");
            printf("%d\n", c_queue[c_front + 1]);
            delete_cq();
        }
        else break;
        printf("index : element\n");
        int i = (c_front + 1) % c_queue_size;
        while (i != (c_rear + 1) % c_queue_size) {
            printf("%d : %d\n", i, c_queue[i]);
            i = (i + 1) % c_queue_size;
        }
    }
}