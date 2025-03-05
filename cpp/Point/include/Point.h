#pragma once
class Point {
public:
    Point();
    Point(const char *name, const float &x, const float &y);
    ~Point();
    void Print() const;
    static void PrintCount();

private:
    char *m_name;
    float m_x;
    float m_y;
    static int s_count;
};
