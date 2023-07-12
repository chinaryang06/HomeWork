
#include <iostream>

struct Vector {

int size;
int capacity;
int* arr;

};



void reserve(Vector* vec, int new_cap) {
 
 if(new_cap <= vec->capacity) {

  std::cout << "You already have an allocated space";
  return;
 }

 int *newarr = new int[new_cap];
 for(int i = 0; i < vec->size; ++i) {
    newarr[i] = vec->arr[i];
 }
  std::cout << "You allocated " << (new_cap - vec->capacity) * 4 << " bytes for your vector" << std::endl;
 delete[] vec->arr;
 
 vec->arr = newarr;
 vec->capacity = new_cap;

}



void erase(Vector* vec, int pos) {

 if(pos >= vec->size) {
    std::cout << "Invalid Position";
  return;
 }
 
 int* modarr = new int[vec->size-1];
 for(int i = 0; i < pos; i++) {
     modarr[i] = vec->arr[i];
 }
 for(int i = pos + 1; i < vec->size; i++) {
   modarr[i] = vec->arr[i];
}
 delete[] vec->arr;
 vec->arr = modarr;
 vec->size--;

}



void pushback(Vector* vec, int element) {

if (vec->size >= vec->capacity) {

vec->capacity = vec->capacity * 2;

int* newarr = new int[vec->capacity];

for (int i = 0; i < vec->size; i++) {

newarr[i] = vec->arr[i];

}

delete[] vec->arr;

vec->arr = newarr;

}

vec->arr[vec->size] = element;

vec->size++;

}



int at(Vector* vec, int pos) {

if(pos < 0 || pos >= vec->size) {
  std::cout << "Invalid position!!!" << std::endl;
  return -1;
}
return vec->arr[pos];
}



int main() {

Vector vec;

vec.size = 0;

vec.capacity = 1;

vec.arr = new int[vec.capacity];

pushback(&vec,99);
pushback(&vec,88);
reserve(&vec,5);
pushback(&vec,77);
erase(&vec,2);
//Try something with vector functions


for (int i = 0; i < vec.size; i++) {

std::cout << vec.arr[i] << " ";

}

delete[] vec.arr;

return 0;

}



