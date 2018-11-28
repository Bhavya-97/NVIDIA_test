#include<iostream>
#include<math.h>
#include<assert.h>

using namespace std;

template<typename T>
class 3dVector  {
  private:
    T x, y, z;

  public:
    3dVector() {                                        //Constructor to instantiate and Initialise all vector components to 0
      x = y = z = 0;
    }

    3dVector(T x, T y, T z) {                           //Parameterised Constructor
      this.x = x;
      this.y = y;
      this.z = z;
    }

    3dVector(3dVector vector) {                         //copy Constructor
      this.x = vector.x;
      this.y = vector.y;
      this.z = vector.z;
    }

    3dVector operator+(const 3dVector &operand);        //returns the sum 2 vectors
    3dVector &operator+=(const 3dVector &operand);      //Adds 2 vectors and stores the sum

    3dVector operator-(const 3dVector &operand);        //Returns the differnce of 2 vectors
    3dVector &operator-=(const 3dVector &operand);      //Subttracts 2 vectors and stores the difference

    3dVector operator*(const T value);                  //Returns the product
    3dVector &operator*=(const T value);                //Multiplies and stores the product

    3dVector operator/(const T value);                  //returns the quotient
    3dVector &operator/=(const T value);                //Divides and stores the quotient

    T dot_product(const 3dVector &vector);              //returns the dot product
    3dVector scalar_multiplication(const T scalar);     //returns the product of vector and scalar

    3dVector cross_product(const 3dVector &vector);     //returns the cross product of 2 vectors

    float magnitude();                                  //returns the magnitude of the vector
    3dVector normalisation();                           //returns the normalised vector

    T square();                                         //returns the square of the vector
    float distance(const 3dVector &vector);             //returns the distance between 2 vectors

    void display();                                     //prints the value of the vector
}

3dvector 3dVector :: operator+(const 3dVector &operand) {
  this.x += operand.x;
  this.y += operand.y;
  this.z += operand.z;

  return *this;
}

3dvector 3dVector :: operator-(const 3dVector &operand) {
  this.x -= operand.x;
  this.y -= operand.y;
  this.z -= operand.z;

  return *this;
}

3dvector 3dVector :: operator*(const T value) {
  this.x *= value;
  this.y *= value;
  this.z *= value;

  return *this;
}

3dvector 3dVector :: operator/(const T value) {
  this.x /= value;
  this.y /= value;
  this.z /= value;

  return *this;
}

3dvector 3dVector :: &operator+=(const 3dVector &operand) {
  this.x += operand.x;
  this.y += operand.y;
  this.z += operand.z;

  return *this;
}

3dvector 3dVector :: &operator-=(const 3dVector &operand) {
  this.x -= operand.x;
  this.y -= operand.y;
  this.z -= operand.z;

  return *this;
}

3dvector 3dVector :: &operator*=(const T value) {
  this.x *= value;
  this.y *= value;
  this.z *= value;

  return *this;
}

3dvector 3dVector :: &operator/=(const T value) {
  this.x /= value;
  this.y /= value;
  this.z /= value;

  return *this;
}

T 3dVector :: dot_product(const 3dVector &vector) {
  returns x*vector.x + y*vector.y + z*vector.z;
}

3dVector 3dVector :: scalar_multiplication(const T scalar) {
  x *= scalar;
  y *= scalar;
  z *= scalar;

  return *this;
}

3dVector 3dVector :: cross_product(const 3dVector &vector) {
  T ni = y*vector.z-z*vector.y;
  T nj = z*vector.x-x*vector.z;
  T nk = x*vector.y-y*vector.x;

  return 3dVector(ni,nj,nk);
}

float 3dVector :: magnitude() {
  return sqrt(square());
}

T 3dVector :: square() {
  return x*x +y*y + z*z;
}

3dVector 3dVector:: normalization()
{
    assert(magnitude() != 0);
    *this /= magnitude();
    return *this;
}

float 3dVector :: distance(const 3dVector &vector) {
  3dVector dist = *this - vector;
  return magnitude();
}

void 3dVector :: display() {
  cout << x << " " << y << " " << z << endl;
}
