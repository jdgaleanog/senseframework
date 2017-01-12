#include "Arduino.h"
#include "controller.h"

#include "../view/view.h"
#include "../model/model.h"

int controller::sensorSelect(int type, int pin0)
{

  sensorInit(type, pin0, 0);
  name[idSensor]="0";
  return idSensor-1;

}
void controller::sensorName(int idS, char Sname[])
{
  name[idS]=Sname;

}

String controller::sensorName(int idS)

{String Rname;
  if (name[idS]=="0") {
    Rname=(char)idS;
  }
  else{
    Rname=name[idS];
  }
  return Rname;

}
void controller::connectSV(int idS, int idO)
{

  viewsArray[idStruct].idSensor =  idS;
  viewsArray[idStruct].idOutput =  idO;
  if(outputType[idO]==LCD)
  {
    lcdnum=lcdnum+1;
  }
  idStruct=idStruct+1;

}

void controller::connectSV(int idS, int idO, String name)
{

  viewsArray[idStruct].idSensor =  idS;
  viewsArray[idStruct].idOutput =  idO;
  viewsArray[idStruct].name =  name;
  idStruct=idStruct+1;

  webnum=webnum+1;

}

void controller::run()
{
  int idO=0;
  int idserial=0;
  for (int i = 0; i <idStruct; i++) {


    if (outputType[viewsArray[i].idOutput]==WEB)
    {
      String serial="serial";
      varName[j]=serial + idserial;
      value[j]=sensorName(viewsArray[i].idSensor);
      j=j+1;
      varName[j]=(viewsArray[i].name);
      sensorValue[i]=sensorRead(viewsArray[i].idSensor);
      String Sread= String(sensorValue[i]);
      value[j]=Sread;

      j=j+1;
      idserial=idserial+1;
      if(j==2)
      {
        idO=viewsArray[i].idOutput;
      }
    }
    else{
      currentMillis=millis();
      currentMillisView=currentMillis;
      sensorValue[i]=sensorRead(viewsArray[i].idSensor);

      outputShow(viewsArray[i].idOutput, sensorValue[i]);
    }

  }

  if(webnum>=1)
  {
    outputShow(varName, value, j, idO);

  }
  j=0;
}
