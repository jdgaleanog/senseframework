#include "arduino.h"
#include "view.h"



void view::show(float refer1, int limit1, float var)
{
      switch (_type) {

        case LED:
          showled(refer1, limit1, var);
        break;

}
}

void view::show(float higherThan, float lowerThan, float var)
{
      switch (_type) {

        case LED:
          showled(higherThan, lowerThan, var);
        break;

}
}



void view::show(char const* name, float var)
{


      switch (_type) {


        case LCD:
          
           setCursor(0,0);
           print(name);
           setCursor(0,1);
           print(var);
        break;

}
}


void view::show(char const* name, float var, char const* name2, float var2)
{


      switch (_type) {

        case LCD:
        //_name2=name2;
        //_name=name;
          _var=0;
          _var2=0;
          _var=var;
          _var2=var2;

          setCursor(0,0);
          print(name);
          print(": ");
          print(_var);
          setCursor(0,1);
          print(name2);
          print(": ");
          print(_var2);
        break;

}
}
