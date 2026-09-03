#include <iostream>

using namespace std;

class Test {
    private:
        int count;
        int data;

    public:
        Test() {
            count = 10;
        }

    public:
        void increCount() {
            this->count++;
        }
        void decreCount() {
            this->count--;
        }
        void setData(int data) {
            this->data = data;
        }
        int getCount() {
            return this->count;
        }

        int getData() {
            return this->data;
        }
};

int main() {
    Test t1 = Test();
    t1.increCount();
    cout << t1.getCount() << endl;
    t1.setData(10);
    cout << t1.getData() << endl;

    Test *t2 = new Test();
    t2->decreCount();
    cout << t2->getCount() << endl;
    t2->setData(20);
    cout << t2->getData() << endl;
    delete(t2);
}