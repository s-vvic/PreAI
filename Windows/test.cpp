#include <iostream>

using namespace std;

class Test {
    private:
        int count;
        int data;
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
    Test t = Test();
    t.increCount();
    cout << t.getCount() << endl;
    t.setData(10);
    cout << t.getData() << endl;
}