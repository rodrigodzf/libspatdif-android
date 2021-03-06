/** @file
 *
 * @ingroup spatdiflib-examples
 *
 * @brief Example: Test #sdOSCResponder
 *
 * @details
 *
 * @authors Chikashi Miyama, Trond Lossius
 *
 * @copyright Copyright (C) 2013 - 2014 Zurich University of the Arts, Institute for Computer Music and Sound Technology @n
 * This code is licensed under the terms of the "New BSD License" @n
 * http://creativecommons.org/licenses/BSD/
 */


#include "sdMain.h"
#include <string>
#include <iostream>
#include <iomanip>

int main(void){
  using namespace std;
  
  sdScene scene;
  sdOSCResponder oscResponder(&scene);
  std::cout.setf( std::ios::showpoint );  
  vector<sdOSCMessage> returnedMessageVector;

  cout << "----set/get queryTime----" << endl;
  {
    sdOSCMessage setQueryTime("/spatdifcmd/setQueryTime");
    setQueryTime.appendFloat(1.52);
  	oscResponder.forwardOSCMessage(setQueryTime);   
  	sdOSCMessage getQueryTime("/spatdifcmd/getQueryTime");
   	returnedMessageVector = oscResponder.forwardOSCMessage(getQueryTime);
   	cout << returnedMessageVector[0].getMessageAsString() << endl;
  }
  cout << "----set/get writeTime----" << endl;
  {
    sdOSCMessage setWriteTime("/spatdifcmd/setWriteTime");
    setWriteTime.appendFloat(3.14);
    oscResponder.forwardOSCMessage(setWriteTime);   
    sdOSCMessage getWriteTime("/spatdifcmd/getWriteTime");
    returnedMessageVector = oscResponder.forwardOSCMessage(getWriteTime);
    cout << returnedMessageVector[0].getMessageAsString() << endl;
  }
  
  cout << "----set/get Interval----" << endl;
  {
    sdOSCMessage setInterval("/spatdifcmd/setInterval");
    setInterval.appendFloat(2.25);
    oscResponder.forwardOSCMessage(setInterval);   
    sdOSCMessage getInterval("/spatdifcmd/getInterval");
    returnedMessageVector = oscResponder.forwardOSCMessage(getInterval);
    cout << returnedMessageVector[0].getMessageAsString() << endl;
  }
  cout << "----set/get Ordering----" << endl;
  {
    sdOSCMessage setOrderingToTrack("/spatdifcmd/setOrdering");
    setOrderingToTrack.appendString("track");
    oscResponder.forwardOSCMessage(setOrderingToTrack);

    sdOSCMessage getOrdering("/spatdifcmd/getOrdering");
    returnedMessageVector = oscResponder.forwardOSCMessage(getOrdering);
    cout << returnedMessageVector[0].getMessageAsString() << endl;

    sdOSCMessage setOrderingToTime("/spatdifcmd/setOrdering");
    setOrderingToTime.appendString("time");
    oscResponder.forwardOSCMessage(setOrderingToTime);

    returnedMessageVector = oscResponder.forwardOSCMessage(getOrdering);
    cout << returnedMessageVector[0].getMessageAsString() << endl;

  }
  cout << "----add/remove/query/removeAll Entities----" << endl;
  {
    sdOSCMessage addTest1Entity("/spatdifcmd/addEntity");
    addTest1Entity.appendString("test1Entity");
    oscResponder.forwardOSCMessage(addTest1Entity);
    cout << "test1Entity added" << endl;

    sdOSCMessage addTest2Entity("/spatdifcmd/addEntity");
    addTest2Entity.appendString("test2Entity");
    oscResponder.forwardOSCMessage(addTest2Entity);
    cout << "test2Entity added" << endl;

    sdOSCMessage getNumberOfEntities("/spatdifcmd/getNumberOfEntities");
    returnedMessageVector = oscResponder.forwardOSCMessage(getNumberOfEntities);
    cout << returnedMessageVector[0].getMessageAsString() << endl;

    sdOSCMessage getEntityNames("/spatdifcmd/getEntityNames");
    returnedMessageVector = oscResponder.forwardOSCMessage(getEntityNames);
    cout << returnedMessageVector[0].getMessageAsString() << endl;

    sdOSCMessage removeTest1Entity("/spatdifcmd/removeEntity");
    removeTest1Entity.appendString("test1Entity");
    returnedMessageVector = oscResponder.forwardOSCMessage(removeTest1Entity);
    cout << "test1Entity removed from the scene " << endl;

    returnedMessageVector = oscResponder.forwardOSCMessage(getEntityNames);
    cout << returnedMessageVector[0].getMessageAsString() << endl;

    sdOSCMessage removeAllEntities("/spatdifcmd/removeAllEntities");
    oscResponder.forwardOSCMessage(removeAllEntities);
    cout << "all entities removed" << endl;

    returnedMessageVector = oscResponder.forwardOSCMessage(getNumberOfEntities);
    cout << returnedMessageVector[0].getMessageAsString() << endl;

  }
  cout << "----set/get Position----" << endl;
  {
  // both query and write at 10.0
    sdOSCMessage setWriteTime("/spatdifcmd/setWriteTime");
    setWriteTime.appendFloat(10.0);
    oscResponder.forwardOSCMessage(setWriteTime);
    sdOSCMessage setQueryTime("/spatdifcmd/setQueryTime");
    setQueryTime.appendFloat(10.0);
    oscResponder.forwardOSCMessage(setQueryTime);

    sdOSCMessage setPosition("/spatdifcmd/setPosition");
    setPosition.appendString("myEntity");
    float pos[3] = {1.0, 2.0, 3.0};
    setPosition.appendFloats(pos, 3);
    oscResponder.forwardOSCMessage(setPosition);

    sdOSCMessage getPosition("/spatdifcmd/getPosition");
    getPosition.appendString("myEntity");
    returnedMessageVector = oscResponder.forwardOSCMessage(getPosition);
    cout << returnedMessageVector[0].getMessageAsString() << endl;
  }
  {
    // search event with next command
    cout << "query time at: 5.0. ask for next event" << endl;
    sdOSCMessage setQueryTime("/spatdifcmd/setQueryTime");
    setQueryTime.appendFloat(5.0);
    oscResponder.forwardOSCMessage(setQueryTime);

    sdOSCMessage getNextPosition("/spatdifcmd/getNextPosition");
    getNextPosition.appendString("myEntity");
    returnedMessageVector = oscResponder.forwardOSCMessage(getNextPosition);
    cout << returnedMessageVector[0].getMessageAsString() << endl;
  }
  {
    // search event with previous command
    cout << "query time at: 15.0. ask for previous event" << endl;
    sdOSCMessage setQueryTime("/spatdifcmd/setQueryTime");
    setQueryTime.appendFloat(15.0);
    oscResponder.forwardOSCMessage(setQueryTime);

    sdOSCMessage getPreviousPosition("/spatdifcmd/getPreviousPosition");
    getPreviousPosition.appendString("myEntity");
    returnedMessageVector = oscResponder.forwardOSCMessage(getPreviousPosition);
    cout << returnedMessageVector[0].getMessageAsString() << endl;
  }
  cout << "----set/get Orientation----" << endl;
  {
    sdOSCMessage setOrientation("/spatdifcmd/setOrientation");
    setOrientation.appendString("myEntity");

    sdOSCMessage setWriteTime("/spatdifcmd/setWriteTime");
    setWriteTime.appendFloat(10.0);
    oscResponder.forwardOSCMessage(setWriteTime);
    sdOSCMessage setQueryTime("/spatdifcmd/setQueryTime");
    setQueryTime.appendFloat(10.0);
    oscResponder.forwardOSCMessage(setQueryTime);

    float ori[3] = {1.0, 2.0, 3.0};
    setOrientation.appendFloats(ori, 3);
    oscResponder.forwardOSCMessage(setOrientation);

    sdOSCMessage getOrientation("/spatdifcmd/getOrientation");
    getOrientation.appendString("myEntity");
    returnedMessageVector = oscResponder.forwardOSCMessage(getOrientation);
    cout << returnedMessageVector[0].getMessageAsString() << endl;
  }
  cout << "----set/get Present----" << endl;
  {
    sdOSCMessage setPresent("/spatdifcmd/setPresent");
    setPresent.appendString("myEntity");
    setPresent.appendInt(1);
    oscResponder.forwardOSCMessage(setPresent);

    sdOSCMessage getPresent("/spatdifcmd/getPresent");
    getPresent.appendString("myEntity");
    returnedMessageVector = oscResponder.forwardOSCMessage(getPresent);
    cout << returnedMessageVector[0].getMessageAsString() << endl;
  }
  cout << "----get all events in the specified time frame----" << endl;
  { 

    sdOSCMessage setQueryTime("/spatdifcmd/setQueryTime");
    setQueryTime.appendFloat(5.0);
    oscResponder.forwardOSCMessage(setQueryTime);

    sdOSCMessage setInterval("/spatdifcmd/setInterval");
    setInterval.appendFloat(10.0);
    oscResponder.forwardOSCMessage(setInterval);

    sdOSCMessage getEventsSetsFromAllEntities("/spatdifcmd/getEventSetsFromAllEntities");
    returnedMessageVector = oscResponder.forwardOSCMessage(getEventsSetsFromAllEntities);
    cout << "number of events found:" << returnedMessageVector.size() << endl;
    vector<sdOSCMessage>::iterator it = returnedMessageVector.begin();

    while(it != returnedMessageVector.end()){
      sdOSCMessage mes = *it;
      cout << mes.getMessageAsString() << endl;
      it++;
    }
  }
  cout << "----set/get extentsion data " << endl;
  {

   //activate 
  	sdOSCMessage addExtension("/spatdifcmd/addExtension");
  	addExtension.appendString("media");
  	oscResponder.forwardOSCMessage(addExtension);

    sdOSCMessage getNumberOfActivatedExtensions("/spatdifcmd/getNumberOfActivatedExtensions");
    returnedMessageVector = oscResponder.forwardOSCMessage(getNumberOfActivatedExtensions);
    cout << returnedMessageVector[0].getMessageAsString() << endl;

    sdOSCMessage setWriteTime("/spatdifcmd/setWriteTime");
    setWriteTime.appendFloat(15.0);
    oscResponder.forwardOSCMessage(setWriteTime);

    sdOSCMessage setID("/spatdifcmd/media/setID");
    setID.appendString("myEntity");
    setID.appendString("piano");
    oscResponder.forwardOSCMessage(setID);

    sdOSCMessage setType("/spatdifcmd/media/setType");
    setType.appendString("myEntity");
    setType.appendString("file");
    oscResponder.forwardOSCMessage(setType);

    sdOSCMessage setLocation("/spatdifcmd/media/setLocation");
    setLocation.appendString("myEntity");
    setLocation.appendString("/Users/spat/Music/piano.aif");
    oscResponder.forwardOSCMessage(setLocation);

    sdOSCMessage setChannel("/spatdifcmd/media/setChannel");
    setChannel.appendString("myEntity");
    setChannel.appendInt(1);
    oscResponder.forwardOSCMessage(setChannel);

    sdOSCMessage setTimeOffset("/spatdifcmd/media/setTimeOffset");
    setTimeOffset.appendString("myEntity");
    setTimeOffset.appendFloat(12.4);
    oscResponder.forwardOSCMessage(setTimeOffset);

   	sdOSCMessage setGain("/spatdifcmd/media/setGain");
    setGain.appendString("myEntity");
    setGain.appendFloat(0.5);
    oscResponder.forwardOSCMessage(setGain);

    cout << "set query time to 15.0." << endl;
    sdOSCMessage setQueryTime("/spatdifcmd/setQueryTime");
    setQueryTime.appendFloat(15.0);
    oscResponder.forwardOSCMessage(setQueryTime);

    sdOSCMessage getEventsSetsFromAllEntities("/spatdifcmd/getEventSetsFromAllEntities");
    returnedMessageVector = oscResponder.forwardOSCMessage(getEventsSetsFromAllEntities);
    cout << "number of events found:" << returnedMessageVector.size() << endl;
    vector<sdOSCMessage>::iterator it = returnedMessageVector.begin();

    while(it != returnedMessageVector.end()){
      sdOSCMessage mes = *it;
      cout << mes.getMessageAsString() << endl;
      it++;
    }
  }
  cout << "----set a value to an unknown entity-----" << endl;
  {
    sdOSCMessage setUnknown("/spatdifcmd/setPosition");
    setUnknown.appendString("unknownEntity");
    float pos[3] = {1.0, 2.0, 3.0};
    setUnknown.appendFloats(pos, 3);
    oscResponder.forwardOSCMessage(setUnknown);

    sdOSCMessage getEntityNames("/spatdifcmd/getEntityNames");
    returnedMessageVector = oscResponder.forwardOSCMessage(getEntityNames);
    cout << returnedMessageVector[0].getMessageAsString() << endl;
  }
  cout << "----set/get metadata " << endl;
  {
    sdOSCMessage returnedMessage;
    sdOSCMessage setAuthor("/spatdifcmd/setAuthor");
    setAuthor.appendString("Chikashi Miyama");
    oscResponder.forwardOSCMessage(setAuthor);

    sdOSCMessage setHost("/spatdifcmd/setHost");
    setHost.appendString("Some computer");
    oscResponder.forwardOSCMessage(setHost);
   
    sdOSCMessage setDate("/spatdifcmd/setDate");
    setDate.appendString("2014-3-7");
    oscResponder.forwardOSCMessage(setDate);

    sdOSCMessage setLocation("/spatdifcmd/setLocation");
    setLocation.appendString("ICST, Zürich, Switzerland");
    oscResponder.forwardOSCMessage(setLocation);

    sdOSCMessage setSession("/spatdifcmd/setSession");
    setSession.appendString("1.1");
    oscResponder.forwardOSCMessage(setSession);
   
    sdOSCMessage setAnnotation("/spatdifcmd/setAnnotation");
    setAnnotation.appendString("This is a test with OSC messages");
    oscResponder.forwardOSCMessage(setAnnotation);

    sdOSCMessage getAuthor("/spatdifcmd/getAuthor");
    returnedMessageVector = oscResponder.forwardOSCMessage(getAuthor);
    cout << returnedMessageVector[0].getMessageAsString() << endl;

    sdOSCMessage getHost("/spatdifcmd/getHost");
    returnedMessageVector = oscResponder.forwardOSCMessage(getHost);
    cout << returnedMessageVector[0].getMessageAsString() << endl;

    sdOSCMessage getDate("/spatdifcmd/getDate");
    returnedMessageVector = oscResponder.forwardOSCMessage(getDate);
    cout << returnedMessageVector[0].getMessageAsString() << endl;

    sdOSCMessage getLocation("/spatdifcmd/getLocation");
    returnedMessageVector = oscResponder.forwardOSCMessage(getLocation);
    cout << returnedMessageVector[0].getMessageAsString() << endl;

    sdOSCMessage getSession("/spatdifcmd/getSession");
    returnedMessageVector = oscResponder.forwardOSCMessage(getSession);
    cout << returnedMessageVector[0].getMessageAsString() << endl;

    sdOSCMessage getAnnotation("/spatdifcmd/getAnnotation");
    returnedMessageVector = oscResponder.forwardOSCMessage(getAnnotation);
    cout << returnedMessageVector[0].getMessageAsString() << endl;



  }
  

  return 0;
}
