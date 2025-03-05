#include <iostream>

class Point {
public:
    Point();
    Point(const char *name, const float &x, const float &y);
    inline void Print() const;
    static void PrintNumberOfOccurences();
    ~Point();

private:
    char *m_name;
    float m_x;
    float m_y;
    static int s_numberOfOccurences;
};

inline void Point::Print() const {
    std::cout << m_name << "(" << m_x << ", " << m_y << ")" << std::endl;
}
