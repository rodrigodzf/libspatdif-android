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

#ifndef ____sdEntityCore__
#define ____sdEntityCore__

#include <set>
#include <string>
#include "sdEventCore.h"
#include "sdEntityExtension.h"
#include "sdDescriptor.h"
#include "sdExtensible.h"

class sdScene;

/*!
 sdEntityCore is responsible for
 - identifing its kind (source or sink)
 - maintaining its events
 - giveing pointer to a certain, ranged, or the entire list of event(s)
 - forwarding a query to a proper extension and answer to the client
 */

class sdEntityCore: public sdEntity, public sdExtensible{
    friend class sdScene; // only sdScene can instantiate this class
    
private:
    
 
    
    /*! the name of the entity. This name is invariable (const)*/
    const std::string name;
   
    /*! define the kind of the entity. This property is declared as const and invariable (const). */
    EKind kind;
    EType type;
    
    /*! constructor. intentionally declared as a private function. 
     the sdEntityCore class must be instantiated through the addEntity function of sdScene. this guarantees that all instances of sdEntityCore are be aware of their parent scene and activated extensions.
     @param name the name of new Entity
     @param kind the kind of new Entity. default = SD_SOURCE
     */
    sdEntityCore(std::string name, EKind kind = SD_SOURCE, EType type = SD_POINT) :name(name), kind(kind){
        sdEntityCore::type = type;
        for(int i = 0; i < sdEventCore::numberOfDescriptors; i++){
            if(sdEventCore::descriptors[i].getInterpolability()){
                interpolationVector.push_back(SD_ENTITY_INTERPOLATION_DEACTIVATED);
            }else{
                interpolationVector.push_back(SD_ENTITY_INTERPOLATION_IMPOSSIBLE);
            }
        }
    };
   
public:
    static bool isCoreDescriptor(EDescriptor descriptor);
    static bool isCoreDescriptor(std::string descriptor);
    
    /*!
     @name Setter/Getter
     @{
     */
    
    /*! this returns a set of sdEvents with specified descriptor whose time parameter is between start and end time
     @param start start time
     @param end end time
     @param descriptor
     */
    
    /*!  returns the name of the entity */
    std::string getName(void);
    
    /*! returns the kind of the entity */
    EKind getKind(void);
    
    /*! returns the kind of the entity as a string*/
    std::string getKindAsString(void);

    /*! returns the type of the entity */
    EType getType(void);
    std::string getTypeAsString(void);
    
      
    /*! This is the only method for adding an new event to the entity*/
    sdEvent* addEvent(double time, EDescriptor descriptor, void* value);
    
    /*! same as above but you can specify arguments with string */
    sdEvent* addEvent(std::string time, std::string descriptor, std::string value);

    /*! remove specified event
     @param time time of the event
     @param descriptor desciprot of the event
     */
    
    void removeEvent(double time, EDescriptor descriptor);
    void removeEvent(std::string time, std::string descriptor);


    /*! overridden function. this function sum up all events (i.e. both core and extension events) and return it */
     int getNumberOfEvents();

    /*!
     overridden function. this function forwards the query to the extensions if an extended descriptor is provided as an argument.
     @param time the time of the event in second
     @param descriptor the descriptor of the event declared in sdConst.h
     */
    sdEvent* getEvent(double time, EDescriptor descriptor);
    
    /*!
     overridden  and overloaded functions. this function forwards the query also to the attached extensions and return all events as a multiset.
     @param time the time of the event in second
     @param descriptor the descriptor of the event declared in sdConst.h
     */
    std::multiset<sdEvent*, sdEventCompare> getEventSet(void);
    std::multiset<sdEvent*, sdEventCompare> getEventSet(double time);
    std::multiset<sdEvent*, sdEventCompare> getEventSet(double start, double end);
    std::multiset<sdEvent*, sdEventCompare> getEventSet(double start, double end, EDescriptor descriptor);

    /*!
     overridden function. this function forwards the query to the extensions if an extended descriptor is provided as an argument.
     @param time the next event from this time point will be returned
     @param descriptor the descriptor of the event declared in sdConst.h
     */
    sdEvent* getNextEvent(double time, EDescriptor descriptor);
    std::multiset<sdEvent*, sdEventCompare> getNextEventSet(double time);
    double getNextEventTime(double time);

    sdEvent* getPreviousEvent(double time, EDescriptor descriptor);
    std::multiset<sdEvent*, sdEventCompare> getPreviousEventSet(double time);
    double getPreviousEventTime(double time);

    sdEvent* getFirstEvent(EDescriptor descriptor);
    std::multiset<sdEvent*, sdEventCompare> getFirstEventSet();
    double getFirstEventTime();

    sdEvent* getLastEvent(EDescriptor descriptor);
    std::multiset<sdEvent*, sdEventCompare> getLastEventSet();
    double getLastEventTime();

    /*!
     overridden function. this function forwards the query to the extensions if an extended descriptor is provided as an argument.
     @param time time of the event
     @param descriptor descriptor of the event
     */
    void* getValue(double time, EDescriptor descriptor);

    /*!
     returns the value of an event at specified time with specific descriptor.
     @param time time of the event
     @param descriptor descriptor of the event
     */
    std::string getValueAsString(double time, EDescriptor descriptor);
    
    
    bool activateInterpolation(const EDescriptor descriptor = SD_ALL);
    bool deactivateInterpolation(const EDescriptor descriptor = SD_ALL);
    bool isInterpolationActivated(const EDescriptor descriptor);
    
    /*!static function for sorting. employed by sdSaver*/
    static bool sortAlphabetically( sdEntityCore *leftEntity, sdEntityCore *rightEntity);
    
};


#pragma mark implementations
inline std::string sdEntityCore::getName(void){
    return name;
}

inline EKind sdEntityCore::getKind(void){
    return kind;
}

inline EType sdEntityCore::getType(void){
    return type;
}



inline bool sdEntityCore::sortAlphabetically( sdEntityCore *leftEntity,  sdEntityCore *rightEntity){
    return leftEntity->getName().compare(rightEntity->getName()) ? false:true;
}

inline bool sdEntityCore::isCoreDescriptor(EDescriptor descriptor){
    for(int i = 0; i< sdEventCore::numberOfDescriptors; i++){
        if(sdEventCore::descriptors[i].getDescriptor() == descriptor) return true;
    }
    return false;
}

inline bool sdEntityCore::isCoreDescriptor(std::string descriptor){
    for(int i = 0; i< sdEventCore::numberOfDescriptors; i++){
        if(sdEventCore::descriptors[i].getDescriptorAsString() == descriptor)
            return true;
    }
    return false;
}


#endif /* defined(____sdEntityCore__) */
