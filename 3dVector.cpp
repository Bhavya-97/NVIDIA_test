#include<iostream>
#include<math.h>
#include<assert.h>

using namespace std;

class vector3d  {
  private:
    float x, y, z;

  public:
    vector3d() {                                              //Constructor to instantiate and Initialise all vector components to 0
      x = y = z = 0;
    }

    vector3d(float x1, float y1, float z1) {                  //Parameterised Constructor
      x = x1;
      y = y1;
      z = z1;
    }

    vector3d(vector3d &vector) {                              //copy Constructor
      x = vector.x;
      y = vector.y;
      z = vector.z;
    }

    vector3d operator+(const vector3d &operand);            //returns the sum 2 vectors
    vector3d &operator+=(const vector3d &operand);          //Adds 2 vectors and stores the sum

    vector3d operator-(const vector3d &operand);            //Returns the differnce of 2 vectors
    vector3d &operator-=(const vector3d &operand);          //Subttracts 2 vectors and stores the difference

    vector3d operator*(const float value);                  //Returns the product
    vector3d &operator*=(const float value);                //Multiplies and stores the product

    vector3d operator/(const float value);                  //returns the quotient
    vector3d &operator/=(const float value);                //Divides and stores the quotient

    float dot_product(const vector3d &vector);              //returns the dot product
    vector3d scalar_multiplication(const float scalar);     //returns the product of vector and scalar

    vector3d cross_product(const vector3d &vector);         //returns the cross product of 2 vectors

    float magnitude();                                      //returns the magnitude of the vector
    vector3d normalisation();                               //returns the normalised vector

    float square();                                         //returns the square of the vector
    float distance(const vector3d &vector);                 //returns the distance between 2 vectors

    void display();                                         //prints the value of the vector
};

vector3d vector3d ::operator+(const vector3d &operand) {
  vector3d result;

  result.x = x + operand.x;
  result.y = y + operand.y;
  result.z = z + operand.z;

  return result;
}

vector3d vector3d :: operator-(const vector3d &operand) {
  vector3d result;

  result.x = x - operand.x;
  result.y = y - operand.y;
  result.z = z - operand.z;

  return result;
}

vector3d vector3d :: operator*(const float value) {
  vector3d result;

  result.x = x * value;
  result.y = y * value;
  result.z = z * value;

  return result;
}

vector3d vector3d :: operator/(const float value) {
  vector3d result;

  result.x = x / value;
  result.y = y / value;
  result.z = z / value;

  return result;
}

vector3d &vector3d :: operator+=(const vector3d &operand) {
  x += operand.x;
  y += operand.y;
  z += operand.z;

  return *this;
}

vector3d &vector3d :: operator-=(const vector3d &operand) {
  x -= operand.x;
  y -= operand.y;
  z -= operand.z;

  return *this;
}

vector3d &vector3d :: operator*=(const float value) {
  x *= value;
  y *= value;
  z *= value;

  return *this;
}

vector3d &vector3d :: operator/=(const float value) {
  x /= value;
  y /= value;
  z /= value;

  return *this;
}

float vector3d :: dot_product(const vector3d &vector) {
  return x*vector.x + y*vector.y + z*vector.z;
}

vector3d vector3d :: scalar_multiplication(const float scalar) {
  x *= scalar;
  y *= scalar;
  z *= scalar;

  return *this;
}

vector3d vector3d :: cross_product(const vector3d &vector) {
  vector3d result;

  result.x = y*vector.z - z*vector.y;
  result.y = z*vector.x - x*vector.z;
  result.z = x*vector.y - y*vector.x;

  return result;
}

float vector3d :: magnitude() {
  return sqrt(square());
}

float vector3d :: square() {
  return x*x +y*y + z*z;
}

vector3d vector3d:: normalisation()
{
    assert(magnitude() != 0);
    *this /= magnitude();
    return *this;
}

float vector3d :: distance(const vector3d &vector) {
  vector3d dist(*this - vector);
  return magnitude();
}

void vector3d :: display() {
  cout << x << " " << y << " " << z << endl;
}
