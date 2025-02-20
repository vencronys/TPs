class Point {
public:
  Point(int x, int y);
  int getX() const;
  int getY() const;
  void setX(int x);
  void setY(int y);
  void move(int dx, int dy);
  void print() const;
private:
    int x;
    int y;
};
