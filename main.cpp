#include <iostream>
using namespace std;

// 1. Struct Definition
struct Point {
    int x;
    int y;
};

// 4. Nested Struct
struct Rectangle {
    Point topLeft;
    Point bottomRight;
};

// 7. Base struct for simulated inheritance
struct Shape {
    int x;
    int y;
};

// Circle containing Shape
struct Circle {
    Shape base;
    int radius;
};

// 8. Recursive Struct
struct Node {
    int data;
    Node* next;
};

// 9. Bit Field Struct
struct Flags {
    unsigned int flag1 : 1;
    unsigned int flag2 : 1;
};

// 10. Dynamic Buffer
struct Buffer {
    int n;
    char* data;
};

// 11. Stack ADT
struct Stack {
    int data[10];
    int top;
};

// Function prototypes
void printPoint(Point p);
void movePoint(Point &p);
void move(Shape &s, int dx, int dy);
void push(Stack &s, int val);

// Function implementations
void printPoint(Point p){
    cout << "Point: (" << p.x << ", " << p.y << ")" << endl;
}

void movePoint(Point &p){
    p.x += 1;
    p.y += 1;
}

void move(Shape &s, int dx, int dy){
    s.x += dx;
    s.y += dy;
}

void push(Stack &s, int val){
    if(s.top < 10){
        s.data[s.top] = val;
        s.top++;
    } else {
        cout << "Stack is full" << endl;
    }
}

int main(){

    // 2. Declaring and initializing struct
    Point p = {10, 20};
    printPoint(p);

    // 3. Pointer to struct
    Point* ptr = &p;
    ptr->x = 15;
    cout << "After pointer modification: (" << p.x << ", " << p.y << ")" << endl;

    // 4. Nested struct
    Rectangle rect = {{0,0}, {10,10}};
    cout << "Rectangle top-left: (" << rect.topLeft.x << "," << rect.topLeft.y << ")" << endl;

    // 5. Array of structs
    Point points[3] = {{1,2}, {3,4}, {5,6}};
    cout << "Array of Points:" << endl;
    for(int i=0;i<3;i++){ 
        cout << "(" << points[i].x << "," << points[i].y << ")" << endl;
    }

    // 6. Passing structs to functions
    movePoint(p);
    cout << "After movePoint(): (" << p.x << "," << p.y << ")" << endl;

    // 7. Simulated inheritance
    Circle c;
    c.base.x = 0;
    c.base.y = 0;
    c.radius = 5;

    move(c.base, 3, 4);
    cout << "Circle moved to: (" << c.base.x << "," << c.base.y << ")" << endl;

    // 8. Recursive struct
    Node* head = new Node;
    head->data = 10;
    head->next = nullptr;
    cout << "Node data: " << head->data << endl;

    // 9. Bit fields
    Flags f;
    f.flag1 = 1;
    f.flag2 = 0;
    cout << "Flags: " << f.flag1 << " " << f.flag2 << endl;

    // 10. Dynamic buffer
    Buffer buf;
    buf.n = 100;
    buf.data = new char[buf.n];
    buf.data[0] = 'a';
    cout << "Buffer first element: " << buf.data[0] << endl;

    // 11. Stack ADT
    Stack s;
    s.top = 0;

    push(s, 5);
    push(s, 10);

    cout << "Stack contents:" << endl;
    for(int i=0;i<s.top;i++){ 
        cout << s.data[i] << endl;
    }

    // Clean up memory
    delete head;
    delete[] buf.data;

    return 0;
}