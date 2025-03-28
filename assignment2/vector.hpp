#include <cmath>
#include <iostream>

// 2D vector class with all the necessary operators

template<typename T>
struct Vector2d 
{

    T x, y;

    Vector2d<T>& operator+=(Vector2d<T> const& v)
    {
        x += v.x, y += v.y;
        return *this;
    }

    Vector2d<T>& operator-=(Vector2d<T> const& v)
    {
        x -= v.x, y -= v.y;
        return *this;
    }

    Vector2d<T>& operator*=(T const& a)
    {
        x *= a, y *= a;
        return *this;
    }

    Vector2d<T>& operator/=(T const& a)
    {
        x /= a, y /= a;
        return *this;
    }

};


template<typename T>
 Vector2d<T> operator+(Vector2d<T> const& a, Vector2d<T> const& b)
 {
    return Vector2d<T>{a.x + b.x, a.y + b.y};
 }


template<typename T>
 Vector2d<T> operator-(Vector2d<T> const& a, Vector2d<T> const& b)
 {
    return Vector2d<T>{a.x - b.x, a.y - b.y};
 }

 template<typename T>
 Vector2d<T> operator/(Vector2d<T> const& a, T const& b)
 {
    return Vector2d<T>{a.x/b, a.y/b};
 }

 template<typename T>
 Vector2d<T> operator*(Vector2d<T> const& a, T const& b)
 {
    return Vector2d<T>{a.x * b, a.y * b };
 }

 template<typename T>
 Vector2d<T> operator*(T const& a, Vector2d<T> const& b)
 {
    return Vector2d<T>{b.x * a, b.y * a };
 }

template<typename T>
 std::ostream& operator<<(std::ostream& o, Vector2d<T> const& v)
 {
    o << v.x << " " << v.y;
    return o;
 }

 template<typename T>
 std::istream& operator>>(std::istream& i, Vector2d<T>& v)
 {
    i >> v.x;
    i >> v.y;
    return i;
 }


 template<typename T>
 double dot(Vector2d<T> const& a, Vector2d<T> const& b)        // calculates the dot product of two vectors
 {
    return (a.x * b.x + a.y * b.y);
 }


template<typename T>
 double length(Vector2d<T> const& v)                         // calculates the length of a vector
 {
    return (std::sqrt(std::pow(v.x, 2) + std::pow(v.y, 2)));
 }

 template<typename T>
 double sqlength(Vector2d<T> const& v)                       // calculates the square of a vector's length
 {
    return (std::pow(v.x, 2) + std::pow(v.y, 2));
 }
