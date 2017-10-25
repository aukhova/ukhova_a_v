#include <iostream>
#include <sstream>

class Point2d
{
public:
	Point2d() = default;
	Point2d(const double x_, const double y_);
	~Point2d() = default;
	Point2d operator=(const Point2d t);

	Point2d Otrazh_Oy();
	Point2d Otrazh_Ox();
	Point2d Otrazh_O();
	Point2d Sme_x(const double d);
	Point2d Sme_y(const double d);
	Point2d Sme_vec(const double x_, const double y_);
	Point2d povorot(const double al);

	std::ostream& writeTo(std::ostream& ostrm)const;
	std::istream& readFrom(std::istream& istrm);
public:
	double x;
	double y;

	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };
};

std::ostream&operator<<(std::ostream& ostrm, const Point2d& rhs);
std::istream&operator >> (std::istream& istrm, Point2d& rhs);
double Rast(const Point2d point1, const Point2d point2);

int main()
{
	using namespace std;
	Point2d n(3, 4);
	cout << "n=" << n << endl;
	Point2d k(0, 0);
	cout << "k=" << k << endl;
	double r = Rast(n, k);
	cout << "Rast(n, k)=" << r << endl;
	n = n.Otrazh_Oy();
	cout << "n.Otrazh_Oy=" << n << endl;
	n = n.Otrazh_Ox();
	cout << "Otrazh_Ox=" << n << endl;
	n = n.Otrazh_O();
	cout << "n.Otrazh_O=" << n << endl;
	n = n.Sme_x(2);
	cout << "n.Sme_x(2)=" << n << endl;
	n = n.Sme_y(5);
	cout << "n.Sme_y(5)=" << n << endl;
	n = n.Sme_vec(6, -8);
	cout << "n.Sme_vec(6, -8)=" << n << endl;
	n = Point2d(2, 0);
	cout << "n=" << n << endl;
	n = n.povorot(90);
	cout << "n.povorot(90)=" << n << endl;
	system("pause");
	return 0;
};

double Rast(const Point2d point1, const Point2d point2)
{
	return sqrt((point1.x - point2.x)*(point1.x - point2.x) + (point1.y - point2.y)*(point1.y - point2.y));
}

Point2d::Point2d(const double x_, const double y_)
	:x(x_)
	, y(y_)
{

}

Point2d Point2d::Otrazh_Oy()
{
	x = -x;
	return *this;
}

Point2d Point2d::Otrazh_Ox()
{
	y = -y;
	return *this;
}

Point2d Point2d::Otrazh_O()
{
	x = -x;
	y = -y;
	return *this;
}

Point2d Point2d::operator=(const Point2d t)
{
	x = t.x;
	y = t.y;
	return *this;
}
Point2d Point2d::Sme_x(const double d)
{
	x += d;
	return *this;
}

Point2d Point2d::Sme_y(const double d)
{
	y += d;
	return *this;
}

Point2d Point2d::Sme_vec(const double x_, const double y_)
{
	x += x_;
	y += y_;
	return *this;
}

Point2d Point2d::povorot(const double al)
{
	double x_ = x*cos(al*3.14 / 180) - y*sin(al*3.14 / 180);
	double y_ = x*sin(al*3.14 / 180) + y*cos(al*3.14 / 180);
	x = x_;
	y = y_;
	return *this;
}

std::ostream& operator<<(std::ostream& ostrm, const Point2d& rhs)
{
	return rhs.writeTo(ostrm);
}

std::istream& operator >> (std::istream& istrm, Point2d& rhs)
{
	return rhs.readFrom(istrm);
}

std::ostream& Point2d::writeTo(std::ostream& ostrm) const
{
	ostrm << leftBrace << x << separator << y << rightBrace;
	return ostrm;
}

std::istream& Point2d::readFrom(std::istream& istrm)
{
	char leftBrace(0);
	double x_(0.0);
	char comma(0);
	double y_(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> x_ >> comma>> y_ >> rightBrace;
	if (istrm.good())
	{
		if ((Point2d::leftBrace == leftBrace) && (Point2d::separator == comma)  && (Point2d::rightBrace == rightBrace))
		{
			x = x_;
			y = y_;
		}
		else
		{
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}

bool testParse(const std::string& str)
{
	using namespace std;
	istringstream istrm(str);
	Point2d z;
	istrm >> z;
	if (istrm.good())
	{
		cout << "Read success: " << str << "->" << z << endl;
	}
	else
	{
		cout << "Read error  : " << str << "->" << z << endl;
	}
	return istrm.good();
}