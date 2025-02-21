#include <iostream>

class Point {
public:
    Point(int x, int y);
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    void move(int dx, int dy);
    void print() const {
    std::cout << "(" << m_x << ", " << m_y << ")" << std::endl;
}
    static void PrintNumberOfOccurences() ;
private:
    int m_x;
    int m_y;
    static int s_numberOfOccurences;
};
