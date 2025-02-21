#include <iostream>
#include <string>

class Point {
public:
    Point();
    void SetPoint(std::string name, int x, int y);
    inline void Print() const;
    static void PrintNumberOfOccurences() ;
private:
    std::string m_name;
    int m_x;
    int m_y;
    static int s_numberOfOccurences;
};

inline void Point::Print() const {
    std::cout << m_name << "(" << m_x << ", " << m_y << ")" << std::endl;
}
