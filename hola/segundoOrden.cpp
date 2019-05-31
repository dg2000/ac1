#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

double E(double e, double m, double B, double Eo, double t, double y)
{
  if(y<0.005 && y>-0.005)
    {
      return Eo*cos(e*B*t/m);
    }
  else
    {
      return 0.0;
    }
}

double xp(double e, double m, double B, double Eo, double t, double x, double y, double x1, double y1)
{
  return x1;
}

double xpp(double e, double m, double B, double Eo, double t, double x, double y, double x1, double y1)
{
  return e*B*y1/m;
}

double yp(double e, double m, double B, double Eo, double t, double x, double y, double x1, double y1)
{
  return y1;
}

double ypp(double e, double m, double B, double Eo, double t, double x, double y, double x1, double y1)
{
  return -e*x1*B/m  + e*E(e, m, B, Eo, t, y)/m;
}


int main()
{

  double h = 0.0001*6.283e-8;
  double e = 1.602176e-19;
  double m = 1.672621e-27;
  double B = 1.0;
  double Eo = 1.0e7;
  double Rmax = 1.0;
  double t = 0.0;
  double x = 0.01;
  double y = 1.0e-50;
  double x1 = 0.0;
  double y1 = 1.0e3;
  double ultimo_t = 0.0;
  double T = 0.0;

  bool llego = false;

  while(!llego)
    {
      double a1 = xp(e, m, B, Eo, t, x, y, x1, y1);
      double b1 = yp(e, m, B, Eo, t, x, y, x1, y1);
      double c1 = xpp(e, m, B, Eo, t, x, y, x1, y1);
      double d1 = ypp(e, m, B, Eo, t, x, y, x1, y1);

      double a2 = xp(e, m, B, Eo, t + h/2.0, x + h*a1/2.0, y + h*b1/2.0, x1 + h*c1/2.0, y1 + h*d1/2.0);
      double b2 = yp(e, m, B, Eo, t + h/2.0, x + h*a1/2.0, y + h*b1/2.0, x1 + h*c1/2.0, y1 + h*d1/2.0);
      double c2 = xpp(e, m, B, Eo, t + h/2.0, x + h*a1/2.0, y + h*b1/2.0, x1 + h*c1/2.0, y1 + h*d1/2.0);
      double d2 = ypp(e, m, B, Eo, t + h/2.0, x + h*a1/2.0, y + h*b1/2.0, x1 + h*c1/2.0, y1 + h*d1/2.0);

      double a3 = xp(e, m, B, Eo, t + h/2.0, x + h*a2/2.0, y + h*b2/2.0, x1 + h*c2/2.0, y1 + h*d2/2.0);
      double b3 = yp(e, m, B, Eo, t + h/2.0, x + h*a2/2.0, y + h*b2/2.0, x1 + h*c2/2.0, y1 + h*d2/2.0);
      double c3 = xpp(e, m, B, Eo, t + h/2.0, x + h*a2/2.0, y + h*b2/2.0, x1 + h*c2/2.0, y1 + h*d2/2.0);
      double d3 = ypp(e, m, B, Eo, t + h/2.0, x + h*a2/2.0, y + h*b2/2.0, x1 + h*c2/2.0, y1 + h*d2/2.0);

      double a4 = xp(e, m, B, Eo, t + h, x + h*a3, y + h*b3, x1 + h*c3, y1 + h*d3);
      double b4 = yp(e, m, B, Eo, t + h, x + h*a3, y + h*b3, x1 + h*c3, y1 + h*d3);
      double c4 = xpp(e, m, B, Eo, t + h, x + h*a3, y + h*b3, x1 + h*c3, y1 + h*d3);
      double d4 = ypp(e, m, B, Eo, t + h, x + h*a3, y + h*b3, x1 + h*c3, y1 + h*d3);
      
      if( y < 0.0 && y+h*(b1 + 2.0*b2 + 2.0*b3 + b4)/6.0 >= 0.0)
	{
	  T = t - ultimo_t;
	  ultimo_t = t;
	}
      else
	{
	  T = 0.0;
	}

      
      t = t + h;
      x = x + h*(a1 + 2.0*a2 + 2.0*a3 + a4)/6.0;
      y = y + h*(b1 + 2.0*b2 + 2.0*b3 + b4)/6.0;
      x1 = x1 + h*(c1 + 2.0*c2 + 2.0*c3 + c4)/6.0;
      y1 = y1 + h*(d1 + 2.0*d2 + 2.0*d3 + d4)/6.0;
      
      if(sqrt(x*x + y*y) < Rmax)
	{
	  cout << t << " " << x << " " << y << " " << x1 << " " << y1 << " " << T << endl;
	}
      else
	{
	  llego = true;
	  cout << e << " " << m << " " << B << " " << Eo << " " << Rmax << "  " << 1.0 << endl;
	}

    }

  return 0;
}



      

