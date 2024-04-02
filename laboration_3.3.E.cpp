#include "Triad.h"
#include <iostream>
using namespace std;

int main() {
    Triad triad1(1, 2, 3);
    Date date1(10, 12, 2022);

    cout << "Number of objects (Triad and Date): " << Object::Count() << endl;

    return 0;
}
