#include <stdio.h>
#include <string.h>

#define SIZE 15


struct CircularBuffer {
    char buffer[SIZE];
    int head;
    int tail;
    int count;
};

void init(struct CircularBuffer *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

int isFull(struct CircularBuffer *cb) {
    return cb->count == SIZE;
}

int isEmpty(struct CircularBuffer *cb) {
    return cb->count == 0;
}

void write(struct CircularBuffer *cb, char data) {
    if (isFull(cb)) {
        printf("\n[Overflow] Buffer is full! Cannot add: %c", data);
        return;
    }
    cb->buffer[cb->tail] = data;
    cb->tail = (cb->tail + 1) % SIZE;
    cb->count++;
}

char read(struct CircularBuffer *cb) {
    if (isEmpty(cb)) {
        printf("\n[Underflow] Buffer is empty!");
        return '\0';
    }
    char data = cb->buffer[cb->head];
    cb->head = (cb->head + 1) % SIZE;
    cb->count--;
    return data;
}

int main() {
    struct CircularBuffer cb;
    init(&cb);

    char name[100];
    printf("Enter your name: ");
    scanf("%s", name);

    strcat(name, "CE-ESY");
    printf("Text after suffix: %s\n", name);

    for (int i = 0; i < strlen(name); i++) {
        write(&cb, name[i]);
    }

    printf("\nData from buffer: ");
    while (!isEmpty(&cb)) {
        printf("%c", read(&cb));
    }
    
    printf("\n\nProcess complete. Buffer is now empty.\n");
    return 0;
}
