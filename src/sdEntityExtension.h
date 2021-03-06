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

#ifndef ____sdEntityExtension__
#define ____sdEntityExtension__

#include <string>
#include <vector>
#include "sdConst.h"
#include "sdEntity.h"


/*! a pure abstract class for entity extensions.
  the subclasses of this class must override getValue function
 */
class sdEntityExtension: public sdEntity{

protected:
    /*! sub classes must define their descriptors*/
    static const std::vector <EDescriptor>descriptors;

public:
    /*! returns vector of EDescriptor that a subclass of this class is responsible for */
    static std::vector<EDescriptor> getDescriptors(void);
    virtual EExtension getExtensionName(void) = 0;
    virtual std::string getExtensionNameAsString(void) = 0;
};

#endif
