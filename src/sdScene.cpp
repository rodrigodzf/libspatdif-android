/** @file
 *
 * @ingroup spatdiflib
 *
 * @brief
 *
 * @details
 *
 * @authors Chikashi Miyama, Trond Lossius
 *
 * @copyright Copyright (C) 2013 - 2014 Zurich University of the Arts, Institute for Computer Music and Sound Technology @n
 * This code is licensed under the terms of the "New BSD License" @n
 * http://creativecommons.org/licenses/BSD/
 */

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cfloat>
#include "sdMain.h"


std::string sdScene::getEntityName(int index){
    
    std::vector<std::string> names = getEntityNames();
    return names[index];
}

std::vector<std::string> sdScene::getEntityNames(){
    
    std::vector <std::string> names;
    std::vector <sdEntityCore *>::iterator it = entityVector.begin();
    while(it != entityVector.end()){
        sdEntityCore* entity = *it;
        names.push_back(entity->getName());
        it++;
    }
    return names;
}

sdEntityCore* sdScene::getEntity(std::string name){
    std::vector <sdEntityCore*>::iterator it = entityVector.begin();
    while( it != entityVector.end() ){
		std::string entityName = (*it)->getName();
        if(entityName == name){
            return *it;
        }
	it++;
    }
    return NULL;
}

unsigned int sdScene::getNumberOfEntities(void){
    return entityVector.size();
}

sdEntityCore* sdScene::addEntity(std::string name, EKind kind){
    
    sdEntityCore* ent = getEntity(name);
    // if already exist just return the existing one
    if(ent){
        return ent;
    }
    
    sdEntityCore* entityCore = new sdEntityCore(name, kind); // private constructor

    // attach extensions to the newly created sdEntityCore.
    std::vector <EExtension> ::iterator it = activatedExtensionVector.begin();


    while(it != activatedExtensionVector.end()){
        entityCore->addExtension(*it);
        it++;
    }
    
    // insert the entity in the vector
    entityVector.push_back(entityCore);
    
    // return the pointer
    return entityCore;
}

void sdScene::removeEntity(std::string name){
    sdEntityCore* entity = getEntity(name);
    if(entity){
        removeEntity(entity);
    }
}

void sdScene::removeEntity(sdEntityCore *entity){
    std::vector <sdEntityCore*>::iterator it = entityVector.begin();
    while (it != entityVector.end()) {
        if(*it == entity){
            it = entityVector.erase(it);
            return;
        }
        it++;
    }
}

void sdScene::removeAllEntities(void){
    entityVector.clear();
}

void sdScene::setValue(std::string name, double time, EDescriptor descriptor,  void* value){
    sdEntityCore* entity = getEntity(name);
    if(!entity){
        entity = addEntity(name);
    }
    entity->addEvent(time, descriptor, value);
}

void* sdScene::getValue(std::string name, double time, EDescriptor descriptor){
    sdEntityCore* entity = getEntity(name);
    if (!entity) {
        return NULL;
    }
    return entity->getValue(time, descriptor);
}

int sdScene::getNumberOfActivatedExtensions(void){
    return activatedExtensionVector.size();
}

EExtension sdScene::getActivatedExtension(int index){
    return activatedExtensionVector[index];
}

std::vector<EExtension> sdScene::getActivatedExtensions(){
    return activatedExtensionVector;
}

std::vector<std::string> sdScene::getActivatedExtensionsAsStrings(){
    std::vector<std::string> strings;
    std::vector<EExtension>::iterator it = activatedExtensionVector.begin();
    while(it != activatedExtensionVector.end()){
        strings.push_back(extensionToString(*it));
        it++;
    }
    return strings;
}

void sdScene::addExtension(EExtension extension){
    std::vector <EExtension>::iterator pos;
    pos= find(activatedExtensionVector.begin(),
         activatedExtensionVector.end(),
         extension);

    //duplication check
    if(pos != activatedExtensionVector.end()){
        std::cout << "sdScene Error: Extension already activated." << std::endl;
        return;
    }

    activatedExtensionVector.push_back(extension);
    std::vector <sdEntityCore*>::iterator it = entityVector.begin();
    while (it != entityVector.end()) {
        sdEntityCore* entityCore = *it;
        entityCore->addExtension(extension);
        it++;
    }
    
}

void sdScene::addExtension(std::string extension){
    EExtension ext = stringToExtension(extension);
    if(ext == SD_EXTENSION_ERROR){
        std::cout << "sdScene Error: No such extension." << std::endl;
        return;
    }
    addExtension(ext);
}

bool sdScene::isExtensionActivated(EExtension extension){
    std::vector <EExtension>::iterator it = activatedExtensionVector.begin();
    while(it != activatedExtensionVector.end()){
        EExtension et = *it;
        if(et == extension){
            return true;
        }
        it++;
    }
    return false;
}

bool sdScene::isExtensionActivated(std::string extensionString){
    EExtension extension = stringToExtension(extensionString);
    return isExtensionActivated(extension);
}

void sdScene::removeExtension(EExtension extension){

    std::vector <EExtension>::iterator it = activatedExtensionVector.begin();
    while (it != activatedExtensionVector.end()) {
        if(*it == extension){
            it = activatedExtensionVector.erase(it);
            return;
        }
        it++;
    }
    std::cout << "sdScene Error: No such activated extension." << std::endl;
}

void sdScene::removeExtension(std::string extension){
    EExtension ext = stringToExtension(extension);
    if(ext == SD_EXTENSION_ERROR){
        std::cout << "sdScene Error: No such activated extension." << std::endl;
    }
    removeExtension(ext);
}

void sdScene::removeAllExtensions(){
    activatedExtensionVector.clear();
}

std::vector<sdReport> sdScene::getNextEventSetsFromAllEntities(double time){
    std::vector<sdReport> reportVector;
    std::vector<sdEntityCore*>::iterator it = entityVector.begin();
    while (it != entityVector.end()) {
        sdReport report;
        sdEntityCore* entityCore = *it;
        report.entity = entityCore;
        report.eventSet= entityCore->getNextEventSet(time);
        if(report.eventSet.size() != 0){
            reportVector.push_back(report);
        }
        it++;
    }
    return reportVector;
}

std::vector<sdReport> sdScene::getPreviousEventSetsFromAllEntities(double time){
    std::vector<sdReport> reportVector;
    std::vector<sdEntityCore*>::iterator it = entityVector.begin();
    while (it != entityVector.end()) {
        sdReport report;
        sdEntityCore* entityCore = *it;
        report.entity = entityCore;
        report.eventSet= entityCore->getPreviousEventSet(time);
        if(report.eventSet.size() != 0){
            reportVector.push_back(report);
        }
        it++;
    }
    return reportVector;
}

std::vector<sdReport> sdScene::getFirstEventSetsFromAllEntities(){
    return getNextEventSetsFromAllEntities(-1.0);
}

std::vector<sdReport> sdScene::getLastEventSetsFromAllEntities(){
    return getPreviousEventSetsFromAllEntities(DBL_MAX);
}

std::vector<sdReport> sdScene::getNextEventSets(double time){
    // collect next events from all entities, compare them and return the soonest events 
    std::vector<sdReport> reportVector = getNextEventSetsFromAllEntities(time);
    std::vector<sdReport> soonestReportVector;
    if(reportVector.empty()){
        return soonestReportVector;
    }

    std::vector<sdReport>::iterator it = reportVector.begin();
    double soonestEventTime = (*((*it).eventSet.begin()))->getTime();

    // look for the soonest event
    while (it != reportVector.end()) {
        sdReport report = *it;
        std::multiset<sdEvent*, sdEventCompare>::iterator rit=report.eventSet.begin();
        while (rit != report.eventSet.end()) {
            sdEvent* event = *rit;
            if( soonestEventTime > event->getTime()){
                soonestEventTime = event->getTime();
            }
            rit++;
        }
        it++;
    }
    // include entities and events if events have soonestEventTime
    
    it = reportVector.begin();
    while (it != reportVector.end()) {
        sdReport report = *it;
        if(soonestEventTime == (*((*it).eventSet.begin()))->getTime()){
            soonestReportVector.push_back(report);
        }
        it++;
    }
    return soonestReportVector;
}

double sdScene::getNextEventTime(double time){
    std::vector<sdReport> reportVector = getNextEventSets(time);
    if(reportVector.empty()){
        return -1.0;
    }
    sdReport report = reportVector[0];
    std::multiset<sdEvent*, sdEventCompare> eventSet = report.eventSet;
    std::multiset<sdEvent*, sdEventCompare>::iterator it = eventSet.begin();
    return (*it)->getTime();
}

double sdScene::getDeltaTimeToNextEvent(double time){
    return getNextEventTime(time) - time;
}

std::vector<sdReport> sdScene::getFirstEventSets(){
    return getNextEventSets(-1.0);
}

std::vector<sdReport> sdScene::getEventSetsFromAllEntities(double time){
    std::vector<sdReport> reportVector;
    std::vector<sdEntityCore*>::iterator it = entityVector.begin();
    while (it != entityVector.end()) {
        sdEntityCore* entityCore = *it;
        sdReport report;
        report.entity = entityCore;
        report.eventSet= entityCore->getEventSet(time);
        if(report.eventSet.size() != 0){
            reportVector.push_back(report);
        }
        it++;
    }
    return reportVector;
}

std::vector<sdReport> sdScene::getEventSetsFromAllEntities(double start, double end){
    std::vector<sdReport> reportVector;
    std::vector<sdEntityCore*>::iterator it = entityVector.begin();
    while (it != entityVector.end()) {
        sdEntityCore* entityCore = *it;
        sdReport report;
        report.entity = entityCore;
        report.eventSet= entityCore->getEventSet(start, end);
        if(report.eventSet.size() != 0){
            reportVector.push_back(report);
        }
        it++;
    }
    return reportVector;
}


std::string sdScene::dump(bool consoleOut){
    std::ostringstream os;
    
    os << "---------- Meta ----------"<< std::endl;
    os << "author:" << info.getAuthor() <<std::endl;
    os << "annotaion:" <<  info.getAnnotation() <<std::endl;
    os << "ordering:" <<  getOrderingAsString()<<std::endl;
    os << "extensions:" << activatedExtensionVector.size() << std::endl;
    
    os << "number of entity used:" <<  getNumberOfEntities()<<std::endl;

    os << "---------- Entities --------" << std::endl;
    std::vector <sdEntityCore*>::iterator it = entityVector.begin();
    while( it != entityVector.end() )
	{
		std::string entityName = (*it)->getName();
        std::string kind = (*it)->getKindAsString();
        os << ">>entity name:" << entityName <<std::endl;
        os << "kind:" << kind <<std::endl;
        os << "number of events:" << (*it)->getNumberOfEvents()<< std::endl;
        std::multiset <sdEvent*, sdEventCompare> evnts = (*it)->getEventSet();
        std::multiset <sdEvent*, sdEventCompare>::iterator itt = evnts.begin();

        while(itt != evnts.end()){
            sdEventCore *eventCore = static_cast<sdEventCore*>(*itt);
            os << "["  << eventCore->getTimeAsString() << " " << eventCore->getDescriptorAsString() << " " << eventCore->getValueAsString() << "]" << std::endl;
            itt++;
            
        }
		it++;
	}
    if(consoleOut){
        std::cout << os.str() << std::endl;
    }
    return os.str();
}
